//
// Created by Jie on 18.12.24.
//

#include <SFML/Window.hpp>

#include "core/Application.h"
#include "entt/signal/dispatcher.hpp"

Application::Application() {
    m_window = new sf::Window(sf::VideoMode(800, 600), "light");

    m_stateMachine = std::make_unique<StateMachine>();
}

Application::~Application() {
    m_window->close();
    m_window = NULL;
    delete(m_window);
}

bool Application::run() {

    m_stateMachine->load();

    sf::Event event;
    while(m_window->isOpen()){
        m_window->pollEvent(event);

        m_stateMachine->event(&event);

        switch (event.type){
            case sf::Event::Closed:
                m_window->close();
                break;
            default:
                break;
        }

        m_stateMachine->update(0.2f);

        // m_window->clear();

        m_stateMachine->render();

        m_window->display();
    }

    m_stateMachine->unload();

	return true;
}