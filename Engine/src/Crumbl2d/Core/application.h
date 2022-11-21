#pragma once
#include "core.h"
#include "../Events/input.h"

namespace crumbl2d
{
    class CRUMBL_API application
    {
    public:
        application();
        virtual ~application();

        void run();

        crumbl2d::input input;
    private:
        bool m_running = true;
    };

    // Defined in client
    application* createApplication();
}