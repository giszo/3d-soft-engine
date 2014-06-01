#include "rasterizer.hpp"

#include <stdexcept>

Rasterizer::Rasterizer(Window& window)
    : m_window(window)
{
    m_window.lock();
    m_window.clear();
}

Rasterizer::~Rasterizer()
{
    m_window.unlock();
}

void Rasterizer::drawPoint(int x, int y, uint32_t color)
{
    if (x < 0 || y < 0 || x >= m_window.width() || y >= m_window.height())
        return;

    uint32_t* fb = reinterpret_cast<uint32_t*>(m_window.frameBuffer());
    fb += y * m_window.width() + x;
    *fb = color;
}
