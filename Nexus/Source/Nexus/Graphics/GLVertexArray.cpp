/// File: Source\Nexus\Graphics\GLVertexArray.cpp.
///
/// Summary:  Implements the gl vertex array class.

#include <GLAD\GL.h>
#include <Nexus\Graphics\GLVertexArray.hpp>
#include <Nexus\DebugWriter.hpp>

namespace Nexus::Graphics
{
GLVertexArray::GLVertexArray() : GLVertexArray(GLVERTEXARRAYATTRIBUTE_DEFAULT_ATTRIBUTES, GLVERTEXARRAYBINDINGPOINT_DEFAULT_BINDING_POINTS)
{
  
}

GLVertexArray::GLVertexArray(const unsigned int& attributes, const unsigned int& bindingPoints)
{
  // Create vao
  glCreateVertexArrays(1, &mGLID);

  // Create starting binding points
  mBindingPoints = GLVertexArrayBindingPoint::AllocateVertexArrayBindingPoints(
    mGLID, bindingPoints);

  // Get reference to the default binding point for all attributes
  const GLVertexArrayBindingPoint& defaultBindingPoint =
    *mBindingPoints.at(GLVERTEXARRAYBINDINGPOINT_DEFAULT_BINDING_POINT_INDEX);

  // Create starting attributes
  mAttributes = GLVertexArrayAttribute::AllocateVertexArrayAttributes(
    mGLID, defaultBindingPoint, attributes);

  DebugWriter().Write("GLVertexArray %u created.\n", mGLID);
}

GLVertexArray::~GLVertexArray() noexcept
{
  // Delete all attributes
  GLVertexArrayAttribute::FreeVertexArrayAttributes(mAttributes);

  // Delete all binding points
  GLVertexArrayBindingPoint::FreeVertexArrayBindingPoints(mBindingPoints);

  // Delete vao
  glDeleteVertexArrays(1, &mGLID);

  DebugWriter().Write("GLVertexArray %u destroyed.\n", mGLID);
}

void GLVertexArray::Bind() noexcept
{
  glBindVertexArray(mGLID);
}

void GLVertexArray::SetElementBuffer(const GLBuffer<unsigned int>* ebo) noexcept
{
  glVertexArrayElementBuffer(mGLID, ebo ? ebo->GetGLID() : GL_NONE);
}

std::vector<GLVertexArrayAttribute*>& GLVertexArray::GetAttributes() noexcept
{
  return mAttributes;
}

std::vector<GLVertexArrayBindingPoint*>& GLVertexArray::GetBindingPoints() noexcept
{
  return mBindingPoints;
}

unsigned int GLVertexArray::GetElementBufferGLID() const noexcept
{
  int ebo;

  glGetVertexArrayiv(mGLID, GL_ELEMENT_ARRAY_BUFFER_BINDING, &ebo);

  return static_cast<unsigned int>(ebo);
}
}

// End of Source\Nexus\Graphics\GLVertexArray.cpp
