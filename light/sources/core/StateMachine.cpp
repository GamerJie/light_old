//
// Created by Jie on 18.12.24.
//

#include "core/StateMachine.h"


void StateMachine::load() {
    if(!m_states.empty() && !m_stack.empty())
        m_states[m_stack.top()]->load();
}

void StateMachine::unload() {
    if(!m_stack.empty() && !m_states.empty())
        m_states[m_stack.top()]->unload();
}

void StateMachine::event(sf::Event *event) {
    if(!m_stack.empty() && !m_states.empty())
        m_states[m_stack.top()]->event(event);
}

void StateMachine::update(const double dt) {
    if(!m_stack.empty() && !m_states.empty())
        m_states[m_stack.top()]->update(dt);
}

void StateMachine::render() {
    if(!m_stack.empty() && !m_states.empty())
        m_states[m_stack.top()]->render();
}


void StateMachine::push(const std::string &state) {
    if (m_states.find(state) != m_states.end()) {
        m_stack.push(state);
    } else {
        // log error
    }
}

void StateMachine::pop() {
    m_stack.pop();
}


inline State* StateMachine::top() {
	State* outPut = nullptr;

	if (!m_stack.empty() && !m_stack.empty()) {
		outPut = m_states[m_stack.top()];
	}
	else {
		// log error
	}

	return outPut;
}