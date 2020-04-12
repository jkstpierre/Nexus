/// File: Source\Nexus\Graphics\GLVertexArrayAttribute.cpp.
///
/// Summary:  Implements the gl vertex array attribute class.

#include <GLAD\GL.h>
#include <Nexus\Graphics\GLVertexArrayAttribute.hpp>

namespace Nexus::Graphics
{
GLVertexArrayAttribute::GLVertexArrayAttribute(const unsigned int& vaoGLID, const unsigned int& vaoAttributeIndex, const GLVertexArrayBindingPoint& vaoBindingPoint) noexcept :
  mGLVertexArrayGLID(vaoGLID), mAttributeIndex(vaoAttributeIndex), 
  mSize(GLVERTEXARRAYATTRIBUTE_DEFAULT_SIZE), 
  mType(GLVERTEXARRAYATTRIBUTE_DEFAULT_TYPE),
  mRelativeOffset(GLVERTEXARRAYATTRIBUTE_DEFAULT_RELATIVE_OFFSET),
  mEnabled(GLVERTEXARRAYATTRIBUTE_DEFAULT_ENABLED),
  mBindingPoint(&vaoBindingPoint)
{
  SetBindingPoint(vaoBindingPoint); // Set the initial binding point for the attribute
}

void GLVertexArrayAttribute::Format(const unsigned int& size, const GLType& type, const unsigned int& relativeOffset) noexcept
{
  if ( type == GLType::_FLOAT )
  {
    // Format regular floating point attributes
    glVertexArrayAttribFormat(mGLVertexArrayGLID, mAttributeIndex, size, static_cast<GLenum>(type), GL_FALSE, relativeOffset);
  }
  else if ( type == GLType::_DOUBLE )
  {
    // Format double precision floating point attributes
    glVertexArrayAttribLFormat(mGLVertexArrayGLID, mAttributeIndex, size, static_cast<GLenum>(type), relativeOffset);
  }
  else
  {
    // Format integer attributes
    glVertexArrayAttribIFormat(mGLVertexArrayGLID, mAttributeIndex, size, static_cast<GLenum>(type), relativeOffset);
  }
  
  mSize = size;
  mType = type;
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
  mBindingPoint = &vaoBindingPoint; // Set the binding point for the attribute
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

const unsigned int& GLVertexArrayAttribute::GetRelativeOffset() const noexcept
{
  return mRelativeOffset;
}

const bool& GLVertexArrayAttribute::IsEnabled() const noexcept
{
  return mEnabled;
}

const GLVertexArrayBindingPoint& GLVertexArrayAttribute::GetBindingPoint() const noexcept
{
  return *mBindingPoint;
}
}

// End of Source\Nexus\Graphics\GLVertexArrayAttribute.cpp
