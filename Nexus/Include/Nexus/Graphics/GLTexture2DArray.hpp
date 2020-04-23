/// File: Include\Nexus\Graphics\GLTexture2DArray.hpp.
///
/// Summary:  Declares the gl texture 2D array class.

#ifndef __NEXUS_GRAPHICS_GLTEXTURE2DARRAY_HPP__
#define __NEXUS_GRAPHICS_GLTEXTURE2DARRAY_HPP__

#include <Nexus\Graphics\Base\GLTexture.hpp>

namespace Nexus::Graphics
{
/// Class:  GLTexture2DArray
///
/// Summary:  List of gl texture 2ds.
///
/// Author: jkstpierre
///
/// Date: 4/20/2020
///
/// See:
/// Base::GLTexture - 
class GLTexture2DArray : public Base::GLTexture
{
private:
  /// Function: GLTexture2DArray::GLTexture2DArray
  ///
  /// Summary:  Default constructor.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/21/2020
  GLTexture2DArray() noexcept;

  /// Function: GLTexture2DArray::~GLTexture2DArray
  ///
  /// Summary:  Destructor.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/23/2020
  virtual ~GLTexture2DArray() noexcept;

public:
  /// Function: SetStorage
  ///
  /// Summary:  Sets up the storage for the texture array so that it can be filled with data.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/23/2020
  ///
  /// Parameters:
  /// levels -          The levels.
  /// internalFormat -  The internal format.
  /// width -           The width.
  /// height -          The height.
  /// depth -           The depth.
  void SetStorage(const unsigned int& levels, const Base::GLTextureInternalFormat& internalFormat, 
                  const unsigned int& width, const unsigned int& height, const unsigned int& depth) noexcept;


};
}

#endif

// End of Include\Nexus\Graphics\GLTexture2DArray.hpp
