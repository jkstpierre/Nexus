/// File: Source\Nexus\Graphics\GLTextureCache.cpp.
///
/// Summary:  Implements the gl texture cache class.

#include <Nexus\Graphics\GLTextureCache.hpp>
#include <Nexus\Exception.hpp>
#include <Nexus\DebugWriter.hpp>

namespace Nexus::Graphics
{
GLTextureCache::GLTextureCache() noexcept
{
  DebugWriter().Write("GLTextureCache created.\n");
}

GLTextureCache::~GLTextureCache() noexcept
{
  ClearTextures();
  DebugWriter().Write("GLTextureCache destroyed.\n");
}

void GLTextureCache::AddTexture(const std::string& refName, Base::GLTexture* texture)
{
  if ( !texture )
  {
    throw Exception("GLTextureCache Error: Cannot cache null texture.\n");
  }
  else if ( refName.empty() )
  {
    throw Exception("GLTextureCache Error: Cannot cache empty reference.\n");
  }
  else if ( mTextures.find(refName) != mTextures.end() )
  {
    throw Exception("GLTextureCache Error: Texture already cached under reference %s.\n", refName.c_str());
  }

  /// Summary:  Add the texture to the cache.
  mTextures[refName] = texture;
}

void GLTextureCache::ClearTextures() noexcept
{
  // Free every texture from memory
  for ( auto& texturePair : mTextures )
  {
    delete texturePair.second;
  }

  mTextures.clear();
}

Base::GLTexture* GLTextureCache::GetTexture(const std::string& refName) noexcept
{
  if ( mTextures.find(refName) != mTextures.end() )
  {
    return mTextures.at(refName);
  }

  return nullptr;
}
}

// End of Source\Nexus\Graphics\GLTextureCache.cpp
