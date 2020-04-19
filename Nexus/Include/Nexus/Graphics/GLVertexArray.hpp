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
  std::vector<GLVertexArrayAttribute*> mAttributes;
  /// Summary:  The binding points for the VAO.
  std::vector<GLVertexArrayBindingPoint*> mBindingPoints;

public:
  /// Function: GLVertexArray::GLVertexArray
  ///
  /// Summary:  Default constructor.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/9/2020
  GLVertexArray();

  /// Function: GLVertexArray::GLVertexArray
  ///
  /// Summary:  Constructor.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/18/2020
  ///
  /// Parameters:
  /// attributes -      The number of attributes to allocate.
  /// bindingPoints -   The number of binding points to allocate.
  GLVertexArray(const unsigned int& attributes, const unsigned int& bindingPoints);

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
  /// Function: GetAttributes
  ///
  /// Summary:  Gets the attributes.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/18/2020
  ///
  /// Returns:  Null if it fails, else the attributes.
  std::vector<GLVertexArrayAttribute*>& GetAttributes() noexcept;

  /// Function: GetBindingPoints
  ///
  /// Summary:  Gets binding points.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/18/2020
  ///
  /// Returns:  Null if it fails, else the binding points.
  std::vector<GLVertexArrayBindingPoint*>& GetBindingPoints() noexcept;

  /// Function: GetElementBufferGLID
  ///
  /// Summary:  Gets element buffer glid.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/18/2020
  ///
  /// Returns:  The element buffer glid.
  unsigned int GetElementBufferGLID() const noexcept;
};
}

#endif

// End of Include\Nexus\Graphics\GLVertexArray.hpp
