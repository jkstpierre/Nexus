/// File: Source\Nexus\Graphics\GLVertexArrayBindingPoint.cpp.
///
/// Summary:  Implements the gl vertex array binding point class.

#include <GLAD\GL.h>
#include <Nexus\Graphics\GLVertexArrayBindingPoint.hpp>

namespace Nexus::Graphics
{
GLVertexArrayBindingPoint::GLVertexArrayBindingPoint(const unsigned int& vaoGLID, const unsigned int& vaoBindingIndex) noexcept :
  mGLVertexArrayGLID(vaoGLID), mBindingIndex(vaoBindingIndex), mDivisor(0)
{}

void GLVertexArrayBindingPoint::SetDivisor(const unsigned int& divisor) noexcept
{
  glVertexArrayBindingDivisor(mGLVertexArrayGLID, mBindingIndex, divisor);
  mDivisor = divisor;
}

const unsigned int& GLVertexArrayBindingPoint::GetGLVertexArrayGLID() const noexcept
{
  return mGLVertexArrayGLID;
}

const unsigned int& GLVertexArrayBindingPoint::GetBindingIndex() const noexcept
{
  return mBindingIndex;
}

const unsigned int& GLVertexArrayBindingPoint::GetDivisor() const noexcept
{
  return mDivisor;
}
}

// End of Source\Nexus\Graphics\GLVertexArrayBindingPoint.cpp
