//
// Created by Jie on 18.12.24.
//

#ifndef light_world_h
#define light_world_h

#include <memory>
#include <typeindex>
#include <functional>
#include <unordered_map>

#include "Light.h"
#include "System.h"
#include "sol2/sol.hpp"
#include "spdlog/spdlog.h"
#include "entt/entity/registry.hpp"
#include "entt/core/hashed_string.hpp"

class LightAPI World final {
public:
    World();
    ~World() noexcept;

    entt::registry<>::entity_type createEntity(const std::string& script);

    void update(const int dt);


	template<typename Tag>
	void registerTag(Tag tag);

	template<typename Component>
	void registerComponent(Component component);

	template<typename System>
	void registerSystem();

	void registerLuaSystem(const std::string fileName);

	template<typename System>
	System* getSystem();

	template<typename System>
	void remove();

	void removeLua(const std::string systemName);

public:
    entt::registry<> m_registry;

private:
	std::unordered_map<entt::hashed_string::hash_type, std::function<void(const entt::registry<>::entity_type, \
	const sol::table&)>> m_tagAssign;

	std::unordered_map<entt::hashed_string::hash_type, std::function<void(const entt::registry<>::entity_type, \
	const sol::table&)>> m_componentAssign;

	std::unordered_map<std::string, std::unique_ptr<System>> m_systems;
	std::shared_ptr<spdlog::logger> console;
};

template<typename Tag>
inline void World::registerTag(Tag tag) {
	entt::hashed_string hs(tag.c_str());

	if (m_tagAssign.find(hs) != m_tagAssign.end()) {
		// todo
		// log try to register repeat tag
	} else {
		m_tagAssign.emplace(hs, [this](const entt::registry<>::entity_type entity, const sol::table &table) {
			m_registry.assign<Tag>(entity, table);
		});
	}
}

template<typename Component>
inline void World::registerComponent(Component component) {
	entt::hashed_string hs(component.c_str());

	if (m_componentAssign.find(hs) != m_componentAssign.end()) {
		// todo
		// log try to register repeat component
	} else {
		m_componentAssign.emplace(hs, [this](const entt::registry<>::entity_type entity, const sol::table &table) {
			m_registry.assign<Component>(entity, table);
		});
	}
}

template<typename System>
inline void World::registerSystem(){
	std::type_index t(typeid(System));
	std::string key(t.name());

	if(m_systems.find(key) != m_systems.end()){
		// todo
		// log try to register repeat system
	}else
		m_systems[key] = std::make_unique<System>();
		// m_systems[t] = std::make_unique<System>(std::forward<Args>(args)...);
};


template<typename System>
inline System* World::getSystem(){
	return dynamic_cast<System*>(m_systems[typeid(System).name()].get());
}

template<typename System>
void World::remove() {
	std::type_index t(typeid(System));
	std::string key(t.name());

	if(m_systems.find(key) != m_systems.end()){
		m_systems[key].reset();
		m_systems.erase(key);
	}else{
		// todo
		// log try to remove none-exit system
	}
}

#endif //light_world_h
