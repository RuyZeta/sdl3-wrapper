//
// Created by rodri on 22/07/2025.
//

#ifndef MOVEMENT_H
#define MOVEMENT_H

#include <cmath>

class CartesianVector {

    float m_x, m_y;
public:
    CartesianVector(float x, float y) : m_x(x), m_y(y) {}
    CartesianVector() : m_x(0), m_y(0) {};
    CartesianVector(const CartesianVector &other) { *this = other; }
    CartesianVector &operator=(const CartesianVector &other) {
        if (this == &other)
            return *this;
        m_x = other.m_x;
        m_y = other.m_y;
        return *this;
    }
    bool operator==(const CartesianVector &other) const {
        return m_x == other.m_x && m_y == other.m_y;
    }
    float getX() const { return m_x; }
    float getY() const { return m_y; }
    void setX(const float& x) { m_x = x; }
    void setY(const float& y) { m_y = y; }
    float largo_vector () {return sqrt(m_x * m_x + m_y * m_y);}
    CartesianVector operator+(const CartesianVector& other) const {
        return {m_x + other.m_x, m_y + other.m_y}; // lo mismo que retornar cartesianvector
    }
    CartesianVector operator-(const CartesianVector& other) const {
        return {m_x - other.m_x, m_y - other.m_y};
    }
    CartesianVector& operator+=(const CartesianVector& other) {
        m_x += other.m_x;
        m_y += other.m_y;
        return *this;
    }
    CartesianVector& operator-=(const CartesianVector &other) {
        m_x -= other.m_x;
        m_y -= other.m_y;
        return *this;
    }
    CartesianVector operator*(const float& scalar) const {
        return CartesianVector(m_x * scalar, m_y * scalar);
    }
    CartesianVector operator*=(const float& scalar) {
        m_x *= scalar;
        m_y *= scalar;
        return *this;
    }
    CartesianVector operator/(const float& scalar) const {
        return CartesianVector(m_x / scalar, m_y / scalar);
    }
    CartesianVector operator/=(const float& scalar) {
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
