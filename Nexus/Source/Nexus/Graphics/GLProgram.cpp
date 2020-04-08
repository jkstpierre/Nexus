/// File: Source\Nexus\Graphics\GLProgram.cpp.
///
/// Summary:  Implements the gl program class.

#include <GLAD\GL.h>
#include <Nexus\Graphics\GLProgram.hpp>
#include <Nexus\Exception.hpp>
#include <Nexus\DebugWriter.hpp>

namespace Nexus::Graphics
{
GLProgram::GLProgram(const bool& separable) : mSeparable(separable)
{
  // Create a new program
  mGLID = glCreateProgram();
  if ( mGLID )
  {
    // Set whether the program is able to be used by a GLPipeline object
    glProgramParameteri(mGLID, GL_PROGRAM_SEPARABLE, IsSeparable());
    DebugWriter().Write("GLProgram %u created.\n", mGLID);
  }
  else
  {
    throw Exception("GLProgram Error: Failed to create GLProgram.\n");
  }
}

GLProgram::~GLProgram() noexcept
{
  glDeleteProgram(mGLID);
  DebugWriter().Write("GLProgram %u destroyed.\n", mGLID);
}

void GLProgram::LinkShader(const GLShader& shader)
{
  // Attach and link the shader to the program
  glAttachShader(mGLID, shader.GetGLID());
  glLinkProgram(mGLID);

  // Check for errors
  static const unsigned int ERROR_LOG_SIZE = 512U;
  static GLchar errorLog[ERROR_LOG_SIZE];
  static GLint  success;
  glGetProgramiv(mGLID, GL_LINK_STATUS, &success);

  if ( !success )
  {
    // In case of error, get error log, delete program, and throw exception
    glGetProgramInfoLog(mGLID, ERROR_LOG_SIZE, GL_NONE, errorLog);
    glDeleteProgram(mGLID);
    mGLID = Base::GLOBJECT_GLID_NONE;
    throw Exception("GLProgram Error: Failed to link.\nGLSL %s\n", errorLog);
  }
}

void GLProgram::SetUniformBool(const char* name, const bool& b) noexcept
{
  glProgramUniform1i(mGLID, GetUniformIndex(name), b);
}

void GLProgram::SetUniformInt(const char* name, const int& i) noexcept
{
  glProgramUniform1i(mGLID, GetUniformIndex(name), i);
}

void GLProgram::SetUniformFloat(const char* name, const float& f) noexcept
{
  glProgramUniform1f(mGLID, GetUniformIndex(name), f);
}

void GLProgram::SetUniformIntArray(const char* name, const size_t& count, const int* iArray) noexcept
{
  glProgramUniform1iv(mGLID, GetUniformIndex(name), count, iArray);
}

void GLProgram::SetUniformFloatArray(const char* name, const size_t& count, const float* fArray) noexcept
{
  glProgramUniform1fv(mGLID, GetUniformIndex(name), count, fArray);
}

void GLProgram::SetUniformVector2f(const char* name, const Math::Vector2f& vector) noexcept
{
  glProgramUniform2fv(mGLID, GetUniformIndex(name), 1, vector.GetComponents());
}

void GLProgram::SetUniformVector3f(const char* name, const Math::Vector3f& vector) noexcept
{
  glProgramUniform3fv(mGLID, GetUniformIndex(name), 1, vector.GetComponents());
}

void GLProgram::SetUniformVector4f(const char* name, const Math::Vector4f& vector) noexcept
{
  glProgramUniform4fv(mGLID, GetUniformIndex(name), 1, vector.GetComponents());
}

void GLProgram::SetUniformMatrix2f(const char* name, const Math::Matrix2f& matrix) noexcept
{
  glProgramUniformMatrix2fv(mGLID, GetUniformIndex(name), 1, GL_FALSE, matrix.GetData());
}

void GLProgram::SetUniformMatrix3f(const char* name, const Math::Matrix3f& matrix) noexcept
{
  glProgramUniformMatrix3fv(mGLID, GetUniformIndex(name), 1, GL_FALSE, matrix.GetData());
}

void GLProgram::SetUniformMatrix4f(const char* name, const Math::Matrix4f& matrix) noexcept
{
  glProgramUniformMatrix4fv(mGLID, GetUniformIndex(name), 1, GL_FALSE, matrix.GetData());
}

const bool& GLProgram::IsSeparable() const noexcept
{
  return mSeparable;
}

int GLProgram::GetAttributeIndex(const char* name) const noexcept
{
  return glGetAttribLocation(mGLID, name);
}

int GLProgram::GetUniformIndex(const char* name) const noexcept
{
  return glGetUniformLocation(mGLID, name);
}

int GLProgram::GetAttributeCount() const noexcept
{
  GLint attribCount = 0;
  glGetProgramInterfaceiv(mGLID, GL_PROGRAM_INPUT, GL_ACTIVE_RESOURCES, &attribCount);
  return attribCount;
}

int GLProgram::GetUniformCount() const noexcept
{
  GLint uniformCount = 0;
  glGetProgramInterfaceiv(mGLID, GL_UNIFORM, GL_ACTIVE_RESOURCES, &uniformCount);
  return uniformCount;
}
}

// End of Source\Nexus\Graphics\GLProgram.cpp
