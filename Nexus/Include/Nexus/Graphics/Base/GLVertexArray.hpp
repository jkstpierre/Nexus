/// File: Include\Nexus\Graphics\Base\GLVertexArray.hpp.
///
/// Summary:  Declares the gl vertex array class.

#ifndef __NEXUS_GRAPHICS_BASE_GLVERTEXARRAY_HPP__
#define __NEXUS_GRAPHICS_BASE_GLVERTEXARRAY_HPP__

#include <Nexus\Graphics\Base\GLObject.hpp>

namespace Nexus::Graphics::Base
{
/// Class:  GLVertexArray
///
/// Summary:  Backend implementation of a GLVertexArray object. This class is an abstract base class.
///
/// Author: jkstpierre.
///
/// Date: 4/10/2020.
///
/// See:
/// Base::GLObject - 
class GLVertexArray : public Base::GLObject
{
protected:
  /// Function: GLVertexArray::GLVertexArray
  ///
  /// Summary:  Default constructor.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/11/2020
  GLVertexArray() noexcept;

  /// Function: GLVertexArray::~GLVertexArray
  ///
  /// Summary:  Destructor.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/11/2020
  virtual ~GLVertexArray() noexcept;

protected:
  /// Function: BindVertexBuffer
  ///
  /// Summary:  Bind vertex buffer.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/11/2020
  ///
  /// Parameters:
  /// vbo -           The vbo.
  /// offset -        The offset.
  /// stride -        The stride.
  /// bindingIndex -  Zero-based index of the binding.
  void BindVertexBuffer(const unsigned int& vbo, const unsigned int& offset, const unsigned int& stride, const unsigned int& bindingIndex) noexcept;

  /// Function: BindElementBuffer
  ///
  /// Summary:
  ///   Binds an element buffer to the GLVertexArray object. If 0, the GLVertexArray object will have
  ///   no element buffer.
  ///
  /// Author: jkstpierre.
  ///
  /// Date: 4/11/2020.
  ///
  /// Parameters:
  /// ebo -   The ebo.
  void BindElementBuffer(const unsigned int& ebo) noexcept;
};
}

#endif

// End of Include\Nexus\Graphics\Base\GLVertexArray.hpp
