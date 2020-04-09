/// File: Source\Nexus\Graphics\Base\GLObject.cpp.
///
/// Summary:  Implements the gl object class.

#include <Nexus\Graphics\Base\GLObject.hpp>

namespace Nexus::Graphics::Base
{
GLObject::GLObject() noexcept : GLObject(GLOBJECT_GLID_NONE)
{

}

GLObject::GLObject(const unsigned int& glID) noexcept : mGLID(glID)
{

}

const unsigned int& GLObject::GetGLID() const noexcept
{
  return mGLID;
}
}

// End of Source\Nexus\Graphics\Base\GLObject.cpp
