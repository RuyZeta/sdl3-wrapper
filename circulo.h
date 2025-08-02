//
// Created by rodrigo on 28/07/25.
//

#ifndef CIRCULO_H
#define CIRCULO_H

#include "gameobject.h"
#include "Force.h"

class circle : public ObjetoAbstractoBase {
    Vec2r gravedad, peso, gravitationalForce;

    int x, y, radio,nFactor;
public:
    particula* m_particula, *m_otra_particula;
    circle(const int& x, const int& y, const int& radio, const int& masa );
    virtual ~circle() {
        delete m_particula; // liberar memoria de la particula
    }
    virtual void draw();
    virtual void update();
    virtual void clean() {};
    void set_Negative_Factor(const int& i) { nFactor = i; }
    particula* getParticula();
    void add_particula(particula* p) {
        m_otra_particula = p;
    }



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
