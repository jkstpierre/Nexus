/// File: Source\Nexus\Graphics\GLVertexArrayAttribute.cpp.
///
/// Summary:  Implements the gl vertex array attribute class.

#include <GLAD\GL.h>
#include <Nexus\Graphics\GLVertexArrayAttribute.hpp>
#include <Nexus\DebugWriter.hpp>
#include <Nexus\Exception.hpp>

namespace Nexus::Graphics
{
GLVertexArrayAttribute::GLVertexArrayAttribute(const unsigned int& vaoGLID, const unsigned int& vaoAttributeIndex, const GLVertexArrayBindingPoint& vaoBindingPoint) noexcept :
  mVertexArrayGLID(vaoGLID),
  mAttributeIndex(vaoAttributeIndex), 
  mBindingPointIndex(vaoBindingPoint.GetBindingPointIndex())
{
  SetBindingPoint(vaoBindingPoint); // Set the initial binding point for the attribute

  DebugWriter().Write("GLVertexArrayAttribute %u created for GLVertexArray %u.\n",
                      mAttributeIndex, mVertexArrayGLID);
}

GLVertexArrayAttribute::~GLVertexArrayAttribute() noexcept
{
  DebugWriter().Write("GLVertexArrayAttribute %u destroyed for GLVertexArray %u.\n",
                      mAttributeIndex, mVertexArrayGLID);
}

std::vector<GLVertexArrayAttribute*> GLVertexArrayAttribute::AllocateVertexArrayAttributes(
  const unsigned int& vaoGLID,
  const GLVertexArrayBindingPoint& vaoBindingPoint,
  const unsigned int& count)
{
  /// Summary:  Get the maximum number of attributes that can be generated
  unsigned int maxAttributes = QueryMaxVertexArrayAttributes();
  
  // Create the attributes
  if ( count <= maxAttributes )
  {
    std::vector<GLVertexArrayAttribute*> attributes;

    for ( unsigned int i = 0; i < count; i++ )
    {
      attributes.push_back(new GLVertexArrayAttribute(vaoGLID, i, vaoBindingPoint));
    }

    return attributes;
  }
  else
  {
    throw Exception("GLVertexArrayAttribute Error: Cannot allocate %u attributes. Maximum is %u.\n",
                    count, maxAttributes);
  }
}

void GLVertexArrayAttribute::FreeVertexArrayAttributes(std::vector<GLVertexArrayAttribute*>& attributes) noexcept
{
  for ( auto& attribute : attributes )
  {
    delete attribute;
  }

  attributes.clear();
}

unsigned int GLVertexArrayAttribute::QueryMaxVertexArrayAttributes() noexcept
{
  int maxAttributes;

  glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &maxAttributes);

  return maxAttributes;
}

void GLVertexArrayAttribute::Format(const unsigned int& size, const GLType& type, const unsigned int& relativeOffset) noexcept
{
  if ( type == GLType::_FLOAT )
  {
    // Format regular floating point attributes
    glVertexArrayAttribFormat(mVertexArrayGLID, mAttributeIndex, size, static_cast<GLenum>(type), GL_FALSE, relativeOffset);
  }
  else if ( type == GLType::_DOUBLE )
  {
    // Format double precision floating point attributes
    glVertexArrayAttribLFormat(mVertexArrayGLID, mAttributeIndex, size, static_cast<GLenum>(type), relativeOffset);
  }
  else
  {
    // Format integer attributes
    glVertexArrayAttribIFormat(mVertexArrayGLID, mAttributeIndex, size, static_cast<GLenum>(type), relativeOffset);
  }
}

void GLVertexArrayAttribute::Enable() noexcept
{
  glEnableVertexArrayAttrib(mVertexArrayGLID, mAttributeIndex);
}

void GLVertexArrayAttribute::Disable() noexcept
{
  glDisableVertexArrayAttrib(mVertexArrayGLID, mAttributeIndex);
}

void GLVertexArrayAttribute::SetBindingPoint(const GLVertexArrayBindingPoint& vaoBindingPoint) noexcept
{
  glVertexArrayAttribBinding(mVertexArrayGLID, mAttributeIndex, vaoBindingPoint.GetBindingPointIndex());
  mBindingPointIndex = vaoBindingPoint.GetBindingPointIndex(); // Set the binding point for the attribute
}

const unsigned int& GLVertexArrayAttribute::GetVertexArrayGLID() const noexcept
{
  return mVertexArrayGLID;
}

const unsigned int& GLVertexArrayAttribute::GetAttributeIndex() const noexcept
{
  return mAttributeIndex;
}

unsigned int GLVertexArrayAttribute::GetSize() const noexcept
{
  int size;

  glGetVertexArrayIndexediv(mVertexArrayGLID, mAttributeIndex, GL_VERTEX_ATTRIB_ARRAY_SIZE, &size);

  return static_cast<unsigned int>(size);
}

GLType GLVertexArrayAttribute::GetType() const noexcept
{
  int type;

  glGetVertexArrayIndexediv(mVertexArrayGLID, mAttributeIndex, GL_VERTEX_ATTRIB_ARRAY_TYPE, &type);

  return static_cast<GLType>(type);
}

unsigned int GLVertexArrayAttribute::GetRelativeOffset() const noexcept
{
  int relativeOffset;

  glGetVertexArrayIndexediv(mVertexArrayGLID, mAttributeIndex, GL_VERTEX_ATTRIB_RELATIVE_OFFSET, &relativeOffset);

  return static_cast<unsigned int>(relativeOffset);
}

unsigned int GLVertexArrayAttribute::GetStride() const noexcept
{
  int stride;

  glGetVertexArrayIndexediv(mVertexArrayGLID, mAttributeIndex, GL_VERTEX_ATTRIB_ARRAY_STRIDE, &stride);

  return static_cast<unsigned int>(stride);
}

unsigned int GLVertexArrayAttribute::GetDivisor() const noexcept
{
  int divisor;

  glGetVertexArrayIndexediv(mVertexArrayGLID, mAttributeIndex, GL_VERTEX_ATTRIB_ARRAY_DIVISOR, &divisor);

  return static_cast<unsigned int>(divisor);
}

bool GLVertexArrayAttribute::IsEnabled() const noexcept
{
  int enabled;

  glGetVertexArrayIndexediv(mVertexArrayGLID, mAttributeIndex, GL_VERTEX_ATTRIB_ARRAY_ENABLED, &enabled);

  return enabled;
}

const unsigned int& GLVertexArrayAttribute::GetBindingPointIndex() const noexcept
{
  return mBindingPointIndex;
}
}

// End of Source\Nexus\Graphics\GLVertexArrayAttribute.cpp
