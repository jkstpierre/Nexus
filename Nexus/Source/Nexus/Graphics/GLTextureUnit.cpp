/// File: Source\Nexus\Graphics\GLTextureUnit.cpp.
///
/// Summary:  Implements the gl texture unit class.

#include <GLAD\GL.h>
#include <Nexus\Graphics\GLTextureUnit.hpp>
#include <Nexus\DebugWriter.hpp>
#include <Nexus\Exception.hpp>

namespace Nexus::Graphics
{
GLTextureUnit::GLTextureUnit(const unsigned int& textureUnitIndex) noexcept : 
  mTextureUnitIndex(textureUnitIndex), mSampler(nullptr), mTexture(nullptr)
{
  BindSampler(nullptr);   // No sampler by default
  BindTexture(nullptr);   // No texture by default

  DebugWriter().Write("GLTextureUnit %u created.\n", textureUnitIndex);
}

GLTextureUnit::~GLTextureUnit() noexcept
{
  BindSampler(nullptr);   // Unbind sampler from this unit
  BindTexture(nullptr);   // Unbind texture from this unit

  DebugWriter().Write("GLTextureUnit %u destroyed.\n", mTextureUnitIndex);
}

std::vector<GLTextureUnit*> GLTextureUnit::AllocateTextureUnits(const unsigned int& count)
{
  unsigned int maxUnits = QueryMaxTextureUnits();

  if ( count <= maxUnits )
  {
    std::vector<GLTextureUnit*> textureUnits;

    for ( unsigned int i = 0; i < count; i++ )
    {
      textureUnits.push_back(new GLTextureUnit(i));
    }

    return textureUnits;
  }
  else
  {
    throw Exception("GLTextureUnit Error: Cannot allocate %u indices. Maximum is %u.\n", 
                    count, maxUnits);
  }
}

void GLTextureUnit::FreeTextureUnits(std::vector<GLTextureUnit*>& textureUnits) noexcept
{
  for ( auto& textureUnit : textureUnits )
  {
    delete textureUnit;
  }

  textureUnits.clear();
}

unsigned int GLTextureUnit::QueryMaxTextureUnits() noexcept
{
  int maxUnits;

  glGetIntegerv(GL_MAX_TEXTURE_IMAGE_UNITS, &maxUnits);

  return static_cast<unsigned int>(maxUnits);
}

void GLTextureUnit::BindSampler(const GLSampler* sampler) noexcept
{
  glBindSampler(mTextureUnitIndex, sampler ? sampler->GetGLID() : GL_NONE);
  mSampler = sampler;
}

void GLTextureUnit::BindTexture(const Base::GLTexture* texture) noexcept
{
  glBindTextureUnit(mTextureUnitIndex, texture ? texture->GetGLID() : GL_NONE);
  mTexture = texture;
}

const unsigned int& GLTextureUnit::GetTextureUnitIndex() const noexcept
{
  return mTextureUnitIndex;
}

const GLSampler* GLTextureUnit::GetSampler() const noexcept
{
  return mSampler;
}

const Base::GLTexture* GLTextureUnit::GetTexture() const noexcept
{
  return mTexture;
}
}

// End of Source\Nexus\Graphics\GLTextureUnit.cpp
