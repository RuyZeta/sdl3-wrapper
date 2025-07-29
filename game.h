//
// Created by rodrigo on 19/07/25.
// Reusable Game class for SDL3

#ifndef GAME_H
#define GAME_H
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include "texturemanager.h"
#include "gameobject.h"
#include <vector>
#include <SDL3_gfx/SDL3_gfxPrimitives.h>
#include "movement.h"
#include "constantes.h"

// this is the game class that will handle the game loop, events, rendering, etc.
// hecho como singleton

class Game {
    SDL_Window *pWindow;
    SDL_Renderer *pRenderer; // espacio de renderizado (para pintar), relacionado con una ventana
    SDL_Event e;
    bool bRunning;

    SDL_Texture *pTexture; // textura que se va a renderizar
    SDL_FRect sourceRect;
    SDL_FRect destRect;

    int ancho, alto;
    int m_currentFrame;
    int m_currentRow;
    uint32_t color = 0xff056263;

    Actor* m_actor; // actor que se va a mover
    circle* circulo;




    // todos los actores del juego
    std::vector<ObjetoAbstractoBase *> m_players;

    Game();
public:
    static int timePreviousFrame;
    static float deltaTime;
    ~Game() {};

    static Game* s_pInstance;
    static Game* getInstance() {
        if (s_pInstance ==nullptr) {
            s_pInstance = new Game();
            return s_pInstance;
        }
        return s_pInstance;
    }
    SDL_Renderer* getRenderer() const { return pRenderer; }
    bool init(const char *name, int width, int height, int flags);

    bool isRunning() const {return bRunning;};
    // eventos del loop
    void handeEvents();
    void render();
    void update();
    //
    void clean();
    // getters
    int get_Ancho() const { return ancho; }
    int get_Alto() const { return alto; }

};

typedef Game TheGame;


#endif //GAME_H
