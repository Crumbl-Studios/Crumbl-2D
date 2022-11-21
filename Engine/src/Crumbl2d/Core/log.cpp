#include "../cbpch.h"
#include "log.h"
#include "stdout_color_sinks.h"

namespace crumbl2d
{
    std::shared_ptr<spdlog::logger> log::s_core_logger;
    std::shared_ptr<spdlog::logger> log::s_client_logger;

    void log::init()
    {
        spdlog::set_pattern("%^[%T] %n: %v%$");
        s_core_logger = spdlog::stdout_color_mt("CRUMBL2D");
        s_core_logger->set_level(spdlog::level::trace);

        s_client_logger = spdlog::stdout_color_mt("APP");
        s_client_logger->set_level(spdlog::level::trace);
    }
}