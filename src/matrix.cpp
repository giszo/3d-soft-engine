#include "matrix.hpp"

#include "math.hpp"

#include <cmath>
#include <stdexcept>

Matrix::Matrix()
{
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            m_data[i * 4 + j] = (i == j) ? 1 : 0;
        }
    }
}

float Matrix::at(int row, int col) const
{
    if (row < 0 || row >= 4 || col < 0 || col >= 4)
        throw std::runtime_error("invalid matrix index");

    return m_data[4 * row + col];
}

Matrix Matrix::translate(float x, float y, float z)
{
    Matrix m;
    m.m_data[3] = x;
    m.m_data[7] = y;
    m.m_data[11] = z;
    return m;
}

Matrix Matrix::scale(float x, float y, float z)
{
    Matrix m;
    m.m_data[0] = x;
    m.m_data[5] = y;
    m.m_data[10] = z;
    return m;
}

Matrix Matrix::rotate(float x, float y, float z)
{
    x = deg_to_rad(x);
    y = deg_to_rad(y);
    z = deg_to_rad(z);

    double sx = sin(x);
    double cx = cos(x);
    double sy = sin(y);
    double cy = cos(y);
    double sz = sin(z);
    double cz = cos(z);

    Matrix m;

    // Rotation order is x, y, z
    // See details here: http://inside.mines.edu/~gmurray/ArbitraryAxisRotation/
    m.m_data[0] = cy * cz;
    m.m_data[1] = cz * sx * sy - cx * sz;
    m.m_data[2] = cx * cz * sy + sx * sz;
    m.m_data[4] = cy * sz;
    m.m_data[5] = cx * cz + sx * sy * sz;
    m.m_data[6] = -cz * sx + cx * sy * sz;
    m.m_data[8] = -sy;
    m.m_data[9] = cy * sx;
    m.m_data[10] = cx * cy;

    return m;
}

Matrix Matrix::lookAt(const Vector& eye, const Vector& target, const Vector& up)
{
    Matrix m;

    // Details and explanation: http://3dgep.com/?p=1700

    Vector zAxis = (target - eye).normalized();
    Vector xAxis = up.crossProduct(zAxis).normalized();
    Vector yAxis = zAxis.crossProduct(xAxis);

    m.m_data[0] = xAxis.x();
    m.m_data[1] = yAxis.x();
    m.m_data[2] = zAxis.x();
    m.m_data[3] = -xAxis.dotProduct(eye);
    m.m_data[4] = xAxis.y();
    m.m_data[5] = yAxis.y();
    m.m_data[6] = zAxis.y();
    m.m_data[7] = -yAxis.dotProduct(eye);
    m.m_data[8] = xAxis.z();
    m.m_data[9] = yAxis.z();
    m.m_data[10] = zAxis.z();
    m.m_data[11] = -zAxis.dotProduct(eye);

    return m;
}

Matrix Matrix::perspectiveProjection(float fov, float aspectRatio, float near, float far)
{
    Matrix m;

    // See http://www.opengl.org/sdk/docs/man2/xhtml/gluPerspective.xml for details

    float f = 1 / tanf(deg_to_rad(fov) * 0.5f);

    m.m_data[0] = f / aspectRatio;
    m.m_data[5] = f;
    m.m_data[10] = (far + near) / (near - far);
    m.m_data[11] = (2 * far * near) / (near - far);
    m.m_data[14] = -1;
    m.m_data[15] = 0;

    return m;
}

Vertex Matrix::operator*(const Vertex& v)
{
    return Vertex(v.x() * at(0, 0) + v.y() * at(0, 1) + v.z() * at(0, 2) + v.w() * at(0, 3),
                  v.x() * at(1, 0) + v.y() * at(1, 1) + v.z() * at(1, 2) + v.w() * at(1, 3),
                  v.x() * at(2, 0) + v.y() * at(2, 1) + v.z() * at(2, 2) + v.w() * at(2, 3),
                  v.x() * at(3, 0) + v.y() * at(3, 1) + v.z() * at(3, 2) + v.w() * at(3, 3));
}

Matrix Matrix::operator*(const Matrix& m)
{
    Matrix res;

    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
            res.m_data[i * 4 + j] = at(i, 0) * m.at(0, j) + at(i, 1) * m.at(1, j) + at(i, 2) * m.at(2, j) + at(i, 3) * m.at(3, j);
    }

    return res;
}
