//
// Created by Jie on 18.12.26.
//

#ifndef light_system_h
#define light_system_h

#include <entt/entt.hpp>

#include "World.h"

class LightAPI System {
    friend class World;

public:
    virtual ~System() = default;

protected:
    System() = default;

    virtual void update(const double dt, entt::Registry<>& registry) = 0;

};

#endif //light_system_h
