/// File: Source\Nexus\Graphics\Base\GLVertexArray.cpp.
///
/// Summary:  Implements the gl vertex array class.

#include <GLAD\GL.h>
#include <Nexus\Graphics\Base\GLVertexArray.hpp>
#include <Nexus\DebugWriter.hpp>

namespace Nexus::Graphics::Base
{
GLVertexArray::GLVertexArray() noexcept
{
  glCreateVertexArrays(1, &mGLID);
  DebugWriter().Write("GLVertexArray %u created.\n", mGLID);
}

GLVertexArray::~GLVertexArray() noexcept
{
  glDeleteVertexArrays(1, &mGLID);
  DebugWriter().Write("GLVertexArray &u destroyed.\n", mGLID);
}

void GLVertexArray::BindVertexBuffer(const unsigned int& vbo, const unsigned int& offset, 
                                     const unsigned int& stride, const unsigned int& bindingIndex) noexcept
{
  glVertexArrayVertexBuffer(mGLID, bindingIndex, vbo, offset, stride);
}

void GLVertexArray::BindElementBuffer(const unsigned int& ebo) noexcept
{
  glVertexArrayElementBuffer(mGLID, ebo);
}
}

// End of Source\Nexus\Graphics\Base\GLVertexArray.cpp
