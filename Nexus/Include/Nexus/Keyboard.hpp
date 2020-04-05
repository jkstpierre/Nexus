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
  UNKNOWN = 0x00,
  BACKSPACE = 0x08,
  TAB = 0x09,
  RETURN = 0x0D,
  ESCAPE = 0x1B,
  SPACE = 0x20,
  EXCLAIM = 0x21,
  QUOTEDBL = 0x22,
  HASH = 0x23,
  DOLLAR = 0x24,
  PERCENT = 0x25,
  AMPERSAND = 0x26,
  QUOTE = 0x27,
  LEFTPAREN = 0x28,
  RIGHTPAREN = 0x29,
  ASTERISK = 0x2A,
  PLUS = 0x2B,
  COMMA = 0x2C,
  MINUS = 0x2D,
  PERIOD = 0x2E,
  SLASH = 0x2F,
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
  COLON = 0x3A,
  SEMICOLON = 0x3B,
  LESS = 0x3C,
  EQUALS = 0x3D,
  GREATER = 0x3E,
  QUESTION = 0x3F,
  AT = 0x40,
  LEFTBRACKET = 0x5B,
  BACKSLASH = 0x5C,
  RIGHTBRACKET = 0x5D,
  CARET = 0x5E,
  UNDERSCORE = 0x5F,
  BACKQUOTE = 0x60,
  A = 0x61,
  B = 0x62,
  C = 0x63,
  D = 0x64,
  E = 0x65,
  F = 0x66,
  G = 0x67,
  H = 0x68,
  I = 0x69,
  J = 0x6A,
  K = 0x6B,
  L = 0x6C,
  M = 0x6D,
  N = 0x6E,
  O = 0x6F,
  P = 0x70,
  Q = 0x71,
  R = 0x72,
  S = 0x73,
  T = 0x74,
  U = 0x75,
  V = 0x76,
  W = 0x77,
  X = 0x78,
  Y = 0x79,
  Z = 0x7A,
  DEL = 0x7F,
  CAPSLOCK = 0x40000039,
  F1 = 0x4000003A,
  F2 = 0x4000003B,
  F3 = 0x4000003C,
  F4 = 0x4000003D,
  F5 = 0x4000003E,
  F6 = 0x4000003F,
  F7 = 0x40000040,
  F8 = 0x40000041,
  F9 = 0x40000042,
  F10 = 0x40000043,
  F11 = 0x40000044,
  F12 = 0x40000045,
  PRINTSCREEN = 0x40000046,
  SCROLLLOCK = 0x40000047,
  PAUSE = 0x40000048,
  INSERT = 0x40000049,
  HOME = 0x4000004A,
  PAGEUP = 0x4000004B,
  END = 0x4000004D,
  PAGEDOWN = 0x4000004E,
  RIGHT = 0x4000004F,
  LEFT = 0x40000050,
  DOWN = 0x40000051,
  UP = 0x40000052,
  NUMLOCKCLEAR = 0x40000053,
  KP_DIVIDE = 0x40000054,
  KP_MULTIPLY = 0x40000055,
  KP_MINUS = 0x40000056,
  KP_PLUS = 0x40000057,
  KP_ENTER = 0x40000058,
  KP_1 = 0x40000059,
  KP_2 = 0x4000005A,
  KP_3 = 0x4000005B,
  KP_4 = 0x4000005C,
  KP_5 = 0x4000005D,
  KP_6 = 0x4000005E,
  KP_7 = 0x4000005F,
  KP_8 = 0x40000060,
  KP_9 = 0x40000061,
  KP_0 = 0x40000062,
  KP_PERIOD = 0x40000063,
  APPLICATION = 0x40000065,
  POWER = 0x40000066,
  KP_EQUALS = 0x40000067,
  F13 = 0x40000068,
  F14 = 0x40000069,
  F15 = 0x4000006A,
  F16 = 0x4000006B,
  F17 = 0x4000006C,
  F18 = 0x4000006D,
  F19 = 0x4000006E,
  F20 = 0x4000006F,
  F21 = 0x40000070,
  F22 = 0x40000071,
  F23 = 0x40000072,
  F24 = 0x40000073,
  EXECUTE = 0x40000074,
  HELP = 0x40000075,
  MENU = 0x40000076,
  SELECT = 0x40000077,
  STOP = 0x40000078,
  AGAIN = 0x40000079,
  UNDO = 0x4000007A,
  CUT = 0x4000007B,
  COPY = 0x4000007C,
  PASTE = 0x4000007D,
  FIND = 0x4000007E,
  MUTE = 0x4000007F,
  VOLUMEUP = 0x40000080,
  VOLUMEDOWN = 0x40000081,
  KP_COMMA = 0x40000085,
  KP_EQUALSAS400 = 0x40000086,
  ALTERASE = 0x40000099,
  SYSREQ = 0x4000009A,
  CANCEL = 0x4000009B,
  CLEAR = 0x4000009C,
  PRIOR = 0x4000009D,
  RETURN2 = 0x4000009E,
  SEPARATOR = 0x4000009F,
  OUTPUT = 0x400000A0,
  OPER = 0x400000A1,
  CLEARAGAIN = 0x400000A2,
  CRSEL = 0x400000A3,
  EXSEL = 0x400000A4,
  KP_00 = 0x400000B0,
  KP_000 = 0x400000B1,
  THOUSANDSSEPARATOR = 0x400000B2,
  DECIMALSEPARATOR = 0x400000B3,
  CURRENCYUNIT = 0x400000B4,
  CURRENCYSUBUNIT = 0x400000B5,
  KP_LEFTPAREN = 0x400000B6,
  KP_RIGHTPAREN = 0x400000B7,
  KP_LEFTBRACE = 0x400000B8,
  KP_RIGHTBRACE = 0x400000B9,
  KP_TAB = 0x400000BA,
  KP_BACKSPACE = 0x400000BB,
  KP_A = 0x400000BC,
  KP_B = 0x400000BD,
  KP_C = 0x400000BE,
  KP_D = 0x400000BF,
  KP_E = 0x400000C0,
  KP_F = 0x400000C1,
  KP_XOR = 0x400000C2,
  KP_POWER = 0x400000C3,
  KP_PERCENT = 0x400000C4,
  KP_LESS = 0x400000C5,
  KP_GREATER = 0x400000C6,
  KP_AMPERSAND = 0x400000C7,
  KP_DBLAMPERSAND = 0x400000C8,
  KP_VERTICALBAR = 0x400000C9,
  KP_DBLVERTICALBAR = 0x400000CA,
  KP_COLON = 0x400000CB,
  KP_HASH = 0x400000CC,
  KP_SPACE = 0x400000CD,
  KP_AT = 0x400000CE,
  KP_EXCLAM = 0x400000CF,
  KP_MEMSTORE = 0x400000D0,
  KP_MEMRECALL = 0x400000D1,
  KP_MEMCLEAR = 0x400000D2,
  KP_MEMADD = 0x400000D3,
  KP_MEMSUBTRACT = 0x400000D4,
  KP_MEMMULTIPLY = 0x400000D5,
  KP_MEMDIVIDE = 0x400000D6,
  KP_PLUSMINUS = 0x400000D7,
  KP_CLEAR = 0x400000D8,
  KP_CLEARENTRY = 0x400000D9,
  KP_BINARY = 0x400000DA,
  KP_OCTAL = 0x400000DB,
  KP_DECIMAL = 0x400000DC,
  KP_HEXADECIMAL = 0x400000DD,
  LCTRL = 0x400000E0,
  LSHIFT = 0x400000E1,
  LALT = 0x400000E2,
  LGUI = 0x400000E3,
  RCTRL = 0x400000E4,
  RSHIFT = 0x400000E5,
  RALT = 0x400000E6,
  RGUI = 0x400000E7,
  MODE = 0x40000101,
  AUDIONEXT = 0x40000102,
  AUDIOPREV = 0x40000103,
  AUDIOSTOP = 0x40000104,
  AUDIOPLAY = 0x40000105,
  AUDIOMUTE = 0x40000106,
  MEDIASELECT = 0x40000107,
  WWW = 0x40000108,
  MAIL = 0x40000109,
  CALCULATOR = 0x4000010A,
  COMPUTER = 0x4000010B,
  AC_SEARCH = 0x4000010C,
  AC_HOME = 0x4000010D,
  AC_BACK = 0x4000010E,
  AC_FORWARD = 0x4000010F,
  AC_STOP = 0x40000110,
  AC_REFRESH = 0x40000111,
  AC_BOOKMARKS = 0x40000112,
  BRIGHTNESSDOWN = 0x40000113,
  BRIGHTNESSUP = 0x40000114,
  DISPLAYSWITCH = 0x40000115,
  KBDILLUMTOGGLE = 0x40000116,
  KBDILLUMDOWN = 0x40000117,
  KBDILLUMUP = 0x40000118,
  EJECT = 0x40000119,
  SLEEP = 0x4000011A
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
