/// File: Source\Nexus\Graphics\GLVertexArray.cpp.
///
/// Summary:  Implements the gl vertex array class.

#include <GLAD\GL.h>
#include <Nexus\Graphics\GLVertexArray.hpp>
#include <Nexus\DebugWriter.hpp>
#include <Nexus\Exception.hpp>

namespace Nexus::Graphics
{
GLVertexArray::GLVertexArray() noexcept : mAttributes{ NULL }, mBindingPoints{ NULL }
{
  // Create vao
  glCreateVertexArrays(1, &mGLID);

  // Create starting attributes
  for ( unsigned int i = 0; i < GLVERTEXARRAY_MAX_ATTRIBUTES; i++ )
  {
    mAttributes[i] = new GLVertexArrayAttribute(mGLID, i);
  }

  // Create starting binding points
  for ( unsigned int i = 0; i < GLVERTEXARRAY_MAX_BINDING_POINTS; i++ )
  {
    mBindingPoints[i] = new GLVertexArrayBindingPoint(mGLID, i);
  }

  DebugWriter().Write("GLVertexArray %u created.\n", mGLID);
}

GLVertexArray::~GLVertexArray() noexcept
{
  // Delete vao
  glDeleteVertexArrays(1, &mGLID);

  // Delete all attributes
  for ( auto& attribute : mAttributes )
  {
    delete attribute;
  }

  // Delete all binding points
  for ( auto& bindingPoint : mBindingPoints )
  {
    delete bindingPoint;
  }

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

GLVertexArrayAttribute& GLVertexArray::GetAttribute(const unsigned int& attributeIndex)
{
  if ( attributeIndex < GLVERTEXARRAY_MAX_ATTRIBUTES )
  {
    return *mAttributes.at(attributeIndex);
  }
  else
  {
    throw Exception("GLVertexArray Error: Cannot reference attribute %u. Maximum valid index is %u.\n", 
                    attributeIndex, GLVERTEXARRAY_MAX_ATTRIBUTES - 1);
  }
}

GLVertexArrayBindingPoint& GLVertexArray::GetBindingPoint(const unsigned int& bindingIndex)
{
  if ( bindingIndex < GLVERTEXARRAY_MAX_BINDING_POINTS )
  {
    return *mBindingPoints.at(bindingIndex);
  }
  else
  {
    throw Exception("GLVertexArray Error: Cannot reference binding point %u. Maximum valid index is %u.\n", 
                    bindingIndex, GLVERTEXARRAY_MAX_BINDING_POINTS - 1);
  }
}
}

// End of Source\Nexus\Graphics\GLVertexArray.cpp
