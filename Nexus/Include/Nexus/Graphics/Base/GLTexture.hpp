/// File: Include\Nexus\Graphics\Base\GLTexture.hpp.
///
/// Summary:  Declares the gl texture class.

#ifndef __NEXUS_GRAPHICS_BASE_GLTEXTURE_HPP__
#define __NEXUS_GRAPHICS_BASE_GLTEXTURE_HPP__

#include <Nexus\Graphics\Base\GLObject.hpp>

namespace Nexus::Graphics::Base
{
/// Enum: GLTextureType
///
/// Summary:  Values that represent gl texture types.
enum class GLTextureType : unsigned int
{
  _TEXTURE_1D = 0x0DE0,
  _TEXTURE_2D = 0x0DE1,
  _TEXTURE_3D = 0x806F,
  _TEXTURE_1D_ARRAY = 0x8C18,
  _TEXTURE_2D_ARRAY = 0x8C1A,
  _TEXTURE_CUBE_MAP = 0x8513,
  _TEXTURE_CUBE_MAP_ARRAY = 0x9009
};

/// Class:  GLTexture
///
/// Summary:  A gl texture.
///
/// Author: jkstpierre
///
/// Date: 4/13/2020
///
/// See:
/// Base::GLObject - 
class GLTexture : public Base::GLObject
{
private:
  /// Summary:  The type of the texture.
  GLTextureType mType;

protected:
  /// Function: GLTexture::GLTexture
  ///
  /// Summary:  Default constructor.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/13/2020
  GLTexture(const GLTextureType& type) noexcept;

  /// Function: GLTexture::~GLTexture
  ///
  /// Summary:  Destructor.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/13/2020
  virtual ~GLTexture() noexcept;

public:
  /// Function: GetType
  ///
  /// Summary:  Gets the type.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/13/2020
  ///
  /// Returns:  The type.
  const GLTextureType& GetType() const noexcept;
};
}

#endif

// End of Include\Nexus\Graphics\Base\GLTexture.hpp
