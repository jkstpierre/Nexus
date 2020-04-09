/// File: Include\Nexus\Graphics\GLProgram.hpp.
///
/// Summary:  Declares the gl program class.

#ifndef __NEXUS_GRAPHICS_GLPROGRAM_HPP__
#define __NEXUS_GRAPHICS_GLPROGRAM_HPP__

#include <initializer_list>
#include <functional>
#include <Nexus\Graphics\GLShader.hpp>
#include <Nexus\Math\Vector2.hpp>
#include <Nexus\Math\Vector3.hpp>
#include <Nexus\Math\Vector4.hpp>
#include <Nexus\Math\Matrix2.hpp>
#include <Nexus\Math\Matrix3.hpp>
#include <Nexus\Math\Matrix4.hpp>

namespace Nexus::Graphics
{
/// Class:  GLProgram
///
/// Summary:
///   A GLProgram is a linked executable of 1 or more GLShader objects which can be loaded onto the
///   GPU.
///
/// Author: jkstpierre.
///
/// Date: 4/8/2020.
///
/// See:
/// Base::GLObject - 
class GLProgram : public Base::GLObject 
{
private:
  /// Summary:  True if separable.
  bool mSeparable;

private:
  /// Function: GLProgram::GLProgram
  ///
  /// Summary:  Default constructor.
  ///
  /// Author: jkstpierre.
  ///
  /// Date: 4/8/2020.
  ///
  /// Parameters:
  /// separable -   True if separable.
  GLProgram(const bool& separable);

public:
  /// Function: GLProgram::GLProgram< S,... Sargs>
  ///
  /// Summary:  Constructor.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/8/2020
  ///
  /// Typeparams:
  /// S -         Type of the s.
  /// Sargs -     Type of the sargs.
  /// Parameters:
  /// separable -   True if separable.
  /// shader -      The shader.
  /// shaders -     Variable arguments providing [in,out] The shaders.
  template <class... Sargs>
  GLProgram(const bool& separable, const GLShader& shader, Sargs&&... shaders) : GLProgram(separable, shaders...)
  {
    LinkShader(shader);   // Recursively link each shader
  }

  /// Function: GLProgram::~GLProgram
  ///
  /// Summary:  Destructor.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/8/2020
  virtual ~GLProgram() noexcept;

private:
  /// Function: LinkShader
  ///
  /// Summary:  Links a shader.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/8/2020
  ///
  /// Parameters:
  /// shader -  The shader.
  void LinkShader(const GLShader& shader);

public:
  /// Function: SetUniformBool
  ///
  /// Summary:  Sets uniform bool.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/8/2020
  ///
  /// Parameters:
  /// name -      The name.
  /// b -         True to b.
  void SetUniformBool(const char* name, const bool& b) noexcept;

  /// Function: SetUniformInt
  ///
  /// Summary:  Sets uniform int.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/8/2020
  ///
  /// Parameters:
  /// name -      The name.
  /// i -         Zero-based index of the.
  void SetUniformInt(const char* name, const int& i) noexcept;

  /// Function: SetUniformFloat
  ///
  /// Summary:  Sets uniform float.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/8/2020
  ///
  /// Parameters:
  /// name -      The name.
  /// f -         A float to process.
  void SetUniformFloat(const char* name, const float& f) noexcept;

  /// Function: SetUniformIntArray
  ///
  /// Summary:  Sets uniform int array.
  ///
  /// Author: jkstpierre.
  ///
  /// Date: 4/8/2020.
  ///
  /// Parameters:
  /// name -      The name.
  /// count -     Number of.
  /// iArray -    The array.
  void SetUniformIntArray(const char* name, const size_t& count, const int* iArray) noexcept;

  /// Function: SetUniformFloatArray
  ///
  /// Summary:  Sets uniform float array.
  ///
  /// Author: jkstpierre.
  ///
  /// Date: 4/8/2020.
  ///
  /// Parameters:
  /// name -      The name.
  /// count -     Number of.
  /// fArray -    The array.
  void SetUniformFloatArray(const char* name, const size_t& count, const float* fArray) noexcept;

  /// Function: SetUniformVector2f
  ///
  /// Summary:  Sets uniform vector 2f.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/8/2020
  ///
  /// Parameters:
  /// name -      The name.
  /// vector -    The vector.
  void SetUniformVector2f(const char* name, const Math::Vector2f& vector) noexcept;

  /// Function: SetUniformVector3f
  ///
  /// Summary:  Sets uniform vector 3f.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/8/2020
  ///
  /// Parameters:
  /// name -      The name.
  /// vector -    The vector.
  void SetUniformVector3f(const char* name, const Math::Vector3f& vector) noexcept;

  /// Function: SetUniformVector4f
  ///
  /// Summary:  Sets uniform vector 4f.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/8/2020
  ///
  /// Parameters:
  /// name -      The name.
  /// vector -    The vector.
  void SetUniformVector4f(const char* name, const Math::Vector4f& vector) noexcept;

  /// Function: SetUniformMatrix2f
  ///
  /// Summary:  Sets uniform matrix 2f.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/8/2020
  ///
  /// Parameters:
  /// name -      The name.
  /// matrix -    The matrix.
  void SetUniformMatrix2f(const char* name, const Math::Matrix2f& matrix) noexcept;

  /// Function: SetUniformMatrix3f
  ///
  /// Summary:  Sets uniform matrix 3f.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/8/2020
  ///
  /// Parameters:
  /// name -      The name.
  /// matrix -    The matrix.
  void SetUniformMatrix3f(const char* name, const Math::Matrix3f& matrix) noexcept;

  /// Function: SetUniformMatrix4f
  ///
  /// Summary:  Sets uniform matrix 4f.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/8/2020
  ///
  /// Parameters:
  /// name -      The name.
  /// matrix -    The matrix.
  void SetUniformMatrix4f(const char* name, const Math::Matrix4f& matrix) noexcept;

public:
  /// Function: IsSeparable
  ///
  /// Summary:  Is separable.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/8/2020
  ///
  /// Returns:  A reference to a const bool.
  const bool& IsSeparable() const noexcept;

  /// Function: GetAttributeIndex
  ///
  /// Summary:  Gets attribute index.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/8/2020
  ///
  /// Parameters:
  /// name -  The name.
  ///
  /// Returns:  The attribute index.
  int GetAttributeIndex(const char* name) const noexcept;

  /// Function: GetUniformIndex
  ///
  /// Summary:  Gets uniform index.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/8/2020
  ///
  /// Parameters:
  /// name -  The name.
  ///
  /// Returns:  The uniform index.
  int GetUniformIndex(const char* name) const noexcept;

  /// Function: GetAttributeCount
  ///
  /// Summary:  Gets attribute count.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/8/2020
  ///
  /// Returns:  The attribute count.
  int GetAttributeCount() const noexcept;

  /// Function: GetUniformCount
  ///
  /// Summary:  Gets uniform count.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/8/2020
  ///
  /// Returns:  The uniform count.
  int GetUniformCount() const noexcept;
};
}

#endif

// End of Include\Nexus\Graphics\GLProgram.hpp
