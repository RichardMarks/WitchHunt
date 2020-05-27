//
// Created by Richard Marks on 5/27/20.
//

#ifndef WITCHHUNT_H
#define WITCHHUNT_H

#include "engine.h"

namespace witchhunt {
  class Game : public engine::Game {
    // TODO: remove this debugging code
    float x{};
    float y{};
  public:
    void Boot() override;
    void Unload() override;
    void UpdateFrame(float deltaTime) override;
    void RenderFrame() override;
    bool HandleEvent(engine::Dependencies& dependencies) override;
  };
}

#endif //WITCHHUNT_H
