#pragma once
#include "application.h"
#include "log.h"

extern crumbl2d::application* crumbl2d::createApplication();

int main(int argc, char** argv)
{
    crumbl2d::log::init();
    CB_CORE_WARN("Initialized Log!");
    CB_INFO("Saluton!");

    auto app = crumbl2d::createApplication();
    app->run();
    delete app;
}