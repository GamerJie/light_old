//
// Created by Jie on 18.12.24.
//

#ifndef light_state_h
#define light_state_h

#include "Light.h"

namespace sf{
    class Event;
}

class LightAPI State {
public:
    virtual ~State() = default;

    virtual void load() = 0;
    virtual void unload() = 0;
    virtual void event(sf::Event* event) = 0;
    virtual void update(const double dt) = 0;
    virtual void render() = 0;

protected:
    State() = default;
};


#endif //light_state_h
