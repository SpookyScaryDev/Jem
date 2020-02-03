#pragma once

// Copied from SDL_Scancode.h

namespace Jem {
	enum KeyCode {
	    JEM_KEY_UNKNOWN = 0,
	
	    /**
	     *  \name Usage page 0x07
	     *
	     *  These values are from usage page 0x07 (USB keyboard page).
	     */
	    /* @{ */
	
	    JEM_KEY_A = 4,
	    JEM_KEY_B = 5,
	    JEM_KEY_C = 6,
	    JEM_KEY_D = 7,
	    JEM_KEY_E = 8,
	    JEM_KEY_F = 9,
	    JEM_KEY_G = 10,
	    JEM_KEY_H = 11,
	    JEM_KEY_I = 12,
	    JEM_KEY_J = 13,
	    JEM_KEY_K = 14,
	    JEM_KEY_L = 15,
	    JEM_KEY_M = 16,
	    JEM_KEY_N = 17,
	    JEM_KEY_O = 18,
	    JEM_KEY_P = 19,
	    JEM_KEY_Q = 20,
	    JEM_KEY_R = 21,
	    JEM_KEY_S = 22,
	    JEM_KEY_T = 23,
	    JEM_KEY_U = 24,
	    JEM_KEY_V = 25,
	    JEM_KEY_W = 26,
	    JEM_KEY_X = 27,
	    JEM_KEY_Y = 28,
	    JEM_KEY_Z = 29,
	
	    JEM_KEY_1 = 30,
	    JEM_KEY_2 = 31,
	    JEM_KEY_3 = 32,
	    JEM_KEY_4 = 33,
	    JEM_KEY_5 = 34,
	    JEM_KEY_6 = 35,
	    JEM_KEY_7 = 36,
	    JEM_KEY_8 = 37,
	    JEM_KEY_9 = 38,
	    JEM_KEY_0 = 39,
	
	    JEM_KEY_RETURN = 40,
	    JEM_KEY_ESCAPE = 41,
	    JEM_KEY_BACKSPACE = 42,
	    JEM_KEY_TAB = 43,
	    JEM_KEY_SPACE = 44,
	
	    JEM_KEY_MINUS = 45,
	    JEM_KEY_EQUALS = 46,
	    JEM_KEY_LEFTBRACKET = 47,
	    JEM_KEY_RIGHTBRACKET = 48,
	    JEM_KEY_BACKSLASH = 49, /**< Located at the lower left of the return
	                                  *   key on ISO keyboards and at the right end
	                                  *   of the QWERTY row on ANSI keyboards.
	                                  *   Produces REVERSE SOLIDUS (backslash) and
	                                  *   VERTICAL LINE in a US layout, REVERSE
	                                  *   SOLIDUS and VERTICAL LINE in a UK Mac
	                                  *   layout, NUMBER SIGN and TILDE in a UK
	                                  *   Windows layout, DOLLAR SIGN and POUND SIGN
	                                  *   in a Swiss German layout, NUMBER SIGN and
	                                  *   APOSTROPHE in a German layout, GRAVE
	                                  *   ACCENT and POUND SIGN in a French Mac
	                                  *   layout, and ASTERISK and MICRO SIGN in a
	                                  *   French Windows layout.
	                                  */
	    JEM_KEY_NONUSHASH = 50, /**< ISO USB keyboards actually use this code
	                                  *   instead of 49 for the same key, but all
	                                  *   OSes I've seen treat the two codes
	                                  *   identically. So, as an implementor, unless
	                                  *   your keyboard generates both of those
	                                  *   codes and your OS treats them differently,
	                                  *   you should generate JEM_KEY_BACKSLASH
	                                  *   instead of this code. As a user, you
	                                  *   should not rely on this code because SDL
	                                  *   will never generate it with most (all?)
	                                  *   keyboards.
	                                  */
	    JEM_KEY_SEMICOLON = 51,
	    JEM_KEY_APOSTROPHE = 52,
	    JEM_KEY_GRAVE = 53, /**< Located in the top left corner (on both ANSI
	                              *   and ISO keyboards). Produces GRAVE ACCENT and
	                              *   TILDE in a US Windows layout and in US and UK
	                              *   Mac layouts on ANSI keyboards, GRAVE ACCENT
	                              *   and NOT SIGN in a UK Windows layout, SECTION
	                              *   SIGN and PLUS-MINUS SIGN in US and UK Mac
	                              *   layouts on ISO keyboards, SECTION SIGN and
	                              *   DEGREE SIGN in a Swiss German layout (Mac:
	                              *   only on ISO keyboards), CIRCUMFLEX ACCENT and
	                              *   DEGREE SIGN in a German layout (Mac: only on
	                              *   ISO keyboards), SUPERSCRIPT TWO and TILDE in a
	                              *   French Windows layout, COMMERCIAL AT and
	                              *   NUMBER SIGN in a French Mac layout on ISO
	                              *   keyboards, and LESS-THAN SIGN and GREATER-THAN
	                              *   SIGN in a Swiss German, German, or French Mac
	                              *   layout on ANSI keyboards.
	                              */
	    JEM_KEY_COMMA = 54,
	    JEM_KEY_PERIOD = 55,
	    JEM_KEY_SLASH = 56,
	
	    JEM_KEY_CAPSLOCK = 57,
	
	    JEM_KEY_F1 = 58,
	    JEM_KEY_F2 = 59,
	    JEM_KEY_F3 = 60,
	    JEM_KEY_F4 = 61,
	    JEM_KEY_F5 = 62,
	    JEM_KEY_F6 = 63,
	    JEM_KEY_F7 = 64,
	    JEM_KEY_F8 = 65,
	    JEM_KEY_F9 = 66,
	    JEM_KEY_F10 = 67,
	    JEM_KEY_F11 = 68,
	    JEM_KEY_F12 = 69,
	
	    JEM_KEY_PRINTSCREEN = 70,
	    JEM_KEY_SCROLLLOCK = 71,
	    JEM_KEY_PAUSE = 72,
	    JEM_KEY_INSERT = 73, /**< insert on PC, help on some Mac keyboards (but
	                                   does send code 73, not 117) */
	    JEM_KEY_HOME = 74,
	    JEM_KEY_PAGEUP = 75,
	    JEM_KEY_DELETE = 76,
	    JEM_KEY_END = 77,
	    JEM_KEY_PAGEDOWN = 78,
	    JEM_KEY_RIGHT = 79,
	    JEM_KEY_LEFT = 80,
	    JEM_KEY_DOWN = 81,
	    JEM_KEY_UP = 82,
	
	    JEM_KEY_NUMLOCKCLEAR = 83, /**< num lock on PC, clear on Mac keyboards
	                                     */
	    JEM_KEY_KP_DIVIDE = 84,
	    JEM_KEY_KP_MULTIPLY = 85,
	    JEM_KEY_KP_MINUS = 86,
	    JEM_KEY_KP_PLUS = 87,
	    JEM_KEY_KP_ENTER = 88,
	    JEM_KEY_KP_1 = 89,
	    JEM_KEY_KP_2 = 90,
	    JEM_KEY_KP_3 = 91,
	    JEM_KEY_KP_4 = 92,
	    JEM_KEY_KP_5 = 93,
	    JEM_KEY_KP_6 = 94,
	    JEM_KEY_KP_7 = 95,
	    JEM_KEY_KP_8 = 96,
	    JEM_KEY_KP_9 = 97,
	    JEM_KEY_KP_0 = 98,
	    JEM_KEY_KP_PERIOD = 99,
	
	    JEM_KEY_NONUSBACKSLASH = 100, /**< This is the additional key that ISO
	                                        *   keyboards have over ANSI ones,
	                                        *   located between left shift and Y.
	                                        *   Produces GRAVE ACCENT and TILDE in a
	                                        *   US or UK Mac layout, REVERSE SOLIDUS
	                                        *   (backslash) and VERTICAL LINE in a
	                                        *   US or UK Windows layout, and
	                                        *   LESS-THAN SIGN and GREATER-THAN SIGN
	                                        *   in a Swiss German, German, or French
	                                        *   layout. */
	    JEM_KEY_APPLICATION = 101, /**< windows contextual menu, compose */
	    JEM_KEY_POWER = 102, /**< The USB document says this is a status flag,
	                               *   not a physical key - but some Mac keyboards
	                               *   do have a power key. */
	    JEM_KEY_KP_EQUALS = 103,
	    JEM_KEY_F13 = 104,
	    JEM_KEY_F14 = 105,
	    JEM_KEY_F15 = 106,
	    JEM_KEY_F16 = 107,
	    JEM_KEY_F17 = 108,
	    JEM_KEY_F18 = 109,
	    JEM_KEY_F19 = 110,
	    JEM_KEY_F20 = 111,
	    JEM_KEY_F21 = 112,
	    JEM_KEY_F22 = 113,
	    JEM_KEY_F23 = 114,
	    JEM_KEY_F24 = 115,
	    JEM_KEY_EXECUTE = 116,
	    JEM_KEY_HELP = 117,
	    JEM_KEY_MENU = 118,
	    JEM_KEY_SELECT = 119,
	    JEM_KEY_STOP = 120,
	    JEM_KEY_AGAIN = 121,   /**< redo */
	    JEM_KEY_UNDO = 122,
	    JEM_KEY_CUT = 123,
	    JEM_KEY_COPY = 124,
	    JEM_KEY_PASTE = 125,
	    JEM_KEY_FIND = 126,
	    JEM_KEY_MUTE = 127,
	    JEM_KEY_VOLUMEUP = 128,
	    JEM_KEY_VOLUMEDOWN = 129,
	/* not sure whether there's a reason to enable these */
	/*     JEM_KEY_LOCKINGCAPSLOCK = 130,  */
	/*     JEM_KEY_LOCKINGNUMLOCK = 131, */
	/*     JEM_KEY_LOCKINGSCROLLLOCK = 132, */
	    JEM_KEY_KP_COMMA = 133,
	    JEM_KEY_KP_EQUALSAS400 = 134,
	
	    JEM_KEY_INTERNATIONAL1 = 135, /**< used on Asian keyboards, see
	                                            footnotes in USB doc */
	    JEM_KEY_INTERNATIONAL2 = 136,
	    JEM_KEY_INTERNATIONAL3 = 137, /**< Yen */
	    JEM_KEY_INTERNATIONAL4 = 138,
	    JEM_KEY_INTERNATIONAL5 = 139,
	    JEM_KEY_INTERNATIONAL6 = 140,
	    JEM_KEY_INTERNATIONAL7 = 141,
	    JEM_KEY_INTERNATIONAL8 = 142,
	    JEM_KEY_INTERNATIONAL9 = 143,
	    JEM_KEY_LANG1 = 144, /**< Hangul/English toggle */
	    JEM_KEY_LANG2 = 145, /**< Hanja conversion */
	    JEM_KEY_LANG3 = 146, /**< Katakana */
	    JEM_KEY_LANG4 = 147, /**< Hiragana */
	    JEM_KEY_LANG5 = 148, /**< Zenkaku/Hankaku */
	    JEM_KEY_LANG6 = 149, /**< reserved */
	    JEM_KEY_LANG7 = 150, /**< reserved */
	    JEM_KEY_LANG8 = 151, /**< reserved */
	    JEM_KEY_LANG9 = 152, /**< reserved */
	
	    JEM_KEY_ALTERASE = 153, /**< Erase-Eaze */
	    JEM_KEY_SYSREQ = 154,
	    JEM_KEY_CANCEL = 155,
	    JEM_KEY_CLEAR = 156,
	    JEM_KEY_PRIOR = 157,
	    JEM_KEY_RETURN2 = 158,
	    JEM_KEY_SEPARATOR = 159,
	    JEM_KEY_OUT = 160,
	    JEM_KEY_OPER = 161,
	    JEM_KEY_CLEARAGAIN = 162,
	    JEM_KEY_CRSEL = 163,
	    JEM_KEY_EXSEL = 164,
	
	    JEM_KEY_KP_00 = 176,
	    JEM_KEY_KP_000 = 177,
	    JEM_KEY_THOUSANDSSEPARATOR = 178,
	    JEM_KEY_DECIMALSEPARATOR = 179,
	    JEM_KEY_CURRENCYUNIT = 180,
	    JEM_KEY_CURRENCYSUBUNIT = 181,
	    JEM_KEY_KP_LEFTPAREN = 182,
	    JEM_KEY_KP_RIGHTPAREN = 183,
	    JEM_KEY_KP_LEFTBRACE = 184,
	    JEM_KEY_KP_RIGHTBRACE = 185,
	    JEM_KEY_KP_TAB = 186,
	    JEM_KEY_KP_BACKSPACE = 187,
	    JEM_KEY_KP_A = 188,
	    JEM_KEY_KP_B = 189,
	    JEM_KEY_KP_C = 190,
	    JEM_KEY_KP_D = 191,
	    JEM_KEY_KP_E = 192,
	    JEM_KEY_KP_F = 193,
	    JEM_KEY_KP_XOR = 194,
	    JEM_KEY_KP_POWER = 195,
	    JEM_KEY_KP_PERCENT = 196,
	    JEM_KEY_KP_LESS = 197,
	    JEM_KEY_KP_GREATER = 198,
	    JEM_KEY_KP_AMPERSAND = 199,
	    JEM_KEY_KP_DBLAMPERSAND = 200,
	    JEM_KEY_KP_VERTICALBAR = 201,
	    JEM_KEY_KP_DBLVERTICALBAR = 202,
	    JEM_KEY_KP_COLON = 203,
	    JEM_KEY_KP_HASH = 204,
	    JEM_KEY_KP_SPACE = 205,
	    JEM_KEY_KP_AT = 206,
	    JEM_KEY_KP_EXCLAM = 207,
	    JEM_KEY_KP_MEMSTORE = 208,
	    JEM_KEY_KP_MEMRECALL = 209,
	    JEM_KEY_KP_MEMCLEAR = 210,
	    JEM_KEY_KP_MEMADD = 211,
	    JEM_KEY_KP_MEMSUBTRACT = 212,
	    JEM_KEY_KP_MEMMULTIPLY = 213,
	    JEM_KEY_KP_MEMDIVIDE = 214,
	    JEM_KEY_KP_PLUSMINUS = 215,
	    JEM_KEY_KP_CLEAR = 216,
	    JEM_KEY_KP_CLEARENTRY = 217,
	    JEM_KEY_KP_BINARY = 218,
	    JEM_KEY_KP_OCTAL = 219,
	    JEM_KEY_KP_DECIMAL = 220,
	    JEM_KEY_KP_HEXADECIMAL = 221,
	
	    JEM_KEY_LCTRL = 224,
	    JEM_KEY_LSHIFT = 225,
	    JEM_KEY_LALT = 226, /**< alt, option */
	    JEM_KEY_LGUI = 227, /**< windows, command (apple), meta */
	    JEM_KEY_RCTRL = 228,
	    JEM_KEY_RSHIFT = 229,
	    JEM_KEY_RALT = 230, /**< alt gr, option */
	    JEM_KEY_RGUI = 231, /**< windows, command (apple), meta */
	
	    JEM_KEY_MODE = 257,    /**< I'm not sure if this is really not covered
	                                 *   by any of the above, but since there's a
	                                 *   special KMOD_MODE for it I'm adding it here
	                                 */
	
	    /* @} *//* Usage page 0x07 */
	
	    /**
	     *  \name Usage page 0x0C
	     *
	     *  These values are mapped from usage page 0x0C (USB consumer page).
	     */
	    /* @{ */
	
	    JEM_KEY_AUDIONEXT = 258,
	    JEM_KEY_AUDIOPREV = 259,
	    JEM_KEY_AUDIOSTOP = 260,
	    JEM_KEY_AUDIOPLAY = 261,
	    JEM_KEY_AUDIOMUTE = 262,
	    JEM_KEY_MEDIASELECT = 263,
	    JEM_KEY_WWW = 264,
	    JEM_KEY_MAIL = 265,
	    JEM_KEY_CALCULATOR = 266,
	    JEM_KEY_COMPUTER = 267,
	    JEM_KEY_AC_SEARCH = 268,
	    JEM_KEY_AC_HOME = 269,
	    JEM_KEY_AC_BACK = 270,
	    JEM_KEY_AC_FORWARD = 271,
	    JEM_KEY_AC_STOP = 272,
	    JEM_KEY_AC_REFRESH = 273,
	    JEM_KEY_AC_BOOKMARKS = 274,
	
	    /* @} *//* Usage page 0x0C */
	
	    /**
	     *  \name Walther keys
	     *
	     *  These are values that Christian Walther added (for mac keyboard?).
	     */
	    /* @{ */
	
	    JEM_KEY_BRIGHTNESSDOWN = 275,
	    JEM_KEY_BRIGHTNESSUP = 276,
	    JEM_KEY_DISPLAYSWITCH = 277, /**< display mirroring/dual display
	                                           switch, video mode switch */
	    JEM_KEY_KBDILLUMTOGGLE = 278,
	    JEM_KEY_KBDILLUMDOWN = 279,
	    JEM_KEY_KBDILLUMUP = 280,
	    JEM_KEY_EJECT = 281,
	    JEM_KEY_SLEEP = 282,
	
	    JEM_KEY_APP1 = 283,
	    JEM_KEY_APP2 = 284,
	
	    /* @} *//* Walther keys */
	
	    /**
	     *  \name Usage page 0x0C (additional media keys)
	     *
	     *  These values are mapped from usage page 0x0C (USB consumer page).
	     */
	    /* @{ */
	
	    JEM_KEY_AUDIOREWIND = 285,
	    JEM_KEY_AUDIOFASTFORWARD = 286,
	
	    /* @} *//* Usage page 0x0C (additional media keys) */
	
	    /* Add any other keys here. */
	
		JEM_NUM_SCANCODES = 512 /**< not a key, just marks the number of scancodes
	                                 for array bounds */
	};
}