/// File: Source\Nexus\Graphics\GLVertexArrayAttribute.cpp.
///
/// Summary:  Implements the gl vertex array attribute class.

#include <GLAD\GL.h>
#include <Nexus\Graphics\GLVertexArrayAttribute.hpp>

namespace Nexus::Graphics
{
GLVertexArrayAttribute::GLVertexArrayAttribute(const unsigned int& vaoGLID, const unsigned int& vaoAttributeIndex) noexcept :
  mGLVertexArrayGLID(vaoGLID), mAttributeIndex(vaoAttributeIndex), 
  mSize(GLVERTEXARRAYATTRIBUTE_DEFAULT_SIZE), 
  mType(GLVERTEXARRAYATTRIBUTE_DEFAULT_TYPE),
  mNormalized(GLVERTEXARRAYATTRIBUTE_DEFAULT_NORMALIZED),
  mRelativeOffset(GLVERTEXARRAYATTRIBUTE_DEFAULT_RELATIVE_OFFSET),
  mEnabled(GLVERTEXARRAYATTRIBUTE_DEFAULT_ENABLED)
{

}

void GLVertexArrayAttribute::Format(const unsigned int& size, const GLType& type, const bool& normalized, const unsigned int& relativeOffset) noexcept
{
  glVertexArrayAttribFormat(mGLVertexArrayGLID, mAttributeIndex, size, static_cast<GLenum>(type), normalized, relativeOffset);

  mSize = size;
  mType = type;
  mNormalized = normalized;
  mRelativeOffset = relativeOffset;
}

void GLVertexArrayAttribute::Enable() noexcept
{
  glEnableVertexArrayAttrib(mGLVertexArrayGLID, mAttributeIndex);
  mEnabled = true;
}

void GLVertexArrayAttribute::Disable() noexcept
{
  glDisableVertexArrayAttrib(mGLVertexArrayGLID, mAttributeIndex);
  mEnabled = false;
}

void GLVertexArrayAttribute::SetBindingPoint(const GLVertexArrayBindingPoint& vaoBindingPoint) noexcept
{
  glVertexArrayAttribBinding(mGLVertexArrayGLID, mAttributeIndex, vaoBindingPoint.GetBindingIndex());
}

const unsigned int& GLVertexArrayAttribute::GetGLVertexArrayGLID() const noexcept
{
  return mGLVertexArrayGLID;
}

const unsigned int& GLVertexArrayAttribute::GetAttributeIndex() const noexcept
{
  return mAttributeIndex;
}

const unsigned int& GLVertexArrayAttribute::GetSize() const noexcept
{
  return mSize;
}

const GLType& GLVertexArrayAttribute::GetType() const noexcept
{
  return mType;
}

const bool& GLVertexArrayAttribute::IsNormalized() const noexcept
{
  return mNormalized;
}

const unsigned int& GLVertexArrayAttribute::GetRelativeOffset() const noexcept
{
  return mRelativeOffset;
}

const bool& GLVertexArrayAttribute::IsEnabled() const noexcept
{
  return mEnabled;
}
}

// End of Source\Nexus\Graphics\GLVertexArrayAttribute.cpp
