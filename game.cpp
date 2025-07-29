//
// Created by rodrigo on 19/07/25.
//

#include "game.h"



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
// aquí se inicializa
bool Game::init(const char* name, int width, int height, int flags) {

    if (SDL_Init(SDL_INIT_VIDEO) == true ) {
        const SDL_DisplayMode* displayMode = SDL_GetCurrentDisplayMode(1);
        ancho = displayMode->w;
        alto = displayMode->h;
        if ((pWindow = SDL_CreateWindow(name, ancho, alto, flags )) != nullptr) {
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

    //if (!TheTextureManager::getInstance()->load("../assets/ball5.png", "ball2", pRenderer))

    circulo = new circle(850, 450, 10, 3);
    circulito = new circle(1350, 450, 12, 4);

    //m_players.push_back(circulo);
    //m_players.push_back(circulito);


    return true;
}

void Game::render() {
    SDL_SetRenderDrawColor(pRenderer, color>>16, color>>8, color, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(pRenderer);

    /*for (std::vector<ObjetoAbstractoBase*>::iterator it = m_players.begin(); it != m_players.end(); ++it) {
        (*it)->draw();
    }*/
    circulo->draw();

    SDL_RenderPresent(pRenderer); // esto lo presenta al buffer de pantalla
}



void Game::update() {

    // si va muy rápido para 60fps, se agrega una demora
    const int timeToWait = MILISEGUNDOS_POR_FRAME - (SDL_GetTicks() - timePreviousFrame);
    if (timeToWait > 0)
        SDL_Delay(timeToWait);

    deltaTime = (SDL_GetTicks() - timePreviousFrame) / 1000.0f; // tiempo en segundos
    if (deltaTime > 0.16f)  // si es mayor a 0.16 segundos, se limita a 0.16 para evitar problemas de velocidad
        deltaTime = 0.016f; // 60 fps

    timePreviousFrame = SDL_GetTicks();

    /*for (std::vector<ObjetoAbstractoBase *>::size_type i = 0; i < m_players.size(); ++i) {
        m_players[i]->update();
    }*/
    circulo->update();

}

void Game::handeEvents() {
    if (SDL_PollEvent(&e)) {
        switch (e.type) {
            case SDL_EVENT_QUIT:
                bRunning = false;
                break;
            case SDL_EVENT_KEY_DOWN:
                if (e.key.key == SDLK_ESCAPE) {
                    bRunning = false;
                }


            default:
                break;
        }
    }
}

void Game::clean() {
    delete circulo;
    //delete circulito;

    SDL_DestroyRenderer(pRenderer);
    SDL_DestroyWindow(pWindow);
    SDL_Quit();
}

Game* Game::s_pInstance = nullptr;
int Game::timePreviousFrame = 0;
float Game::deltaTime = 0.0f;