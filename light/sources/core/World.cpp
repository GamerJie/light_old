//
// Created by Jie on 18.12.24.
//

#include "core/World.h"
#include "nlohmann/json.hpp"
#include "core/ServiceLocator.h"
#include "components/Transform.h"

World::World() {
    console = spdlog::stdout_color_mt("World");


    console->info("World init over.");
}

World::~World() {
    m_tagAssign.clear();
    m_componentAssign.clear();
    m_systems.clear();
    m_registry.reset();
}

entt::registry<>::entity_type World::createEntity(const std::string& script) {
    auto source = Locator::fileSystem->openAsString(script);
    entt::registry<>::entity_type entity = m_registry.create();
    sol::table entity_table = Locator::lua->script(source);
    if(! entity_table.valid()){
        console->error("create entity failed !  file: {}", script);
        return 0;
    }

    sol::table components = entity_table["components"];
    if(! components.valid()){
        console->error("create entity load components failed !  file: {}", script);
        return 0;
    }

    for(auto& kv : components){
        if(kv.first.get_type() != sol::type::string){
            return 0;
        }
        auto name = kv.first.as<std::string>();
    }



    return entity;
}


void World::registerLuaSystem(const std::string fileName) {
    if(m_systems.find(fileName) != m_systems.end()){
        // todo
        // log try to register repeat system
    }else
        m_systems[fileName] = std::make_unique<LuaSystem>(fileName);
};

void World::removeLua(const std::string key) {
    if (m_systems.find(key) != m_systems.end()) {
        m_systems[key].reset();
        m_systems.erase(key);
    } else {
        // todo
        // log try to remove none-exit system
    }
}

void World::update(const int dt){
    for(auto& pair : m_systems){
        pair.second->update(dt, m_registry);
    }
}
