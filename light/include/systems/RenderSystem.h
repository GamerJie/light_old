//
// Created by Jie on 19.1.5.
//

#ifndef light_render_system_h
#define light_render_system_h

#include "core/System.h"

class LightAPI RenderSystem: public System {
public:
    RenderSystem();

protected:
    void update(const int dt, entt::registry<>& registry) override;
};

#endif //light_render_system_h
