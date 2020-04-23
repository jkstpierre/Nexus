/// File: Include\Nexus\Graphics\GLTextureCache.hpp.
///
/// Summary:  Declares the gl texture cache class.

#ifndef __NEXUS_GRAPHICS_GLTEXTURECACHE_HPP__
#define __NEXUS_GRAPHICS_GLTEXTURECACHE_HPP__

#include <unordered_map>
#include <Nexus\Graphics\Base\GLTexture.hpp>

namespace Nexus::Graphics
{
/// Class:  GLTextureCache
///
/// Summary:
///   Stores texture objects for easy retrieval in a single location allowing for them to be shared
///   across GLRenderable objects. This reduces the CPU and memory cost of creating unique textures
///   for every GLRenderable object.
///
/// Author: jkstpierre.
///
/// Date: 4/20/2020.
class GLTextureCache
{
private:
  /// Summary:  The textures in the cache.
  std::unordered_map<std::string, Base::GLTexture*> mTextures;

public:
  /// Function: GLTextureCache::GLTextureCache
  ///
  /// Summary:  Default constructor.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/20/2020
  GLTextureCache() noexcept;

  /// Function: GLTextureCache::~GLTextureCache
  ///
  /// Summary:  Destructor.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/20/2020
  virtual ~GLTextureCache() noexcept;

public:
  /// Function: AddTexture
  ///
  /// Summary:
  ///   Adds a texture to the cache. Throws exception if a texture already existed under refName. 
  ///   WARNING: texture pointer must be heap allocated, all textures in the cache will be freed by the cache.
  ///
  /// Author: jkstpierre.
  ///
  /// Date: 4/20/2020.
  ///
  /// Parameters:
  /// refName -   Name of the reference.
  /// texture -   [in,out] If non-null, the texture.
  void AddTexture(const std::string& refName, Base::GLTexture* texture);

  /// Function: Clear
  ///
  /// Summary:  Clears all textures cached in memory and frees them.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/20/2020
  void ClearTextures() noexcept;

public:
  /// Function: GetTexture
  ///
  /// Summary:  Gets a texture from the cache.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/20/2020
  ///
  /// Parameters:
  /// refName -   Name of the reference.
  ///
  /// Returns:  Null if it fails, else the texture.
  Base::GLTexture* GetTexture(const std::string& refName) noexcept;
};
}

#endif

// End of Include\Nexus\Graphics\GLTextureCache.hpp
