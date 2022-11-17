#pragma once

#ifdef CB_PLATFORM_WINDOWS
    #ifdef CB_BUILD_DLL
        #define CRUMBL_API __declspec(dllexport)
    #else
        #define CRUMBL_API __declspec(dll_import)
    #endif
#elif CB_PLAFORM_MAC || CB_PLAFORM_LINUX
    #define CRUMBL_API
#endif