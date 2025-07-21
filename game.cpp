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

bool Game::init(const char* name, int width, int height, int flags) {
    if (SDL_Init(SDL_INIT_VIDEO) == true ) {
        if ((pWindow = SDL_CreateWindow(name, width, height, flags )) != nullptr) {
            if ((pRenderer = SDL_CreateRenderer(pWindow, NULL)) != nullptr)
                SDL_SetRenderDrawColor(pRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
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
    bRunning = true;
    // Load the texture
    if (!TheTextureManager::getInstance()->load("../assets/child.png", "txtExplosion", pRenderer)) {
        SDL_Log("Failed to load texture");
        return false;
    }
    TheTextureManager::getInstance()->GetTextureDimensions("txtExplosion", sourceRect);
    ancho = sourceRect.w;
    alto = sourceRect.h;
    sourceRect.w /= 7; //
    sourceRect.h /= 3; //
    return true;
}

void Game::render() {
    SDL_RenderClear(pRenderer);
    // el origen es la textura y sourceRect. El destino es el Renderer (la ventana) y destRect.
    //tmTextureManager.draw("txtExplosion", 0, 0, sourceRect.w, sourceRect.h, pRenderer);
    TheTextureManager::getInstance()->drawFrame("txtExplosion", 0  , 0, sourceRect.w, sourceRect.h,
    m_currentRow, m_currentFrame, pRenderer);
    SDL_RenderPresent(pRenderer); // esto lo presenta al buffer de pantalla
}

void Game::update() {
    //if (!(sourceRect.x = (int)(sourceRect.x + ancho) % (int)(ancho * 8))) // 8 frames in the x direction
     //   sourceRect.y = (int)(sourceRect.y + alto) % (int)(alto * 4); // 4 frames in the y direction
    m_currentFrame = ((m_currentFrame+1) % 6);
    if (!m_currentFrame)
        m_currentRow = ((m_currentRow+1) % 3);
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
