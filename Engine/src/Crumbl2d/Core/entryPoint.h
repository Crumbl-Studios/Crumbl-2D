#pragma once
#include "application.h"
#include "log.h"

extern Crumbl2D::Application* Crumbl2D::CreateApplication();

int main(int argc, char** argv)
{
    Crumbl2D::Log::Init();
    CB_CORE_WARN("Initialized Log!");
    CB_INFO("Saluton!");

    auto app = Crumbl2D::CreateApplication();
    app->Run();
    delete app;
}