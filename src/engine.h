//
// Created by Richard Marks on 5/27/20.
//

#ifndef WITCHHUNT_ENGINE_H
#define WITCHHUNT_ENGINE_H

#include <stdexcept>

#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>

#include <SDL.h>

namespace engine {
  namespace logger {
    class Log {
    public:
      static void Write(const std::string& s) {
        std::cout << s << std::endl;
      }
    };
  }
  [[maybe_unused]] constexpr bool USE_FULLSCREEN_DISPLAY = true;
  [[maybe_unused]] constexpr bool USE_WINDOWED_DISPLAY = false;

  class Dependencies;
  class Configuration;
  class Game;
  class GameConsole;
  class GameConsoleDisplayController;
  class GameConsoleInputController;
  class GameConsoleAudioController;
  class GameConsoleFileSystemController;
  class GameConsoleRuntime;

  class GameConsoleDisplayController {
    GameConsole& gameConsole;
    bool shouldRender{};
    uint8_t backgroundColorRed{};
    uint8_t backgroundColorGreen{};
    uint8_t backgroundColorBlue{};
    uint8_t foregroundColorRed{};
    uint8_t foregroundColorGreen{};
    uint8_t foregroundColorBlue{};
    int columns{};
    int rows{};
    int cursorColumn{};
    int cursorRow{};
    uint8_t* characterROM{};
  public:
    explicit GameConsoleDisplayController(GameConsole &console);
    bool HandleEvent(Dependencies& dependencies);
    [[nodiscard]] bool ShouldRender() const;
    void Enable();
    void Disable();
    void SetBackgroundColor(uint8_t red, uint8_t green, uint8_t blue);
    void SetForegroundColor(uint8_t red, uint8_t green, uint8_t blue);
    void SetSize(int numColumns, int numRows);
    void SetCursorPosition(int column, int row);
    void WriteText(const char* text);
    void WriteChar(char c);

    void PrepareFrame();
    void PresentFrame();
  };

  class InputState {
  public:
    bool up;
    bool down;
    bool left;
    bool right;

    bool confirm;
    bool cancel;
    bool start;
    bool back;

    bool confirmPressed;
    bool cancelPressed;
    bool startPressed;
    bool backPressed;

    int mouseX;
    int mouseY;
    bool mouseDown;
  };

  namespace Input {
    enum AxisName {
      Horizontal,
      Vertical
    };

    enum ButtonName {
      Confirm,
      Cancel,
      Start,
      Back
    };
  }

  class GameConsoleInputController {
    GameConsole& gameConsole;
    InputState inputState{};
  public:
    explicit GameConsoleInputController(GameConsole &console);
    bool HandleEvent(Dependencies& dependencies);

    [[nodiscard]] float GetAxis(Input::AxisName axisName) const;
    [[nodiscard]] bool GetButtonDown(Input::ButtonName buttonName);
    [[nodiscard]] bool GetButtonUp(Input::ButtonName buttonName);
    [[nodiscard]] bool GetButton(Input::ButtonName buttonName) const;
  };

  class GameConsoleAudioController {
  public:
    explicit GameConsoleAudioController(GameConsole &console);
    bool HandleEvent(Dependencies& dependencies);
  };

  class GameConsoleFileSystemController {
  public:
    explicit GameConsoleFileSystemController(GameConsole &console);
    bool HandleEvent(Dependencies& dependencies);
  };

  class GameConsoleRuntime {
    float timeScale{};
    bool isRunning{};
    bool isPaused{};
    GameConsole& gameConsole;
  public:
    explicit GameConsoleRuntime(GameConsole &console);

    void Start(Game& externalGameInstance);
    void Stop();
    bool HandleEvent(Dependencies& dependencies);
  };

  class Dependencies {
    SDL_Window* mainWindowPtr;
    SDL_Renderer* mainRendererPtr;
    SDL_Event sdlEvent{};
  public:
    Dependencies();
    explicit Dependencies(const Configuration& configuration);
    ~Dependencies();

    SDL_Window* GetMainWindow();
    SDL_Renderer* GetMainRenderer();
    SDL_Event& GetEvent();

    bool HasPendingEvent();
    static float GetTicks();
  };

  class Configuration {
  public:
    int resolutionX;
    int resolutionY;
    int windowWidth;
    int windowHeight;
    bool useFullScreen;
    const char* windowTitle;
  };

  class Game {
    Configuration configuration{};

  public:
    [[nodiscard]] const Configuration& Configuration() const;

    void Configure(const char *windowTitle, int screenWidth, int screenHeight, bool useFullScreen, int windowWidth, int windowHeight);
    void Configure(const char *windowTitle, int screenWidth, int screenHeight, bool useFullScreen);

    virtual void Boot() = 0;
    virtual void Unload() = 0;
    virtual void UpdateFrame(float deltaTime) = 0;
    virtual void RenderFrame() = 0;
    virtual bool HandleEvent(Dependencies& dependencies) = 0;

    GameConsole* gameConsole;
  };

  class GameConsole {
    Dependencies* dependencies;
    GameConsoleRuntime* runtime;
    GameConsoleDisplayController* displayController;
    GameConsoleInputController* inputController;
    GameConsoleAudioController* audioController;
    GameConsoleFileSystemController* fileSystemController;
    Game* game;
  public:
    void Load(Game& externalGameInstance);
    void Unload();
    // get references to all components
    [[nodiscard]] Dependencies& Dependencies() const;
    [[nodiscard]] GameConsoleDisplayController& Display() const;
    [[nodiscard]] GameConsoleInputController& Input() const;
    [[nodiscard]] GameConsoleAudioController& Audio() const;
    [[nodiscard]] GameConsoleFileSystemController& FileSystem() const;
    [[nodiscard]] GameConsoleRuntime& Runtime() const;
    [[nodiscard]] Game& Game() const;
  };
}

#endif //WITCHHUNT_ENGINE_H
