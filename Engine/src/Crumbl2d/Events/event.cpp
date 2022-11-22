#include "../cbpch.h"
#include "event.h"
#include <SDL.h>

namespace Crumbl2D
{
    void EventHandler::PollEvents()
    {
        SDL_Event sdl_event;

        key_events.empty();
        while (SDL_PollEvent(&sdl_event))
        {
            switch(sdl_event.type)
            {
                case SDL_QUIT:
                    events[WindowClose].event_state = true;
                case SDL_WINDOWEVENT:
                    switch(sdl_event.window.event)
                    {
                        case SDL_WINDOWEVENT_RESIZED:
                            events[WindowResize].event_state = true;
                        case SDL_WINDOWEVENT_FOCUS_GAINED:
                            events[WindowFocus].event_state = true;
                        case SDL_WINDOWEVENT_FOCUS_LOST:
                            events[WindowLostFocus].event_state = true;
                        case SDL_WINDOWEVENT_MOVED:
                            events[WindowMoved].event_state = true;
                    }
                case SDL_MOUSEMOTION:
                    events[MouseMotion].event_state = true;
                case SDL_MOUSEBUTTONDOWN:
                    switch (sdl_event.button.button)
                    {
                        case SDL_BUTTON_LEFT:
                            key_events[Mouse0].key_state = -1;
                        case SDL_BUTTON_RIGHT:
                            key_events[Mouse1].key_state = -1;
                        case SDL_BUTTON_MIDDLE:
                            key_events[Mouse2].key_state = -1;
                        case SDL_BUTTON(3):
                            key_events[Mouse3].key_state = -1;
                        case SDL_BUTTON(4):
                            key_events[Mouse4].key_state = -1;
                    }
                case SDL_MOUSEBUTTONUP:
                    switch (sdl_event.button.button)
                    {
                        case SDL_BUTTON_LEFT:
                            key_events[Mouse0].key_state = 1;
                        case SDL_BUTTON_RIGHT:
                            key_events[Mouse1].key_state = 1;
                        case SDL_BUTTON_MIDDLE:
                            key_events[Mouse2].key_state = 1;
                        case SDL_BUTTON(3):
                            key_events[Mouse3].key_state = 1;
                        case SDL_BUTTON(4):
                            key_events[Mouse4].key_state = 1;
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
                        case SDLK_F13:
                            key_events[F13].key_state = -1;
                        case SDLK_F14:
                            key_events[F14].key_state = -1;
                        case SDLK_F15:
                            key_events[F15].key_state = -1;

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
                        case SDLK_RGUI:
                            key_events[RightMeta].key_state = -1;
                        case SDLK_RCTRL:
                            key_events[RightControl].key_state = -1;

                        case SDLK_LEFT:
                            key_events[LeftArrow].key_state = -1;
                        case SDLK_DOWN:
                            key_events[DownArrow].key_state = -1;
                        case SDLK_RIGHT:
                            key_events[RightArrow].key_state = -1;

                        case SDLK_CLEAR:
                            key_events[Clear].key_state = -1;
                        case SDLK_KP_0:
                            key_events[Keypad0].key_state = -1;
                        case SDLK_KP_1:
                            key_events[Keypad1].key_state = -1;
                        case SDLK_KP_2:
                            key_events[Keypad2].key_state = -1;
                        case SDLK_KP_3:
                            key_events[Keypad3].key_state = -1;
                        case SDLK_KP_4:
                            key_events[Keypad4].key_state = -1;
                        case SDLK_KP_5:
                            key_events[Keypad5].key_state = -1;
                        case SDLK_KP_6:
                            key_events[Keypad6].key_state = -1;
                        case SDLK_KP_7:
                            key_events[Keypad7].key_state = -1;
                        case SDLK_KP_8:
                            key_events[Keypad8].key_state = -1;
                        case SDLK_KP_9:
                            key_events[Keypad9].key_state = -1;

                        case SDLK_KP_PERIOD:
                            key_events[KeypadPeriod].key_state = -1;
                        case SDLK_KP_DIVIDE:
                            key_events[KeypadDivide].key_state = -1;
                        case SDLK_KP_MULTIPLY:
                            key_events[KeypadMultiply].key_state = -1;
                        case SDLK_KP_MINUS:
                            key_events[KeypadMinus].key_state = -1;
                        case SDLK_KP_PLUS:
                            key_events[KeypadPlus].key_state = -1;
                        case SDLK_KP_ENTER:
                            key_events[KeypadEnter].key_state = -1;
                        case SDLK_KP_EQUALS:
                            key_events[KeypadEquals].key_state = -1;

                        case SDLK_EXCLAIM:
                            key_events[Exclaim].key_state = -1;
                        case SDLK_QUOTEDBL:
                            key_events[DoubleQuote].key_state = -1;
                        case SDLK_HASH:
                            key_events[Hash].key_state = -1;
                        case SDLK_DOLLAR:
                            key_events[Dollar].key_state = -1;
                        case SDLK_PERCENT:
                            key_events[Percent].key_state = -1;
                        case SDLK_AMPERSAND:
                            key_events[Ampersand].key_state = -1;
                        case SDLK_LEFTPAREN:
                            key_events[LeftParen].key_state = -1;
                        case SDLK_RIGHTPAREN:
                            key_events[RightParen].key_state = -1;
                        case SDLK_ASTERISK:
                            key_events[Asterisk].key_state = -1;
                        case SDLK_COLON:
                            key_events[Colon].key_state = -1;
                        case SDLK_LESS:
                            key_events[Less].key_state = -1;
                        case SDLK_EQUALS:
                            key_events[Equals].key_state = -1;
                        case SDLK_GREATER:
                            key_events[Greater].key_state = -1;
                        case SDLK_QUESTION:
                            key_events[Question].key_state = -1;
                        case SDLK_AT:
                            key_events[At].key_state = -1;
                        case SDLK_UNDERSCORE:
                            key_events[Underscore].key_state = -1;;

                        case SDLK_NUMLOCKCLEAR:
                            key_events[NumLock].key_state = -1;
                        case SDLK_HELP:
                            key_events[Help].key_state = -1;
                        case SDLK_SYSREQ:
                            key_events[SysReq].key_state = -1;
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
                        case SDLK_F13:
                            key_events[F13].key_state = 1;
                        case SDLK_F14:
                            key_events[F14].key_state = 1;
                        case SDLK_F15:
                            key_events[F15].key_state = 1;

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
                        case SDLK_RGUI:
                            key_events[RightMeta].key_state = 1;
                        case SDLK_RCTRL:
                            key_events[RightControl].key_state = 1;

                        case SDLK_LEFT:
                            key_events[LeftArrow].key_state = 1;
                        case SDLK_DOWN:
                            key_events[DownArrow].key_state = 1;
                        case SDLK_RIGHT:
                            key_events[RightArrow].key_state = 1;

                        case SDLK_CLEAR:
                            key_events[Clear].key_state = 1;
                        case SDLK_KP_0:
                            key_events[Keypad0].key_state = 1;
                        case SDLK_KP_1:
                            key_events[Keypad1].key_state = 1;
                        case SDLK_KP_2:
                            key_events[Keypad2].key_state = 1;
                        case SDLK_KP_3:
                            key_events[Keypad3].key_state = 1;
                        case SDLK_KP_4:
                            key_events[Keypad4].key_state = 1;
                        case SDLK_KP_5:
                            key_events[Keypad5].key_state = 1;
                        case SDLK_KP_6:
                            key_events[Keypad6].key_state = 1;
                        case SDLK_KP_7:
                            key_events[Keypad7].key_state = 1;
                        case SDLK_KP_8:
                            key_events[Keypad8].key_state = 1;
                        case SDLK_KP_9:
                            key_events[Keypad9].key_state = 1;

                        case SDLK_KP_PERIOD:
                            key_events[KeypadPeriod].key_state = 1;
                        case SDLK_KP_DIVIDE:
                            key_events[KeypadDivide].key_state = 1;
                        case SDLK_KP_MULTIPLY:
                            key_events[KeypadMultiply].key_state = 1;
                        case SDLK_KP_MINUS:
                            key_events[KeypadMinus].key_state = 1;
                        case SDLK_KP_PLUS:
                            key_events[KeypadPlus].key_state = 1;
                        case SDLK_KP_ENTER:
                            key_events[KeypadEnter].key_state = 1;
                        case SDLK_KP_EQUALS:
                            key_events[KeypadEquals].key_state = 1;

                        case SDLK_EXCLAIM:
                            key_events[Exclaim].key_state = 1;
                        case SDLK_QUOTEDBL:
                            key_events[DoubleQuote].key_state = 1;
                        case SDLK_HASH:
                            key_events[Hash].key_state = 1;
                        case SDLK_DOLLAR:
                            key_events[Dollar].key_state = 1;
                        case SDLK_PERCENT:
                            key_events[Percent].key_state = 1;
                        case SDLK_AMPERSAND:
                            key_events[Ampersand].key_state = 1;
                        case SDLK_LEFTPAREN:
                            key_events[LeftParen].key_state = 1;
                        case SDLK_RIGHTPAREN:
                            key_events[RightParen].key_state = 1;
                        case SDLK_ASTERISK:
                            key_events[Asterisk].key_state = 1;
                        case SDLK_COLON:
                            key_events[Colon].key_state = 1;
                        case SDLK_LESS:
                            key_events[Less].key_state = 1;
                        case SDLK_EQUALS:
                            key_events[Equals].key_state = 1;
                        case SDLK_GREATER:
                            key_events[Greater].key_state = 1;
                        case SDLK_QUESTION:
                            key_events[Question].key_state = 1;
                        case SDLK_AT:
                            key_events[At].key_state = 1;
                        case SDLK_UNDERSCORE:
                            key_events[Underscore].key_state = 1;

                        case SDLK_NUMLOCKCLEAR:
                            key_events[NumLock].key_state = 1;
                        case SDLK_HELP:
                            key_events[Help].key_state = 1;
                        case SDLK_SYSREQ:
                            key_events[SysReq].key_state = 1;
                    }
            }
        }
    }

    bool EventHandler::GetKey(Keycode p_keycode)
    {
        if (key_events[p_keycode].key_state != 0)
        {
            return true;
        }
    }

    bool EventHandler::GetKeyDown(Keycode p_keycode)
    {
        if (key_events[p_keycode].key_state == -1)
        {
            key_events[p_keycode].key_state = 0;
            return true;
        }
    }

    bool EventHandler::GetKeyUp(Keycode p_keycode)
    {
        if (key_events[p_keycode].key_state == 1)
        {
            key_events[p_keycode].key_state = 0;
            return true;
        }
    }

    bool EventHandler::GetEvent(Eventcode p_eventcode)
    {
        if (events[p_eventcode].event_state == true)
        {
            events[p_eventcode].event_state = false;
            return true;
        }
    }

    void EventHandler::CreateEvent(Eventcode p_eventcode)
    {
        events[p_eventcode].event_state = true;
    }
}