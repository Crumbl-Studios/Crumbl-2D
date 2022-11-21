#include "../cbpch.h"
#include "application.h"
#include "log.h"

namespace crumbl2d
{
    application::application()
    {
        input = crumbl2d::input();
    }

    application::~application()
    {
    }

    void application::run()
    {
        while (m_running)
        {
            input.pollEvents();
        }
    }
}