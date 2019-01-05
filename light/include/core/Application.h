//
// Created by Jie on 18.12.24.
//

#ifndef light_application_h
#define light_application_h

#include <string>
#include <iosfwd>
#include <memory>
#include <functional>

#include "World.h"
#include "entt/entt.hpp"
#include "StateMachine.h"

namespace sf {
    class Window;
}

class LightAPI Application {
public:
    virtual ~Application();

    virtual bool run() final;

protected:
    Application();
    Application(const std::string config);

private:
    Application(const Application&) = delete;
    Application(Application&&) = delete;

protected:
    sf::Window* m_window;
    std::unique_ptr<World> m_world;
    std::unique_ptr<StateMachine> m_stateMachine;
    std::unique_ptr<entt::dispatcher> m_dispatcher;
};


#endif //light_application_h
