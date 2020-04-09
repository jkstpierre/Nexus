/// File: Include\Nexus\Graphics\GLMessage.hpp.
///
/// Summary:  Declares the gl message class.

#ifndef __NEXUS_GRAPHICS_GLMESSAGE_HPP__
#define __NEXUS_GRAPHICS_GLMESSAGE_HPP__

#include <Nexus\Graphics\Base\GLObject.hpp>
#include <string>

namespace Nexus::Graphics
{
/// Enum: GLMessageSource
///
/// Summary:  Values that represent gl message sources.
enum class GLMessageSource : unsigned int
{
  _NONE = 0x00,
  _API = 0x8246,
  _WINDOW_SYSTEM = 0x8247,
  _SHADER_COMPILER = 0x8248,
  _THIRD_PARTY = 0x8249,
  _APPLICATION = 0x824A,
  _OTHER = 0x824B
};

/// Enum: GLMessageType
///
/// Summary:  Values that represent gl message types.
enum class GLMessageType : unsigned int
{
  _NONE = 0x00,
  _ERROR = 0x824C,
  _DEPRECATED_BEHAVIOR = 0x824D,
  _UNDEFINED_BEHAVIOR = 0x824E,
  _PORTABILITY = 0x824F,
  _PERFORMANCE = 0x8250,
  _MARKER = 0x8268,
  _PUSH_GROUP = 0x8269,
  _POP_GROUP = 0x826A,
  _OTHER = 0x8251
};

/// Enum: GLMessageSeverity
///
/// Summary:  Values that represent gl message severities.
enum class GLMessageSeverity : unsigned int
{
  _NONE = 0x00,
  _HIGH = 0x9146,
  _MEDIUM = 0x9147,
  _LOW = 0x9148,
  _NOTIFICATION = 0x826B
};

/// Class:  GLMessage
///
/// Summary:  A gl message.
///
/// Author: jkstpierre
///
/// Date: 4/9/2020
class GLMessage : public Base::GLObject
{
private:
  /// Summary:  Source for the.
  GLMessageSource mSource;
  /// Summary:  The type.
  GLMessageType mType;
  /// Summary:  The severity.
  GLMessageSeverity mSeverity;
  /// Summary:  The message.
  std::string mMessage;

public:
  /// Function: GLMessage::GLMessage
  ///
  /// Summary:  Constructor.
  ///
  /// Author: jkstpierre.
  ///
  /// Date: 4/9/2020.
  ///
  /// Parameters:
  /// source -          Source for the.
  /// type -            The type.
  /// severity -        The severity.
  /// glID -            Identifier for the gl.
  /// message -         The message.
  /// messageLength -   Length of the message.
  GLMessage(const GLMessageSource& source, const GLMessageType& type, const GLMessageSeverity& severity, const unsigned int& glID, const char* message, const size_t& messageLength) noexcept;
  GLMessage(const GLMessage&) = default;
  GLMessage(GLMessage&&) noexcept = default;
  GLMessage& operator=(const GLMessage&) = default;
  GLMessage& operator=(GLMessage&&) noexcept = default;

  /// Function: GLMessage::~GLMessage
  ///
  /// Summary:  Destructor.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/9/2020
  virtual ~GLMessage() noexcept = default;

public:
  /// Function: ==
  ///
  /// Summary:  Equality operator.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/9/2020
  ///
  /// Parameters:
  /// msg -   The message.
  ///
  /// Returns:  True if the parameters are considered equivalent.
  bool operator==(const GLMessage& msg) const noexcept;

  /// Function: !=
  ///
  /// Summary:  Inequality operator.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/9/2020
  ///
  /// Parameters:
  /// msg -   The message.
  ///
  /// Returns:  True if the parameters are not considered equivalent.
  bool operator!=(const GLMessage& msg) const noexcept;

public:
  /// Function: GetSource
  ///
  /// Summary:  Gets the source.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/9/2020
  ///
  /// Returns:  The source.
  const GLMessageSource& GetSource() const noexcept;

  /// Function: GetType
  ///
  /// Summary:  Gets the type.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/9/2020
  ///
  /// Returns:  The type.
  const GLMessageType& GetType() const noexcept;

  /// Function: GetSeverity
  ///
  /// Summary:  Gets the severity.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/9/2020
  ///
  /// Returns:  The severity.
  const GLMessageSeverity& GetSeverity() const noexcept;

  /// Function: ReadMessage
  ///
  /// Summary:  Reads the message.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/9/2020
  ///
  /// Returns:  Null if it fails, else the message.
  const char* ReadMessage() const noexcept;
};

/// Summary:  The glmessage none.
const GLMessage GLMESSAGE_NONE = GLMessage(GLMessageSource::_NONE, GLMessageType::_NONE, GLMessageSeverity::_NONE, Base::GLOBJECT_GLID_NONE, "", 0);
}

#endif

// End of Include\Nexus\Graphics\GLMessage.hpp
