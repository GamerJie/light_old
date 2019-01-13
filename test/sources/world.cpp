//
// Created by Jie on 19.1.13.
//

#include "world.h"
#include "registry.h"

world* world::current = nullptr;

world::world() {
    world::current = this;
    m_reg = new registry(this);

    lua.open_libraries(sol::lib::base);
}

entity_type world::create(std::string name) {
    index ++;
    if(name == "")
        return index;
    sol::table entt = lua.script_file(name + ".lua");
    sol::table components = entt["components"];
    if(! components.valid()){
        printf("init component failed ! not find 'components' !");
        return index;
    }

    for(auto& kv: components){
        if(kv.second.get_type() != sol::type::table){
            printf("init component failed ! components data must be a table !");
            return index;
        }

        assign(index, kv.first.as<std::string>(), kv.second.as<sol::table>());
    }
}

void world::assign(entity_type entity, const std::string name) {
    assign(entity, name, lua.script_file(name + ".lua"));
}

void world::assign(entity_type entity, std::string name, sol::table com) {
    entities[entity][name] = com;
}

void world::reg_sys(std::string name) {
    systems[name] = new lua_system(name);
}

void world::update(int dt) {
    for(auto& kv: systems){
        kv.second->update(dt, m_reg);
    }
}