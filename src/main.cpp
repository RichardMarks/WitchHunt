#include "witchhunt.h"

int main(int argc, char* argv[]) {
  try {
    engine::GameConsole console;
    witchhunt::Game game;
    game.Configure("WiTCHHUNT", 640, 480, engine::USE_WINDOWED_DISPLAY);
    console.Load(game);
  } catch (const std::exception& ex) {
    std::cerr << "FATAL ERROR: " << ex.what() << std::endl;
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
