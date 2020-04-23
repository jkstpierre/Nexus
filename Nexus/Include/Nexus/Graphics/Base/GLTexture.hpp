/// File: Include\Nexus\Graphics\Base\GLTexture.hpp.
///
/// Summary:  Declares the gl texture class.

#ifndef __NEXUS_GRAPHICS_BASE_GLTEXTURE_HPP__
#define __NEXUS_GRAPHICS_BASE_GLTEXTURE_HPP__

#include <unordered_map>
#include <string>
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

/// Enum: GLTextureInternalFormat
///
/// Summary:
///   Values that represent gl texture internal formats. TODO: Add other internal formats later.
enum class GLTextureInternalFormat : unsigned int
{
  _R8 = 0x8229,
  _RG8 = 0x822B,
  _RGB8 = 0x8051,
  _RGBA8 = 0x8058
};

/// Struct: GLImage_t
///
/// Summary:  A gl image.
///
/// Author: jkstpierre.
///
/// Date: 4/19/2020.
struct GLImage_t
{
  /// Summary:  Filename of the file.
  std::string filename;
  /// Summary:  The data.
  unsigned char* data;
  /// Summary:  The width.
  int width;
  /// Summary:  The height.
  int height;
  /// Summary:  The channels.
  int channels;
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
protected:
  /// Function: GLTexture::GLTexture
  ///
  /// Summary:  Default constructor.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/13/2020
  GLTexture(const GLTextureType& type) noexcept;

public:
  /// Function: GLTexture::~GLTexture
  ///
  /// Summary:  Destructor.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/13/2020
  virtual ~GLTexture() noexcept;

protected:
  /// Function: LoadImage
  ///
  /// Summary:  Loads an image from disk.
  ///
  /// Author: jkstpierre.
  ///
  /// Date: 4/19/2020.
  ///
  /// Parameters:
  /// filepath -  The filepath.
  ///
  /// Returns:  The image.
  const GLImage_t* LoadImage(const char* filepath) const noexcept;

  /// Function: FreeImage
  ///
  /// Summary:  Free image. Should be called after image data has been passed to OpenGL.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/19/2020
  ///
  /// Parameters:
  /// image -   The image.
  void FreeImage(const GLImage_t* image) const noexcept;
};
}

#endif

// End of Include\Nexus\Graphics\Base\GLTexture.hpp
