#include "input.h"

namespace crumbl2d
{
    void input::pollEvents()
    {
        SDL_Event sdl_event;
        std::map<std::string, bool> n_raw_events;

        std::vector<event> n_events;
        while (SDL_PollEvent(&sdl_event))
        {
            switch(sdl_event.type)
            {
                case SDL_QUIT:
                    raw_events["Quit"] = true;
                case SDL_MOUSEMOTION:
                    raw_events["Mouse"] = true;
                case SDL_MOUSEBUTTONDOWN:
                    raw_events["MouseButtonDown"] = true;
                    switch (sdl_event.button.button)
                    {
                        case SDL_BUTTON_LEFT:
                            raw_events["LeftMouseButtonDown"] = true;
                        case SDL_BUTTON_MIDDLE:
                            raw_events["MiddleMouseButtonDown"] = true;
                        case SDL_BUTTON_RIGHT:
                            raw_events["RightMouseButtonDown"] = true;
                    }
                case SDL_MOUSEBUTTONUP:
                    raw_events["MouseButtonUp"] = true;
                    switch (sdl_event.button.button)
                    {
                        case SDL_BUTTON_LEFT:
                            raw_events["LeftMouseButtonUp"] = true;
                        case SDL_BUTTON_MIDDLE:
                            raw_events["MiddleMouseButtonUp"] = true;
                        case SDL_BUTTON_RIGHT:
                            raw_events["RightMouseButtonUp"] = true;
                    }
                case SDL_KEYDOWN:
                    raw_events["KeyDown"] = true;
                    switch (sdl_event.key.keysym.sym)
                    {
                        case SDLK_ESCAPE:
                            raw_events["EscapeKeyDown"] = true;

                        case SDLK_F1:
                            raw_events["F1KeyDown"] = true;
                        case SDLK_F2:
                            raw_events["F2KeyDown"] = true;
                        case SDLK_F3:
                            raw_events["F3KeyDown"] = true;
                        case SDLK_F4:
                            raw_events["F4KeyDown"] = true;
                        case SDLK_F5:
                            raw_events["F5KeyDown"] = true;
                        case SDLK_F6:
                            raw_events["F6KeyDown"] = true;
                        case SDLK_F7:
                            raw_events["F7KeyDown"] = true;
                        case SDLK_F8:
                            raw_events["F8KeyDown"] = true;
                        case SDLK_F9:
                            raw_events["F9KeyDown"] = true;
                        case SDLK_F10:
                            raw_events["F10KeyDown"] = true;
                        case SDLK_F11:
                            raw_events["F11KeyDown"] = true;
                        case SDLK_F12:
                            raw_events["F12KeyDown"] = true;

                        case SDLK_PRINTSCREEN:
                            raw_events["PrintScreenKeyDown"] = true;
                        case SDLK_SCROLLLOCK:
                            raw_events["ScrollLockKeyDown"] = true;
                        case SDLK_PAUSE:
                            raw_events["PauseKeyDown"] = true;

                        case SDLK_BACKQUOTE:
                            raw_events["BackQuoteKeyDown"] = true;

                        case SDLK_1:
                            raw_events["1KeyDown"] = true;
                        case SDLK_2:
                            raw_events["2KeyDown"] = true;
                        case SDLK_3:
                            raw_events["3KeyDown"] = true;
                        case SDLK_4:
                            raw_events["4KeyDown"] = true;
                        case SDLK_5:
                            raw_events["5KeyDown"] = true;
                        case SDLK_6:
                            raw_events["6KeyDown"] = true;
                        case SDLK_7:
                            raw_events["7KeyDown"] = true;
                        case SDLK_8:
                            raw_events["8KeyDown"] = true;
                        case SDLK_9:
                            raw_events["9KeyDown"] = true;
                        case SDLK_0:
                            raw_events["0KeyDown"] = true;

                        case SDLK_MINUS:
                            raw_events["MinusKeyDown"] = true;
                        case SDLK_PLUS:
                            raw_events["PlusKeyDown"] = true;
                        case SDLK_BACKSPACE:
                            raw_events["BackSpaceKeyDown"] = true;

                        case SDLK_INSERT:
                            raw_events["InsertKeyDown"] = true;
                        case SDLK_HOME:
                            raw_events["HomeKeyDown"] = true;
                        case SDLK_PAGEUP:
                            raw_events["PageUpKeyDown"] = true;

                        case SDLK_TAB:
                            raw_events["TabKeyDown"] = true;
                        case SDLK_q:
                            raw_events["QKeyDown"] = true;
                        case SDLK_w:
                            raw_events["WKeyDown"] = true;
                        case SDLK_e:
                            raw_events["EKeyDown"] = true;
                        case SDLK_r:
                            raw_events["RKeyDown"] = true;
                        case SDLK_t:
                            raw_events["TKeyDown"] = true;
                        case SDLK_y:
                            raw_events["YKeyDown"] = true;
                        case SDLK_u:
                            raw_events["UKeyDown"] = true;
                        case SDLK_i:
                            raw_events["IKeyDown"] = true;
                        case SDLK_o:
                            raw_events["OKeyDown"] = true;
                        case SDLK_p:
                            raw_events["PKeyDown"] = true;

                        case SDLK_LEFTBRACKET:
                            raw_events["LeftBracketKeyDown"] = true;
                        case SDLK_RIGHTBRACKET:
                            raw_events["RightBracketKeyDown"] = true;
                        case SDLK_BACKSLASH:
                            raw_events["BackSlashKeyDown"] = true;

                        case SDLK_DELETE:
                            raw_events["DeleteTKeyDown"] = true;
                        case SDLK_END:
                            raw_events["EndKeyDown"] = true;
                        case SDLK_PAGEDOWN:
                            raw_events["PageDownKeyDown"] = true;

                        case SDLK_CAPSLOCK:
                            raw_events["CapsLockUpKeyDown"] = true;

                        case SDLK_a:
                            raw_events["AKeyDown"] = true;
                        case SDLK_s:
                            raw_events["SKeyDown"] = true;
                        case SDLK_d:
                            raw_events["DKeyDown"] = true;
                        case SDLK_f:
                            raw_events["FKeyDown"] = true;
                        case SDLK_g:
                            raw_events["GKeyDown"] = true;
                        case SDLK_h:
                            raw_events["TabKeyDown"] = true;
                        case SDLK_j:
                            raw_events["JKeyDown"] = true;
                        case SDLK_k:
                            raw_events["KKeyDown"] = true;
                        case SDLK_l:
                            raw_events["LKeyDown"] = true;

                        case SDLK_SEMICOLON:
                            raw_events["SemicolonKeyDown"] = true;
                        case SDLK_QUOTE:
                            raw_events["QuoteKeyDown"] = true;
                        case SDLK_RETURN:
                            raw_events["ReturnKeyDown"] = true;

                        case SDLK_LSHIFT:
                            raw_events["LeftShiftKeyDown"] = true;

                        case SDLK_z:
                            raw_events["ZKeyDown"] = true;
                        case SDLK_x:
                            raw_events["XKeyDown"] = true;
                        case SDLK_c:
                            raw_events["CKeyDown"] = true;
                        case SDLK_v:
                            raw_events["VKeyDown"] = true;
                        case SDLK_b:
                            raw_events["BKeyDown"] = true;
                        case SDLK_n:
                            raw_events["NKeyDown"] = true;
                        case SDLK_m:
                            raw_events["MKeyDown"] = true;

                        case SDLK_COMMA:
                            raw_events["CommaKeyDown"] = true;
                        case SDLK_PERIOD:
                            raw_events["PeriodKeyDown"] = true;
                        case SDLK_SLASH:
                            raw_events["SlashKeyDown"] = true;
                        case SDLK_RSHIFT:
                            raw_events["RightShiftKeyDown"] = true;

                        case SDLK_UP:
                            raw_events["UpKeyDown"] = true;

                        case SDLK_LCTRL:
                            raw_events["LeftControlKeyDown"] = true;
                        case SDLK_LGUI:
                            raw_events["LeftGUIKeyDown"] = true;
                        case SDLK_LALT:
                            raw_events["LeftAltKeyDown"] = true;
                        case SDLK_SPACE:
                            raw_events["SpaceKeyDown"] = true;
                        case SDLK_RALT:
                            raw_events["RightAltKeyDown"] = true;
                        case SDLK_RCTRL:
                            raw_events["RightControlKeyDown"] = true;

                        case SDLK_LEFT:
                            raw_events["LeftKeyDown"] = true;
                        case SDLK_DOWN:
                            raw_events["DownKeyDown"] = true;
                        case SDLK_RIGHT:
                            raw_events["RightKeyDown"] = true;
                    }
                case SDL_KEYUP:
                    raw_events["KeyUp"] = true;
                    switch (sdl_event.key.keysym.sym)
                    {
                        case SDLK_ESCAPE:
                            raw_events["EscapeKeyUp"] = true;

                        case SDLK_F1:
                            raw_events["F1KeyUp"] = true;
                        case SDLK_F2:
                            raw_events["F2KeyUp"] = true;
                        case SDLK_F3:
                            raw_events["F3KeyUp"] = true;
                        case SDLK_F4:
                            raw_events["F4KeyUp"] = true;
                        case SDLK_F5:
                            raw_events["F5KeyUp"] = true;
                        case SDLK_F6:
                            raw_events["F6KeyUp"] = true;
                        case SDLK_F7:
                            raw_events["F7KeyUp"] = true;
                        case SDLK_F8:
                            raw_events["F8KeyUp"] = true;
                        case SDLK_F9:
                            raw_events["F9KeyUp"] = true;
                        case SDLK_F10:
                            raw_events["F10KeyUp"] = true;
                        case SDLK_F11:
                            raw_events["F11KeyUp"] = true;
                        case SDLK_F12:
                            raw_events["F12KeyUp"] = true;

                        case SDLK_PRINTSCREEN:
                            raw_events["PrintScreenKeyUp"] = true;
                        case SDLK_SCROLLLOCK:
                            raw_events["ScrollLockKeyUp"] = true;
                        case SDLK_PAUSE:
                            raw_events["PauseKeyUp"] = true;

                        case SDLK_BACKQUOTE:
                            raw_events["BackQuoteKeyUp"] = true;

                        case SDLK_1:
                            raw_events["1KeyUp"] = true;
                        case SDLK_2:
                            raw_events["2KeyUp"] = true;
                        case SDLK_3:
                            raw_events["3KeyUp"] = true;
                        case SDLK_4:
                            raw_events["4KeyUp"] = true;
                        case SDLK_5:
                            raw_events["5KeyUp"] = true;
                        case SDLK_6:
                            raw_events["6KeyUp"] = true;
                        case SDLK_7:
                            raw_events["7KeyUp"] = true;
                        case SDLK_8:
                            raw_events["8KeyUp"] = true;
                        case SDLK_9:
                            raw_events["9KeyUp"] = true;
                        case SDLK_0:
                            raw_events["0KeyUp"] = true;

                        case SDLK_MINUS:
                            raw_events["MinusKeyUp"] = true;
                        case SDLK_PLUS:
                            raw_events["PlusKeyUp"] = true;
                        case SDLK_BACKSPACE:
                            raw_events["BackSpaceKeyUp"] = true;

                        case SDLK_INSERT:
                            raw_events["InsertKeyUp"] = true;
                        case SDLK_HOME:
                            raw_events["HomeKeyUp"] = true;
                        case SDLK_PAGEUP:
                            raw_events["PageUpKeyUp"] = true;

                        case SDLK_TAB:
                            raw_events["TabKeyUp"] = true;
                        case SDLK_q:
                            raw_events["QKeyUp"] = true;
                        case SDLK_w:
                            raw_events["WKeyUp"] = true;
                        case SDLK_e:
                            raw_events["EKeyUp"] = true;
                        case SDLK_r:
                            raw_events["RKeyUp"] = true;
                        case SDLK_t:
                            raw_events["TKeyUp"] = true;
                        case SDLK_y:
                            raw_events["YKeyUp"] = true;
                        case SDLK_u:
                            raw_events["UKeyUp"] = true;
                        case SDLK_i:
                            raw_events["IKeyUp"] = true;
                        case SDLK_o:
                            raw_events["OKeyUp"] = true;
                        case SDLK_p:
                            raw_events["PKeyUp"] = true;

                        case SDLK_LEFTBRACKET:
                            raw_events["LeftBracketKeyUp"] = true;
                        case SDLK_RIGHTBRACKET:
                            raw_events["RightBracketKeyUp"] = true;
                        case SDLK_BACKSLASH:
                            raw_events["BackSlashKeyUp"] = true;

                        case SDLK_DELETE:
                            raw_events["DeleteTKeyUp"] = true;
                        case SDLK_END:
                            raw_events["EndKeyUp"] = true;
                        case SDLK_PAGEDOWN:
                            raw_events["PageDownKeyUp"] = true;

                        case SDLK_CAPSLOCK:
                            raw_events["CapsLockUpKeyUp"] = true;

                        case SDLK_a:
                            raw_events["AKeyUp"] = true;
                        case SDLK_s:
                            raw_events["SKeyUp"] = true;
                        case SDLK_d:
                            raw_events["DKeyUp"] = true;
                        case SDLK_f:
                            raw_events["FKeyUp"] = true;
                        case SDLK_g:
                            raw_events["GKeyUp"] = true;
                        case SDLK_h:
                            raw_events["TabKeyUp"] = true;
                        case SDLK_j:
                            raw_events["JKeyUp"] = true;
                        case SDLK_k:
                            raw_events["KKeyUp"] = true;
                        case SDLK_l:
                            raw_events["LKeyUp"] = true;

                        case SDLK_SEMICOLON:
                            raw_events["SemicolonKeyUp"] = true;
                        case SDLK_QUOTE:
                            raw_events["QuoteKeyUp"] = true;
                        case SDLK_RETURN:
                            raw_events["ReturnKeyUp"] = true;

                        case SDLK_LSHIFT:
                            raw_events["LeftShiftKeyUp"] = true;

                        case SDLK_z:
                            raw_events["ZKeyUp"] = true;
                        case SDLK_x:
                            raw_events["XKeyUp"] = true;
                        case SDLK_c:
                            raw_events["CKeyUp"] = true;
                        case SDLK_v:
                            raw_events["VKeyUp"] = true;
                        case SDLK_b:
                            raw_events["BKeyUp"] = true;
                        case SDLK_n:
                            raw_events["NKeyUp"] = true;
                        case SDLK_m:
                            raw_events["MKeyUp"] = true;

                        case SDLK_COMMA:
                            raw_events["CommaKeyUp"] = true;
                        case SDLK_PERIOD:
                            raw_events["PeriodKeyUp"] = true;
                        case SDLK_SLASH:
                            raw_events["SlashKeyUp"] = true;
                        case SDLK_RSHIFT:
                            raw_events["RightShiftKeyUp"] = true;

                        case SDLK_UP:
                            raw_events["UpKeyUp"] = true;

                        case SDLK_LCTRL:
                            raw_events["LeftControlKeyUp"] = true;
                        case SDLK_LGUI:
                            raw_events["LeftGUIKeyUp"] = true;
                        case SDLK_LALT:
                            raw_events["LeftAltKeyUp"] = true;
                        case SDLK_SPACE:
                            raw_events["SpaceKeyUp"] = true;
                        case SDLK_RALT:
                            raw_events["RightAltKeyUp"] = true;
                        case SDLK_RCTRL:
                            raw_events["RightControlKeyUp"] = true;

                        case SDLK_LEFT:
                            raw_events["LeftKeyUp"] = true;
                        case SDLK_DOWN:
                            raw_events["DownKeyUp"] = true;
                        case SDLK_RIGHT:
                            raw_events["RightKeyUp"] = true;
                    }
            }
        }
        raw_events =  n_raw_events;
        events = n_events;
    }

    bool input::getKey(keycode p_keycode)
    {
        if (key_events[p_keycode].key_state != 0)
        {
            return true;
        }
    }

    bool input::getKeyDown(keycode p_keycode)
    {
        if (key_events[p_keycode].key_state == -1)
        {
            return true;
        }
    }

    bool input::getKeyUp(keycode p_keycode)
    {
        if (key_events[p_keycode].key_state == 1)
        {
            return true;
        }
    }
}