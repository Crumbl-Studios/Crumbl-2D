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
                            key_events[Mouse0].key_state = -1;
                        case SDL_BUTTON_RIGHT:
                            raw_events["RightMouseButtonDown"] = true;
                            key_events[Mouse1].key_state = -1;
                        case SDL_BUTTON_MIDDLE:
                            raw_events["MiddleMouseButtonDown"] = true;
                            key_events[Mouse2].key_state = -1;
                    }
                case SDL_MOUSEBUTTONUP:
                    raw_events["MouseButtonUp"] = true;
                    switch (sdl_event.button.button)
                    {
                        case SDL_BUTTON_LEFT:
                            raw_events["LeftMouseButtonUp"] = true;
                            key_events[Mouse1].key_state = 1;
                        case SDL_BUTTON_MIDDLE:
                            raw_events["MiddleMouseButtonUp"] = true;
                            key_events[Mouse1].key_state = 1;
                        case SDL_BUTTON_RIGHT:
                            raw_events["RightMouseButtonUp"] = true;
                            key_events[Mouse2].key_state = 1;
                    }
                case SDL_KEYDOWN:
                    raw_events["KeyDown"] = true;
                    switch (sdl_event.key.keysym.sym)
                    {
                        case SDLK_ESCAPE:
                            raw_events["EscapeKeyDown"] = true;
                            key_events[Escape].key_state = -1;

                        case SDLK_F1:
                            raw_events["F1KeyDown"] = true;
                            key_events[F1].key_state = -1;
                        case SDLK_F2:
                            raw_events["F2KeyDown"] = true;
                            key_events[F2].key_state = -1;
                        case SDLK_F3:
                            raw_events["F3KeyDown"] = true;
                            key_events[F3].key_state = -1;
                        case SDLK_F4:
                            raw_events["F4KeyDown"] = true;
                            key_events[F4].key_state = -1;
                        case SDLK_F5:
                            raw_events["F5KeyDown"] = true;
                            key_events[F5].key_state = -1;
                        case SDLK_F6:
                            raw_events["F6KeyDown"] = true;
                            key_events[F6].key_state = -1;
                        case SDLK_F7:
                            raw_events["F7KeyDown"] = true;
                            key_events[F7].key_state = -1;
                        case SDLK_F8:
                            raw_events["F8KeyDown"] = true;
                            key_events[F8].key_state = -1;
                        case SDLK_F9:
                            raw_events["F9KeyDown"] = true;
                            key_events[F9].key_state = -1;
                        case SDLK_F10:
                            raw_events["F10KeyDown"] = true;
                            key_events[F10].key_state = -1;
                        case SDLK_F11:
                            raw_events["F11KeyDown"] = true;
                            key_events[F11].key_state = -1;
                        case SDLK_F12:
                            raw_events["F12KeyDown"] = true;
                            key_events[F12].key_state = -1;

                        case SDLK_PRINTSCREEN:
                            raw_events["PrintScreenKeyDown"] = true;
                            key_events[Print].key_state = -1;
                        case SDLK_SCROLLLOCK:
                            raw_events["ScrollLockKeyDown"] = true;
                            key_events[ScrollLock].key_state = -1;
                        case SDLK_PAUSE:
                            raw_events["PauseKeyDown"] = true;
                            key_events[Pause].key_state = -1;

                        case SDLK_BACKQUOTE:
                            raw_events["BackQuoteKeyDown"] = true;
                            key_events[BackQuote].key_state = -1;

                        case SDLK_1:
                            raw_events["1KeyDown"] = true;
                            key_events[ONE].key_state = -1;
                        case SDLK_2:
                            raw_events["2KeyDown"] = true;
                            key_events[TWO].key_state = -1;
                        case SDLK_3:
                            raw_events["3KeyDown"] = true;
                            key_events[THREE].key_state = -1;
                        case SDLK_4:
                            raw_events["4KeyDown"] = true;
                            key_events[FOUR].key_state = -1;
                        case SDLK_5:
                            raw_events["5KeyDown"] = true;
                            key_events[FIVE].key_state = -1;
                        case SDLK_6:
                            raw_events["6KeyDown"] = true;
                            key_events[SIX].key_state = -1;
                        case SDLK_7:
                            raw_events["7KeyDown"] = true;
                            key_events[SEVEN].key_state = -1;
                        case SDLK_8:
                            raw_events["8KeyDown"] = true;
                            key_events[EIGHT].key_state = -1;
                        case SDLK_9:
                            raw_events["9KeyDown"] = true;
                            key_events[NINE].key_state = -1;
                        case SDLK_0:
                            raw_events["0KeyDown"] = true;
                            key_events[ZERO].key_state = -1;

                        case SDLK_MINUS:
                            raw_events["MinusKeyDown"] = true;
                            key_events[Minus].key_state = -1;
                        case SDLK_PLUS:
                            raw_events["PlusKeyDown"] = true;
                            key_events[Plus].key_state = -1;
                        case SDLK_BACKSPACE:
                            raw_events["BackSpaceKeyDown"] = true;
                            key_events[Backspace].key_state = -1;

                        case SDLK_INSERT:
                            raw_events["InsertKeyDown"] = true;
                            key_events[Insert].key_state = -1;
                        case SDLK_HOME:
                            raw_events["HomeKeyDown"] = true;
                            key_events[Home].key_state = -1;
                        case SDLK_PAGEUP:
                            raw_events["PageUpKeyDown"] = true;
                            key_events[PageUp].key_state = -1;

                        case SDLK_TAB:
                            raw_events["TabKeyDown"] = true;
                            key_events[Tab].key_state = -1;
                        case SDLK_q:
                            raw_events["QKeyDown"] = true;
                            key_events[Q].key_state = -1;
                        case SDLK_w:
                            raw_events["WKeyDown"] = true;
                            key_events[W].key_state = -1;
                        case SDLK_e:
                            raw_events["EKeyDown"] = true;
                            key_events[E].key_state = -1;
                        case SDLK_r:
                            raw_events["RKeyDown"] = true;
                            key_events[R].key_state = -1;
                        case SDLK_t:
                            raw_events["TKeyDown"] = true;
                            key_events[T].key_state = -1;
                        case SDLK_y:
                            raw_events["YKeyDown"] = true;
                            key_events[Y].key_state = -1;
                        case SDLK_u:
                            raw_events["UKeyDown"] = true;
                            key_events[U].key_state = -1;
                        case SDLK_i:
                            raw_events["IKeyDown"] = true;
                            key_events[I].key_state = -1;
                        case SDLK_o:
                            raw_events["OKeyDown"] = true;
                            key_events[O].key_state = -1;
                        case SDLK_p:
                            raw_events["PKeyDown"] = true;
                            key_events[P].key_state = -1;

                        case SDLK_LEFTBRACKET:
                            raw_events["LeftBracketKeyDown"] = true;
                            key_events[LeftBracket].key_state = -1;
                        case SDLK_RIGHTBRACKET:
                            raw_events["RightBracketKeyDown"] = true;
                            key_events[RightBracket].key_state = -1;
                        case SDLK_BACKSLASH:
                            raw_events["BackslashKeyDown"] = true;
                            key_events[Backslash].key_state = -1;

                        case SDLK_DELETE:
                            raw_events["DeleteTKeyDown"] = true;
                            key_events[Delete].key_state = -1;
                        case SDLK_END:
                            raw_events["EndKeyDown"] = true;
                            key_events[End].key_state = -1;
                        case SDLK_PAGEDOWN:
                            raw_events["PageDownKeyDown"] = true;
                            key_events[PageDown].key_state = -1;

                        case SDLK_CAPSLOCK:
                            raw_events["CapsLockUpKeyDown"] = true;
                            key_events[CapsLock].key_state = -1;

                        case SDLK_a:
                            raw_events["AKeyDown"] = true;
                            key_events[A].key_state = -1;
                        case SDLK_s:
                            raw_events["SKeyDown"] = true;
                            key_events[S].key_state = -1;
                        case SDLK_d:
                            raw_events["DKeyDown"] = true;
                            key_events[D].key_state = -1;
                        case SDLK_f:
                            raw_events["FKeyDown"] = true;
                            key_events[F].key_state = -1;
                        case SDLK_g:
                            raw_events["GKeyDown"] = true;
                            key_events[G].key_state = -1;
                        case SDLK_h:
                            raw_events["TabKeyDown"] = true;
                            key_events[H].key_state = -1;
                        case SDLK_j:
                            raw_events["JKeyDown"] = true;
                            key_events[J].key_state = -1;
                        case SDLK_k:
                            raw_events["KKeyDown"] = true;
                            key_events[K].key_state = -1;
                        case SDLK_l:
                            raw_events["LKeyDown"] = true;
                            key_events[L].key_state = -1;

                        case SDLK_SEMICOLON:
                            raw_events["SemicolonKeyDown"] = true;
                            key_events[Semicolon].key_state = -1;
                        case SDLK_QUOTE:
                            raw_events["QuoteKeyDown"] = true;
                            key_events[Quote].key_state = -1;
                        case SDLK_RETURN:
                            raw_events["ReturnKeyDown"] = true;
                            key_events[Return].key_state = -1;

                        case SDLK_LSHIFT:
                            raw_events["LeftShiftKeyDown"] = true;
                            key_events[LeftShift].key_state = -1;

                        case SDLK_z:
                            raw_events["ZKeyDown"] = true;
                            key_events[Z].key_state = -1;
                        case SDLK_x:
                            raw_events["XKeyDown"] = true;
                            key_events[X].key_state = -1;
                        case SDLK_c:
                            raw_events["CKeyDown"] = true;
                            key_events[C].key_state = -1;
                        case SDLK_v:
                            raw_events["VKeyDown"] = true;
                            key_events[V].key_state = -1;
                        case SDLK_b:
                            raw_events["BKeyDown"] = true;
                            key_events[B].key_state = -1;
                        case SDLK_n:
                            raw_events["NKeyDown"] = true;
                            key_events[N].key_state = -1;
                        case SDLK_m:
                            raw_events["MKeyDown"] = true;
                            key_events[M].key_state = -1;

                        case SDLK_COMMA:
                            raw_events["CommaKeyDown"] = true;
                            key_events[Comma].key_state = -1;
                        case SDLK_PERIOD:
                            raw_events["PeriodKeyDown"] = true;
                            key_events[Period].key_state = -1;
                        case SDLK_SLASH:
                            raw_events["SlashKeyDown"] = true;
                            key_events[Slash].key_state = -1;
                        case SDLK_RSHIFT:
                            raw_events["RightShiftKeyDown"] = true;
                            key_events[RightShift].key_state = -1;

                        case SDLK_UP:
                            raw_events["UpKeyDown"] = true;
                            key_events[UpArrow].key_state = -1;

                        case SDLK_LCTRL:
                            raw_events["LeftControlKeyDown"] = true;
                            key_events[LeftControl].key_state = -1;
                        case SDLK_LGUI:
                            raw_events["LeftGUIKeyDown"] = true;
                            key_events[LeftMeta].key_state = -1;
                        case SDLK_LALT:
                            raw_events["LeftAltKeyDown"] = true;
                            key_events[LeftAlt].key_state = -1;
                        case SDLK_SPACE:
                            raw_events["SpaceKeyDown"] = true;
                            key_events[Space].key_state = -1;
                        case SDLK_RALT:
                            raw_events["RightAltKeyDown"] = true;
                            key_events[RightAlt].key_state = -1;
                        case SDLK_RCTRL:
                            raw_events["RightControlKeyDown"] = true;
                            key_events[RightControl].key_state = -1;

                        case SDLK_LEFT:
                            raw_events["LeftKeyDown"] = true;
                            key_events[LeftArrow].key_state = -1;
                        case SDLK_DOWN:
                            raw_events["DownKeyDown"] = true;
                            key_events[DownArrow].key_state = -1;
                        case SDLK_RIGHT:
                            raw_events["RightKeyDown"] = true;
                            key_events[RightArrow].key_state = -1;
                    }
                case SDL_KEYUP:
                    raw_events["KeyUp"] = true;
                    switch (sdl_event.key.keysym.sym)
                    {
                        case SDLK_ESCAPE:
                            raw_events["EscapeKeyUp"] = true;
                            key_events[Escape].key_state = 1;

                        case SDLK_F1:
                            raw_events["F1KeyUp"] = true;
                            key_events[F1].key_state = 1;
                        case SDLK_F2:
                            raw_events["F2KeyUp"] = true;
                            key_events[F2].key_state = 1;
                        case SDLK_F3:
                            raw_events["F3KeyUp"] = true;
                            key_events[F3].key_state = 1;
                        case SDLK_F4:
                            raw_events["F4KeyUp"] = true;
                            key_events[F4].key_state = 1;
                        case SDLK_F5:
                            raw_events["F5KeyUp"] = true;
                            key_events[F5].key_state = 1;
                        case SDLK_F6:
                            raw_events["F6KeyUp"] = true;
                            key_events[F6].key_state = 1;
                        case SDLK_F7:
                            raw_events["F7KeyUp"] = true;
                            key_events[F7].key_state = 1;
                        case SDLK_F8:
                            raw_events["F8KeyUp"] = true;
                            key_events[F8].key_state = 1;
                        case SDLK_F9:
                            raw_events["F9KeyUp"] = true;
                            key_events[F9].key_state = 1;
                        case SDLK_F10:
                            raw_events["F10KeyUp"] = true;
                            key_events[F10].key_state = 1;
                        case SDLK_F11:
                            raw_events["F11KeyUp"] = true;
                            key_events[F11].key_state = 1;
                        case SDLK_F12:
                            raw_events["F12KeyUp"] = true;
                            key_events[F12].key_state = 1;

                        case SDLK_PRINTSCREEN:
                            raw_events["PrintScreenKeyUp"] = true;
                            key_events[Print].key_state = 1;
                        case SDLK_SCROLLLOCK:
                            raw_events["ScrollLockKeyUp"] = true;
                            key_events[ScrollLock].key_state = 1;
                        case SDLK_PAUSE:
                            raw_events["PauseKeyUp"] = true;
                            key_events[Pause].key_state = 1;

                        case SDLK_BACKQUOTE:
                            raw_events["BackQuoteKeyUp"] = true;
                            key_events[BackQuote].key_state = 1;

                        case SDLK_1:
                            raw_events["1KeyUp"] = true;
                            key_events[ONE].key_state = 1;
                        case SDLK_2:
                            raw_events["2KeyUp"] = true;
                            key_events[TWO].key_state = 1;
                        case SDLK_3:
                            raw_events["3KeyUp"] = true;
                            key_events[THREE].key_state = 1;
                        case SDLK_4:
                            raw_events["4KeyUp"] = true;
                            key_events[FOUR].key_state = 1;
                        case SDLK_5:
                            raw_events["5KeyUp"] = true;
                            key_events[FIVE].key_state = 1;
                        case SDLK_6:
                            raw_events["6KeyUp"] = true;
                            key_events[SIX].key_state = 1;
                        case SDLK_7:
                            raw_events["7KeyUp"] = true;
                            key_events[SEVEN].key_state = 1;
                        case SDLK_8:
                            raw_events["8KeyUp"] = true;
                            key_events[EIGHT].key_state = 1;
                        case SDLK_9:
                            raw_events["9KeyUp"] = true;
                            key_events[NINE].key_state = 1;
                        case SDLK_0:
                            raw_events["0KeyUp"] = true;
                            key_events[ZERO].key_state = 1;

                        case SDLK_MINUS:
                            raw_events["MinusKeyUp"] = true;
                            key_events[Minus].key_state = 1;
                        case SDLK_PLUS:
                            raw_events["PlusKeyUp"] = true;
                            key_events[Plus].key_state = 1;
                        case SDLK_BACKSPACE:
                            raw_events["BackSpaceKeyUp"] = true;
                            key_events[Backspace].key_state = 1;

                        case SDLK_INSERT:
                            raw_events["InsertKeyUp"] = true;
                            key_events[Insert].key_state = 1;
                        case SDLK_HOME:
                            raw_events["HomeKeyUp"] = true;
                            key_events[Home].key_state = 1;
                        case SDLK_PAGEUP:
                            raw_events["PageUpKeyUp"] = true;
                            key_events[PageUp].key_state = 1;

                        case SDLK_TAB:
                            raw_events["TabKeyUp"] = true;
                            key_events[Tab].key_state = 1;
                        case SDLK_q:
                            raw_events["QKeyUp"] = true;
                            key_events[Q].key_state = 1;
                        case SDLK_w:
                            raw_events["WKeyUp"] = true;
                            key_events[W].key_state = 1;
                        case SDLK_e:
                            raw_events["EKeyUp"] = true;
                            key_events[E].key_state = 1;
                        case SDLK_r:
                            raw_events["RKeyUp"] = true;
                            key_events[R].key_state = 1;
                        case SDLK_t:
                            raw_events["TKeyUp"] = true;
                            key_events[T].key_state = 1;
                        case SDLK_y:
                            raw_events["YKeyUp"] = true;
                            key_events[Y].key_state = 1;
                        case SDLK_u:
                            raw_events["UKeyUp"] = true;
                            key_events[U].key_state = 1;
                        case SDLK_i:
                            raw_events["IKeyUp"] = true;
                            key_events[I].key_state = 1;
                        case SDLK_o:
                            raw_events["OKeyUp"] = true;
                            key_events[O].key_state = 1;
                        case SDLK_p:
                            raw_events["PKeyUp"] = true;
                            key_events[P].key_state = 1;

                        case SDLK_LEFTBRACKET:
                            raw_events["LeftBracketKeyUp"] = true;
                            key_events[LeftBracket].key_state = 1;
                        case SDLK_RIGHTBRACKET:
                            raw_events["RightBracketKeyUp"] = true;
                            key_events[RightBracket].key_state = 1;
                        case SDLK_BACKSLASH:
                            raw_events["BackslashKeyUp"] = true;
                            key_events[Backslash].key_state = 1;

                        case SDLK_DELETE:
                            raw_events["DeleteTKeyUp"] = true;
                            key_events[Delete].key_state = 1;
                        case SDLK_END:
                            raw_events["EndKeyUp"] = true;
                            key_events[End].key_state = 1;
                        case SDLK_PAGEDOWN:
                            raw_events["PageDownKeyUp"] = true;
                            key_events[PageDown].key_state = 1;

                        case SDLK_CAPSLOCK:
                            raw_events["CapsLockUpKeyUp"] = true;
                            key_events[CapsLock].key_state = 1;

                        case SDLK_a:
                            raw_events["AKeyUp"] = true;
                            key_events[A].key_state = 1;
                        case SDLK_s:
                            raw_events["SKeyUp"] = true;
                            key_events[S].key_state = 1;
                        case SDLK_d:
                            raw_events["DKeyUp"] = true;
                            key_events[D].key_state = 1;
                        case SDLK_f:
                            raw_events["FKeyUp"] = true;
                            key_events[F].key_state = 1;
                        case SDLK_g:
                            raw_events["GKeyUp"] = true;
                            key_events[G].key_state = 1;
                        case SDLK_h:
                            raw_events["TabKeyUp"] = true;
                            key_events[H].key_state = 1;
                        case SDLK_j:
                            raw_events["JKeyUp"] = true;
                            key_events[J].key_state = 1;
                        case SDLK_k:
                            raw_events["KKeyUp"] = true;
                            key_events[K].key_state = 1;
                        case SDLK_l:
                            raw_events["LKeyUp"] = true;
                            key_events[L].key_state = 1;

                        case SDLK_SEMICOLON:
                            raw_events["SemicolonKeyUp"] = true;
                            key_events[Semicolon].key_state = 1;
                        case SDLK_QUOTE:
                            raw_events["QuoteKeyUp"] = true;
                            key_events[Quote].key_state = 1;
                        case SDLK_RETURN:
                            raw_events["ReturnKeyUp"] = true;
                            key_events[Return].key_state = 1;

                        case SDLK_LSHIFT:
                            raw_events["LeftShiftKeyUp"] = true;
                            key_events[LeftShift].key_state = 1;

                        case SDLK_z:
                            raw_events["ZKeyUp"] = true;
                            key_events[Z].key_state = 1;
                        case SDLK_x:
                            raw_events["XKeyUp"] = true;
                            key_events[X].key_state = 1;
                        case SDLK_c:
                            raw_events["CKeyUp"] = true;
                            key_events[C].key_state = 1;
                        case SDLK_v:
                            raw_events["VKeyUp"] = true;
                            key_events[V].key_state = 1;
                        case SDLK_b:
                            raw_events["BKeyUp"] = true;
                            key_events[B].key_state = 1;
                        case SDLK_n:
                            raw_events["NKeyUp"] = true;
                            key_events[N].key_state = 1;
                        case SDLK_m:
                            raw_events["MKeyUp"] = true;
                            key_events[M].key_state = 1;

                        case SDLK_COMMA:
                            raw_events["CommaKeyUp"] = true;
                            key_events[Comma].key_state = 1;
                        case SDLK_PERIOD:
                            raw_events["PeriodKeyUp"] = true;
                            key_events[Period].key_state = 1;
                        case SDLK_SLASH:
                            raw_events["SlashKeyUp"] = true;
                            key_events[Slash].key_state = 1;
                        case SDLK_RSHIFT:
                            raw_events["RightShiftKeyUp"] = true;
                            key_events[RightShift].key_state = 1;

                        case SDLK_UP:
                            raw_events["UpKeyUp"] = true;
                            key_events[UpArrow].key_state = 1;

                        case SDLK_LCTRL:
                            raw_events["LeftControlKeyUp"] = true;
                            key_events[LeftControl].key_state = 1;
                        case SDLK_LGUI:
                            raw_events["LeftGUIKeyUp"] = true;
                            key_events[LeftMeta].key_state = 1;
                        case SDLK_LALT:
                            raw_events["LeftAltKeyUp"] = true;
                            key_events[LeftAlt].key_state = 1;
                        case SDLK_SPACE:
                            raw_events["SpaceKeyUp"] = true;
                            key_events[Space].key_state = 1;
                        case SDLK_RALT:
                            raw_events["RightAltKeyUp"] = true;
                            key_events[RightAlt].key_state = 1;
                        case SDLK_RCTRL:
                            raw_events["RightControlKeyUp"] = true;
                            key_events[RightControl].key_state = 1;

                        case SDLK_LEFT:
                            raw_events["LeftKeyUp"] = true;
                            key_events[LeftArrow].key_state = 1;
                        case SDLK_DOWN:
                            raw_events["DownKeyUp"] = true;
                            key_events[DownArrow].key_state = 1;
                        case SDLK_RIGHT:
                            raw_events["RightKeyUp"] = true;
                            key_events[RightArrow].key_state = 1;
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