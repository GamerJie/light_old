//
// Created by Jie on 18.12.26.
//

#ifndef light_system_h
#define light_system_h

#include "Light.h"
#include "sol2/sol.hpp"
#include "spdlog/spdlog.h"
#include "entt/entity/registry.hpp"
#include "spdlog/sinks/stdout_color_sinks.h"

class LightAPI System {
    friend class World;

public:
    virtual ~System() = default;

    System()= default;
    System(const std::string fileName);

    virtual void update(const int dt, entt::registry<>& registry) = 0;


protected:
    bool is_luaSystem = false;
    std::shared_ptr<spdlog::logger> console;
};


class LightAPI LuaSystem : public System {
public:
    LuaSystem(const std::string fileName);

protected:
    void update(const int dt, entt::registry<>& registry) override;

private:
    sol::function m_update_func;
};

#endif //light_system_h
