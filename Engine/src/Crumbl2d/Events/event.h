#pragma once
#include "../cbpch.h"
#include "../Core/core.h"
#include "event.h"

namespace Crumbl2D
{
    enum Eventcode
    {
        WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
        AppTick, AppUpdate, AppRender,
        MouseMotion,
        UserEvent0, UserEvent1, UserEvent2
    };

    enum Keycode
    {
        ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, ZERO,
        Backspace, Delete, Tab, Clear, Return, Pause, Escape, Space,
        Keypad0, Keypad1, Keypad2, Keypad3, Keypad4, Keypad5, Keypad6, Keypad7,
        Keypad8, Keypad9, KeypadPeriod, KeypadDivide, KeypadMultiply, KeypadMinus,
        KeypadPlus, KeypadEnter, KeypadEquals,
        UpArrow, DownArrow, RightArrow, LeftArrow,
        Insert, Home, End, PageUp, PageDown,
        F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12, F13, F14, F15,
        Exclaim, DoubleQuote, Hash, Dollar, Percent, Ampersand,
        Quote, LeftParen, RightParen, Asterisk, Plus, Comma, Minus, Period,
        Slash, Colon, Semicolon, Less, Equals, Greater, Question, At,
        LeftBracket, Backslash, RightBracket, Caret, Underscore, BackQuote,
        A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
        LeftCurlyBracket, Pipe, RightCurlyBracket, Tilde,
        NumLock, CapsLock, ScrollLock, RightShift, LeftShift, RightControl, LeftControl,
        RightAlt, LeftAlt, LeftMeta, RightMeta, Help, Print, SysReq, Menu,
        Mouse0, Mouse1, Mouse2, Mouse3, Mouse4
    };

    struct CRUMBL_API Event
    {
        Event(const char* p_event="event", bool p_event_state=false)
        {
            event = p_event;
            event_state = p_event_state;
        }

        const char* event;
        bool event_state;
        Eventcode Eventcode;
    };

    struct CRUMBL_API KeyEvent
    {
        KeyEvent(int p_key_state=0, int p_repeat=0)
        {
            key_state = p_key_state;
            repeat = p_repeat;
        }

        Keycode Keycode;
        int key_state;
        int repeat;
    };

    class CRUMBL_API EventHandler
    {
    public:
        void PollEvents();
        bool GetKey(Keycode p_keycode);
        bool GetKeyDown(Keycode p_keycode);
        bool GetKeyUp(Keycode p_keycode);

        bool GetAxis();

        bool GetEvent(Eventcode p_eventcode);
        void CreateEvent(Eventcode p_eventcode);
    private:
        std::map<Eventcode, Event> events;
        std::map<Keycode, KeyEvent> key_events;
    };
}