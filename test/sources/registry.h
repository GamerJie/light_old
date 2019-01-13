//
// Created by Jie on 19.1.13.
//

#ifndef UNTITLED1_REGISTRY_H
#define UNTITLED1_REGISTRY_H

#include <vector>

#include "world.h"
#include "system.h"

class registry {
public:
    registry(world* ww){
        m_world = ww;
    }

    std::vector<component_data> view(std::string name){
        std::vector<component_data> result;
        for(auto& kv: m_world->entities){
            for(auto& cv: kv.second){
                if(cv.first == name.c_str())
                    result.push_back(cv.second);
            }
        }

        return result;
    }

    template <typename C>
    std::vector<component_data> view(){
        return view(typeid(C).name());
    }


private:
    world* m_world;
};

#endif //UNTITLED1_REGISTRY_H
