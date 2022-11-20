#pragma once
#include "../Core/core.h"

namespace crumbl2d
{
    class CRUMBL_API event
    {
    };

    enum keycode
    {
        None = 0,
        Backspace, Delete, Tab, Clear, Return, Pause, Escape, Space,
        Keypad0, Keypad1, Keypad2, Keypad3, Keypad4, Keypad5, Keypad6, Keypad7,
        Keypad8, Keypad9, KeypadPeriod, KeypadDivide, KeypadMultiply, KeypadMinus,
        KeypadPlus, KeypadEnter, KeypadEquals,
        UpArrow, DownArrow, RightArrow, LeftArrow,
        Insert, Home, End, PageUp, PageDown,
        F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12, F13, F14, F15,
        Exclaim, DoubleQuote, Hash, Dollar, Percent, Ampersand,
        Quote, LeftParen, RightParen, Aserisk, Plus, Comma, Minus, Period,
        Slash, Colon, Semicolon, Less, Equals, Greater, Question, At,
        LeftBracket, Backslash, RightBracket, Caret, Underscore, BackQuote,
        A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
        LeftCurlyBracket, Pipe, RightCurlyBracket, Tilde,
        NumLock, CapsLock, ScrollLock, RightShift, LeftShift, RightControl, LeftControl,
        RightAlt, LeftAlt, LeftMeta, RightMeta, Help, Print, SysReq, Break, Menu,
        Mouse0, Mouse1, Mouse2, Mouse3, Mouse4, Mouse5, Mouse6
    };

    struct keyEvent : public event
    {
        keyEvent(int p_key_state = 0, int p_repeat = 0)
        {
            key_state = p_key_state;
            repeat = p_repeat;
        }

        keycode keycode;
        int key_state;
        int repeat;
    };
}