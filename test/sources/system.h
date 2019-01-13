//
// Created by Jie on 19.1.13.
//

#ifndef UNTITLED1_SYSTEM_H
#define UNTITLED1_SYSTEM_H

#include <string>

#include "sol2/sol.hpp"

class registry;

class systems {
public:
    systems() = default;
    virtual void update(int dt, registry* reg) = 0;
};


class lua_system : public systems {
public:
    lua_system(std::string file);
    void update(int dt, registry* reg) override;

private:
    sol::table m_components_tbl;
    sol::function m_update_func;
};
#endif //UNTITLED1_SYSTEM_H
