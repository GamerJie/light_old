//
// Created by Jie on 19.1.5.
//

#ifndef light_service_locator_h
#define light_service_locator_h

#include "World.h"
#include "entt/entt.hpp"
#include "StateMachine.h"
#include "fs/FileSystem.h"
#include "graphics/Window.h"

class Locator {
public:


public:
    static inline World* world;
    static inline Window* window;
    static inline StateMachine* stateMachine;
    static inline entt::dispatcher* dispatcher;
    static inline FileSystem* fileSystem;
};

#endif //light_service_locator_h
