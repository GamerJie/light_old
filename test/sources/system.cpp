//
// Created by Jie on 19.1.13.
//

#include <stdio.h>

#include "system.h"
#include "registry.h"

lua_system::lua_system(std::string file): systems() {
    sol::table system_table = world::current->lua.script_file(file + ".lua");
    if(! system_table.valid()){
        printf("load error! valid lua system !");
        return;
    }

    sol::function init_func = system_table["init"];
    if(! init_func.valid()){
        printf("load error! no init function !");
        return;
    }
    m_components_tbl = init_func();
    if(! m_components_tbl.valid()){
        printf("init function error ! init must be return a table with components type.");
        return;
    }

    sol::function update_func = system_table["update"];
    if(! update_func.valid()){
        printf("load error! no update function !");
        return;
    }
    m_update_func = update_func;
}

void lua_system::update(int dt, registry *reg) {
    if(! m_update_func.valid() || ! m_components_tbl.valid())
        return;

    int index = 1;
    sol::table list = world::current->lua.create_table();

    for(auto& com: m_components_tbl) {
        if(com.second.get_type() != sol::type::string) {
            printf("update component data failed!");
            break;
        }

        for (auto kv: reg->view(com.second.as<std::string>())) {
            list[index++] = kv.table;
        }
    }

    m_update_func(dt, list);
}