//
// Created by rodrigo on 31/07/25.
//

#include "Force.h"


Force::Force() {}

Force* Force::getInstance() {
    if (sForce_instance == nullptr) {
        sForce_instance = new Force();
        return sForce_instance;
    }
    return sForce_instance;
}

Vec2r Force::GenerateDragForce(const particula &particle, const float &dragCoefficient) {
    // Fd = -0.5 * Cd * A * ρ * v^2
    // donde:
    // Cd = coeficiente de arrastre
    // A = área frontal (asumimos un círculo)
    // ρ = densidad del fluido (aire)
    // v = velocidad del objeto
    float area = M_PI * particle.getRadio() * particle.getRadio(); // área de un círculo
    float density = 1.225f; // densidad del aire a nivel del mar en kg/m^3
    Vec2r velocity = particle.getVelocity();
    float speedSquared = velocity.magnitude() * velocity.magnitude();

    return velocity.normalize() * (-0.5f * dragCoefficient * area * density * speedSquared)  ;
}

Force* Force::sForce_instance = nullptr;

