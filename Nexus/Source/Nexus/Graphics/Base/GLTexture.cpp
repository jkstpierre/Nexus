/// File: Source\Nexus\Graphics\Base\GLTexture.cpp.
///
/// Summary:  Implements the gl texture class.

#include <GLAD\GL.h>
#define STB_IMAGE_IMPLEMENTATION
#include <stb\stb_image.h>
#include <Nexus\Graphics\Base\GLTexture.hpp>
#include <Nexus\DebugWriter.hpp>

namespace Nexus::Graphics::Base
{
GLTexture::GLTexture(const GLTextureType& type) noexcept
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

const GLImage_t* GLTexture::LoadImage(const char* filepath) const noexcept
{
  GLImage_t *image = new GLImage_t();

  // Flip the image on load and then load then image
  stbi_set_flip_vertically_on_load(true);
  image->data = stbi_load(filepath, &image->width, &image->height, &image->channels, 0);

  // Delete image struct if load failed, this way the function will evaluate to nullptr
  if ( !image->data )
  {
    delete image;
    image = nullptr;
  }

  return image;
}

void GLTexture::FreeImage(const GLImage_t* image) const noexcept
{
  stbi_image_free(image->data);
  delete image;
  image = nullptr;
}
}

// End of Source\Nexus\Graphics\Base\GLTexture.cpp
