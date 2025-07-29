#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include "game.h"
#include "gameobject.h"
#include "texturemanager.h"
#include <SDL3_gfx/SDL3_framerate.h>

//const int FPS = 60;
//const int DELAY_TIME = 1000.0f/FPS;

int main(int argc, char *argv[]) {

    // Initialize SDL
    if (TheGame::getInstance()->init("SDL3 Game", 2000, 1200,
        SDL_WINDOW_BORDERLESS)) {

        while (TheGame::getInstance()->isRunning()) {

            TheGame::getInstance()->handeEvents();
            TheGame::getInstance()->update();
            TheGame::getInstance()->render();
        }
    } else {
        SDL_Log("Game initialization failed.");
    }

    TheGame::getInstance()->clean();

    return 0;
}