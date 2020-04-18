/// File: Source\Nexus\Graphics\Base\GLTexture.cpp.
///
/// Summary:  Implements the gl texture class.

#include <GLAD\GL.h>
#include <Nexus\Graphics\Base\GLTexture.hpp>
#include <Nexus\DebugWriter.hpp>

namespace Nexus::Graphics::Base
{
GLTexture::GLTexture(const GLTextureType& type) noexcept : mType(type)
{
  glCreateTextures(static_cast<GLenum>(type), 1, &mGLID);
  DebugWriter().Write("GLTexture %u created of type %u.\n", 
                      mGLID, static_cast<unsigned int>(type));
}

GLTexture::~GLTexture() noexcept
{
  glDeleteTextures(1, &mGLID);
  DebugWriter().Write("GLTexture &u destroyed.\n", mGLID);
}

const GLTextureType& GLTexture::GetType() const noexcept
{
  return mType;
}
}

// End of Source\Nexus\Graphics\Base\GLTexture.cpp
