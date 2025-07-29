//
// Created by rodri on 22/07/2025.
//

#ifndef MOVEMENT_H
#define MOVEMENT_H

#include <cmath>

// macro para comparar dos números de punto flotante
// esto es por el error que se produce en la representación binaria de números punto flotante
// no se pueden comparar en forma simple, más bien tomar un margen de comparación que es aceptable
#define CMP(x, y) ((fabs((x) - (y)) < 1e-6) * fmaxf(1.0f, fmaxf(fabs(x), fabs(y))))

//vector en un plano cartesiano
class Vec2r {

    float m_x, m_y;
public:
    Vec2r(const float& x, const float& y) : m_x(x), m_y(y) {}
    Vec2r() : m_x(0.0f), m_y(0.0f) {};
    Vec2r(const Vec2r &other) { *this = other; }
    float getX() const { return m_x; }
    float getY() const { return m_y; }
    void setX(const float& x) { m_x = x; }
    void setY(const float& y) { m_y = y; }

    // operaciones con vectores
    Vec2r &operator=(const Vec2r &r) {
        if (this != &r) {
            m_x = r.m_x;
            m_y = r.m_y;
        }
        return *this;
    }
    bool operator==(const Vec2r &other) const {
        return CMP(m_x, other.m_x) && CMP(m_y, other.m_y);
    }
    Vec2r operator+(const Vec2r& rhs) const {
        return Vec2r(m_x + rhs.m_x, m_y + rhs.m_y);
    }
    Vec2r operator-(const Vec2r& other) const {
        return {m_x - other.m_x, m_y - other.m_y};
    }
    Vec2r& operator+=(const Vec2r& rhs) {
        m_x += rhs.m_x;
        m_y += rhs.m_y;
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
    Vec2r operator*(const Vec2r& other) const {
        return Vec2r(m_x * other.m_x, m_y * other.m_y);
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
    void normalize();
    float largo_vector () const ;
    float magnitude () const;
    float dot(const Vec2r& other) const;
    Vec2r perpendicular() const;
};

////////////////////////////////////////////////////////////////////////
//////////////////////// particula
///


class particula {
    Vec2r m_position;
    Vec2r m_velocity;
    Vec2r m_acceleration;
    float m_masa;
public:
    particula(const float& x, const float& y, const float& masa);
    ~particula(){}
    Vec2r getPosition() ;
    Vec2r getVelocity() const;
    Vec2r getAcceleration() const;
    float getMasa() const { return m_masa; }
    void setMasa(const float& masa) { m_masa = masa; }
    void setPosition(const Vec2r& p) {m_position = p;}
    void setVelocity(const Vec2r& v) {m_velocity = v;}
    void setAcceleration(const Vec2r& a) { m_acceleration = a; }


};

#endif //MOVEMENT_H
