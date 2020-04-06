/// File: Include\Nexus\Math\Vector4.hpp.
///
/// Summary:  Declares the vector 4 class.

#ifndef __NEXUS_MATH_VECTOR4_HPP__
#define __NEXUS_MATH_VECTOR4_HPP__

#include <Nexus\Math\Base\Vector.hpp>

namespace Nexus::Math
{
/// Class:  Vector4
///
/// Summary:  A vector 4.
///
/// Author: jkstpierre
///
/// Date: 4/5/2020
///
/// Typeparams:
/// T -   Generic type parameter.
///
/// See:
/// Base::Vector{Vector4{T}, T, 4} - 
template <typename T>
class Vector4 : public Base::Vector<Vector4<T>, T, 4> 
{
public:
  /// Function: Vector4::Vector4
  ///
  /// Summary:  Default constructor.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/5/2020
  Vector4() noexcept : Vector4(0, 0, 0, 1)
  {}

  /// Function: Vector4::Vector4< Y>
  ///
  /// Summary:  Convert vector of same size but different underlying type.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/5/2020
  ///
  /// Typeparams:
  /// Y -   Generic type parameter.
  /// Parameters:
  /// vector -  The vector.
  template <typename Y>
  Vector4(const Vector4<Y>& vector) noexcept : Vector4(static_cast<T>(vector.GetX()), static_cast<T>(vector.GetY()), static_cast<T>(vector.GetZ()), static_cast<T>(vector.GetW()))
  {}

  /// Function: Vector4::Vector4
  ///
  /// Summary:  Constructor.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/5/2020
  ///
  /// Parameters:
  /// x -         A T to process.
  /// y -         A T to process.
  /// z -         A T to process.
  /// w -         A T to process.
  Vector4(const T& x, const T& y, const T& z, const T& w) noexcept : Vector4(std::array<T, 4>{ x, y, z, w })
  {}

  /// Function: Vector4::Vector4
  ///
  /// Summary:  Constructor.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/5/2020
  ///
  /// Parameters:
  /// components -  The components.
  Vector4(const std::array<T, 4>& components) noexcept : Base::Vector<Vector4<T>, T, 4>(components)
  {}

public:
  /// Function: GetX
  ///
  /// Summary:  Get x coordinate.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/5/2020
  ///
  /// Returns:  The x coordinate.
  const T& GetX() const noexcept
  {
    return Base::Vector<Vector4<T>, T, 4>::GetComponents()[0];
  }

  /// Function: GetY
  ///
  /// Summary:  Get y coordinate.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/5/2020
  ///
  /// Returns:  The y coordinate.
  const T& GetY() const noexcept
  {
    return Base::Vector<Vector4<T>, T, 4>::GetComponents()[1];
  }

  /// Function: GetZ
  ///
  /// Summary:  Get z coordinate.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/5/2020
  ///
  /// Returns:  The z coordinate.
  const T& GetZ() const noexcept
  {
    return Base::Vector<Vector4<T>, T, 4>::GetComponents()[2];
  }

  /// Function: GetW
  ///
  /// Summary:  Gets the w.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/5/2020
  ///
  /// Returns:  The w.
  const T& GetW() const noexcept
  {
    return Base::Vector<Vector4<T>, T, 4>::GetComponents()[3];
  }
};

/// Typedef:  Vector4<float> Vector4f
///
/// Summary:  Defines an alias representing the vector 4f.
typedef Vector4<float> Vector4f;

/// Typedef:  Vector4<int> Vector4i
///
/// Summary:  Defines an alias representing the vector 4i.
typedef Vector4<int> Vector4i;
}

#endif

// End of Include\Nexus\Math\Vector4.hpp
