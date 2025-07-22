#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include "game.h"
#include "gameobject.h"
#include "texturemanager.h"

Game *game = nullptr;
int main(int argc, char *argv[]) {

    // Initialize SDL
    if (TheGame::getInstance()->init("SDL3 Game", 1600, 900, SDL_WINDOW_RESIZABLE)) {
        while (TheGame::getInstance()->isRunning()) {
            TheGame::getInstance()->handeEvents();
            TheGame::getInstance()->update();
            TheGame::getInstance()->render();
            SDL_Delay(20); // Approx 60 FPS
        }
    } else {
        SDL_Log("Game initialization failed.");
    }

    TheGame::getInstance()->clean();

    return 0;
}