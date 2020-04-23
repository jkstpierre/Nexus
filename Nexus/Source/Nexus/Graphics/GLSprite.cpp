/// File: Source\Nexus\Graphics\GLSprite.cpp.
///
/// Summary:  Implements the gl sprite class.

#include <unordered_map>
#include <Nexus\Graphics\GLSprite.hpp>

namespace Nexus::Graphics
{
GLSprite::GLSprite() noexcept : mDimensions(GLSPRITE_DEFAULT_DIMENSIONS)
{

}

GLSprite::GLSprite(const glm::vec4& ambientColor, const char* diffuseMapPath,
                   const char* specularMapPath, const char* normalMapPath,
                   const glm::vec3& position, const glm::vec2& dimensions) :
  Base::GLRenderable(ambientColor, position),
  mDimensions(dimensions)
{
  SetMaterial(diffuseMapPath, specularMapPath, normalMapPath);  // Set the material for the Sprite
}

void GLSprite::SetMaterial(const char* diffuseMapPath, const char* specularMapPath, const char* normalMapPath)
{
  /// Summary:  Get reference to the texture cache
  auto& textureCache = glDevice->GetTextureCache();

  // Index counter for computing the indices for a material
  int index = 0;

  /// Summary:  Default to null texture array.
  mMaterial.textureArray = GLSPRITEMATERIAL_NO_TEXTURE_ARRAY;

  // Compute the refName for the cached texture and according indices
  std::string ref = "GLTexture2DArray";
  if ( diffuseMapPath )
  {
    ref += "|diffuse:" + std::string(diffuseMapPath);
    mMaterial.diffuseMapIndex = index++;
  }
  else
  {
    mMaterial.diffuseMapIndex = GLSPRITEMATERIAL_NO_DIFFUSE_MAP;
  }

  if ( specularMapPath )
  {
    ref += "|specular:" + std::string(specularMapPath);
    mMaterial.specularMapIndex = index++;
  }
  else
  {
    mMaterial.specularMapIndex = GLSPRITEMATERIAL_NO_SPECULAR_MAP;
  }

  if ( normalMapPath )
  {
    ref += "|normal:" + std::string(normalMapPath);
    mMaterial.normalMapIndex = index++;
  }
  else
  {
    mMaterial.normalMapIndex = GLSPRITEMATERIAL_NO_NORMAL_MAP;
  }

  // If a material is in fact requested
  if ( index > 0 )
  {
    // Attempt to load the requested texture array from the cache
    mMaterial.textureArray = dynamic_cast<GLTexture2DArray*>(textureCache.GetTexture(ref));
    if ( !mMaterial.textureArray )
    {
      // Attempt to create a new texture since one does not yet exist
      // TODO: Create new texture and cache it, throw exception if failure
    }
  }
}

void GLSprite::SetUVRect(const GLSpriteUVRect_t& uvRect) noexcept
{
  mUVRect = uvRect;
}

const GLSpriteMaterial_t& GLSprite::GetMaterial() const noexcept
{
  return mMaterial;
}

const GLSpriteUVRect_t& GLSprite::GetUVRect() const noexcept
{
  return mUVRect;
}

Base::GLRenderableState<glm::vec2>& GLSprite::GetDimensions() noexcept
{
  return mDimensions;
}
}

// End of Source\Nexus\Graphics\GLSprite.cpp
