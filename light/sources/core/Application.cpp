//
// Created by Jie on 18.12.24.
//

#include <SFML/Window.hpp>

#include "core/Application.h"
#include "entt/signal/dispatcher.hpp"


Application::Application() {
    console = spdlog::stdout_color_mt("Application");

    m_world = std::make_unique<World>();
    m_stateMachine = std::make_unique<StateMachine>();
    m_window = std::make_unique<Window>(800, 600, "light");
    m_dispatcher = std::make_unique<entt::dispatcher>();

    Locator::world = m_world.get();
    Locator::window = m_window.get();
    Locator::stateMachine = m_stateMachine.get();
    Locator::dispatcher = m_dispatcher.get();

    console->info("Application init over.");
}

Application::~Application() {
    m_world.reset();
    m_window.reset();
    m_stateMachine.reset();
    m_dispatcher.reset();
}

bool Application::run() {

    m_stateMachine->load();

    sf::Event event{};
    sf::Clock deltaClock;
    while(m_window->isOpen()){
        while(m_window->pollEvent(event)) {
            m_stateMachine->event(&event);

            switch (event.type) {
                case sf::Event::Closed:
                    m_window->close();
                    break;
                default:
                    break;
            }
        }

        auto dt = deltaClock.restart();
        m_stateMachine->update(dt.asMilliseconds());
        m_world->update(dt.asMilliseconds());

        m_stateMachine->render();
        m_window->display();
    }

    m_stateMachine->unload();
    m_window->close();

	return true;
}