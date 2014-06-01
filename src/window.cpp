#include "window.hpp"

#include <stdexcept>

Window::Window(int width, int height)
    : m_width(width)
    , m_height(height)
    , m_surface(SDL_SetVideoMode(width, height, 32, SDL_HWSURFACE | SDL_DOUBLEBUF))
{
    if (!m_surface)
        throw std::runtime_error("unable to initialize SDL surface");
}

int Window::width() const
{
    return m_width;
}

int Window::height() const
{
    return m_height;
}

int Window::bpp() const
{
    return 32;
}

void* Window::frameBuffer() const
{
    return m_surface->pixels;
}

bool Window::processEvents()
{
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
            return false;
    }

    return true;
}

void Window::lock()
{
    SDL_LockSurface(m_surface);
}

void Window::unlock()
{
    SDL_UnlockSurface(m_surface);
    SDL_Flip(m_surface);
}

void Window::clear()
{
    SDL_FillRect(m_surface, NULL, 0);
}
