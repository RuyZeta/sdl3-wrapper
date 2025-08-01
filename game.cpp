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
    pushForce = Vec2r(0, 0);
}

Game * Game::getInstance() { // función para obtener la instancia del juego
    if (s_pInstance ==nullptr) {
        s_pInstance = new Game();
        return s_pInstance;
    }
    return s_pInstance;
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

    circulo = new circle(850, 450, 9, 9);
    circulito = new circle(1350, 450, 15, 15);

    m_players.push_back(circulo);
    m_players.push_back(circulito);
    m_players.push_back(new rectangulo(0, alto/2, ancho, alto/2,0x696e00ff ));

    return true;
}

void Game::render() {
    SDL_SetRenderDrawColor(pRenderer, color>>16, color>>8, color, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(pRenderer);
    ////////////////////////////////////////
    for (std::vector<ObjetoAbstractoBase*>::iterator it = m_players.begin(); it != m_players.end(); ++it) {
        (*it)->draw();
    }
    ////////////////////////////////////////
    SDL_RenderPresent(pRenderer); // esto lo presenta al buffer de pantalla
}



void Game::update() {

    // si va muy rápido para 60fps, se agrega una demora
    const int timeToWait = MILISEGUNDOS_POR_FRAME - (SDL_GetTicks() - timePreviousFrame);
    if (timeToWait > 0)
        SDL_Delay(timeToWait);

    deltaTime = (SDL_GetTicks() - timePreviousFrame) / 1000.0f; // tiempo en segundos
    if (deltaTime > 0.016f)  // si es mayor a 0.16 segundos, se limita a 0.16 para evitar problemas de velocidad
        deltaTime = 0.016f; // 60 fps

    timePreviousFrame = SDL_GetTicks();

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
            case SDL_EVENT_KEY_DOWN:
                if (e.key.key == SDLK_ESCAPE)
                    bRunning = false;
                if (e.key.key == SDLK_UP)
                    pushForce.setY(-50.0f * PIXELS_POR_METRO);
                if (e.key.key == SDLK_DOWN)
                    pushForce.setY(50.0f * PIXELS_POR_METRO);
                if (e.key.key == SDLK_LEFT)
                    pushForce.setX(-50.0f * PIXELS_POR_METRO);
                if (e.key.key == SDLK_RIGHT)
                    pushForce.setX(50.0f * PIXELS_POR_METRO);
                break;
            case SDL_EVENT_KEY_UP:
                if (e.key.key == SDLK_UP || e.key.key == SDLK_DOWN)
                    pushForce.setY(0.0f);
                if (e.key.key == SDLK_LEFT || e.key.key == SDLK_RIGHT)
                    pushForce.setX(0.0f);
                break;

            default:
                break;
        }
    }
}

void Game::clean() {
    for (std::vector<ObjetoAbstractoBase *>::size_type i = 0; i < m_players.size(); ++i) {
        delete m_players[i]; // liberar memoria de los objetos
    }
    m_players.clear();

    SDL_DestroyRenderer(pRenderer);
    SDL_DestroyWindow(pWindow);
    SDL_Quit();
}

bool Game::isRunning() const {return bRunning;}

Game* Game::s_pInstance = nullptr;
int Game::timePreviousFrame = 0;
float Game::deltaTime = 0.0f;