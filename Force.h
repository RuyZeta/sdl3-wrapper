//
// Created by rodrigo on 31/07/25.
//

#ifndef FORCE_H
#define FORCE_H
#include "movement.h"
#include <cmath>
#include <SDL3_gfx/SDL3_gfxPrimitives.h>
#include "constantes.h"

// clase ayuda para generar fuerzas
class Force {
    // singleton
    Force();
public:
    static Force* sForce_instance;
    static Force* getInstance();
    Vec2r GenerateDragForce(const particula& particle, const float& dragCoefficient);
    Vec2r GenerateFrictionForce(const particula& particle, const float& frictionCoefficient);
    Vec2r GenerateGravitationalForce(const particula& a, const particula& b, const float& G);

};

typedef Force TheForce;

#endif //FORCE_H
