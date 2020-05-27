#include <iostream>
#include <sstream>
#include <stdexcept>

#include <SDL.h>

constexpr int SCREEN_WIDTH = 1920 / 2;
constexpr int SCREEN_HEIGHT = 1080 / 2;
constexpr const char* WINDOW_TITLE = "WiTCHHUNT";

namespace witchhunt {
  class Game {
    struct Input {
      bool up;
      bool down;
      bool left;
      bool right;
      bool jump;
      int mouseX;
      int mouseY;
      bool mouseDown;
    };

  public:
    Game();
    ~Game();
    void load();
    void unload();
    void create();
    void destroy();
    void update(float deltaTime);
    void render();

    SDL_Window* mainWindowPtr;
    SDL_Renderer* mainRendererPtr;
    Input input;
    float timeScale;
    bool isRunning;
    bool isPaused;
  };

}

int main (int argc, char* argv[]) {
  try {
    witchhunt::Game game;
  } catch (const std::exception& ex) {
    std::cerr << "Runtime Error: " << ex.what() << std::endl;
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}

witchhunt::Game::Game() : mainWindowPtr(nullptr), mainRendererPtr(nullptr) {
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    std::stringstream msg;
    msg << "Error occurred in init_game()\nUnable to initialize SDL2: " << SDL_GetError() << std::endl;
    throw std::runtime_error(msg.str());
  }

  mainWindowPtr = SDL_CreateWindow(
    WINDOW_TITLE,
    SDL_WINDOWPOS_UNDEFINED,
    SDL_WINDOWPOS_UNDEFINED,
    SCREEN_WIDTH,
    SCREEN_HEIGHT,
    SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE
  );

  if (!mainWindowPtr) {
    std::stringstream msg;
    msg << "Error occurred in init_game()\nUnable to create the main window: " << SDL_GetError() << std::endl;
    throw std::runtime_error(msg.str());
  }

  mainRendererPtr = SDL_CreateRenderer(
    mainWindowPtr,
    -1,
    SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE
  );

  if (!mainRendererPtr) {
    std::stringstream msg;
    msg << "Error occurred in init_game()\nUnable to create the main renderer:" << SDL_GetError() << std::endl;
    throw std::runtime_error(msg.str());
  }

  SDL_RenderSetLogicalSize(mainRendererPtr, SCREEN_WIDTH, SCREEN_HEIGHT);
  SDL_MaximizeWindow(mainWindowPtr);

  load();
  create();

  isRunning = true;
  isPaused = false;

  input.up = false;
  input.down = false;
  input.left = false;
  input.right = false;
  input.jump = false;
  input.mouseX = 0;
  input.mouseY = 0;
  input.mouseDown = false;

  SDL_Event sdlEvent;

  float lastTime = static_cast<float>(SDL_GetTicks() * 0.001f);
  float newTime = 0;
  float deltaTime = 0.0f;

  timeScale = 1.0f;

  while (isRunning) {
    newTime = static_cast<float>(SDL_GetTicks() * 0.001f);
    if (newTime - lastTime < 1) {
      deltaTime = (newTime - lastTime) * timeScale;
      update(deltaTime);
    }
    lastTime = newTime;

    render();

    while (SDL_PollEvent(&sdlEvent)) {
      switch (sdlEvent.type) {
        case SDL_QUIT: {
          isRunning = false;
        } break;

        case SDL_KEYDOWN: {
          switch (sdlEvent.key.keysym.scancode) {
            case SDL_SCANCODE_ESCAPE: { isRunning = false; } break;
            case SDL_SCANCODE_W: { input.up = true; } break;
            case SDL_SCANCODE_S: { input.down = true; } break;
            case SDL_SCANCODE_A: { input.left = true; } break;
            case SDL_SCANCODE_D: { input.right = true; } break;

            case SDL_SCANCODE_UP: { input.up = true; } break;
            case SDL_SCANCODE_DOWN: { input.down = true; } break;
            case SDL_SCANCODE_LEFT: { input.left = true; } break;
            case SDL_SCANCODE_RIGHT: { input.right = true; } break;

            case SDL_SCANCODE_SPACE: { input.jump = true; } break;
            default: break;
          }
        } break;

        case SDL_KEYUP: {
          switch (sdlEvent.key.keysym.scancode) {
            case SDL_SCANCODE_W: { input.up = false; } break;
            case SDL_SCANCODE_S: { input.down = false; } break;
            case SDL_SCANCODE_A: { input.left = false; } break;
            case SDL_SCANCODE_D: { input.right = false; } break;

            case SDL_SCANCODE_UP: { input.up = false; } break;
            case SDL_SCANCODE_DOWN: { input.down = false; } break;
            case SDL_SCANCODE_LEFT: { input.left = false; } break;
            case SDL_SCANCODE_RIGHT: { input.right = false; } break;

            case SDL_SCANCODE_SPACE: { input.jump = false; } break;
            default: break;
          }
        } break;

        case SDL_MOUSEMOTION: {
          input.mouseX = sdlEvent.motion.x;
          input.mouseY = sdlEvent.motion.y;
        } break;

        case SDL_MOUSEBUTTONDOWN: {
          input.mouseDown = true;
          input.mouseX = sdlEvent.button.x;
          input.mouseY = sdlEvent.button.y;
        } break;

        case SDL_MOUSEBUTTONUP: {
          input.mouseDown = false;
          input.mouseX = sdlEvent.button.x;
          input.mouseY = sdlEvent.button.y;
        } break;

        default: break;
      }
    }
  }
}

witchhunt::Game::~Game() {
  destroy();
  unload();
  SDL_DestroyRenderer(mainRendererPtr);
  SDL_DestroyWindow(mainWindowPtr);
  SDL_Quit();
}

void witchhunt::Game::load() {
  // load resources
}

void witchhunt::Game::unload() {
  // free resources
}

void witchhunt::Game::create() {
  // allocate objects
}

void witchhunt::Game::destroy() {
  // free objects
}

void witchhunt::Game::update(float deltaTime) {
  // update objects
}

void witchhunt::Game::render() {
  SDL_SetRenderDrawColor(mainRendererPtr, 0x30, 0x60, 0x90, 0xFF);
  SDL_RenderClear(mainRendererPtr);

  // draw objects

  SDL_RenderPresent(mainRendererPtr);
}
