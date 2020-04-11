/// File: Include\Nexus\Graphics\GLVertexArrayAttribute.hpp.
///
/// Summary:  Declares the gl vertex array attribute class.

#ifndef __NEXUS_GRAPHICS_GLVERTEXARRAYATTRIBUTE_HPP__
#define __NEXUS_GRAPHICS_GLVERTEXARRAYATTRIBUTE_HPP__

#include <Nexus\Graphics\GLType.hpp>
#include <Nexus\Graphics\GLVertexArrayBindingPoint.hpp>

namespace Nexus::Graphics
{
/// Summary:  Size of the glvertexarrayattribute default.
const unsigned int GLVERTEXARRAYATTRIBUTE_DEFAULT_SIZE = 4U;
/// Summary:  Type of the glvertexarrayattribute default.
const GLType GLVERTEXARRAYATTRIBUTE_DEFAULT_TYPE = GLType::_FLOAT;
/// Summary:  True if glvertexarrayattribute default normalized.
const bool GLVERTEXARRAYATTRIBUTE_DEFAULT_NORMALIZED = false;
/// Summary:  The glvertexarrayattribute default relative offset.
const unsigned int GLVERTEXARRAYATTRIBUTE_DEFAULT_RELATIVE_OFFSET = 0U;
/// Summary:  True to enable, false to disable the glvertexarrayattribute default.
const bool GLVERTEXARRAYATTRIBUTE_DEFAULT_ENABLED = false;

/// Class:  GLVertexArrayAttribute
///
/// Summary:  Attribute for gl vertex array.
///
/// Author: jkstpierre
///
/// Date: 4/11/2020
class GLVertexArrayAttribute
{
private:
  /// Summary:  The gl vertex array glid.
  unsigned int mGLVertexArrayGLID;
  /// Summary:  Zero-based index of the attribute.
  unsigned int mAttributeIndex;
  /// Summary:  The size.
  unsigned int mSize;
  /// Summary:  The type.
  GLType mType;
  /// Summary:  True if normalized.
  bool mNormalized;
  /// Summary:  The relative offset.
  unsigned int mRelativeOffset;
  /// Summary:  True to enable, false to disable.
  bool mEnabled;

public:
  /// Function: GLVertexArrayAttribute::GLVertexArrayAttribute
  ///
  /// Summary:  Constructor.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/11/2020
  ///
  /// Parameters:
  /// vaoGLID -             The vao glid.
  /// vaoAttributeIndex -   Zero-based index of the vao attribute.
  GLVertexArrayAttribute(const unsigned int& vaoGLID, const unsigned int& vaoAttributeIndex) noexcept;

public:
  /// Function: Format
  ///
  /// Summary:  Formats the attribute.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/11/2020
  ///
  /// Parameters:
  /// size -            The size.
  /// type -            The type.
  /// normalized -      True if normalized.
  /// relativeOffset -  The relative offset.
  void Format(const unsigned int& size, const GLType& type, const bool& normalized, const unsigned int& relativeOffset) noexcept;

  /// Function: Enable
  ///
  /// Summary:  Enables this attribute. 
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/11/2020
  void Enable() noexcept;

  /// Function: Disable
  ///
  /// Summary:  Disables this attribute. 
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/11/2020
  void Disable() noexcept;

  /// Function: SetBindingPoint
  ///
  /// Summary:  Sets binding point.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/11/2020
  ///
  /// Parameters:
  /// vaoBindingPoint -   The vao binding point.
  void SetBindingPoint(const GLVertexArrayBindingPoint& vaoBindingPoint) noexcept;

public:
  /// Function: GetGLVertexArrayGLID
  ///
  /// Summary:  Gets gl vertex array glid.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/11/2020
  ///
  /// Returns:  The gl vertex array glid.
  const unsigned int& GetGLVertexArrayGLID() const noexcept;

  /// Function: GetAttributeIndex
  ///
  /// Summary:  Gets attribute index.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/11/2020
  ///
  /// Returns:  The attribute index.
  const unsigned int& GetAttributeIndex() const noexcept;

  /// Function: GetSize
  ///
  /// Summary:  Gets the size.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/11/2020
  ///
  /// Returns:  The size.
  const unsigned int& GetSize() const noexcept;

  /// Function: GetType
  ///
  /// Summary:  Gets the type.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/11/2020
  ///
  /// Returns:  The type.
  const GLType& GetType() const noexcept;

  /// Function: IsNormalized
  ///
  /// Summary:  Is normalized.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/11/2020
  ///
  /// Returns:  A reference to a const bool.
  const bool& IsNormalized() const noexcept;

  /// Function: GetRelativeOffset
  ///
  /// Summary:  Gets relative offset.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/11/2020
  ///
  /// Returns:  The relative offset.
  const unsigned int& GetRelativeOffset() const noexcept;

  /// Function: IsEnabled
  ///
  /// Summary:  Is enabled.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/11/2020
  ///
  /// Returns:  A reference to a const bool.
  const bool& IsEnabled() const noexcept;
};
}

#endif

// End of Include\Nexus\Graphics\GLVertexArrayAttribute.hpp
