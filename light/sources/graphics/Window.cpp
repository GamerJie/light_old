//
// Created by Jie on 19.1.5.
//

#include "graphics/Window.h"

#include <SFML/Window.hpp>

Window::Window(const unsigned int width, const unsigned int height, const std::string title) {
    m_window = new sf::Window(sf::VideoMode(width, height), title);

    m_window->setFramerateLimit(60);
}

Window::~Window() {
    m_window = nullptr;
    delete m_window;
}

bool Window::isOpen() const {
    return m_window->isOpen();
}

bool Window::pollEvent(sf::Event& event) const {
    return m_window->pollEvent(event);
}

void Window::display() {
    m_window->display();
}

void Window::close() {
    m_window->close();
}

void Window::setTitle(const std::string title) {
    m_window->setTitle(title);
}