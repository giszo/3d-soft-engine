#ifndef MESH_HPP_INCLUDED
#define MESH_HPP_INCLUDED

#include <vertex.hpp>

#include <vector>

class Mesh
{
    public:
        const std::vector<Vertex>& vertices() const;

        void addVertex(const Vertex& v);

    private:
        std::vector<Vertex> m_vertices;
};

#endif
