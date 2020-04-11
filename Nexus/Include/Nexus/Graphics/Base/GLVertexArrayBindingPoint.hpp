/// File: Include\Nexus\Graphics\Base\GLVertexArrayBindingPoint.hpp.
///
/// Summary:  Declares the gl vertex array binding point class.

#ifndef __NEXUS_GRAPHICS_BASE_GLVERTEXARRAYBINDINGPOINT_HPP__
#define __NEXUS_GRAPHICS_BASE_GLVERTEXARRAYBINDINGPOINT_HPP__

namespace Nexus::Graphics::Base
{
/// Class:  GLVertexArrayBindingPoint
///
/// Summary:
///   Backend implementation for GLVertexArrayBindingPoint objects. This class is an abstract base
///   class and cannot be instantiated. Use the templated wrapper class of the same name instead.
///
/// Author: jkstpierre.
///
/// Date: 4/11/2020.
class GLVertexArrayBindingPoint
{
protected:
  /// Function: GLVertexArrayBindingPoint::GLVertexArrayBindingPoint
  ///
  /// Summary:  Default constructor.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/11/2020
  GLVertexArrayBindingPoint() = default;

  /// Function: GLVertexArrayBindingPoint::~GLVertexArrayBindingPoint
  ///
  /// Summary:  Destructor.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/11/2020
  virtual ~GLVertexArrayBindingPoint() = default;

protected:
  /// Function: SetVertexBuffer
  ///
  /// Summary:  Bind vertex buffer.
  ///
  /// Author: jkstpierre.
  ///
  /// Date: 4/11/2020.
  ///
  /// Parameters:
  /// vao -               The vao.
  /// vaoBindingIndex -   Zero-based index of the vao binding.
  /// vbo -               The vbo.
  /// offset -            The offset.
  /// stride -            The stride.
  void SetVertexBuffer(const unsigned int& vao, const unsigned int& vaoBindingIndex, const unsigned int& vbo, 
                       const unsigned int& offset, const unsigned int& stride) noexcept;
};
}

#endif

// End of Include\Nexus\Graphics\Base\GLVertexArrayBindingPoint.hpp
