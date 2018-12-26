//
// Created by Jie on 18.12.26.
//

#ifndef PROJECT_SYSTEM_H
#define PROJECT_SYSTEM_H

#include "World.h"

namespace entt {
    class DefaultRegistry;
}

class System {
    friend class World;

public:
    virtual ~System() = default;

protected:
    System() = default;

    virtual void update(const double dt, entt::DefaultRegistry& registry) = 0;

};

#endif //PROJECT_SYSTEM_H
