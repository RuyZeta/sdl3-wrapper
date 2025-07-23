//
// Created by rodri on 22/07/2025.
//

#ifndef MOVEMENT_H
#define MOVEMENT_H

#include <cmath>

//vector en un plano cartesiano
class Vector2d {

    float m_x, m_y;
public:
    Vector2d(float x, float y) : m_x(x), m_y(y) {}
    Vector2d() : m_x(0), m_y(0) {};
    Vector2d(const Vector2d &other) { *this = other; }
    Vector2d &operator=(const Vector2d &other) {
        if (this == &other)
            return *this;
        m_x = other.m_x;
        m_y = other.m_y;
        return *this;
    }
    bool operator==(const Vector2d &other) const {
        return m_x == other.m_x && m_y == other.m_y;
    }
    float getX() const { return m_x; }
    float getY() const { return m_y; }
    void setX(const float& x) { m_x = x; }
    void setY(const float& y) { m_y = y; }
    float largo_vector () {return sqrt(m_x * m_x + m_y * m_y);}
    Vector2d operator+(const Vector2d& other) const {
        return {m_x + other.m_x, m_y + other.m_y}; // lo mismo que retornar cartesianvector
    }
    Vector2d operator-(const Vector2d& other) const {
        return {m_x - other.m_x, m_y - other.m_y};
    }
    Vector2d& operator+=(const Vector2d& other) {
        m_x += other.m_x;
        m_y += other.m_y;
        return *this;
    }
    Vector2d& operator-=(const Vector2d &other) {
        m_x -= other.m_x;
        m_y -= other.m_y;
        return *this;
    }
    Vector2d operator*(const float& scalar) const {
        return Vector2d(m_x * scalar, m_y * scalar);
    }
    Vector2d operator*=(const float& scalar) {
        m_x *= scalar;
        m_y *= scalar;
        return *this;
    }
    Vector2d operator/(const float& scalar) const {
        return Vector2d(m_x / scalar, m_y / scalar);
    }
    Vector2d operator/=(const float& scalar) {
        m_x /= scalar;
        m_y /= scalar;
        return *this;
    }
    void normalize() {
        const float l = largo_vector();
        if (l > 0)
            (*this) *= 1 / l;
    }
};




#endif //MOVEMENT_H
