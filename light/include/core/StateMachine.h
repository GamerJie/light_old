//
// Created by Jie on 18.12.24.
//

#ifndef light_state_machine_h
#define light_state_machine_h

#include <stack>
#include <string>
#include <memory>
#include <unordered_map>

#include "State.h"

namespace sf{
    class Event;
}

class LightAPI StateMachine {
public:
    StateMachine() = default;
    ~StateMachine() = default;


    void load();
    void event(sf::Event* event);
    void render();
    void update(const double dt);
    void unload();

    template<typename State, typename ... Args>
    void CreateState(const std::string& id, Args&& ... args);

    void push(const std::string& state);
    void pop();

    State* top();


private:
    std::stack<std::string> m_stack;
    std::unordered_map<std::string, State*> m_states;
};

template<typename State, typename ... Args>
inline void StateMachine::CreateState(const std::string &id, Args &&... args) {
	m_stack.emplace(id, std::make_unique<State>(std::forward<Args>(args)...));
}


#endif //light_state_machine_h
