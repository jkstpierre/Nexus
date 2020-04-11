/// File: Include\Nexus\Graphics\GLBuffer.hpp.
///
/// Summary:  Declares the gl buffer class.

#ifndef __NEXUS_GRAPHICS_GLBUFFER_HPP__
#define __NEXUS_GRAPHICS_GLBUFFER_HPP__

#include <Nexus\Graphics\Base\GLBuffer.hpp>

namespace Nexus::Graphics
{
/// Enum: GLBufferUsage
///
/// Summary:
///   Values that represent how the GLBuffer is to be used. These correspond directly to the OpenGL
///   4.6 specification.
enum class GLBufferUsage : unsigned int
{
  _STREAM_DRAW = 0x88E0,
  _STREAM_READ = 0x88E1,
  _STREAM_COPY = 0x88E2,
  _STATIC_DRAW = 0x88E4,
  _STATIC_READ = 0x88E5,
  _STATIC_COPY = 0x88E6,
  _DYNAMIC_DRAW = 0x88E8,
  _DYNAMIC_READ = 0x88E9,
  _DYNAMIC_COPY = 0x88EA
};

/// Enum: GLBufferAccess
///
/// Summary:
///   Values that represent how a mapped GLBuffer is to be accessed. These correspond directly to
///   the OpenGL 4.6 specification.
enum class GLBufferAccess : unsigned int
{
  _READ_ONLY = 0x88B8,
  _WRITE_ONLY = 0x88B9,
  _READ_WRITE = 0x88BA
};

/// Class:  GLBuffer
///
/// Summary:  Frontend wrapper of the GLBuffer object for use by the user.
///
/// Author: jkstpierre
///
/// Date: 4/10/2020
///
/// Typeparams:
/// T -   Generic type parameter.
///
/// See:
/// Base::GLBuffer - 
template <typename T>
class GLBuffer : public Base::GLBuffer
{
public:
  /// Function: GLBuffer::GLBuffer
  ///
  /// Summary:  Default constructor.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/10/2020
  GLBuffer() noexcept = default;

  /// Function: GLBuffer::~GLBuffer
  ///
  /// Summary:  Destructor.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/10/2020
  virtual ~GLBuffer() noexcept = default;

public:
  /// Function: SetData
  ///
  /// Summary:  Formats the buffer and sends data to the GPU.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/10/2020
  ///
  /// Parameters:
  /// data -      The data to send to the GPU.
  /// size -      The amount of data to send in bytes.
  /// usage -     The usage for the data.
  void SetData(const T* data, const unsigned long& size, const GLBufferUsage& usage) noexcept
  {
    Base::GLBuffer::SetData(data, size, usage);
  }

  /// Function: SetSubdata
  ///
  /// Summary:  Updates a subset of the data on the GPU.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/10/2020
  ///
  /// Parameters:
  /// data -      The data to set.
  /// offset -    The offset.
  /// size -      The size.
  void SetSubdata(const T* data, const unsigned long& offset, const unsigned long& size) noexcept
  {
    Base::GLBuffer::SetSubdata(data, offset, size);
  }

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
  /// Returns:  Null if it fails, else a pointer to a T.
  T* Map(const GLBufferAccess& access) noexcept
  {
    return Base::GLBuffer::Map(access);
  }

  /// Function: Unmap
  ///
  /// Summary:  Unmaps this. 
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/10/2020
  ///
  /// Returns:  True if it succeeds, false if it fails.
  bool Unmap() noexcept
  {
    return Base::GLBuffer::Unmap();
  }
};
}

#endif

// End of Include\Nexus\Graphics\GLBuffer.hpp
