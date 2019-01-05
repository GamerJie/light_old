//
// Created by Jie on 19.1.5.
//

#include "systems/RenderSystem.h"

RenderSystem::RenderSystem() {
    console = spdlog::stdout_color_mt("RenderSystem");

    console->info("RenderSystem init over.");
}

void RenderSystem::update(const int dt, entt::registry<>& registry){

}