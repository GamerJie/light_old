//
// Created by Jie on 18.12.26.
//

#include <systems/RenderSystem.h>

#include "MainGame.h"

MainGame::MainGame() {
    m_world->registerSystem<RenderSystem>();
}