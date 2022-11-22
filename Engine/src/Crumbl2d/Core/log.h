#pragma once
#include <memory>
#include "core.h"
#include "spdlog.h"

namespace crumbl2d
{
    class CRUMBL_API log
    {
    public:
        static void init();

        inline static std::shared_ptr<spdlog::logger>& GetCoreLogger()
        {
            return s_core_logger;
        }
        inline static std::shared_ptr<spdlog::logger>& GetClientLogger()
        {
            return s_client_logger;
        }
    private:
        static std::shared_ptr<spdlog::logger> s_core_logger;
        static std::shared_ptr<spdlog::logger> s_client_logger;
    };
}

// Core log macros
#define CB_CORE_TRACE(...)::crumbl2d::log::GetCoreLogger()->trace(__VA_ARGS__)
#define CB_CORE_INFO(...)::crumbl2d::log::GetCoreLogger()->info(__VA_ARGS__)
#define CB_CORE_WARN(...)::crumbl2d::log::GetCoreLogger()->warn(__VA_ARGS__)
#define CB_CORE_ERROR(...)::crumbl2d::log::GetCoreLogger()->error(__VA_ARGS__)
#define CB_CORE_CRITICAL(...)::crumbl2d::log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client log macros
#define CB_TRACE(...)::crumbl2d::log::GetClientLogger()->trace(__VA_ARGS__)
#define CB_INFO(...)::crumbl2d::log::GetClientLogger()->info(__VA_ARGS__)
#define CB_WARN(...)::crumbl2d::log::GetClientLogger()->warn(__VA_ARGS__)
#define CB_ERROR(...)::crumbl2d::log::GetClientLogger()->error(__VA_ARGS__)
#define CB_CRITICAL(...)::crumbl2d::log::GetClientLogger()->fatal(__VA_ARGS__)

