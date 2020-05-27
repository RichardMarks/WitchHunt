//
// Created by Richard Marks on 5/27/20.
//

#include "witchhunt.h"

static void Log(const std::string& s) {
  engine::logger::Log::Write(s);
}

void witchhunt::Game::Boot() {
  Log("Booting WiTCHHUNT");

  gameConsole->Display().SetBackgroundColor(0x30, 0x60, 0x90);

  // TODO: remove this debugging code
  x = (float)Configuration().resolutionX * 0.5f;
  y = (float)Configuration().resolutionY * 0.5f;
}

void witchhunt::Game::Unload() {
  Log("Unloading WiTCHHUNT");
}

void witchhunt::Game::UpdateFrame(float deltaTime) {
  // TODO: remove this debugging code
  engine::GameConsoleInputController& inputController = gameConsole->Input();

  float horizontal = inputController.GetAxis(engine::Input::Horizontal);
  float vertical = inputController.GetAxis(engine::Input::Vertical);

  if (inputController.GetButtonDown(engine::Input::Back)) {
    Log("back button pressed");
  } else if (inputController.GetButtonDown(engine::Input::Start)) {
    Log("start button pressed");
  } else if (inputController.GetButtonDown(engine::Input::Cancel)) {
    Log("cancel button pressed");
  } else if (inputController.GetButtonDown(engine::Input::Confirm)) {
    Log("confirm button pressed");
  }

  x += horizontal * deltaTime * 100;
  y += vertical * deltaTime * 100;
}

void witchhunt::Game::RenderFrame() {
  // TODO: remove this debugging code
  SDL_Renderer* sdlRenderer = gameConsole->Dependencies().GetMainRenderer();
  SDL_Rect rect { static_cast<int>(x), static_cast<int>(y), 16, 16 };
  SDL_SetRenderDrawColor(sdlRenderer,0xff,0xff,0xff,0xff);
  SDL_RenderFillRect(sdlRenderer, &rect);
}

bool witchhunt::Game::HandleEvent(engine::Dependencies &dependencies) {
  return false;
}
