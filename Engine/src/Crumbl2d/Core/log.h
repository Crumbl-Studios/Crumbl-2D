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
            return s_CoreLogger;
        }
        inline static std::shared_ptr<spdlog::logger>& GetClientLogger()
        {
            return s_ClientLogger;
        }
    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };
}

// Core log macros
#define CB_CORE_TRACE(...)::Crumbl2D::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define CB_CORE_INFO(...)::Crumbl2D::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CB_CORE_WARN(...)::Crumbl2D::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CB_CORE_ERROR(...)::Crumbl2D::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CB_CORE_FATAL(...)::Crumbl2D::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client log macros
#define CB_TRACE(...)::Crumbl2D::Log::GetClientLogger()->trace(__VA_ARGS__)
#define CB_INFO(...)::Crumbl2D::Log::GetClientLogger()->info(__VA_ARGS__)
#define CB_WARN(...)::Crumbl2D::Log::GetClientLogger()->warn(__VA_ARGS__)
#define CB_ERROR(...)::Crumbl2D::Log::GetClientLogger()->error(__VA_ARGS__)
#define CB_FATAL(...)::Crumbl2D::Log::GetClientLogger()->fatal(__VA_ARGS__)

