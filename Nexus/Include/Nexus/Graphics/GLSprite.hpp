/// File: Include\Nexus\Graphics\GLSprite.hpp.
///
/// Summary:  Declares the gl sprite class.

#ifndef __NEXUS_GRAPHICS_GLSPRITE_HPP__
#define __NEXUS_GRAPHICS_GLSPRITE_HPP__

#include <array>
#include <Nexus\Graphics\Data\GLVertex2D.hpp>
#include <Nexus\Graphics\Data\GLMaterial.hpp>

namespace Nexus::Graphics
{
/// Summary:  Number of vertices per sprite.
const unsigned int GLSPRITE_VERTEX_COUNT = 4U;

/// Class:  GLSprite
///
/// Summary:
///   A sprite is a 2D quad made up of 4 vertices. Unlike a GLModel object, GLSprite vertices are
///   unique to it and are not shared between instances.
///
/// Author: jkstpierre.
///
/// Date: 4/17/2020.
class GLSprite
{
private:
  /// Summary:  The vertices for the sprite.
  std::array<Data::GLVertex2D, GLSPRITE_VERTEX_COUNT> mVertices;
  /// Summary:  The material.
  Data::GLMaterial mMaterial;

public:


};
}

#endif

// End of Include\Nexus\Graphics\GLSprite.hpp
