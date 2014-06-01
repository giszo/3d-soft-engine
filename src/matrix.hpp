#ifndef MATRIX_HPP_INCLUDED
#define MATRIX_HPP_INCLUDED

#include "vertex.hpp"
#include "vector.hpp"

class Matrix
{
    public:
        /// Returns matrix data from the specified position.
        float at(int row, int col) const;

        /// Initializes the translation part of the matrix with the given values.
        /// \return The current matrix
        static Matrix translate(float x, float y, float z);

        /// Initializes the scaling part of the matrix with the given values.
        /// \return The current matrix
        static Matrix scale(float x, float y, float z);

        /// Initializes the rotation part of the matrix according to the given values.
        /// The rotation order is x, y, z.
        /// \return The current matrix
        static Matrix rotate(float x, float y, float z);

        /// Calculates a look-at matrix according to the given parameters.
        static Matrix lookAt(const Vector& eye, const Vector& target, const Vector& up);

        static Matrix perspectiveProjection(float fov, float aspectRatio, float near, float far);

        Vertex operator*(const Vertex& v);
        Matrix operator*(const Matrix& m);

        float m_data[4 * 4];

    private:
        /// Initializes an identity matrix.
        Matrix();
};

#endif
