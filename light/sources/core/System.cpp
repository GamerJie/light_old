//
// Created by Jie on 19.1.12.
//

#include <core/System.h>

#include "core/System.h"
#include "core/ServiceLocator.h"

System::System(const std::string fileName) {
    is_luaSystem = true;
    console = spdlog::stdout_color_mt(fileName);
}

LuaSystem::LuaSystem(const std::string fileName) : System(fileName) {
    auto m_source = Locator::fileSystem->openAsString(fmt::format("{}.lua", fileName));
    console->info(m_source);
    sol::table system_table = Locator::lua->script(m_source);
    if(! system_table.valid()){
        console->error("load error! valid lua system !");
        return;
    }

    sol::function init_func = system_table["init"];
    if(! init_func.valid()){
        console->error("load error! no init function !");
        return;
    }
    init_func();

    sol::function update_func = system_table["update"];
    if(! update_func.valid()){
        console->error("load error! no update function !");
        return;
    }
    m_update_func = update_func;
}

void LuaSystem::update(const int dt, entt::registry<> &registry) {
    if (!m_update_func.valid()) {
        console->warn(" no update function !");
        return;
    }

    m_update_func(dt);
}
