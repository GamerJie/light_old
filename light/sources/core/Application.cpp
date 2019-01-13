//
// Created by Jie on 18.12.24.
//

#include <SFML/Window.hpp>

#include "nlohmann/json.hpp"
#include "core/Application.h"
#include "entt/signal/dispatcher.hpp"


Application::Application(const std::string configPath) {
    console = spdlog::stdout_color_mt("Application");

	m_fileSystem = std::make_unique<FileSystem>();
//    auto config = m_fileSystem.openAsString(configPath);
//    auto conf = nlohmann::json::parse(config);

    auto width = 800; // conf["width"];
    auto height = 600; // conf["height"];
    auto title = "light"; // conf["title"];

    m_world = std::make_unique<World>();
    m_stateMachine = std::make_unique<StateMachine>();
    m_window = std::make_unique<Window>(width, height, title);
    m_dispatcher = std::make_unique<entt::dispatcher>();


    m_lua.open_libraries(sol::lib::base);

    Locator::lua = &m_lua;
    Locator::world = m_world.get();
    Locator::window = m_window.get();
    Locator::stateMachine = m_stateMachine.get();
    Locator::dispatcher = m_dispatcher.get();
	Locator::fileSystem = m_fileSystem.get();

	m_lua["log"] = [this](std::string info){
	    this->console->info(info);
	};

	m_lua["get_world"] = [this]() -> World*{
	    return this->m_world.get();
	};

	m_lua["create"] = [this](std::string fileName)->int {
	    return this->m_world->createEntity(fileName);
	};

    console->info("Application init over.");
}

Application::~Application() {
    m_world.reset();
    m_window.reset();
    m_stateMachine.reset();
    m_dispatcher.reset();
	m_fileSystem.reset();
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