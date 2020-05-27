//
// Created by Richard Marks on 5/27/20.
//

#include "engine.h"

// TODO: move into engine_dependencies.cpp

engine::Dependencies::Dependencies() : mainWindowPtr(nullptr), mainRendererPtr(nullptr) {

}

engine::Dependencies::Dependencies(const engine::Configuration &configuration) : Dependencies() {
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    std::stringstream msg;
    msg << "Unable to initialize SDL2: " << SDL_GetError() << std::endl;
    throw std::runtime_error(msg.str());
  }

  mainWindowPtr = SDL_CreateWindow(
    configuration.windowTitle,
    SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED,
    configuration.windowWidth,
    configuration.windowHeight,
    configuration.useFullScreen
    ? SDL_WINDOW_FULLSCREEN_DESKTOP | SDL_WINDOW_SHOWN
    : SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN
  );

  if (!mainWindowPtr) {
    std::stringstream msg;
    msg << "Unable to create the main window: " << SDL_GetError() << std::endl;
    throw std::runtime_error(msg.str());
  }

  mainRendererPtr = SDL_CreateRenderer(
    mainWindowPtr,
    -1,
    SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE
  );

  if (!mainRendererPtr) {
    std::stringstream msg;
    msg << "Unable to create the main renderer:" << SDL_GetError() << std::endl;
    throw std::runtime_error(msg.str());
  }

  SDL_RenderSetLogicalSize(mainRendererPtr, configuration.resolutionX, configuration.resolutionY);
  SDL_MaximizeWindow(mainWindowPtr);
}

engine::Dependencies::~Dependencies() {
  if (mainRendererPtr != nullptr) {
    SDL_DestroyRenderer(mainRendererPtr);
    mainRendererPtr = nullptr;
  }
  if (mainWindowPtr != nullptr) {
    SDL_DestroyWindow(mainWindowPtr);
    mainWindowPtr = nullptr;
  }
  SDL_Quit();
}

SDL_Window *engine::Dependencies::GetMainWindow() {
  return mainWindowPtr;
}

SDL_Renderer *engine::Dependencies::GetMainRenderer() {
  return mainRendererPtr;
}

SDL_Event &engine::Dependencies::GetEvent() {
  return sdlEvent;
}

bool engine::Dependencies::HasPendingEvent() {
  return SDL_PollEvent(&sdlEvent) != 0;
}

float engine::Dependencies::GetTicks() {
  return static_cast<float>(SDL_GetTicks() * 0.001f);
}

// GameConsole
// TODO: move into engine_game_console.cpp

engine::Dependencies & engine::GameConsole::Dependencies() const {
  return *dependencies;
}

engine::Game & engine::GameConsole::Game() const {
  return *game;
}

engine::GameConsoleDisplayController & engine::GameConsole::Display() const {
  return *displayController;
}

engine::GameConsoleInputController & engine::GameConsole::Input() const {
  return *inputController;
}

engine::GameConsoleAudioController & engine::GameConsole::Audio() const {
  return *audioController;
}

engine::GameConsoleFileSystemController & engine::GameConsole::FileSystem() const {
  return *fileSystemController;
}

engine::GameConsoleRuntime & engine::GameConsole::Runtime() const {
  return *runtime;
}

void engine::GameConsole::Load(engine::Game &externalGameInstance) {
  game = &externalGameInstance;

  game->gameConsole = this;

  dependencies = new engine::Dependencies(externalGameInstance.Configuration());

  displayController = new GameConsoleDisplayController(*this);
  inputController = new GameConsoleInputController(*this);
  audioController = new GameConsoleAudioController(*this);
  fileSystemController = new GameConsoleFileSystemController(*this);

  runtime = new GameConsoleRuntime(*this);

  runtime->Start(externalGameInstance);
}

void engine::GameConsole::Unload() {
  game->Unload();
}

// Game
// TODO: move into engine_game.cpp

const engine::Configuration &engine::Game::Configuration() const {
  return configuration;
}

void engine::Game::Configure(const char *windowTitle, int screenWidth, int screenHeight, bool useFullScreen, int windowWidth, int windowHeight) {
  configuration.useFullScreen = useFullScreen;
  configuration.windowTitle = windowTitle;
  configuration.resolutionX = screenWidth;
  configuration.resolutionY = screenHeight;
  configuration.windowWidth = windowWidth;
  configuration.windowHeight = windowHeight;
}

void engine::Game::Configure(const char *windowTitle, int screenWidth, int screenHeight, bool useFullScreen) {
  Configure(windowTitle, screenWidth, screenHeight, useFullScreen, -1, -1);
}

// GameConsoleDisplayController
// TODO: move into engine_game_console_display_controller.cpp

engine::GameConsoleDisplayController::GameConsoleDisplayController(engine::GameConsole &console) : gameConsole(console), shouldRender(true) {

}

bool engine::GameConsoleDisplayController::ShouldRender() const {
  return shouldRender;
}

void engine::GameConsoleDisplayController::Enable() {
  shouldRender = true;
}

void engine::GameConsoleDisplayController::Disable() {
  shouldRender = false;
}

bool engine::GameConsoleDisplayController::HandleEvent(engine::Dependencies &dependencies) {
  // FIXME: we need an abstraction on top of the SDL2 dependency layer for event handling
  SDL_Event& sdlEvent = dependencies.GetEvent();

  switch (sdlEvent.type) {
    case SDL_WINDOWEVENT_FOCUS_LOST:
      shouldRender = false;
      return true;
    case SDL_WINDOWEVENT_FOCUS_GAINED:
      shouldRender = true;
      return true;
    case SDL_WINDOWEVENT_MINIMIZED:
      shouldRender = false;
      return true;
    case SDL_WINDOWEVENT_RESTORED:
      shouldRender = true;
      return true;
  }

  return false;
}

void engine::GameConsoleDisplayController::PrepareFrame() {
  Dependencies& dependencies = gameConsole.Dependencies();
  SDL_Renderer* mainRendererPtr = dependencies.GetMainRenderer();
  uint8_t red = backgroundColorRed;
  uint8_t green = backgroundColorGreen;
  uint8_t blue = backgroundColorBlue;
  SDL_SetRenderDrawColor(mainRendererPtr, red, green, blue, 0xFF);
  SDL_RenderClear(mainRendererPtr);
}

void engine::GameConsoleDisplayController::PresentFrame() {
  Dependencies& dependencies = gameConsole.Dependencies();
  SDL_Renderer* mainRendererPtr = dependencies.GetMainRenderer();
  SDL_RenderPresent(mainRendererPtr);
}

void engine::GameConsoleDisplayController::SetBackgroundColor(uint8_t red, uint8_t green, uint8_t blue) {
  backgroundColorRed = red;
  backgroundColorGreen = green;
  backgroundColorBlue = blue;
}

void engine::GameConsoleDisplayController::SetForegroundColor(uint8_t red, uint8_t green, uint8_t blue) {
  foregroundColorRed = red;
  foregroundColorGreen = green;
  foregroundColorBlue = blue;
}

void engine::GameConsoleDisplayController::SetSize(int numColumns, int numRows) {
  columns = numColumns;
  rows = numRows;
}

void engine::GameConsoleDisplayController::SetCursorPosition(int column, int row) {
  cursorColumn = column;
  cursorRow = row;
}

void engine::GameConsoleDisplayController::WriteText(const char *text) {

}

void engine::GameConsoleDisplayController::WriteChar(char c) {

}

// GameConsoleInputController
// TODO: move into engine_game_console_input_controller.cpp

engine::GameConsoleInputController::GameConsoleInputController(engine::GameConsole &console) : gameConsole(console) {

}

bool engine::GameConsoleInputController::HandleEvent(engine::Dependencies &dependencies) {
  inputState.backPressed = false;
  inputState.startPressed = false;
  inputState.cancelPressed = false;
  inputState.confirmPressed = false;

  // FIXME: we need an abstraction on top of the SDL2 dependency layer for event handling
  SDL_Event& sdlEvent = dependencies.GetEvent();

  switch (sdlEvent.type) {
    case SDL_KEYDOWN: {
      switch (sdlEvent.key.keysym.scancode) {
        // TODO: the game should be responsible for handling this to avoid escape killing the game
        case SDL_SCANCODE_ESCAPE: {
          gameConsole.Runtime().Stop();
        } break;

        case SDL_SCANCODE_W: { inputState.up = true; } break;
        case SDL_SCANCODE_S: { inputState.down = true; } break;
        case SDL_SCANCODE_A: { inputState.left = true; } break;
        case SDL_SCANCODE_D: { inputState.right = true; } break;

        case SDL_SCANCODE_UP: { inputState.up = true; } break;
        case SDL_SCANCODE_DOWN: { inputState.down = true; } break;
        case SDL_SCANCODE_LEFT: { inputState.left = true; } break;
        case SDL_SCANCODE_RIGHT: { inputState.right = true; } break;

        case SDL_SCANCODE_SPACE: { inputState.confirm = true; } break;
        case SDL_SCANCODE_RETURN: { inputState.start = true; } break;
        case SDL_SCANCODE_BACKSPACE: { inputState.back = true; } break;
        case SDL_SCANCODE_LCTRL: { inputState.cancel = true; } break;
        default: break;
      }
      return true;
    } break;

    case SDL_KEYUP: {
      switch (sdlEvent.key.keysym.scancode) {
        case SDL_SCANCODE_W: { inputState.up = false; } break;
        case SDL_SCANCODE_S: { inputState.down = false; } break;
        case SDL_SCANCODE_A: { inputState.left = false; } break;
        case SDL_SCANCODE_D: { inputState.right = false; } break;

        case SDL_SCANCODE_UP: { inputState.up = false; } break;
        case SDL_SCANCODE_DOWN: { inputState.down = false; } break;
        case SDL_SCANCODE_LEFT: { inputState.left = false; } break;
        case SDL_SCANCODE_RIGHT: { inputState.right = false; } break;

        case SDL_SCANCODE_SPACE: { inputState.confirm = false; } break;
        case SDL_SCANCODE_RETURN: { inputState.start = false; } break;
        case SDL_SCANCODE_BACKSPACE: { inputState.back = false; } break;
        case SDL_SCANCODE_LCTRL: { inputState.cancel = false; } break;
        default: break;
      }
      return true;
    } break;

    case SDL_MOUSEMOTION: {
      inputState.mouseX = sdlEvent.motion.x;
      inputState.mouseY = sdlEvent.motion.y;
      return true;
    } break;

    case SDL_MOUSEBUTTONDOWN: {
      inputState.mouseDown = true;
      inputState.mouseX = sdlEvent.button.x;
      inputState.mouseY = sdlEvent.button.y;
      return true;
    } break;

    case SDL_MOUSEBUTTONUP: {
      inputState.mouseDown = false;
      inputState.mouseX = sdlEvent.button.x;
      inputState.mouseY = sdlEvent.button.y;
      return true;
    } break;
  }

  return false;
}

float engine::GameConsoleInputController::GetAxis(const Input::AxisName axisName) const {
  float axis = 0;

  switch (axisName) {
    case Input::Horizontal:
      if (inputState.left) {
        axis = -1.0f;
      } else if (inputState.right) {
        axis = 1.0f;
      }
      break;
    case Input::Vertical:
      if (inputState.up) {
        axis = -1.0f;
      } else if (inputState.down) {
        axis = 1.0f;
      }
      break;
  }

  return axis;
}

bool engine::GameConsoleInputController::GetButtonDown(const Input::ButtonName buttonName) {

  switch (buttonName) {
    case Input::Confirm: {
      if (inputState.confirm && !inputState.confirmPressed) {
        inputState.confirmPressed = true;
        return true;
      } else if (!inputState.confirm) {
        inputState.confirmPressed = false;
      }
    } break;
    case Input::Cancel: {
      if (inputState.cancel && !inputState.cancelPressed) {
        inputState.cancelPressed = true;
        return true;
      } else if (!inputState.cancel) {
        inputState.cancelPressed = false;
      }
    } break;
    case Input::Back: {
      if (inputState.back && !inputState.backPressed) {
        inputState.backPressed = true;
        return true;
      } else if (!inputState.back) {
        inputState.backPressed = false;
      }
    } break;
    case Input::Start: {
      if (inputState.start && !inputState.startPressed) {
        inputState.startPressed = true;
        return true;
      } else if (!inputState.start) {
        inputState.startPressed = false;
      }
    } break;
  }

  return false;
}

bool engine::GameConsoleInputController::GetButtonUp(engine::Input::ButtonName buttonName) {
  return !GetButtonDown(buttonName);
}

bool engine::GameConsoleInputController::GetButton(engine::Input::ButtonName buttonName) const {
  switch (buttonName) {
    case Input::Confirm: return inputState.confirm;
    case Input::Cancel: return inputState.cancel;
    case Input::Back: return inputState.back;
    case Input::Start: return inputState.start;
  }

  return false;
}

// GameConsoleAudioController
// TODO: move into engine_game_console_audio_controller.cpp

engine::GameConsoleAudioController::GameConsoleAudioController(engine::GameConsole &console) {

}

bool engine::GameConsoleAudioController::HandleEvent(engine::Dependencies &dependencies) {
  return false;
}

// GameConsoleFileSystemController
// TODO: move into engine_game_console_file_system_controller.cpp

engine::GameConsoleFileSystemController::GameConsoleFileSystemController(engine::GameConsole &console) {

}

bool engine::GameConsoleFileSystemController::HandleEvent(engine::Dependencies &dependencies) {
  return false;
}

// GameConsoleRuntime
// TODO: move into engine_game_console_runtime.cpp

engine::GameConsoleRuntime::GameConsoleRuntime(engine::GameConsole &console) : gameConsole(console) {

}

void engine::GameConsoleRuntime::Start(engine::Game &externalGameInstance) {
  // local references for code clarity
  Dependencies& dependencies = gameConsole.Dependencies();
  GameConsoleDisplayController& displayController = gameConsole.Display();
  GameConsoleInputController& inputController = gameConsole.Input();
  GameConsoleAudioController& audioController = gameConsole.Audio();
  GameConsoleFileSystemController& fileSystemController = gameConsole.FileSystem();

  isRunning = true;
  isPaused = false;
  timeScale = 1.0f;

  auto lastTime = Dependencies::GetTicks();
  float newTime = 0;
  float deltaTime = 0.0f;

  externalGameInstance.Boot();

  while (isRunning) {
    newTime = Dependencies::GetTicks();
    if (newTime - lastTime < 1) {
      deltaTime = (newTime - lastTime) * timeScale;
      externalGameInstance.UpdateFrame(deltaTime);
    }
    lastTime = newTime;

    if (displayController.ShouldRender()) {
      displayController.PrepareFrame();
      externalGameInstance.RenderFrame();
      displayController.PresentFrame();
    }

    while (dependencies.HasPendingEvent()) {
      // give the game a chance to do something with the event information
      externalGameInstance.HandleEvent(dependencies);

      if (inputController.HandleEvent(dependencies)) {
        // input controller was able to handle the event
      } else if (displayController.HandleEvent(dependencies)) {
        // display controller was able to handle the event
      } else if (HandleEvent(dependencies)) {
        // runtime was able to handle the event
      } else {
        // the event was not handled - what should we do now?
      }
    }
  }

  gameConsole.Unload();
}

void engine::GameConsoleRuntime::Stop() {
  isRunning = false;
}

bool engine::GameConsoleRuntime::HandleEvent(engine::Dependencies &dependencies) {
  // FIXME: we need an abstraction on top of the SDL2 dependency layer for event handling
  SDL_Event& sdlEvent = dependencies.GetEvent();

  switch (sdlEvent.type) {
    case SDL_QUIT: {
      isRunning = false;
      return true;
    } break;
  }

  return false;
}
