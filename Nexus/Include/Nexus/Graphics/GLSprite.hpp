/// File: Include\Nexus\Graphics\GLSprite.hpp.
///
/// Summary:  Declares the gl sprite class.

#ifndef __NEXUS_GRAPHICS_GLSPRITE_HPP__
#define __NEXUS_GRAPHICS_GLSPRITE_HPP__

#include <array>
#include <Nexus\Graphics\Base\GLRenderable.hpp>
#include <Nexus\Graphics\GLTexture2DArray.hpp>

namespace Nexus::Graphics
{
/// Summary:  Array of glspritematerial no textures.
const nullptr_t GLSPRITEMATERIAL_NO_TEXTURE_ARRAY = nullptr;
/// Summary:  The glspritematerial no diffuse map.
const int GLSPRITEMATERIAL_NO_DIFFUSE_MAP = -1;
/// Summary:  The glspritematerial no specular map.
const int GLSPRITEMATERIAL_NO_SPECULAR_MAP = -1;
/// Summary:  The glspritematerial no normal map.
const int GLSPRITEMATERIAL_NO_NORMAL_MAP = -1;

/// Struct: GLSpriteMaterial_t
///
/// Summary:
///   The material for a GLSprite. It contains the texture array storing any and all textures to be
///   sampled.
///
/// Author: jkstpierre.
///
/// Date: 4/21/2020.
struct GLSpriteMaterial_t
{
  /// Summary:  Array of textures.
  GLTexture2DArray* textureArray = GLSPRITEMATERIAL_NO_TEXTURE_ARRAY;
  /// Summary:  Zero-based index of the diffuse map. -1 if no diffuse map.
  int diffuseMapIndex = GLSPRITEMATERIAL_NO_DIFFUSE_MAP;
  /// Summary:  Zero-based index of the specular map. -1 if no specular map.
  int specularMapIndex = GLSPRITEMATERIAL_NO_SPECULAR_MAP;
  /// Summary:  Zero-based index of the normal map. -1 if no normal map.
  int normalMapIndex = GLSPRITEMATERIAL_NO_NORMAL_MAP;
};

/// Summary:  The glspriteuvrect default position.
const glm::vec2 GLSPRITEUVRECT_DEFAULT_POSITION = glm::vec2(0.0f, 0.0f);
/// Summary:  The glspriteuvrect default dimensions.
const glm::vec2 GLSPRITEUVRECT_DEFAULT_DIMENSIONS = glm::vec2(1.0f, 1.0f);

/// Struct: GLSpriteUVRect_t
///
/// Summary:  A gl sprite uv rectangle t.
///
/// Author: jkstpierre
///
/// Date: 4/22/2020
struct GLSpriteUVRect_t
{
  /// Summary:  The position of the UVRect in uv coordinates
  glm::vec2 position = GLSPRITEUVRECT_DEFAULT_POSITION;
  /// Summary:  The dimensions of the UVRect in uv coordinates.
  glm::vec2 dimensions = GLSPRITEUVRECT_DEFAULT_DIMENSIONS;
};

/// Summary:  The glsprite default dimensions.
const glm::vec2 GLSPRITE_DEFAULT_DIMENSIONS = glm::vec2(1.0f, 1.0f);

/// Class:  GLSprite
///
/// Summary:
///   A sprite is a 2D quad made up of 4 vertices. Unlike a GLModel object, GLSprite vertices are
///   unique to it and are not shared between instances.
///
/// Author: jkstpierre.
///
/// Date: 4/17/2020.
class GLSprite : public Base::GLRenderable
{
private:
  /// Summary:  The material.
  GLSpriteMaterial_t mMaterial;

  /// Summary:  The uv rectangle for sampling from the material.
  GLSpriteUVRect_t mUVRect;

  /// Summary:  The dimensions of the sprite.
  Base::GLRenderableState<glm::vec2> mDimensions;

public:
  /// Function: GLSprite::GLSprite
  ///
  /// Summary:  Default constructor.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/21/2020
  GLSprite() noexcept;

  /// Function: GLSprite::GLSprite
  ///
  /// Summary:  Constructor.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/23/2020
  ///
  /// Parameters:
  /// ambientColor -      The ambient color.
  /// diffuseMapPath -    Full pathname of the diffuse map file.
  /// specularMapPath -   Full pathname of the specular map file.
  /// normalMapPath -     Full pathname of the normal map file.
  /// position -          The position.
  /// dimensions -        The dimensions.
  GLSprite(const glm::vec4& ambientColor, const char* diffuseMapPath, 
           const char* specularMapPath, const char* normalMapPath, 
           const glm::vec3& position, const glm::vec2& dimensions);

  /// Function: GLSprite::~GLSprite
  ///
  /// Summary:  Destructor.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/21/2020
  virtual ~GLSprite() noexcept = default;

public:
  /// Function: SetMaterial
  ///
  /// Summary:  Sets the material for the sprite and loads the requested maps into a GLTexture2DArray.
  ///
  /// Author: jkstpierre.
  ///
  /// Date: 4/20/2020.
  ///
  /// Parameters:
  /// diffuseMapPath -    Full pathname of the diffuse map file.
  /// specularMapPath -   Full pathname of the specular map file.
  /// normalMapPath -     Full pathname of the normal map file.
  void SetMaterial(const char* diffuseMapPath, const char* specularMapPath, const char* normalMapPath);

  /// Function: SetUVRect
  ///
  /// Summary:  Sets uv rectangle.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/23/2020
  ///
  /// Parameters:
  /// uvRect -  The uv rectangle.
  void SetUVRect(const GLSpriteUVRect_t& uvRect) noexcept;

public:
  /// Function: GetTextureArray
  ///
  /// Summary:  Gets texture array for this GLSprite
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/20/2020
  ///
  /// Returns:  Null if it fails, else the texture array.
  const GLSpriteMaterial_t& GetMaterial() const noexcept;

  /// Function: GetUVRect
  ///
  /// Summary:  Gets uv rectangle.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/23/2020
  ///
  /// Returns:  The uv rectangle.
  const GLSpriteUVRect_t& GetUVRect() const noexcept;
 
  /// Function: GetDimensions
  ///
  /// Summary:  Gets the dimensions.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/22/2020
  ///
  /// Returns:  The dimensions.
  Base::GLRenderableState<glm::vec2>& GetDimensions() noexcept;
};
}

#endif

// End of Include\Nexus\Graphics\GLSprite.hpp
