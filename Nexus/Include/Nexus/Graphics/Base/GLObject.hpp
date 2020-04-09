/// File: Include\Nexus\Graphics\Base\GLObject.hpp.
///
/// Summary:  Declares the gl object class.

#ifndef __NEXUS_GRAPHICS_BASE_GLOBJECT_HPP__
#define __NEXUS_GRAPHICS_BASE_GLOBJECT_HPP__

namespace Nexus::Graphics::Base
{
/// Summary:  The globject glid none.
const unsigned int GLOBJECT_GLID_NONE = 0U;

/// Class:  GLObject
///
/// Summary:  A gl object.
///
/// Author: jkstpierre
///
/// Date: 4/7/2020
class GLObject
{
protected:
  /// Summary:  The glid.
  unsigned int mGLID;

public:
  /// Function: GLObject::GLObject
  ///
  /// Summary:  Default constructor.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/7/2020
  GLObject() noexcept;

  /// Function: GLObject::GLObject
  ///
  /// Summary:  Constructor.
  ///
  /// Author: jkstpierre.
  ///
  /// Date: 4/9/2020.
  ///
  /// Parameters:
  /// glID -  The glid.
  GLObject(const unsigned int& glID) noexcept;

  /// Function: GLObject::~GLObject
  ///
  /// Summary:  Destructor.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/7/2020
  virtual ~GLObject() noexcept = default;

public:
  /// Function: GetGLID
  ///
  /// Summary:  Gets the glid.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/8/2020
  ///
  /// Returns:  The glid.
  const unsigned int& GetGLID() const noexcept;
};
}

#endif

// End of Include\Nexus\Graphics\Base\GLObject.hpp
