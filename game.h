//
// Created by rodrigo on 19/07/25.
// Reusable Game class for SDL3

#ifndef GAME_H
#define GAME_H
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include "texturemanager.h"



class Game {
    SDL_Window *pWindow;
    SDL_Renderer *pRenderer; // espacio de renderizado (para pintar), relacionado con una ventana
    SDL_Event e;
    bool bRunning;

    SDL_Texture *pTexture; // textura que se va a renderizar
    SDL_FRect sourceRect;
    SDL_FRect destRect;

    float ancho, alto;

    int m_currentFrame;
    int m_currentRow;


public:
    Game();
    ~Game() {};
    bool init(const char *name, int width, int height, int flags);
    void render();
    void update();
    void handeEvents();
    void clean();
    bool isRunning() {return bRunning;};

};



#endif //GAME_H
