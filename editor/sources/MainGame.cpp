//
// Created by Jie on 18.12.26.
//

#include <systems/RenderSystem.h>

#include "MainGame.h"

MainGame::MainGame(const std::string config) :Application(config) {
    m_world->registerSystem<RenderSystem>();
}