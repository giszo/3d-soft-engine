#include "mesh.hpp"

const std::vector<Vertex>& Mesh::vertices() const
{
    return m_vertices;
}

void Mesh::addVertex(const Vertex& v)
{
    m_vertices.push_back(v);
}
