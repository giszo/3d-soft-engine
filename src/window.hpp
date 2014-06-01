#ifndef WINDOW_HPP_INCLUDED
#define WINDOW_HPP_INCLUDED

#include <SDL/SDL.h>

class Window
{
    public:
        Window(int width, int height);

        int width() const;
        int height() const;
        int bpp() const;
        void* frameBuffer() const;

        /// Processes window events.
        /// \return false if the window should be closed, true otherwise
        bool processEvents();

        /// Locks the surface of the window for painting.
        void lock();
        /// Unlocks the surface of the window after painting has been finished.
        void unlock();

        /// Clears the surface of the window.
        void clear();

    private:
        int m_width;
        int m_height;

        SDL_Surface* m_surface;
};

#endif
