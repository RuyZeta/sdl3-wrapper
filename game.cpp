//
// Created by rodrigo on 19/07/25.
//

#include "game.h"
//#include <SDL3_image/SDL_image.h>


Game::Game() : pWindow(nullptr), pRenderer(nullptr), bRunning(false),
  m_currentFrame(0), m_currentRow(0) {
    sourceRect.x = 0;
    sourceRect.y = 0;
    sourceRect.w = 0;
    sourceRect.h = 0;
    destRect.x = 0;
    destRect.y = 0;
    destRect.w = 0;
    destRect.h = 0;
}
// aquí se inicializa todo
bool Game::init(const char* name, int width, int height, int flags) {

    if (SDL_Init(SDL_INIT_VIDEO) == true ) {
        if ((pWindow = SDL_CreateWindow(name, width, height, flags )) != nullptr) {
            if ((pRenderer = SDL_CreateRenderer(pWindow, NULL)) != nullptr)
                SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
            else {
                SDL_Log("Failed to create renderer: %s", SDL_GetError());
                return false;
            }
        } else {
            SDL_Log("Could not create window: %s", SDL_GetError());
            return false;
        }
    } else {
        SDL_Log("Could not initialize SDL: %s", SDL_GetError());
        return false;
    }
    // fin de la inicialización del SDL_Window* y SDL_Renderer*, es decir, ventana y área de pintado
    bRunning = true;
    // Load the texture
    if (!TheTextureManager::getInstance()->load("../assets/ball5.png", "ball2", pRenderer)) {
        SDL_Log("Failed to load texture");
        return false;
    }
    TheTextureManager::getInstance()->setTextureBlend("ball2", SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawBlendMode(pRenderer, SDL_BLENDMODE_BLEND);
    TheTextureManager::getInstance()->GetTextureDimensions("ball2", sourceRect);
    ancho = sourceRect.w;
    alto = sourceRect.h;
    //sourceRect.w /= 8; //
    //sourceRect.h /= 4; //

    // los actores del juego (que tienen un comportamiento) son agregados a un array "on the fly".
    m_players.push_back(new Actor(new LoaderParams(0, 0, sourceRect.w, sourceRect.h, "ball2")));

    return true;
}

void Game::render() {
    SDL_RenderClear(pRenderer);


    for (std::vector<ObjetoAbstractoBase *>::size_type i = 0; i < m_players.size(); ++i) {
        m_players[i]->draw();
    }

    SDL_RenderPresent(pRenderer); // esto lo presenta al buffer de pantalla
}

void Game::update() {

    for (std::vector<ObjetoAbstractoBase *>::size_type i = 0; i < m_players.size(); ++i) {
        m_players[i]->update();
    }
}

void Game::handeEvents() {
    if (SDL_PollEvent(&e)) {
        switch (e.type) {
            case SDL_EVENT_QUIT:
                bRunning = false;
                break;

            default:
                break;
        }
    }
}

void Game::clean() {
    SDL_DestroyRenderer(pRenderer);
    SDL_DestroyWindow(pWindow);
    SDL_Quit();
}

Game* Game::s_pInstance = nullptr;