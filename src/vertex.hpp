#ifndef VERTEX_HPP_INCLUDED
#define VERTEX_HPP_INCLUDED

/// Represents a point in 3D space with homogeneous coordinates.
class Vertex
{
    public:
        Vertex(float x, float y, float z, float w = 1.0f);

        float x() const;
        float y() const;
        float z() const;
        float w() const;

    private:
        float m_x;
        float m_y;
        float m_z;
        float m_w;
};

#endif
