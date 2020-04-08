/// File: Source\Nexus\Graphics\Base\GLObject.cpp.
///
/// Summary:  Implements the gl object class.

#include <Nexus\Graphics\Base\GLObject.hpp>

namespace Nexus::Graphics::Base
{
GLObject::GLObject() noexcept : mGLID(GLOBJECT_GLID_NONE)
{

}

const unsigned int& GLObject::GetGLID() const noexcept
{
  return mGLID;
}
}

// End of Source\Nexus\Graphics\Base\GLObject.cpp
