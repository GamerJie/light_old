//
// Created by Jie on 18.12.26.
//

#ifndef light_system_h
#define light_system_h

#include "Light.h"
#include "spdlog/spdlog.h"
#include "entt/entity/registry.hpp"
#include "spdlog/sinks/stdout_color_sinks.h"

class LightAPI System {
    friend class World;

public:
    virtual ~System() = default;

protected:
    System()= default;

    virtual void update(const int dt, entt::registry<>& registry) = 0;


protected:
    std::shared_ptr<spdlog::logger> console;
};

#endif //light_system_h
