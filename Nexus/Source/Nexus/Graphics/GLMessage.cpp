/// File: Source\Nexus\Graphics\GLMessage.cpp.
///
/// Summary:  Implements the gl message class.

#include <cstring>
#include <Nexus\Graphics\GLMessage.hpp>

namespace Nexus::Graphics
{
GLMessage::GLMessage(const GLMessageSource& source, const GLMessageType& type, const GLMessageSeverity& severity, 
                     const unsigned int& glID, const char* message, const size_t& messageLength) noexcept :
  mSource(source), mType(type), mSeverity(severity), mMessage(message, messageLength), GLObject(glID)
{

}

bool GLMessage::operator==(const GLMessage& msg) const noexcept
{
  return (mSource == msg.GetSource()) && (mType == msg.GetType()) && (mSeverity == msg.GetSeverity()) && (mGLID == msg.GetGLID());
}

bool GLMessage::operator!=(const GLMessage& msg) const noexcept
{
  return !(*this == msg);
}

const GLMessageSource& GLMessage::GetSource() const noexcept
{
  return mSource;
}

const GLMessageType& GLMessage::GetType() const noexcept
{
  return mType;
}

const GLMessageSeverity& GLMessage::GetSeverity() const noexcept
{
  return mSeverity;
}

const char* GLMessage::ReadMessage() const noexcept
{
  return mMessage.c_str();
}
}

// End of Source\Nexus\Graphics\GLMessage.cpp
