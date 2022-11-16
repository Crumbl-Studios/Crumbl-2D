#pragma once
#include "application.h"

extern Crumbl::Application* Crumbl::CreateApplication();

int main(int argc, char** argv)
{
    auto app = Crumbl::CreateApplication();
    app->Run();
    delete app;
}