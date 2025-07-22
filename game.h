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

    GameObject* m_go;
    Actor* m_actor; // actor que se va a mover
    Enemy* m_enemy;

    // todos los actores del juego
    std::vector<GameObject *> m_players;


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
