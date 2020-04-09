/// File: Include\Nexus\Keyboard.hpp.
///
/// Summary:  Declares the keyboard class.

#ifndef __NEXUS_KEYBOARD_HPP__
#define __NEXUS_KEYBOARD_HPP__

#include <unordered_map>

namespace Nexus
{
/// Enum: Key
///
/// Summary:  Values that represent keys.
enum class Key : unsigned int
{
  _UNKNOWN = 0x00,
  _BACKSPACE = 0x08,
  _TAB = 0x09,
  _RETURN = 0x0D,
  _ESCAPE = 0x1B,
  _SPACEBAR = 0x20,
  _EXCLAIM = 0x21,
  _QUOTEDBL = 0x22,
  _HASH = 0x23,
  _DOLLAR = 0x24,
  _PERCENT = 0x25,
  _AMPERSAND = 0x26,
  _QUOTE = 0x27,
  _LEFTPAREN = 0x28,
  _RIGHTPAREN = 0x29,
  _ASTERISK = 0x2A,
  _PLUS = 0x2B,
  _COMMA = 0x2C,
  _MINUS = 0x2D,
  _PERIOD = 0x2E,
  _SLASH = 0x2F,
  _0 = 0x30,
  _1 = 0x31,
  _2 = 0x32,
  _3 = 0x33,
  _4 = 0x34,
  _5 = 0x35,
  _6 = 0x36,
  _7 = 0x37,
  _8 = 0x38,
  _9 = 0x39,
  _COLON = 0x3A,
  _SEMICOLON = 0x3B,
  _LESS = 0x3C,
  _EQUALS = 0x3D,
  _GREATER = 0x3E,
  _QUESTION = 0x3F,
  _AT = 0x40,
  _LEFTBRACKET = 0x5B,
  _BACKSLASH = 0x5C,
  _RIGHTBRACKET = 0x5D,
  _CARET = 0x5E,
  _UNDERSCORE = 0x5F,
  _BACKQUOTE = 0x60,
  _A = 0x61,
  _B = 0x62,
  _C = 0x63,
  _D = 0x64,
  _E = 0x65,
  _F = 0x66,
  _G = 0x67,
  _H = 0x68,
  _I = 0x69,
  _J = 0x6A,
  _K = 0x6B,
  _L = 0x6C,
  _M = 0x6D,
  _N = 0x6E,
  _O = 0x6F,
  _P = 0x70,
  _Q = 0x71,
  _R = 0x72,
  _S = 0x73,
  _T = 0x74,
  _U = 0x75,
  _V = 0x76,
  _W = 0x77,
  _X = 0x78,
  _Y = 0x79,
  _Z = 0x7A,
  _DELETE = 0x7F,
  _CAPSLOCK = 0x40000039,
  _F1 = 0x4000003A,
  _F2 = 0x4000003B,
  _F3 = 0x4000003C,
  _F4 = 0x4000003D,
  _F5 = 0x4000003E,
  _F6 = 0x4000003F,
  _F7 = 0x40000040,
  _F8 = 0x40000041,
  _F9 = 0x40000042,
  _F10 = 0x40000043,
  _F11 = 0x40000044,
  _F12 = 0x40000045,
  _PRINTSCREEN = 0x40000046,
  _SCROLLLOCK = 0x40000047,
  _PAUSE = 0x40000048,
  _INSERT = 0x40000049,
  _HOME = 0x4000004A,
  _PAGEUP = 0x4000004B,
  _END = 0x4000004D,
  _PAGEDOWN = 0x4000004E,
  _RIGHT = 0x4000004F,
  _LEFT = 0x40000050,
  _DOWN = 0x40000051,
  _UP = 0x40000052,
  _NUMLOCKCLEAR = 0x40000053,
  _KP_DIVIDE = 0x40000054,
  _KP_MULTIPLY = 0x40000055,
  _KP_MINUS = 0x40000056,
  _KP_PLUS = 0x40000057,
  _KP_ENTER = 0x40000058,
  _KP_1 = 0x40000059,
  _KP_2 = 0x4000005A,
  _KP_3 = 0x4000005B,
  _KP_4 = 0x4000005C,
  _KP_5 = 0x4000005D,
  _KP_6 = 0x4000005E,
  _KP_7 = 0x4000005F,
  _KP_8 = 0x40000060,
  _KP_9 = 0x40000061,
  _KP_0 = 0x40000062,
  _KP_PERIOD = 0x40000063,
  _APPLICATION = 0x40000065,
  _POWER = 0x40000066,
  _KP_EQUALS = 0x40000067,
  _F13 = 0x40000068,
  _F14 = 0x40000069,
  _F15 = 0x4000006A,
  _F16 = 0x4000006B,
  _F17 = 0x4000006C,
  _F18 = 0x4000006D,
  _F19 = 0x4000006E,
  _F20 = 0x4000006F,
  _F21 = 0x40000070,
  _F22 = 0x40000071,
  _F23 = 0x40000072,
  _F24 = 0x40000073,
  _EXECUTE = 0x40000074,
  _HELP = 0x40000075,
  _MENU = 0x40000076,
  _SELECT = 0x40000077,
  _STOP = 0x40000078,
  _AGAIN = 0x40000079,
  _UNDO = 0x4000007A,
  _CUT = 0x4000007B,
  _COPY = 0x4000007C,
  _PASTE = 0x4000007D,
  _FIND = 0x4000007E,
  _MUTE = 0x4000007F,
  _VOLUMEUP = 0x40000080,
  _VOLUMEDOWN = 0x40000081,
  _KP_COMMA = 0x40000085,
  _KP_EQUALSAS400 = 0x40000086,
  _ALTERASE = 0x40000099,
  _SYSREQ = 0x4000009A,
  _CANCEL = 0x4000009B,
  _CLEAR = 0x4000009C,
  _PRIOR = 0x4000009D,
  _RETURN2 = 0x4000009E,
  _SEPARATOR = 0x4000009F,
  _OUTPUT = 0x400000A0,
  _OPER = 0x400000A1,
  _CLEARAGAIN = 0x400000A2,
  _CRSEL = 0x400000A3,
  _EXSEL = 0x400000A4,
  _KP_00 = 0x400000B0,
  _KP_000 = 0x400000B1,
  _THOUSANDSSEPARATOR = 0x400000B2,
  _DECIMALSEPARATOR = 0x400000B3,
  _CURRENCYUNIT = 0x400000B4,
  _CURRENCYSUBUNIT = 0x400000B5,
  _KP_LEFTPAREN = 0x400000B6,
  _KP_RIGHTPAREN = 0x400000B7,
  _KP_LEFTBRACE = 0x400000B8,
  _KP_RIGHTBRACE = 0x400000B9,
  _KP_TAB = 0x400000BA,
  _KP_BACKSPACE = 0x400000BB,
  _KP_A = 0x400000BC,
  _KP_B = 0x400000BD,
  _KP_C = 0x400000BE,
  _KP_D = 0x400000BF,
  _KP_E = 0x400000C0,
  _KP_F = 0x400000C1,
  _KP_XOR = 0x400000C2,
  _KP_POWER = 0x400000C3,
  _KP_PERCENT = 0x400000C4,
  _KP_LESS = 0x400000C5,
  _KP_GREATER = 0x400000C6,
  _KP_AMPERSAND = 0x400000C7,
  _KP_DBLAMPERSAND = 0x400000C8,
  _KP_VERTICALBAR = 0x400000C9,
  _KP_DBLVERTICALBAR = 0x400000CA,
  _KP_COLON = 0x400000CB,
  _KP_HASH = 0x400000CC,
  _KP_SPACE = 0x400000CD,
  _KP_AT = 0x400000CE,
  _KP_EXCLAM = 0x400000CF,
  _KP_MEMSTORE = 0x400000D0,
  _KP_MEMRECALL = 0x400000D1,
  _KP_MEMCLEAR = 0x400000D2,
  _KP_MEMADD = 0x400000D3,
  _KP_MEMSUBTRACT = 0x400000D4,
  _KP_MEMMULTIPLY = 0x400000D5,
  _KP_MEMDIVIDE = 0x400000D6,
  _KP_PLUSMINUS = 0x400000D7,
  _KP_CLEAR = 0x400000D8,
  _KP_CLEARENTRY = 0x400000D9,
  _KP_BINARY = 0x400000DA,
  _KP_OCTAL = 0x400000DB,
  _KP_DECIMAL = 0x400000DC,
  _KP_HEXADECIMAL = 0x400000DD,
  _LCTRL = 0x400000E0,
  _LSHIFT = 0x400000E1,
  _LALT = 0x400000E2,
  _LGUI = 0x400000E3,
  _RCTRL = 0x400000E4,
  _RSHIFT = 0x400000E5,
  _RALT = 0x400000E6,
  _RGUI = 0x400000E7,
  _MODE = 0x40000101,
  _AUDIONEXT = 0x40000102,
  _AUDIOPREV = 0x40000103,
  _AUDIOSTOP = 0x40000104,
  _AUDIOPLAY = 0x40000105,
  _AUDIOMUTE = 0x40000106,
  _MEDIASELECT = 0x40000107,
  _WWW = 0x40000108,
  _MAIL = 0x40000109,
  _CALCULATOR = 0x4000010A,
  _COMPUTER = 0x4000010B,
  _AC_SEARCH = 0x4000010C,
  _AC_HOME = 0x4000010D,
  _AC_BACK = 0x4000010E,
  _AC_FORWARD = 0x4000010F,
  _AC_STOP = 0x40000110,
  _AC_REFRESH = 0x40000111,
  _AC_BOOKMARKS = 0x40000112,
  _BRIGHTNESSDOWN = 0x40000113,
  _BRIGHTNESSUP = 0x40000114,
  _DISPLAYSWITCH = 0x40000115,
  _KBDILLUMTOGGLE = 0x40000116,
  _KBDILLUMDOWN = 0x40000117,
  _KBDILLUMUP = 0x40000118,
  _EJECT = 0x40000119,
  _SLEEP = 0x4000011A
};

/// Class:  Keyboard
///
/// Summary:  Tracks key presses and key releases during runtime.
///
/// Author: jkstpierre
///
/// Date: 3/30/2020
class Keyboard
{
private:
  /// Summary:  The keys.
  std::unordered_map<Key, bool> mKeys;

public:
  /// Function: Keyboard::Keyboard
  ///
  /// Summary:  Default constructor.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 3/30/2020
  Keyboard() = default;

  /// Function: Keyboard::~Keyboard
  ///
  /// Summary:  Destructor.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 3/30/2020
  virtual ~Keyboard() noexcept = default;

public:
  /// Function: Press
  ///
  /// Summary:  Press the given key.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/1/2020
  ///
  /// Parameters:
  /// key -   The key.
  void Press(const Key& key) noexcept;

  /// Function: Release
  ///
  /// Summary:  Releases the given key.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/1/2020
  ///
  /// Parameters:
  /// key -   The key.
  void Release(const Key& key) noexcept;

  /// Function: IsPressed
  ///
  /// Summary:  Is pressed.
  ///
  /// Author: jkstpierre.
  ///
  /// Date: 4/1/2020.
  ///
  /// Parameters:
  /// key -   The key.
  ///
  /// Returns:  A reference to a const bool.
  const bool& IsPressed(const Key& key) const noexcept;
};
}

#endif

// End of Include\Nexus\Keyboard.hpp
