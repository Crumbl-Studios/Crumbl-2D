#include "../cbpch.h"
#include "input.h"

namespace crumbl2d
{
    void input::pollEvents()
    {
        SDL_Event sdl_event;

        std::vector<event> n_events;
        key_events.empty();
        while (SDL_PollEvent(&sdl_event))
        {
            switch(sdl_event.type)
            {
                case SDL_QUIT:
                    1;
                case SDL_MOUSEMOTION:
                    1;
                case SDL_MOUSEBUTTONDOWN:
                    switch (sdl_event.button.button)
                    {
                        case SDL_BUTTON_LEFT:
                            key_events[Mouse0].key_state = -1;
                        case SDL_BUTTON_RIGHT:
                            key_events[Mouse1].key_state = -1;
                        case SDL_BUTTON_MIDDLE:
                            key_events[Mouse2].key_state = -1;
                    }
                case SDL_MOUSEBUTTONUP:
                    switch (sdl_event.button.button)
                    {
                        case SDL_BUTTON_LEFT:
                            key_events[Mouse1].key_state = 1;
                        case SDL_BUTTON_MIDDLE:
                            key_events[Mouse1].key_state = 1;
                        case SDL_BUTTON_RIGHT:
                            key_events[Mouse2].key_state = 1;
                    }
                case SDL_KEYDOWN:
                    switch (sdl_event.key.keysym.sym)
                    {
                        case SDLK_ESCAPE:
                            key_events[Escape].key_state = -1;

                        case SDLK_F1:
                            key_events[F1].key_state = -1;
                        case SDLK_F2:
                            key_events[F2].key_state = -1;
                        case SDLK_F3:
                            key_events[F3].key_state = -1;
                        case SDLK_F4:
                            key_events[F4].key_state = -1;
                        case SDLK_F5:
                            key_events[F5].key_state = -1;
                        case SDLK_F6:
                            key_events[F6].key_state = -1;
                        case SDLK_F7:
                            key_events[F7].key_state = -1;
                        case SDLK_F8:
                            key_events[F8].key_state = -1;
                        case SDLK_F9:
                            key_events[F9].key_state = -1;
                        case SDLK_F10:
                            key_events[F10].key_state = -1;
                        case SDLK_F11:
                            key_events[F11].key_state = -1;
                        case SDLK_F12:
                            key_events[F12].key_state = -1;

                        case SDLK_PRINTSCREEN:
                            key_events[Print].key_state = -1;
                        case SDLK_SCROLLLOCK:
                            key_events[ScrollLock].key_state = -1;
                        case SDLK_PAUSE:
                            key_events[Pause].key_state = -1;

                        case SDLK_BACKQUOTE:
                            key_events[BackQuote].key_state = -1;

                        case SDLK_1:
                            key_events[ONE].key_state = -1;
                        case SDLK_2:
                            key_events[TWO].key_state = -1;
                        case SDLK_3:
                            key_events[THREE].key_state = -1;
                        case SDLK_4:
                            key_events[FOUR].key_state = -1;
                        case SDLK_5:
                            key_events[FIVE].key_state = -1;
                        case SDLK_6:
                            key_events[SIX].key_state = -1;
                        case SDLK_7:
                            key_events[SEVEN].key_state = -1;
                        case SDLK_8:
                            key_events[EIGHT].key_state = -1;
                        case SDLK_9:
                            key_events[NINE].key_state = -1;
                        case SDLK_0:
                            key_events[ZERO].key_state = -1;

                        case SDLK_MINUS:
                            key_events[Minus].key_state = -1;
                        case SDLK_PLUS:
                            key_events[Plus].key_state = -1;
                        case SDLK_BACKSPACE:
                            key_events[Backspace].key_state = -1;

                        case SDLK_INSERT:
                            key_events[Insert].key_state = -1;
                        case SDLK_HOME:
                            key_events[Home].key_state = -1;
                        case SDLK_PAGEUP:
                            key_events[PageUp].key_state = -1;

                        case SDLK_TAB:
                            key_events[Tab].key_state = -1;
                        case SDLK_q:
                            key_events[Q].key_state = -1;
                        case SDLK_w:
                            key_events[W].key_state = -1;
                        case SDLK_e:
                            key_events[E].key_state = -1;
                        case SDLK_r:
                            key_events[R].key_state = -1;
                        case SDLK_t:
                            key_events[T].key_state = -1;
                        case SDLK_y:
                            key_events[Y].key_state = -1;
                        case SDLK_u:
                            key_events[U].key_state = -1;
                        case SDLK_i:
                            key_events[I].key_state = -1;
                        case SDLK_o:
                            key_events[O].key_state = -1;
                        case SDLK_p:
                            key_events[P].key_state = -1;

                        case SDLK_LEFTBRACKET:
                            key_events[LeftBracket].key_state = -1;
                        case SDLK_RIGHTBRACKET:
                            key_events[RightBracket].key_state = -1;
                        case SDLK_BACKSLASH:
                            key_events[Backslash].key_state = -1;

                        case SDLK_DELETE:
                            key_events[Delete].key_state = -1;
                        case SDLK_END:
                            key_events[End].key_state = -1;
                        case SDLK_PAGEDOWN:
                            key_events[PageDown].key_state = -1;

                        case SDLK_CAPSLOCK:
                            key_events[CapsLock].key_state = -1;

                        case SDLK_a:
                            key_events[A].key_state = -1;
                        case SDLK_s:
                            key_events[S].key_state = -1;
                        case SDLK_d:
                            key_events[D].key_state = -1;
                        case SDLK_f:
                            key_events[F].key_state = -1;
                        case SDLK_g:
                            key_events[G].key_state = -1;
                        case SDLK_h:
                            key_events[H].key_state = -1;
                        case SDLK_j:
                            key_events[J].key_state = -1;
                        case SDLK_k:
                            key_events[K].key_state = -1;
                        case SDLK_l:
                            key_events[L].key_state = -1;

                        case SDLK_SEMICOLON:
                            key_events[Semicolon].key_state = -1;
                        case SDLK_QUOTE:
                            key_events[Quote].key_state = -1;
                        case SDLK_RETURN:
                            key_events[Return].key_state = -1;

                        case SDLK_LSHIFT:
                            key_events[LeftShift].key_state = -1;

                        case SDLK_z:
                            key_events[Z].key_state = -1;
                        case SDLK_x:
                            key_events[X].key_state = -1;
                        case SDLK_c:
                            key_events[C].key_state = -1;
                        case SDLK_v:
                            key_events[V].key_state = -1;
                        case SDLK_b:
                            key_events[B].key_state = -1;
                        case SDLK_n:
                            key_events[N].key_state = -1;
                        case SDLK_m:
                            key_events[M].key_state = -1;

                        case SDLK_COMMA:
                            key_events[Comma].key_state = -1;
                        case SDLK_PERIOD:
                            key_events[Period].key_state = -1;
                        case SDLK_SLASH:
                            key_events[Slash].key_state = -1;
                        case SDLK_RSHIFT:
                            key_events[RightShift].key_state = -1;

                        case SDLK_UP:
                            key_events[UpArrow].key_state = -1;

                        case SDLK_LCTRL:
                            key_events[LeftControl].key_state = -1;
                        case SDLK_LGUI:
                            key_events[LeftMeta].key_state = -1;
                        case SDLK_LALT:
                            key_events[LeftAlt].key_state = -1;
                        case SDLK_SPACE:
                            key_events[Space].key_state = -1;
                        case SDLK_RALT:
                            key_events[RightAlt].key_state = -1;
                        case SDLK_RCTRL:
                            key_events[RightControl].key_state = -1;

                        case SDLK_LEFT:
                            key_events[LeftArrow].key_state = -1;
                        case SDLK_DOWN:
                            key_events[DownArrow].key_state = -1;
                        case SDLK_RIGHT:
                            key_events[RightArrow].key_state = -1;
                    }
                case SDL_KEYUP:
                    switch (sdl_event.key.keysym.sym)
                    {
                        case SDLK_ESCAPE:
                            key_events[Escape].key_state = 1;

                        case SDLK_F1:
                            key_events[F1].key_state = 1;
                        case SDLK_F2:
                            key_events[F2].key_state = 1;
                        case SDLK_F3:
                            key_events[F3].key_state = 1;
                        case SDLK_F4:
                            key_events[F4].key_state = 1;
                        case SDLK_F5:
                            key_events[F5].key_state = 1;
                        case SDLK_F6:
                            key_events[F6].key_state = 1;
                        case SDLK_F7:
                            key_events[F7].key_state = 1;
                        case SDLK_F8:
                            key_events[F8].key_state = 1;
                        case SDLK_F9:
                            key_events[F9].key_state = 1;
                        case SDLK_F10:
                            key_events[F10].key_state = 1;
                        case SDLK_F11:
                            key_events[F11].key_state = 1;
                        case SDLK_F12:
                            key_events[F12].key_state = 1;

                        case SDLK_PRINTSCREEN:
                            key_events[Print].key_state = 1;
                        case SDLK_SCROLLLOCK:
                            key_events[ScrollLock].key_state = 1;
                        case SDLK_PAUSE:
                            key_events[Pause].key_state = 1;

                        case SDLK_BACKQUOTE:
                            key_events[BackQuote].key_state = 1;

                        case SDLK_1:
                            key_events[ONE].key_state = 1;
                        case SDLK_2:
                            key_events[TWO].key_state = 1;
                        case SDLK_3:
                            key_events[THREE].key_state = 1;
                        case SDLK_4:
                            key_events[FOUR].key_state = 1;
                        case SDLK_5:
                            key_events[FIVE].key_state = 1;
                        case SDLK_6:
                            key_events[SIX].key_state = 1;
                        case SDLK_7:
                            key_events[SEVEN].key_state = 1;
                        case SDLK_8:
                            key_events[EIGHT].key_state = 1;
                        case SDLK_9:
                            key_events[NINE].key_state = 1;
                        case SDLK_0:
                            key_events[ZERO].key_state = 1;

                        case SDLK_MINUS:
                            key_events[Minus].key_state = 1;
                        case SDLK_PLUS:
                            key_events[Plus].key_state = 1;
                        case SDLK_BACKSPACE:
                            key_events[Backspace].key_state = 1;

                        case SDLK_INSERT:
                            key_events[Insert].key_state = 1;
                        case SDLK_HOME:
                            key_events[Home].key_state = 1;
                        case SDLK_PAGEUP:
                            key_events[PageUp].key_state = 1;

                        case SDLK_TAB:
                            key_events[Tab].key_state = 1;
                        case SDLK_q:
                            key_events[Q].key_state = 1;
                        case SDLK_w:
                            key_events[W].key_state = 1;
                        case SDLK_e:
                            key_events[E].key_state = 1;
                        case SDLK_r:
                            key_events[R].key_state = 1;
                        case SDLK_t:
                            key_events[T].key_state = 1;
                        case SDLK_y:
                            key_events[Y].key_state = 1;
                        case SDLK_u:
                            key_events[U].key_state = 1;
                        case SDLK_i:
                            key_events[I].key_state = 1;
                        case SDLK_o:
                            key_events[O].key_state = 1;
                        case SDLK_p:
                            key_events[P].key_state = 1;

                        case SDLK_LEFTBRACKET:
                            key_events[LeftBracket].key_state = 1;
                        case SDLK_RIGHTBRACKET:
                            key_events[RightBracket].key_state = 1;
                        case SDLK_BACKSLASH:
                            key_events[Backslash].key_state = 1;

                        case SDLK_DELETE:
                            key_events[Delete].key_state = 1;
                        case SDLK_END:
                            key_events[End].key_state = 1;
                        case SDLK_PAGEDOWN:
                            key_events[PageDown].key_state = 1;

                        case SDLK_CAPSLOCK:
                            key_events[CapsLock].key_state = 1;

                        case SDLK_a:
                            key_events[A].key_state = 1;
                        case SDLK_s:
                            key_events[S].key_state = 1;
                        case SDLK_d:
                            key_events[D].key_state = 1;
                        case SDLK_f:
                            key_events[F].key_state = 1;
                        case SDLK_g:
                            key_events[G].key_state = 1;
                        case SDLK_h:
                            key_events[H].key_state = 1;
                        case SDLK_j:
                            key_events[J].key_state = 1;
                        case SDLK_k:
                            key_events[K].key_state = 1;
                        case SDLK_l:
                            key_events[L].key_state = 1;

                        case SDLK_SEMICOLON:
                            key_events[Semicolon].key_state = 1;
                        case SDLK_QUOTE:
                            key_events[Quote].key_state = 1;
                        case SDLK_RETURN:
                            key_events[Return].key_state = 1;

                        case SDLK_LSHIFT:
                            key_events[LeftShift].key_state = 1;

                        case SDLK_z:
                            key_events[Z].key_state = 1;
                        case SDLK_x:
                            key_events[X].key_state = 1;
                        case SDLK_c:
                            key_events[C].key_state = 1;
                        case SDLK_v:
                            key_events[V].key_state = 1;
                        case SDLK_b:
                            key_events[B].key_state = 1;
                        case SDLK_n:
                            key_events[N].key_state = 1;
                        case SDLK_m:
                            key_events[M].key_state = 1;

                        case SDLK_COMMA:
                            key_events[Comma].key_state = 1;
                        case SDLK_PERIOD:
                            key_events[Period].key_state = 1;
                        case SDLK_SLASH:
                            key_events[Slash].key_state = 1;
                        case SDLK_RSHIFT:
                            key_events[RightShift].key_state = 1;

                        case SDLK_UP:
                            key_events[UpArrow].key_state = 1;

                        case SDLK_LCTRL:
                            key_events[LeftControl].key_state = 1;
                        case SDLK_LGUI:
                            key_events[LeftMeta].key_state = 1;
                        case SDLK_LALT:
                            key_events[LeftAlt].key_state = 1;
                        case SDLK_SPACE:
                            key_events[Space].key_state = 1;
                        case SDLK_RALT:
                            key_events[RightAlt].key_state = 1;
                        case SDLK_RCTRL:
                            key_events[RightControl].key_state = 1;

                        case SDLK_LEFT:
                            key_events[LeftArrow].key_state = 1;
                        case SDLK_DOWN:
                            key_events[DownArrow].key_state = 1;
                        case SDLK_RIGHT:
                            key_events[RightArrow].key_state = 1;
                    }
            }
        }
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