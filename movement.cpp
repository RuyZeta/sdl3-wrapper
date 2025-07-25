//
// Created by rodri on 22/07/2025.
//

#include "movement.h"



void Vec2r::normalize() {
    const float l = largo_vector();
    if (l > 0)
        (*this) *= 1 / l;
}
// igual a magnitude
float Vec2r::largo_vector() const {
    return sqrt(m_x * m_x + m_y * m_y);
}

//suma de la raíz cuadrada de a y b, es decir, la hipotenusa de los dos puntos
float Vec2r::magnitude() const {
    return sqrt(m_x * m_x + m_y * m_y);
}

float Vec2r::dot(const Vec2r &other) const {
    return m_x * other.m_x + m_y * other.m_y;
}

Vec2r Vec2r::perpendicular() const {
    return Vec2r(this->m_y, -this->m_x);
}

