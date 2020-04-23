/// File: Include\Nexus\Graphics\GLTextureUnit.hpp.
///
/// Summary:  Declares the gl texture unit class.

#ifndef __NEXUS_GRAPHICS_GLTEXTUREUNIT_HPP__
#define __NEXUS_GRAPHICS_GLTEXTUREUNIT_HPP__

#include <vector>
#include <Nexus\Graphics\GLSampler.hpp>
#include <Nexus\Graphics\Base\GLTexture.hpp>

namespace Nexus::Graphics
{
/// Summary:  The default maximum number of texture units
const unsigned int GLTEXTUREUNIT_DEFAULT_TEXTURES = 16U;

/// Class:  GLTextureUnit
///
/// Summary:
///   A texture unit is where GLTexture objects are bound to during draw calls. GLSampler objects
///   sample from textures bound to texture units.
///
/// Author: jkstpierre.
///
/// Date: 4/12/2020.
class GLTextureUnit
{
private:
  /// Summary:  The texture unit index.
  unsigned int mTextureUnitIndex;
  /// Summary:  The sampler for this texture unit.
  const GLSampler* mSampler;
  /// Summary:  The texture currently bound to this texture unit
  const Base::GLTexture* mTexture;

private:
  /// Function: GLTextureUnit::GLTextureUnit
  ///
  /// Summary:  Constructor.
  ///
  /// Author: jkstpierre.
  ///
  /// Date: 4/13/2020.
  ///
  /// Parameters:
  /// textureUnitIndex -  The texture unit.
  GLTextureUnit(const unsigned int& textureUnitIndex) noexcept;

  /// Function: GLTextureUnit::~GLTextureUnit
  ///
  /// Summary:  Destructor.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/13/2020
  ~GLTextureUnit() noexcept;

public:
  /// Function: AllocateTextureUnits
  ///
  /// Summary:  Allocate texture units.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/17/2020
  ///
  /// Parameters:
  /// count -   Number of.
  ///
  /// Returns:  Null if it fails, else a std::vector&lt;GLTextureUnit*&gt;
  static std::vector<GLTextureUnit*> AllocateTextureUnits(const unsigned int& count);

  /// Function: FreeTextureUnits
  ///
  /// Summary:  Free texture units.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/17/2020
  ///
  /// Parameters:
  /// textureUnits -  [in,out] [in,out] If non-null, the texture units.
  static void FreeTextureUnits(std::vector<GLTextureUnit*>& textureUnits) noexcept;

  /// Function: QueryMaxTextureUnits
  ///
  /// Summary:  Queries maximum texture units that can be bound for the fragment shader.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/20/2020
  ///
  /// Returns:  The maximum texture units.
  static unsigned int QueryMaxTextureUnits() noexcept;

public:
  /// Function: SetSampler
  ///
  /// Summary:  Binds a GLSampler to this GLTextureUnit. If nullptr, no sampler will be used.
  ///
  /// Author: jkstpierre.
  ///
  /// Date: 4/13/2020.
  ///
  /// Parameters:
  /// sampler -   The sampler.
  void BindSampler(const GLSampler* sampler) noexcept;

  /// Function: BindTexture
  ///
  /// Summary:  Bind a GLTexture to this GLTextureUnit. If nullptr, no texture will be used.
  ///
  /// Author: jkstpierre.
  ///
  /// Date: 4/13/2020.
  ///
  /// Parameters:
  /// texture -   The texture.
  void BindTexture(const Base::GLTexture* texture) noexcept;

public:
  /// Function: GetTextureUnitIndex
  ///
  /// Summary:  Gets texture unit.
  ///
  /// Author: jkstpierre.
  ///
  /// Date: 4/13/2020.
  ///
  /// Returns:  The texture unit.
  const unsigned int& GetTextureUnitIndex() const noexcept;

  /// Function: GetSampler
  ///
  /// Summary:  Gets the sampler.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/13/2020
  ///
  /// Returns:  Null if it fails, else the sampler.
  const GLSampler* GetSampler() const noexcept;

  /// Function: GetTexture
  ///
  /// Summary:  Gets the texture.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/13/2020
  ///
  /// Returns:  Null if it fails, else the texture.
  const Base::GLTexture* GetTexture() const noexcept;
};
}

#endif

// End of Include\Nexus\Graphics\GLTextureUnit.hpp
