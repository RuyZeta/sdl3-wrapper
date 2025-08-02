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
// asume que el fluido es el agua
Vec2r Force::GenerateDragForce(const particula &particle, const float &dragCoefficient) {
    // Fd = -0.5 * Cd * A * ρ * v^2
    // donde:
    // Cd = coeficiente de arrastre
    // A = área frontal (asumimos un círculo)
    // ρ = densidad del fluido (aire)
    // v = velocidad del objeto
    float area = M_PI * particle.getRadio() * particle.getRadio(); // área de un círculo
    float density = 1.0f; // densidad del agua a nivel del mar en kg/m^3
    Vec2r velocity = particle.getVelocity();
    float speedSquared = velocity.magnitude() * velocity.magnitude();

    return velocity.normalize() * (-0.5f * dragCoefficient * area * density * speedSquared)  ;
}

Vec2r Force::GenerateFrictionForce(const particula& particle, const float &frictionCoefficient) {
    Vec2r frictionForce = Vec2r(0,0);
    Vec2r frictionDirection = particle.getVelocity().normalize() * -1; // dirección opuesta a la velocidad
    float frictionMagnitude = frictionCoefficient;
    frictionForce = frictionDirection * frictionMagnitude;
    return frictionForce;

}

Vec2r Force::GenerateGravitationalForce(const particula &a, const particula &b, const float &G) {
    Vec2r distance =(b.getPosition() - a.getPosition());
    float distanceMagnitude = distance.largo_vector();
    Vec2r attractionDirection = distance.normalize();
    float attractionMagnitude = G * (a.getMasa() * b.getMasa()) / distanceMagnitude;
    Vec2r attractionForce = attractionDirection * attractionMagnitude;
    return attractionForce;
}

Force* Force::sForce_instance = nullptr;

