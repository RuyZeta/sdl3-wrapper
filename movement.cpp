//
// Created by rodri on 22/07/2025.
//

#include "movement.h"


Vec2r & Vec2r::operator=(const Vec2r &r) {
    if (this != &r) {
        m_x = r.m_x;
        m_y = r.m_y;
    }
    return *this;
}

bool Vec2r::operator==(const Vec2r &rhs) const {
    return CMP(m_x, rhs.m_x) && CMP(m_y, rhs.m_y);
}

Vec2r Vec2r::operator+(const Vec2r &rhs) const {
    return Vec2r(m_x + rhs.m_x, m_y + rhs.m_y);
}

Vec2r Vec2r::operator-(const Vec2r &other) const {
    return {m_x - other.m_x, m_y - other.m_y};
}

Vec2r Vec2r::operator+=(const Vec2r &rhs) {
    m_x += rhs.m_x;
    m_y += rhs.m_y;
    return *this;
}

Vec2r & Vec2r::operator-=(const Vec2r &other) {
    m_x -= other.m_x;
    m_y -= other.m_y;
    return *this;
}

Vec2r Vec2r::operator*(const float &scalar) const {
    return Vec2r(m_x * scalar, m_y * scalar);
}

Vec2r Vec2r::operator*(const Vec2r &other) const {
    return Vec2r(m_x * other.m_x, m_y * other.m_y);
}

Vec2r Vec2r::operator*=(const float &scalar) {
    m_x *= scalar;
    m_y *= scalar;
    return *this;
}

Vec2r Vec2r::operator/(const float &scalar) const {
    return Vec2r((m_x / scalar), (m_y / scalar));
}

Vec2r Vec2r::operator/=(const float &scalar) {
    m_x /= scalar;
    m_y /= scalar;
    return *this;
}

Vec2r Vec2r::normalize() {
    const float l = largo_vector();
    if (l > 0)
        (*this) *= 1 / l;
    return *this;
}
// igual a magnitude
float Vec2r::largo_vector() const {
    return sqrt(m_x * m_x + m_y * m_y);
}

//suma de la raíz cuadrada de a y b, es decir, la hipotenusa de los dos puntos
float Vec2r::magnitude() const {
    return sqrt(m_x * m_x + m_y * m_y);
}

// el producto punto ve si dos vectores apuntan a la misma dirección (positivo)
// direcciones opuestas (negativo). Perpendiculares (0).
float Vec2r::dot(const Vec2r &other) const {
    return m_x * other.m_x + m_y * other.m_y;
}

Vec2r Vec2r::perpendicular() const {
    return Vec2r(this->m_y, -this->m_x);
}

////////////////////////////////////////////////////////////////////////////////////
//////////////////////// particula
///

particula::particula(const float &x, const float &y, const float &masa, const float &radio) {
    m_position = Vec2r(x, y);
    m_acceleration = Vec2r(0, 0);
    m_velocity = Vec2r(0, 0);
    m_sumForces = Vec2r(0, 0);
    m_masa = masa;
    m_radio = radio; // no se usa, no se necesita, pero se deja para futuras implementaciones
    if (m_masa != 0) {
        m_invMasa = 1.0f / m_masa; // inversa de la masa para evitar dividir por cero
    } else {
        m_invMasa = 0.0f; // si la masa es cero, la inversa es cero
    }
}

Vec2r particula::getPosition() const {
    return m_position;
}

Vec2r particula::getVelocity() const {
    return m_velocity;
}

Vec2r particula::getAcceleration() const {
    return m_acceleration;
}

void particula::addForces(const Vec2r &force) {
    m_sumForces += force;
}

void particula::clearForces() {
    m_sumForces = Vec2r(0, 0);
}

void particula::integrate(const float &dt) {
    m_acceleration = (m_sumForces / m_masa);
    // integra la aceleración con la velocidad  para encontrar la nueva posición
    m_velocity += m_acceleration * dt;
    m_position += m_velocity * dt;
    clearForces(); // limpia las fuerzas acumuladas
}

