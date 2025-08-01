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
#include "circulo.h"

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

    int ancho, alto, m_currentFrame, m_currentRow;
    uint32_t color = 0xff056263;

    circle* circulo;
    circle* circulito;
    Vec2r pushForce;
    std::vector<ObjetoAbstractoBase *> m_players;
    // singleton
    Game();
public:
    static int timePreviousFrame;
    static float deltaTime;
    ~Game() {};

    //SINGLETON
    static Game* s_pInstance; // la instancia del juego. Instanciada fuera de la clase (static).
    static Game* getInstance(); // función para obtener la instancia del juego
    //
    SDL_Renderer* getRenderer() const { return pRenderer; }
    bool init(const char *name, int width, int height, int flags);
    // eventos del loop
    void handeEvents();
    void render();
    void update();
    //
    void clean();
    // getters
    bool isRunning() const ;
    int get_Ancho() const { return ancho; }
    int get_Alto() const { return alto; }
    Vec2r get_PushForce() const { return pushForce; }
};

typedef Game TheGame;


#endif //GAME_H
