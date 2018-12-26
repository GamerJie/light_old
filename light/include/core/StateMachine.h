//
// Created by Jie on 18.12.24.
//

#ifndef STAR_ENGINE_STATEMACHINE_H
#define STAR_ENGINE_STATEMACHINE_H

#include <stack>
#include <string>
#include <memory>
#include <unordered_map>

#include "State.h"

namespace sf{
    class Event;
}

class StateMachine {
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

    template <typename S = State>
    S* top();


private:
    std::stack<std::string> m_stack;
    std::unordered_map<std::string, std::unique_ptr<State>> m_states;
};

template<typename State, typename ... Args>
inline void StateMachine::CreateState(const std::string &id, Args &&... args) {
    m_stack.emplace(id, std::make_unique<State>(std::forward<Args>(args)...));
}

template <typename S = State>
inline S* StateMachine::top() {
    S* outPut = nullptr;

    if(!m_stack.empty() && !m_stack.empty()){
        outPut = m_states[m_stack.top()].get();
    }else{
        // log error
    }

    return outPut;
}


#endif //STAR_ENGINE_STATEMACHINE_H
