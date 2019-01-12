//
// Created by Jie on 18.12.24.
//

#ifndef light_application_h
#define light_application_h

#include <string>
#include <iosfwd>
#include <memory>
#include <functional>

#include "sol2/sol.hpp"
#include "fs/FileSystem.h"
#include "spdlog/spdlog.h"
#include "ServiceLocator.h"


class LightAPI Application {
public:
    virtual ~Application();

    virtual bool run() final;

protected:
    Application() = default;
    Application(const std::string config);

private:
    Application(const Application&) = delete;
    Application(Application&&) = delete;

protected:
    std::unique_ptr<World> m_world;
    std::unique_ptr<Window> m_window;
    std::unique_ptr<StateMachine> m_stateMachine;
    std::unique_ptr<entt::dispatcher> m_dispatcher;

    std::shared_ptr<spdlog::logger> console;
};


#endif //light_application_h
