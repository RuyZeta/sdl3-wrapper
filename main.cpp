#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include "game.h"
#include "gameobject.h"
#include "texturemanager.h"

Game *game = nullptr;
int main(int argc, char *argv[]) {

    game = new Game();

    if (game->init("SDL3 Game", 1600, 900, SDL_WINDOW_RESIZABLE)) {
        while (game->isRunning()) {
            game->handeEvents();
            game->update();
            game->render();
            SDL_Delay(20); // Approx 60 FPS
        }
    } else {
        SDL_Log("Game initialization failed.");
    }

    return 0;
}