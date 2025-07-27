//
// Created by rodri on 21/07/2025.
//

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <SDL3/SDL.h>
#include <string>
#include "movement.h"
#include <SDL3_gfx/SDL3_gfxPrimitives.h>





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
     ObjetoAbstractoBase(/*const LoaderParams* pParams*/) {}
    virtual ~ObjetoAbstractoBase() {}
};


// clase que representa un objeto en el juego, hereda de la clase base abstracta
// con esta clase podemos reusar código y evitar duplicación
class Objeto_en_Juego : public ObjetoAbstractoBase {

public:
    Objeto_en_Juego(const LoaderParams* pParams);

    ~Objeto_en_Juego() {}

    virtual void draw();
    virtual void update();
    virtual void clean();

protected:
    Vec2r m_position, m_unidad, m_velocidad, m_aceleracion, m_magnitude;
    int m_ancho, m_alto;
    int m_currentFrame; // ancho imagen en cuadros
    int m_currentRow; // alto imagen en filas
    std::string m_textureID; // ID de la textura
    Vec2r xAxis;
    Vec2r yAxis;
};


// esto debería ir en un archivo separado
class Actor : public Objeto_en_Juego {

public:
    Actor(const LoaderParams* pParams) : Objeto_en_Juego(pParams) {}
    virtual ~Actor() {}


    void draw();
    void update();
    void clean() { Objeto_en_Juego::clean(); SDL_Log("Player::clean"); }

};

// clase para reutilizar código en las clases derivadas
class circle : public ObjetoAbstractoBase {

    particula* m_particula;
    Vec2r vel;

public:
    circle(const int& x, const int& y, const int& radio);
    virtual ~circle() {}
    virtual void draw();
    virtual void update();
    virtual void clean() {};
protected:
    int x, y, radio;
};

#endif //GAMEOBJECT_H
