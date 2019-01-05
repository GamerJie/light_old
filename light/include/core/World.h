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
#include "sol2/sol.hpp"
#include "entt/entt.hpp"


class LightAPI World final {
public:
    World();
    ~World();

//    entt::DefaultRegistry createEntity(const std::string& script);
//
//	template<typename Tag>
//	void registerTag(Tag tag);
//
//	template<typename Compoent>
//	void registerComponent(Compoent component);
//
//	template<typename System, typename... Args>
//	void registerSystem(Args&&... args);
//
//	template<typename System>
//	System* getSystem();


public:
//	std::unique_ptr<sol::state> m_lua;
//	entt::DefaultRegistry m_registry;

//private:
//	std::unordered_map<entt::HashedString::hash_type, std::function<void(const entt::DefaultRegistry, const sol::table&)>> m_tagAssign;
//	std::unordered_map<entt::HashedString::hash_type, std::function<void(const entt::DefaultRegistry, const sol::table&)>> m_componentAssign;
};

//template<typename Tag>
//inline void World::registerTag(Tag tag) {
//	entt::HashedString hs(tag.c_str());
//
//	if (m_tagAssign.find(hs) != m_tagAssign.end()) {
//
//	} else {
//		m_tagAssign.emplace(hs, [this](const entt::DefaultRegistry entity, const sol::table &table) {
//			m_registry.assign<Tag>(entt::tag_t{}, entity, table);
//		});
//	}
//}

#endif //light_world_h
