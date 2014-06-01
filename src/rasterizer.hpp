#ifndef RASTERIZER_HPP_INCLUDED
#define RASTERIZER_HPP_INCLUDED

#include "window.hpp"

#include <inttypes.h>

class Rasterizer
{
    public:
        Rasterizer(Window& window);
        ~Rasterizer();

        void drawPoint(int x, int y, uint32_t color);

    private:
        Window& m_window;
};

#endif
