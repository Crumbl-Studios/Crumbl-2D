#pragma once
#include "../cbpch.h"
#include "../Core/core.h"
#include "event.h"

namespace crumbl2d
{
    class CRUMBL_API input
    {
    public:
        void pollEvents();
        bool getKey(keycode p_keycode);
        bool getKeyDown(keycode p_keycode);
        bool getKeyUp(keycode p_keycode);

        bool getAxis();

        bool getEvent(eventcode p_eventcode);

        std::map<eventcode, Event> events;
        std::map<keycode, keyEvent> key_events;
    };
}