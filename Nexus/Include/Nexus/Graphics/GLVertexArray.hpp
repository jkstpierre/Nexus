/// File: Include\Nexus\Graphics\GLVertexArray.hpp.
///
/// Summary:  Declares the gl vertex array class.

#ifndef __NEXUS_GRAPHICS_GLVERTEXARRAY_HPP__
#define __NEXUS_GRAPHICS_GLVERTEXARRAY_HPP__

#include <array>
#include <Nexus\Graphics\Base\GLObject.hpp>
#include <Nexus\Graphics\GLVertexArrayAttribute.hpp>
#include <Nexus\Graphics\GLVertexArrayBindingPoint.hpp>

namespace Nexus::Graphics
{
/// Summary:  The glvertexarray maximum attributes.
const unsigned int GLVERTEXARRAY_MAX_ATTRIBUTES = 16U;
/// Summary:  The glvertexarray maximum binding points.
const unsigned int GLVERTEXARRAY_MAX_BINDING_POINTS = 16U;
/// Summary:  The glvertexarray default binding point.
const unsigned int GLVERTEXARRAY_DEFAULT_BINDING_POINT = 0U;

/// Class:  GLVertexArray
///
/// Summary:  Frontend wrapper of the GLVertexArray object for use by the end user.
///
/// Author: jkstpierre
///
/// Date: 4/9/2020
class GLVertexArray : public Base::GLObject
{
private:
  /// Summary:  The attributes.
  std::array<GLVertexArrayAttribute*, GLVERTEXARRAY_MAX_ATTRIBUTES> mAttributes;
  /// Summary:  The binding points.
  std::array<GLVertexArrayBindingPoint*, GLVERTEXARRAY_MAX_BINDING_POINTS> mBindingPoints;

public:
  /// Function: GLVertexArray::GLVertexArray
  ///
  /// Summary:  Default constructor.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/9/2020
  GLVertexArray() noexcept;

  /// Function: GLVertexArray::~GLVertexArray
  ///
  /// Summary:  Destructor.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/9/2020
  virtual ~GLVertexArray() noexcept;

public:
  /// Function: Bind
  ///
  /// Summary:  Binds this GLVertexArray object for use during drawing. 
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/11/2020
  void Bind() noexcept;

  /// Function: SetElementBuffer
  ///
  /// Summary:  Sets element buffer. If ebo is nullptr, vao will have no associated element array buffer.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/11/2020
  ///
  /// Parameters:
  /// ebo -   The ebo.
  void SetElementBuffer(const GLBuffer<unsigned int>* ebo) noexcept;

public:
  /// Function: GetAttribute
  ///
  /// Summary:  Gets an attribute.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/11/2020
  ///
  /// Parameters:
  /// attributeIndex -  Zero-based index of the attribute.
  ///
  /// Returns:  The attribute.
  GLVertexArrayAttribute& GetAttribute(const unsigned int& attributeIndex);

  /// Function: GetBindingPoint
  ///
  /// Summary:  Gets binding point.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/11/2020
  ///
  /// Parameters:
  /// bindingIndex -  Zero-based index of the binding.
  ///
  /// Returns:  The binding point.
  GLVertexArrayBindingPoint& GetBindingPoint(const unsigned int& bindingIndex);
};
}

#endif

// End of Include\Nexus\Graphics\GLVertexArray.hpp
