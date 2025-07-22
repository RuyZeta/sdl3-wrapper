//
// Created by rodri on 21/07/2025.
//

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <SDL3/SDL.h>
#include <string>
#include "texturemanager.h"
#include "game.h"


// una clase ayuda para almacenar los parámetros de un objeto en el juego

class LoaderParams {
    int m_x, m_y, m_ancho, m_alto;
    std::string m_textureID;
public:
    LoaderParams(const int &x, const int &y, const int &ancho, const int &alto, std::string textureID)
    : m_x(x), m_y(y),m_ancho(ancho), m_alto(alto), m_textureID(textureID) {}
    int getX() const { return m_x; }
    int getY() const { return m_y; }
    int getAncho() const { return m_ancho; }
    int getAlto() const { return m_alto; }
    std::string getTextureID() const { return m_textureID; }
};

//clase base abstracta de los objetos en juego
//define la interfaz que deben implementar los objetos en el juego
// Ojo: no siempre es bueno usar herencia. la diferencia es is-a es derivada. Diferente a has-a que es composición.
class ObjetoAbstractoBase {
public:
    virtual void draw() = 0;
    virtual void update() = 0;
    virtual void clean() = 0;
protected:
    ObjetoAbstractoBase(const LoaderParams* pParams) {}
    virtual ~ObjetoAbstractoBase() {}
};


// clase que representa un objeto en el juego, hereda de la clase base abstracta
// con esta clase podemos reusar código y evitar duplicación
class Objeto_en_Juego : public ObjetoAbstractoBase {

public:
    Objeto_en_Juego(const LoaderParams* pParams);

    ~Objeto_en_Juego() override {}

    virtual void draw();
    virtual void update();
    virtual void clean();

protected:
    int m_x, m_y, m_ancho, m_alto;
    int m_currentFrame; // ancho imagen en cuadros
    int m_currentRow; // alto imagen en filas
    std::string m_textureID; // ID de la textura
};




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
