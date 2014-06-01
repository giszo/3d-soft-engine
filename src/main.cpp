#include "window.hpp"
#include "rasterizer.hpp"
#include "vector.hpp"
#include "matrix.hpp"
#include "mesh.hpp"

#include <iostream>

#define WIDTH 640
#define HEIGHT 480

int main(int argc, char** argv)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cerr << "Unable to initialize SDL video" << std::endl;
        return 1;
    }

    Window window(WIDTH, HEIGHT);

    Mesh mesh;
    mesh.addVertex(Vertex( 1.0f,  1.0f, -1.0f));
    mesh.addVertex(Vertex( 1.0f, -1.0f, -1.0f));
    mesh.addVertex(Vertex(-1.0f, -1.0f, -1.0f));
    mesh.addVertex(Vertex(-1.0f,  1.0f, -1.0f));
    mesh.addVertex(Vertex( 1.0f,  1.0f,  1.0f));
    mesh.addVertex(Vertex( 1.0f, -1.0f,  1.0f));
    mesh.addVertex(Vertex(-1.0f, -1.0f,  1.0f));
    mesh.addVertex(Vertex(-1.0f,  1.0f,  1.0f));

    float rotation = 0.0f;

    // Calculate view and projection matrices only once
    Matrix viewTr = Matrix::lookAt(Vector(0.0f, 0.0f, 10.0f), Vector(0.0f, 0.0f, 0.0f), Vector(0.0f, 1.0f, 0.0f));
    Matrix projTr = Matrix::perspectiveProjection(90, WIDTH / HEIGHT, 1.0f, 10.0f);

    while (true)
    {
        if (!window.processEvents())
            break;

        Rasterizer rasterizer(window);

        Matrix modelTr = Matrix::rotate(rotation, rotation, rotation);

        for (const auto& point : mesh.vertices())
        {
            // Apply transformations: model, view and projection
            Vertex p = modelTr * point;
            p = viewTr * p;
            p = projTr * p;

            int x =  (p.x() / p.w()) * WIDTH + WIDTH / 2;
            int y = -(p.y() / p.w()) * HEIGHT + HEIGHT / 2;

            rasterizer.drawPoint(x, y, 0xff0000);
        }

        rotation += 0.01f;
    }

    return 0;
}
