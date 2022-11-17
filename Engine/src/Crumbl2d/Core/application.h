#pragma once
#include "core.h"

namespace Crumbl2D
{
    class CRUMBL_API Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();
    };

    // Defined in client
    Application* CreateApplication();
}