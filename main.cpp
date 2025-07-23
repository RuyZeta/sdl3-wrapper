#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include "game.h"
#include "gameobject.h"
#include "texturemanager.h"

const int FPS = 60;
const int DELAY_TIME = 1000.0f/FPS;

int main(int argc, char *argv[]) {

    // Initialize SDL

    if (TheGame::getInstance()->init("SDL3 Game", 2500, 1800, SDL_WINDOW_RESIZABLE)) {

        while (TheGame::getInstance()->isRunning()) {
            const Uint32 frameStart = SDL_GetTicks();
            TheGame::getInstance()->handeEvents();
            TheGame::getInstance()->update();
            TheGame::getInstance()->render();
            const Uint32 frameTime = SDL_GetTicks() - frameStart;
            if (frameTime < DELAY_TIME)
                SDL_Delay(static_cast<int>(DELAY_TIME - frameTime));
        }
    } else {
        SDL_Log("Game initialization failed.");
    }

    TheGame::getInstance()->clean();

    return 0;
}