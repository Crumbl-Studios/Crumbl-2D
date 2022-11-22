#pragma once
#include "core.h"
#include "../Events/event.h"
#include "window.h"

namespace Crumbl2D
{
    class CRUMBL_API Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();

        Crumbl2D::EventHandler EventHandler = Crumbl2D::EventHandler();
        Crumbl2D::Window Window = Crumbl2D::Window();
    private:
        bool m_running = true;
    };

    // Defined in client
    Application* CreateApplication();
}