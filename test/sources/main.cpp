
#include <map>
#include <vector>
#include <string>
#include <iostream>

#include <SFML/Graphics.hpp>

#include "world.h"
#include "system.h"
#include "registry.h"
#include "components.h"


class cppSystem : public systems {
public:
    void update(int dt, registry* reg) override {
        for(auto kv: reg->view<cppCom>()){
            cppCom* com = (struct cppCom*)(kv.data);
            com->position.x ++;
            printf("cpp system: %d\n", com->position.x);
        }

        for(auto kv: reg->view("testCom")){
            sol::table pos = kv.table["position"];
            sol::object x = pos["x"];
            printf("cpp comcom: %d\n", x.as<int>());
        }
    }
};

int main() {

    world w;

    w.reg_sys("test/testSys");
    w.reg_sys<cppSystem>();

    auto entity = w.create();
    w.assign(entity, "test/testCom");

    w.assign(w.create(), "test/testCom");

    w.create("test/testEntity");

    auto entt = w.create();
    w.assign<cppCom>(entt);


    sf::Window window(sf::VideoMode(800, 600), "test");

    sf::Event event{};
    sf::Clock deltaClock;
    while(window.isOpen()){
        while(window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                default:
                    break;
            }
        }

        auto dt = deltaClock.restart();
        w.update(dt.asMilliseconds());

        window.display();
    }

    window.close();


//    while(true){
//        w.update(1);
//        printf("update ...\n");
//        _sleep(1000);
//    }


    return 0;
}