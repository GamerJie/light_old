//
// Created by Jie on 19.1.13.
//

#ifndef UNTITLED1_WORLD_H
#define UNTITLED1_WORLD_H

#include <map>
#include <string>

#include "sol2/sol.hpp"

#define entity_type int

class systems;
class registry;

struct component_data {
    void* data;
    sol::table table;

    component_data(){

    }

    component_data(void* d){
        data = d;
    }

    component_data(sol::table tbl){
        table = tbl;
    }

    template <typename T>
    T get_data(){
        if(data != nullptr)
            return data;
        else
            return table;
    }
};

class world {
public:

    world();
    entity_type create(std::string name = "");

    template <typename C, typename... Args>
    void assign(entity_type entity, Args... args);

    void assign(entity_type entity, const std::string name);
    void assign(entity_type entity, std::string name, sol::table com);

    template <typename S, typename... Args>
    void reg_sys(Args... args);

    void reg_sys(std::string name);
    void update(int dt);

private:
    int index = 0;
    registry* m_reg;

public:
    static world* current;

    std::map<entity_type, std::map<std::string, component_data>> entities;
    std::map<std::string, systems*> systems;

    sol::state lua;
};

template <typename C, typename... Args>
void world::assign(entity_type entity, Args... args){
    component_data data = new C(std::forward<Args>(args)...);
    entities[entity][typeid(C).name()] = data;
}

template <typename S, typename... Args>
void world::reg_sys(Args... args){
    systems[typeid(S).name()] = new S(std::forward<Args>(args)...);
}

#endif //UNTITLED1_WORLD_H
