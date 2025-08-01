//
// Created by rodrigo on 31/07/25.
//

#ifndef FORCE_H
#define FORCE_H
#include "movement.h"
#include <cmath>

#define M_PI 3.14159265358979323846

class Force {

    Force();
public:
    static Force* sForce_instance;
    static Force* getInstance();
    Vec2r GenerateDragForce(const particula& particle, const float& dragCoefficient);
};



#endif //FORCE_H
