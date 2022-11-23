#pragma once
#include <memory>
#include "core.h"
#include "spdlog.h"

namespace Crumbl2D
{
    class CRUMBL_API Log
    {
    public:
        static void Init();

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
#define CB_CORE_TRACE(...)::Crumbl2D::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define CB_CORE_INFO(...)::Crumbl2D::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CB_CORE_WARN(...)::Crumbl2D::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CB_CORE_ERROR(...)::Crumbl2D::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CB_CORE_CRITICAL(...)::Crumbl2D::Log::GetCoreLogger()->critical(__VA_ARGS__)

//Client log macros
#define CB_TRACE(...)::Crumbl2D::Log::GetClientLogger()->trace(__VA_ARGS__)
#define CB_INFO(...)::Crumbl2D::Log::GetClientLogger()->info(__VA_ARGS__)
#define CB_WARN(...)::Crumbl2D::Log::GetClientLogger()->warn(__VA_ARGS__)
#define CB_ERROR(...)::Crumbl2D::Log::GetClientLogger()->error(__VA_ARGS__)
#define CB_CRITICAL(...)::Crumbl2D::Log::GetClientLogger()->critical(__VA_ARGS__)

