//
// Created by rodrigo on 28/07/25.
//

#ifndef CIRCULO_H
#define CIRCULO_H

#include "gameobject.h"
#include "Force.h"

class circle : public ObjetoAbstractoBase {
    Vec2r gravedad, peso;
    particula* m_particula;
    int x, y, radio;
public:
    circle(const int& x, const int& y, const int& radio, const int& masa );
    virtual ~circle() {
        delete m_particula; // liberar memoria de la particula
    }
    virtual void draw();
    virtual void update();
    virtual void clean() {};

};

class rectangulo : public ObjetoAbstractoBase {
    int x, y, width, height;
    Uint32 color;
    Uint32 blue;
public:
    rectangulo(const int& x, const int& y, const int& width, const int& height, const Uint32& color);
    virtual ~rectangulo() {};
    virtual void draw();
    virtual void update();
    virtual void clean();
    void DrawFillRect() const ;
};

#endif //CIRCULO_H
