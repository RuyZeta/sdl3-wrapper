//
// Created by rodrigo on 28/07/25.
//

#ifndef CIRCULO_H
#define CIRCULO_H

#include "gameobject.h"

class circle : public ObjetoAbstractoBase {
    Vec2r gravedad, peso;
    particula* m_particula;
    int x, y, radio;
public:
    circle(const int& x, const int& y, const int& radio, const int& masa );
    virtual ~circle() {}
    virtual void draw();
    virtual void update();
    virtual void clean() {};
protected:


};



#endif //CIRCULO_H
