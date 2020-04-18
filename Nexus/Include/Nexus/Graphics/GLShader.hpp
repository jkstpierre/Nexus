/// File: Include\Nexus\Graphics\GLShader.hpp.
///
/// Summary:  Declares the gl shader class.

#ifndef __NEXUS_GRAPHICS_GLSHADER_HPP__
#define __NEXUS_GRAPHICS_GLSHADER_HPP__

#include <Nexus\Graphics\Base\GLObject.hpp>

namespace Nexus::Graphics
{
/// Enum: GLShaderType
///
/// Summary:  Values that represent gl shader types.
enum class GLShaderType : unsigned int
{
  _VERTEX = 0x8B31,
  _TESS_CONTROL = 0x8E88,
  _TESS_EVALUATION = 0x8E87,
  _GEOMETRY = 0x8DD9,
  _FRAGMENT = 0x8B30
};

/// Class:  GLShader
///
/// Summary:
///   An executable stage of the rendering pipeline. GLShader objects are composed into GLProgram
///   objects and are loaded onto the GPU for rendering.
///
/// Author: jkstpierre.
///
/// Date: 4/7/2020.
class GLShader : public Base::GLObject
{
private:
  /// Summary:  The type of GLShader.
  GLShaderType mType;

public:
  /// Function: GLShader::GLShader
  ///
  /// Summary:  Constructor.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/8/2020
  ///
  /// Parameters:
  /// type -      The type of GLShader.
  /// source -    Source code for the GLShader to compile.
  GLShader(const GLShaderType& type, const char* source);

  /// Function: GLShader::~GLShader
  ///
  /// Summary:  Destructor.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/8/2020
  virtual ~GLShader() noexcept;

public:
  /// Function: GetType
  ///
  /// Summary:  Gets the type.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/8/2020
  ///
  /// Returns:  The type.
  const GLShaderType& GetType() const noexcept;
};
}

#endif

// End of Include\Nexus\Graphics\GLShader.hpp
