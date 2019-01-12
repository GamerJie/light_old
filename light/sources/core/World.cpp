//
// Created by Jie on 18.12.24.
//

#include "core/World.h"

World::World() {
    console = spdlog::stdout_color_mt("World");
    m_lua.open_libraries(sol::lib::base, sol::lib::math, sol::lib::os, sol::lib::package, \
    sol::lib::string, sol::lib::table, sol::lib::utf8);


    console->info("World init over.");
}

World::~World() {
    m_tagAssign.clear();
    m_componentAssign.clear();
    m_systems.clear();
    m_registry.reset();
}

entt::registry<>::entity_type World::createEntity(const std::string& script) {
    sol::state loader;
    loader.script(script);

    entt::registry<>::entity_type entity = m_registry.create();
    sol::table components = loader.get<sol::table>("entity");

    if(!components.empty()){

    }

    auto tag = components["tags"];
    if(tag.valid()){
        sol::table tags = components.get<sol::table>("tags");
        tags.for_each([&](std::pair<sol::object, sol::object> pair){
            m_tagAssign[entt::hashed_string(pair.first.as<const char*>())](entity, pair.second.as<sol::table>());
        });
    }

    return entity;
}

void World::update(const int dt){
    for(auto& pair : m_systems){
        pair.second->update(dt, m_registry);
    }
}