/// File: Source\Nexus\Graphics\Base\GLRenderer.cpp.
///
/// Summary:  Implements the gl renderer class.

#include <GLAD\GL.h>
#include <Nexus\Graphics\Base\GLRenderer.hpp>
#include <Nexus\DebugWriter.hpp>

namespace Nexus::Graphics::Base
{
GLRenderer::GLRenderer()
{
  DebugWriter().Write("GLRenderer created.\n");
}

GLRenderer::~GLRenderer() noexcept
{
  DebugWriter().Write("GLRenderer destroyed.\n");
}

void GLRenderer::DrawArrays(const GLDrawMode& mode, const int& first, const int& count) noexcept
{
  glDrawArrays(static_cast<GLenum>(mode), first, count);
}

void GLRenderer::DrawArraysIndirect(const GLDrawMode& mode, const GLDrawArraysIndirectCommand& cmd) noexcept
{
  glDrawArraysIndirect(static_cast<GLenum>(mode), &cmd);
}

void GLRenderer::DrawArraysInstanced(const GLDrawMode& mode, const int& first, const int& count, const int& instanceCount) noexcept
{
  glDrawArraysInstanced(static_cast<GLenum>(mode), first, count, instanceCount);
}

void GLRenderer::DrawArraysInstancedBaseInstance(const GLDrawMode& mode, const int& first, const int& count,
                                                 const int& instanceCount, const unsigned int& baseInstance) noexcept
{
  glDrawArraysInstancedBaseInstance(static_cast<GLenum>(mode), first, count, instanceCount, baseInstance);
}

void GLRenderer::DrawElements(const GLDrawMode& mode, const int& count, const void* indices) noexcept
{
  glDrawElements(static_cast<GLenum>(mode), count, GL_UNSIGNED_INT, indices);
}

void GLRenderer::DrawElementsBaseVertex(const GLDrawMode& mode, const int& count, const void* indices, const int& baseVertex) noexcept
{
  glDrawElementsBaseVertex(static_cast<GLenum>(mode), count, GL_UNSIGNED_INT, indices, baseVertex);
}

void GLRenderer::DrawElementsIndirect(const GLDrawMode& mode, const GLDrawElementsIndirectCommand& cmd) noexcept
{
  glDrawElementsIndirect(static_cast<GLenum>(mode), GL_UNSIGNED_INT, &cmd);
}

void GLRenderer::DrawElementsInstanced(const GLDrawMode& mode, const int& count, const void* indices, const int& instanceCount) noexcept
{
  glDrawElementsInstanced(static_cast<GLenum>(mode), count, GL_UNSIGNED_INT, indices, instanceCount);
}

void GLRenderer::DrawElementsInstancedBaseInstance(const GLDrawMode& mode, const int& count, const void* indices, 
                                                   const int& instanceCount, const unsigned int baseInstance) noexcept
{
  glDrawElementsInstancedBaseInstance(static_cast<GLenum>(mode), count, GL_UNSIGNED_INT, indices, instanceCount, baseInstance);
}

void GLRenderer::DrawElementsInstancedBaseVertex(const GLDrawMode& mode, const int& count, const void* indices,
                                                 const int& instanceCount, const int& baseVertex) noexcept
{
  glDrawElementsInstancedBaseVertex(static_cast<GLenum>(mode), count, GL_UNSIGNED_INT, indices, instanceCount, baseVertex);
}

void GLRenderer::DrawElementsInstancedBaseVertexBaseInstance(const GLDrawMode& mode, const int& count, 
                                                             const void* indices, const int& instanceCount, 
                                                             const int& baseVertex, const int& baseInstance) noexcept
{
  glDrawElementsInstancedBaseVertexBaseInstance(static_cast<GLenum>(mode), count, GL_UNSIGNED_INT, indices, instanceCount, baseVertex, baseInstance);
}
}

// End of Source\Nexus\Graphics\Base\GLRenderer.cpp
