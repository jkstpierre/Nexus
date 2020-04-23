/// File: Include\Nexus\Graphics\Base\GLBuffer.hpp.
///
/// Summary:  Declares the gl buffer class.

#ifndef __NEXUS_GRAPHICS_BASE_GLBUFFER_HPP__
#define __NEXUS_GRAPHICS_BASE_GLBUFFER_HPP__

#include <Nexus\Graphics\Base\GLObject.hpp>

namespace Nexus::Graphics::Base
{
/// Class:  GLBuffer
///
/// Summary:  Backend implementation for OpenGL buffers. This class is an abstract base class and cannot be instantiated.
///
/// Author: jkstpierre
///
/// Date: 4/10/2020
class GLBuffer : public Base::GLObject
{
protected:
  /// Function: GLBuffer::GLBuffer
  ///
  /// Summary:  Default constructor.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/10/2020
  GLBuffer() noexcept;

public:
  /// Function: GLBuffer::~GLBuffer
  ///
  /// Summary:  Destructor.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/10/2020
  virtual ~GLBuffer() noexcept;

protected:
  /// Function: SetData
  ///
  /// Summary:  Sets a data.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/10/2020
  ///
  /// Parameters:
  /// data -      The data.
  /// size -      The size.
  /// usage -     The usage.
  void SetData(const void* data, const unsigned long& size, const unsigned int& usage) noexcept;

  /// Function: SetSubdata
  ///
  /// Summary:  Sets sub data.
  ///
  /// Author: jkstpierre.
  ///
  /// Date: 4/10/2020.
  ///
  /// Parameters:
  /// data -      The data.
  /// offset -    The offset.
  /// size -      The size.
  void SetSubdata(const void* data, const unsigned long& offset, const unsigned long& size) noexcept;

  /// Function: Map
  ///
  /// Summary:  Maps the given access.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/10/2020
  ///
  /// Parameters:
  /// access -  The access.
  ///
  /// Returns:  Null if it fails, else a pointer to a void.
  void* Map(const unsigned int& access) noexcept;

  /// Function: Unmap
  ///
  /// Summary:  Unmaps this. 
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/10/2020
  ///
  /// Returns:  True if it succeeds, false if it fails.
  bool Unmap() noexcept;
};
}

#endif

// End of Include\Nexus\Graphics\Base\GLBuffer.hpp
