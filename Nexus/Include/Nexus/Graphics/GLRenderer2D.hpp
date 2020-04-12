/// File: Include\Nexus\Graphics\GLRenderer2D.hpp.
///
/// Summary:  Declares the gl renderer 2D class.

#ifndef __NEXUS_GRAPHICS_GLRENDERER2D_HPP__
#define __NEXUS_GRAPHICS_GLRENDERER2D_HPP__

#include <Nexus\Graphics\Base\GLRenderer.hpp>

namespace Nexus::Graphics
{
/// Struct: Vertex2D
///
/// Summary:  A vertex 2d.
///
/// Author: jkstpierre
///
/// Date: 4/12/2020
struct Vertex2D
{
  Math::Vector2f position;  // The position of the vertex (x, y)
  float depth;  // The depth in the z buffer
};

/// Class:  GLRenderer2D
///
/// Summary:  A gl renderer 2d.
///
/// Author: jkstpierre
///
/// Date: 4/12/2020
///
/// See:
/// Base::GLRenderer{Vertex2D} - 
class GLRenderer2D : public Base::GLRenderer<Vertex2D>
{
private:

public:

};
}

#endif

// End of Include\Nexus\Graphics\GLRenderer2D.hpp
