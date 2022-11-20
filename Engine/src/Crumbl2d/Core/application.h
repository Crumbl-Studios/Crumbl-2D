#pragma once
#include "core.h"

namespace crumbl2d
{
    class CRUMBL_API application
    {
    public:
        application();
        virtual ~application();

        void run();
    };

    // Defined in client
    application* createApplication();
}