/// File: Include\Nexus\Graphics\GLVertexArrayBindingPoint.hpp.
///
/// Summary:  Declares the gl vertex array binding point class.

#ifndef __NEXUS_GRAPHICS_GLVERTEXARRAYBINDINGPOINT_HPP__
#define __NEXUS_GRAPHICS_GLVERTEXARRAYBINDINGPOINT_HPP__

#include <vector>
#include <Nexus\Graphics\Base\GLVertexArrayBindingPoint.hpp>
#include <Nexus\Graphics\GLBuffer.hpp>

namespace Nexus::Graphics
{
/// Summary:  The default vertex array binding point index
const unsigned int GLVERTEXARRAYBINDINGPOINT_DEFAULT_BINDING_POINT_INDEX = 0U;
/// Summary:  The default number of vertex array binding points.
const unsigned int GLVERTEXARRAYBINDINGPOINT_DEFAULT_BINDING_POINTS = 16U;
/// Summary:  The glvertexarraybindingpoint default divisor.
const unsigned int GLVERTEXARRAYBINDINGPOINT_DEFAULT_DIVISOR = 0U;
/// Summary:  Buffer for glvertexarraybindingpoint default vertex data.
const unsigned int GLVERTEXARRAYBINDINGPOINT_DEFAULT_VERTEX_BUFFER_GLID = 0U;

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
  unsigned int mVertexArrayGLID;
  /// Summary:  Zero-based index of the binding on the parent GLVertexArray.
  unsigned int mBindingPointIndex;
  /// Summary:  The glid of the bound vertex buffer to this binding point. 0 means no buffer is bound.
  unsigned int mVertexBufferGLID;

protected:
  /// Function: GLVertexArrayBindingPoint::GLVertexArrayBindingPoint
  ///
  /// Summary:  Constructor.
  ///
  /// Author: jkstpierre.
  ///
  /// Date: 4/11/2020.
  ///
  /// Parameters:
  /// vaoGLID -               The vao glid.
  /// vaoBindingPointIndex -  Zero-based index of the vao binding.
  GLVertexArrayBindingPoint(const unsigned int& vaoGLID, const unsigned int& vaoBindingPointIndex) noexcept;

  /// Function: GLVertexArrayBindingPoint::~GLVertexArrayBindingPoint
  ///
  /// Summary:  Destructor.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/11/2020
  virtual ~GLVertexArrayBindingPoint() noexcept;

public:
  /// Function: AllocateVertexArrayBindingPoints
  ///
  /// Summary:  Allocate vertex array binding points.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/18/2020
  ///
  /// Parameters:
  /// count -   Number of.
  ///
  /// Returns:  Null if it fails, else a std::vector&lt;GLVertexArrayBindingPoint*&gt;
  static std::vector<GLVertexArrayBindingPoint*> AllocateVertexArrayBindingPoints(const unsigned int& vaoGLID, const unsigned int& count);

  /// Function: FreeVertexArrayBindingPoints
  ///
  /// Summary:  Free vertex array binding points.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/18/2020
  ///
  /// Parameters:
  /// bindingPoints -   [in,out] [in,out] If non-null, the binding points.
  static void FreeVertexArrayBindingPoints(std::vector<GLVertexArrayBindingPoint*>& bindingPoints) noexcept;

  /// Function: QueryMaxVertexArrayBindingPoints
  ///
  /// Summary:  Queries max number of binding points that can be allocated for a vao
  ///
  /// Author: jkstpierre.
  ///
  /// Date: 4/18/2020.
  ///
  /// Returns:  The maximum binding points.
  static unsigned int QueryMaxVertexArrayBindingPoints() noexcept;

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
    Base::GLVertexArrayBindingPoint::SetVertexBuffer(mVertexArrayGLID, mBindingPointIndex, vbo ? vbo->GetGLID() : 0, 0, vbo ? sizeof(T) : 0);
    mVertexBufferGLID = vbo ? vbo->GetGLID() : 0; // Store the glid of the vertex buffer set
  }

  /// Function: SetVertexBuffer
  ///
  /// Summary:  Sets vertex buffer.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/18/2020
  ///
  /// Parameters:
  /// parameter1 -  The first parameter.
  void SetVertexBuffer(nullptr_t)
  {
    SetVertexBuffer<nullptr_t>(nullptr);
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
  /// Function: GetVertexArrayGLID
  ///
  /// Summary:  Gets gl vertex array glid.
  ///
  /// Author: jkstpierre.
  ///
  /// Date: 4/11/2020.
  ///
  /// Returns:  The gl vertex array glid.
  const unsigned int& GetVertexArrayGLID() const noexcept;

  /// Function: GetBindingIndex
  ///
  /// Summary:  Gets binding index.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/11/2020
  ///
  /// Returns:  The binding index.
  const unsigned int& GetBindingPointIndex() const noexcept;

  /// Function: GetVertexBufferIndex
  ///
  /// Summary:  Gets vertex buffer index.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/18/2020
  ///
  /// Returns:  The vertex buffer index.
  const unsigned int& GetVertexBufferGLID() const noexcept;
};
}

#endif

// End of Include\Nexus\Graphics\GLVertexArrayBindingPoint.hpp
