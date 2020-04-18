/// File: Include\Nexus\Graphics\GLVertexArrayAttribute.hpp.
///
/// Summary:  Declares the gl vertex array attribute class.

#ifndef __NEXUS_GRAPHICS_GLVERTEXARRAYATTRIBUTE_HPP__
#define __NEXUS_GRAPHICS_GLVERTEXARRAYATTRIBUTE_HPP__

#include <Nexus\Graphics\GLType.hpp>
#include <Nexus\Graphics\GLVertexArrayBindingPoint.hpp>

namespace Nexus::Graphics
{
/// Summary:  The maximum number of attributes
const unsigned int GLVERTEXARRAYATTRIBUTE_DEFAULT_ATTRIBUTES = 16U;

/// Function: offset_of< T1, T2>
///
/// Summary:  Calculates the offset in bytes for fields
///
/// Typeparams:
/// T1 -        Generic type parameter.
/// T2 -        Generic type parameter.
/// Parameters:
/// member -  [in,out] If non-null, the member.
template <typename T1, typename T2>
inline size_t constexpr offset_of(T1 T2::* member)
{
  constexpr T2 object{};
  return size_t(&(object.*member)) - size_t(&object);
}

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
  unsigned int mVertexArrayGLID;
  /// Summary:  Zero-based index of the attribute.
  unsigned int mAttributeIndex;
  /// Summary:  The binding point this attribute is reading from.
  unsigned int mBindingPointIndex;

protected:
  /// Function: GLVertexArrayAttribute::GLVertexArrayAttribute
  ///
  /// Summary:  Constructor.
  ///
  /// Author: jkstpierre.
  ///
  /// Date: 4/11/2020.
  ///
  /// Parameters:
  /// vaoGLID -             The vao glid.
  /// vaoAttributeIndex -   Zero-based index of the vao attribute.
  /// vaoBindingPoint -     The vao binding point.
  GLVertexArrayAttribute(const unsigned int& vaoGLID, const unsigned int& vaoAttributeIndex, const GLVertexArrayBindingPoint& vaoBindingPoint) noexcept;

  /// Function: GLVertexArrayAttribute::~GLVertexArrayAttribute
  ///
  /// Summary:  Destructor.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/18/2020
  virtual ~GLVertexArrayAttribute() noexcept;

public:
  /// Function: AllocateVertexArrayAttributes
  ///
  /// Summary:  Allocate vertex array attributes.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/18/2020
  ///
  /// Parameters:
  /// vaoGLID -           The vao glid.
  /// vaoBindingPoint -   The vao binding point.
  /// count -             Number of.
  ///
  /// Returns:  Null if it fails, else a std::vector&lt;GLVertexArrayAttribute*&gt;
  static std::vector<GLVertexArrayAttribute*> AllocateVertexArrayAttributes(
    const unsigned int& vaoGLID, 
    const GLVertexArrayBindingPoint& vaoBindingPoint, 
    const unsigned int& count);

  /// Function: FreeVertexArrayAttributes
  ///
  /// Summary:  Free vertex array attributes.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/18/2020
  ///
  /// Parameters:
  /// attributes -  [in,out] [in,out] If non-null, the attributes.
  static void FreeVertexArrayAttributes(std::vector<GLVertexArrayAttribute*>& attributes) noexcept;

  /// Function: QueryMaxVertexArrayAttributes
  ///
  /// Summary:  Queries maximum vertex array attributes.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/18/2020
  ///
  /// Returns:  The maximum vertex array attributes.
  static unsigned int QueryMaxVertexArrayAttributes() noexcept;

public:
  /// Function: Format
  ///
  /// Summary:  Formats the attribute.
  ///
  /// Author: jkstpierre.
  ///
  /// Date: 4/11/2020.
  ///
  /// Parameters:
  /// size -            The size.
  /// type -            The type.
  /// relativeOffset -  The relative offset.
  void Format(const unsigned int& size, const GLType& type, const unsigned int& relativeOffset) noexcept;

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
  const unsigned int& GetVertexArrayGLID() const noexcept;

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
  unsigned int GetSize() const noexcept;

  /// Function: GetType
  ///
  /// Summary:  Gets the type.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/11/2020
  ///
  /// Returns:  The type.
  GLType GetType() const noexcept;

  /// Function: GetRelativeOffset
  ///
  /// Summary:  Gets relative offset.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/11/2020
  ///
  /// Returns:  The relative offset.
  unsigned int GetRelativeOffset() const noexcept;

  /// Function: GetStride
  ///
  /// Summary:
  ///   Gets the distance in bytes between successive elements of this attribute. This value is set
  ///   in the GLVertexArrayBindingPoint this attribute is attached to.
  ///
  /// Author: jkstpierre.
  ///
  /// Date: 4/18/2020.
  ///
  /// Returns:  The stride.
  unsigned int GetStride() const noexcept;

  /// Function: GetDivisor
  ///
  /// Summary:
  ///   Gets the divisor for this attribute. This value is set in the GLVertexArrayBindingPoint this
  ///   attribute is attached to.
  ///
  /// Author: jkstpierre.
  ///
  /// Date: 4/18/2020.
  ///
  /// Returns:  The divisor.
  unsigned int GetDivisor() const noexcept;

  /// Function: IsEnabled
  ///
  /// Summary:  Is enabled.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/11/2020
  ///
  /// Returns:  A reference to a const bool.
  bool IsEnabled() const noexcept;

  /// Function: GetBindingPoint
  ///
  /// Summary:
  ///   Gets binding point. Warning: If binding point is changed, this function needs to be called
  ///   again to get the current binding point.
  ///
  /// Author: jkstpierre.
  ///
  /// Date: 4/12/2020.
  ///
  /// Returns:  The binding point.
  const unsigned int& GetBindingPointIndex() const noexcept;
};
}

#endif

// End of Include\Nexus\Graphics\GLVertexArrayAttribute.hpp
