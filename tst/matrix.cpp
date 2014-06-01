#include <boost/test/unit_test.hpp>

#include <matrix.hpp>

BOOST_AUTO_TEST_CASE(translate_vector_with_matrix_multiplication)
{
    Vertex v(1, 1, 1);
    Vertex r = Matrix::translate(2, 3, 4) * v;

    BOOST_CHECK_EQUAL(r.x(), 3);
    BOOST_CHECK_EQUAL(r.y(), 4);
    BOOST_CHECK_EQUAL(r.z(), 5);
}

BOOST_AUTO_TEST_CASE(scale_vector_with_matrix_multiplication)
{
    Vertex v(2, 4, 6);
    Vertex r = Matrix::scale(0.5f, 0.25f, 0.5f) * v;

    BOOST_CHECK_EQUAL(r.x(), 1);
    BOOST_CHECK_EQUAL(r.y(), 1);
    BOOST_CHECK_EQUAL(r.z(), 3);
}

BOOST_AUTO_TEST_CASE(rotate_vector_with_matrix_multiplication)
{
    Vertex v(1, 0, 0);
    Vertex r = Matrix::rotate(0, 90, 0) * v;

    BOOST_CHECK(r.x() > -0.001 && r.x() < 0.001);
    BOOST_CHECK(r.y() > -0.001 && r.y() < 0.001);
    BOOST_CHECK_EQUAL(r.z(), -1);
}
