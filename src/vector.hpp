#ifndef VECTOR_HPP_INCLUDED
#define VECTOR_HPP_INCLUDED

class Vector
{
    public:
        Vector(float x, float y, float z);

        float x() const;
        float y() const;
        float z() const;

        /// Returns the normalized version of this vector.
        Vector normalized() const;

        /// Calculates the cross product of the current and the specified vectors.
        Vector crossProduct(const Vector& v) const;
        /// Calculates the dot product of the current and the specified vectors.
        float dotProduct(const Vector& v) const;

        Vector operator-(const Vector& v) const;

    private:
        float m_x;
        float m_y;
        float m_z;
};

#endif
