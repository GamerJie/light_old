
#include "MainGame.h"

#ifdef WIN32
#ifdef DEBUG_MODE
#pragma comment(linker, "/subsystem:windows /entry:mainCRTStartup" )
#endif
#endif // WIN


int main(int argc, char* argv[]) {

    MainGame game;

    game.run();

    return 0;
}