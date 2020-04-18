/// File: Include\Nexus\Graphics\GLSampler.hpp.
///
/// Summary:  Declares the gl sampler class.

#ifndef __NEXUS_GRAPHICS_GLSAMPLER_HPP__
#define __NEXUS_GRAPHICS_GLSAMPLER_HPP__

#include <Nexus\Graphics\Base\GLObject.hpp>

namespace Nexus::Graphics
{
/// Class:  GLSampler
///
/// Summary:  Defines the manner in which textures bound to texture units are sampled.
///
/// Author: jkstpierre
///
/// Date: 4/12/2020
class GLSampler : public Base::GLObject
{
public:
  /// Function: GLSampler::GLSampler
  ///
  /// Summary:  Default constructor.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/13/2020
  GLSampler() noexcept;

  /// Function: GLSampler::~GLSampler
  ///
  /// Summary:  Destructor.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/13/2020
  virtual ~GLSampler() noexcept;

public:

};
}

#endif

// End of Include\Nexus\Graphics\GLSampler.hpp
