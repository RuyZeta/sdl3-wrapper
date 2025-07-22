//
// Created by rodri on 21/07/2025.
//

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <SDL3/SDL.h>
#include <string>
#include "texturemanager.h"


class GameObject {

public:
    GameObject() {}
    virtual ~GameObject() {}

    virtual void load(int x, int y, int ancho, int alto, std::string textureID);
    virtual void draw(SDL_Renderer* pRenderer);
    virtual void update();
    virtual void clean() {SDL_Log("GameObject::clean");}

protected:
    std::string m_sTextureID;
    int m_x, m_y;
    int m_ancho, m_alto;
    int m_currentFrame; //ancho imagen en cuadros
    int m_currentRow; //alto imagen en filas
};


// esto debería ir en un archivo separado
class Actor : public GameObject {

public:
    Actor() {}
    virtual ~Actor() {}

    void load(int x, int y, int ancho, int alto, std::string textureID);
    void draw(SDL_Renderer *pRenderer);
    void update();
    void clean() { GameObject::clean(); SDL_Log("Player::clean"); }

};

class Enemy : public GameObject {
public:
    Enemy(){}
    ~Enemy() {}
    void load(int x, int y, int ancho, int alto, std::string textureID);
    void draw(SDL_Renderer *pRenderer);
    void update();
    void clean() { GameObject::clean(); SDL_Log("Player::clean"); }
};

#endif //GAMEOBJECT_H
