//
// Created by Jie on 18.12.24.
//

#ifndef STAR_ENGINE_STATE_H
#define STAR_ENGINE_STATE_H

namespace sf{
    class Event;
}

class State {
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


#endif //STAR_ENGINE_STATE_H
