//
// Created by Jie on 18.12.26.
//

#include <systems/RenderSystem.h>

#include "MainGame.h"

MainGame::MainGame(const std::string config) :Application(config) {

    m_fileSystem->mount("scripts");

    m_world->registerSystem<RenderSystem>();
    m_world->registerLuaSystem("testSystem");
}