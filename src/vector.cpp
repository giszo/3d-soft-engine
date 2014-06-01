#include "vector.hpp"

#include <cmath>

Vector::Vector(float x, float y, float z)
    : m_x(x)
    , m_y(y)
    , m_z(z)
{
}

float Vector::x() const
{
    return m_x;
}

float Vector::y() const
{
    return m_y;
}

float Vector::z() const
{
    return m_z;
}

Vector Vector::normalized() const
{
    float length = sqrtf(m_x * m_x + m_y * m_y + m_z * m_z);
    return Vector(m_x / length, m_y / length, m_z / length);
}

Vector Vector::crossProduct(const Vector& v) const
{
    return Vector(m_y * v.m_z - m_z * v.m_y,
                  m_z * v.m_x - m_x * v.m_z,
                  m_x * v.m_y - m_y * v.m_x);
}

float Vector::dotProduct(const Vector& v) const
{
    return m_x * v.m_x + m_y * v.m_y + m_z * v.m_z;
}

Vector Vector::operator-(const Vector& v) const
{
    return Vector(m_x - v.m_x, m_y - v.m_y, m_z - v.m_z);
}
