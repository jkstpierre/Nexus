/// File: Include\Nexus\Graphics\GLVertexArrayBindingPoint.hpp.
///
/// Summary:  Declares the gl vertex array binding point class.

#ifndef __NEXUS_GRAPHICS_GLVERTEXARRAYBINDINGPOINT_HPP__
#define __NEXUS_GRAPHICS_GLVERTEXARRAYBINDINGPOINT_HPP__

#include <Nexus\Graphics\Base\GLVertexArrayBindingPoint.hpp>
#include <Nexus\Graphics\GLBuffer.hpp>

namespace Nexus::Graphics
{
/// Class:  GLVertexArrayBindingPoint
///
/// Summary:  Frontend wrapper for the GLVertexArrayBindingPoint
///
/// Author: jkstpierre
///
/// Date: 4/11/2020
///
/// See:
/// Base::GLVertexArrayBindingPoint - 
class GLVertexArrayBindingPoint : public Base::GLVertexArrayBindingPoint
{
private:
  /// Summary:  The gl vertex array glid.
  unsigned int mGLVertexArrayGLID;
  /// Summary:  Zero-based index of the binding on the parent GLVertexArray.
  unsigned int mBindingIndex;
  /// Summary:  The divisor.
  unsigned int mDivisor;

public:
  /// Function: GLVertexArrayBindingPoint::GLVertexArrayBindingPoint
  ///
  /// Summary:  Constructor.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/11/2020
  ///
  /// Parameters:
  /// vaoGLID -           The vao glid.
  /// vaoBindingIndex -   Zero-based index of the vao binding.
  GLVertexArrayBindingPoint(const unsigned int& vaoGLID, const unsigned int& vaoBindingIndex) noexcept;

  /// Function: GLVertexArrayBindingPoint::~GLVertexArrayBindingPoint
  ///
  /// Summary:  Destructor.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/11/2020
  virtual ~GLVertexArrayBindingPoint() noexcept = default;

public:
  /// Function: SetVertexBuffer< T>
  ///
  /// Summary:
  ///   Set a vertex buffer to the binding point calling off to the backend implementation. If vbo is
  ///   nullptr, binding point will have no associated buffer.
  ///
  /// Typeparams:
  /// T -   Generic type parameter.
  /// Parameters:
  /// vbo -   The vbo.
  template <typename T>
  void SetVertexBuffer(const GLBuffer<T>* vbo) noexcept
  {
    Base::GLVertexArrayBindingPoint::SetVertexBuffer(mGLVertexArrayGLID, mBindingIndex, vbo ? vbo->GetGLID() : 0, 0, sizeof(T));
  }

  /// Function: SetDivisor
  ///
  /// Summary:  Sets a divisor for instanced rendering.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/11/2020
  ///
  /// Parameters:
  /// divisor -   The divisor.
  void SetDivisor(const unsigned int& divisor) noexcept;

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

  /// Function: GetBindingIndex
  ///
  /// Summary:  Gets binding index.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/11/2020
  ///
  /// Returns:  The binding index.
  const unsigned int& GetBindingIndex() const noexcept;

  /// Function: GetDivisor
  ///
  /// Summary:  Gets the divisor.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/11/2020
  ///
  /// Returns:  The divisor.
  const unsigned int& GetDivisor() const noexcept;
};
}

#endif

// End of Include\Nexus\Graphics\GLVertexArrayBindingPoint.hpp
