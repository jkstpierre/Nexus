/// File: Source\Nexus\Graphics\GLTextureUnit.cpp.
///
/// Summary:  Implements the gl texture unit class.

#include <GLAD\GL.h>
#include <Nexus\Graphics\GLTextureUnit.hpp>
#include <Nexus\Exception.hpp>

namespace Nexus::Graphics
{
GLTextureUnit::GLTextureUnit(const unsigned int& textureUnitIndex) noexcept : 
  mTextureUnitIndex(textureUnitIndex), mSampler(nullptr), mTexture(nullptr)
{}

GLTextureUnit::~GLTextureUnit() noexcept
{
  BindSampler(nullptr);   // Unbind sampler from this unit
  BindTexture(nullptr);   // Unbind texture from this unit
}

std::vector<GLTextureUnit*> GLTextureUnit::AllocateTextureUnits(const unsigned int& count)
{
  if ( count <= GLTEXTUREUNIT_MAX_TEXTURE_UNITS )
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
                    GLTEXTUREUNIT_MAX_TEXTURE_UNITS);
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
