#include "vertex.hpp"

Vertex::Vertex(float x, float y, float z, float w)
    : m_x(x)
    , m_y(y)
    , m_z(z)
    , m_w(w)
{
}

float Vertex::x() const
{
    return m_x;
}

float Vertex::y() const
{
    return m_y;
}

float Vertex::z() const
{
    return m_z;
}

float Vertex::w() const
{
    return m_w;
}
