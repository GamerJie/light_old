//
// Created by Jie on 19.1.5.
//

#ifndef light_window_h
#define light_window_h

#include <string>

#include "Light.h"

namespace sf {
    class Window;
    class Event;
}

class LightAPI Window {
public:
    Window(const unsigned int, const unsigned int, const std::string);
    ~Window();

    bool isOpen() const;
    bool pollEvent(sf::Event&) const;
    void display();
    void close();

    void setTitle(const std::string title);

private:
    sf::Window* m_window;
};

#endif //light_window_h
