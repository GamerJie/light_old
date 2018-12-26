//
// Created by Jie on 18.12.24.
//

#ifndef STAR_ENGINE_APPLICATION_H
#define STAR_ENGINE_APPLICATION_H

#include <string>
#include <iosfwd>
#include <memory>
#include <functional>

#include "World.h"
#include "StateMachine.h"

namespace sf {
    class Window;
}

namespace entt {
    class dispatcher;
}

class Application {
public:
    virtual ~Application();

    virtual bool run() final;

protected:
    Application();

private:
//    Application() = default;

    Application(const Application&) = delete;
    Application(Application&&) = delete;

protected:
    std::unique_ptr<World> m_world;
    std::unique_ptr<sf::Window> m_window;
    std::unique_ptr<StateMachine> m_stateMachine;
    std::unique_ptr<entt::dispatcher> m_dispatcher;
};


#endif //STAR_ENGINE_APPLICATION_H
