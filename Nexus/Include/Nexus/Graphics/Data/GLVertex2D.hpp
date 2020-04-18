/// File: Include\Nexus\Graphics\Data\GLVertex2D.hpp.
///
/// Summary:  Declares the gl vertex 2D class.

#ifndef __NEXUS_GRAPHICS_DATA_GLVERTEX2D_HPP__
#define __NEXUS_GRAPHICS_DATA_GLVERTEX2D_HPP__

#include <glm\vec2.hpp>

namespace Nexus::Graphics::Data
{
/// Struct: GLVertex2D
///
/// Summary:  A gl vertex 2d.
///
/// Author: jkstpierre
///
/// Date: 4/16/2020
struct GLVertex2D
{
  /// Summary:  The position (x, y).
  glm::vec2 position;
  /// Summary:  The texture coordinates (u, v).
  glm::vec2 texCoords;
};
}

#endif

// End of Include\Nexus\Graphics\Data\GLVertex2D.hpp
