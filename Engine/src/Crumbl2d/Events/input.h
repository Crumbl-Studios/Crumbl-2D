#pragma once
#include "../cbpch.h"
#include "../Core/core.h"
#include "event.h"
#include <SDL.h>

namespace crumbl2d
{
    class CRUMBL_API input
    {
        void pollEvents();
        bool getKey(keycode p_keycode);
        bool getKeyDown(keycode p_keycode);
        bool getKeyUp(keycode p_keycode);

        bool getMouseButton();
        bool getMouseButtonDown();
        bool getMouseButtonUp();
        bool getAxis();

        std::map<std::string, bool> raw_events;

        std::vector<event> events;
        std::map<keycode, keyEvent> key_events;
    };
}