//
// Created by rodrigo on 31/07/25.
//

#ifndef FORCE_H
#define FORCE_H
#include "movement.h"
#include <cmath>
#include <SDL3_gfx/SDL3_gfxPrimitives.h>


class Force {

    Force();
public:
    static Force* sForce_instance;
    static Force* getInstance();
    Vec2r GenerateDragForce(const particula& particle, const float& dragCoefficient);
};

typedef Force TheForce;

#endif //FORCE_H
