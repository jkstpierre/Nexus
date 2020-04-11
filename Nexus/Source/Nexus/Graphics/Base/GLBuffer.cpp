/// File: Source\Nexus\Graphics\Base\GLBuffer.cpp.
///
/// Summary:  Implements the gl buffer class.

#include <GLAD\GL.h>
#include <Nexus\Graphics\Base\GLBuffer.hpp>
#include <Nexus\DebugWriter.hpp>

namespace Nexus::Graphics::Base
{
GLBuffer::GLBuffer() noexcept
{
  glCreateBuffers(1, &mGLID);
  DebugWriter().Write("GLBuffer %u created...\n", mGLID);
}

GLBuffer::~GLBuffer() noexcept
{
  glDeleteBuffers(1, &mGLID);
  DebugWriter().Write("GLBuffer %u destroyed...\n", mGLID);
}

void GLBuffer::SetData(const void* data, const unsigned long& size, const unsigned int& usage) noexcept
{
  glNamedBufferData(mGLID, size, data, usage);
}

void GLBuffer::SetSubdata(const void* data, const unsigned long& offset, const unsigned long& size) noexcept
{
  glNamedBufferSubData(mGLID, offset, size, data);
}

void* GLBuffer::Map(const unsigned int& access) noexcept
{
  return glMapNamedBuffer(mGLID, access);
}

bool GLBuffer::Unmap() noexcept
{
  return glUnmapNamedBuffer(mGLID);
}
}

// End of Source\Nexus\Graphics\Base\GLBuffer.cpp
