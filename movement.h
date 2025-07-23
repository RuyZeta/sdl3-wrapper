//
// Created by rodri on 22/07/2025.
//

#ifndef MOVEMENT_H
#define MOVEMENT_H

#include <cmath>

//vector en un plano cartesiano
class Vec2r {

    float m_x, m_y;
public:
    Vec2r(float x, float y) : m_x(x), m_y(y) {}
    Vec2r() : m_x(0), m_y(0) {};
    Vec2r(const Vec2r &other) { *this = other; }
    Vec2r &operator=(const Vec2r &other) {
        if (this == &other)
            return *this;
        m_x = other.m_x;
        m_y = other.m_y;
        return *this;
    }
    bool operator==(const Vec2r &other) const {
        return m_x == other.m_x && m_y == other.m_y;
    }
    float getX() const { return m_x; }
    float getY() const { return m_y; }
    void setX(const float& x) { m_x = x; }
    void setY(const float& y) { m_y = y; }
    float largo_vector () {return sqrt(m_x * m_x + m_y * m_y);}
    Vec2r operator+(const Vec2r& other) const {
        return {m_x + other.m_x, m_y + other.m_y}; // lo mismo que retornar cartesianvector
    }
    Vec2r operator-(const Vec2r& other) const {
        return {m_x - other.m_x, m_y - other.m_y};
    }
    Vec2r& operator+=(const Vec2r& other) {
        m_x += other.m_x;
        m_y += other.m_y;
        return *this;
    }
    Vec2r& operator-=(const Vec2r &other) {
        m_x -= other.m_x;
        m_y -= other.m_y;
        return *this;
    }
    Vec2r operator*(const float& scalar) const {
        return Vec2r(m_x * scalar, m_y * scalar);
    }
    Vec2r operator*=(const float& scalar) {
        m_x *= scalar;
        m_y *= scalar;
        return *this;
    }
    Vec2r operator/(const float& scalar) const {
        return Vec2r(m_x / scalar, m_y / scalar);
    }
    Vec2r operator/=(const float& scalar) {
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
