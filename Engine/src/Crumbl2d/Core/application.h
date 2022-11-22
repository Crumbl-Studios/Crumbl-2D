#pragma once
#include "core.h"
#include "../Events/input.h"
#include "window.h"

namespace crumbl2d
{
    class CRUMBL_API application
    {
    public:
        application();
        virtual ~application();

        void run();

        crumbl2d::input input = crumbl2d::input();
        crumbl2d::Window window = crumbl2d::Window();
    private:
        bool m_running = true;
    };

    // Defined in client
    application* createApplication();
}