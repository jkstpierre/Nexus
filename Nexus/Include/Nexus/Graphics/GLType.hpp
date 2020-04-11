/// File: Include\Nexus\Graphics\GLType.hpp.
///
/// Summary:  Declares the gl type class.

#ifndef __NEXUS_GRAPHICS_GLTYPE_HPP__
#define __NEXUS_GRAPHICS_GLTYPE_HPP__

namespace Nexus::Graphics
{
/// Enum: GLType
///
/// Summary:  Enumerates the underlying types for OpenGL
enum class GLType : unsigned int
{
  _BYTE = 0x1400,
  _UNSIGNED_BYTE = 0x1401,
  _SHORT = 0x1402,
  _UNSIGNED_SHORT = 0x1403,
  _INT = 0x1404,
  _UNSIGNED_INT = 0x1405,
  _FLOAT = 0x1406,
  _DOUBLE = 0x140A
};
}

#endif

// End of Include\Nexus\Graphics\GLType.hpp
