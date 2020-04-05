/// File: Include\Nexus\Math\Vector3.hpp.
///
/// Summary:  Declares the vector 3 class.

#ifndef __NEXUS_MATH_VECTOR3_HPP__
#define __NEXUS_MATH_VECTOR3_HPP__

#include <Nexus\Math\Base\Vector.hpp>

namespace Nexus::Math
{
/// Class:  Vector3
///
/// Summary:  A vector 3.
///
/// Author: jkstpierre
///
/// Date: 4/5/2020
///
/// Typeparams:
/// T -   Generic type parameter.
///
/// See:
/// Base::Vector{Vector3, T, 3} - 
template <class T>
class Vector3 : public Base::Vector<Vector3<T>, T, 3>
{
public:
  /// Function: Vector3::Vector3
  ///
  /// Summary:  Default constructor.
  ///
  /// Author: jkstpierre.
  ///
  /// Date: 4/5/2020.
  Vector3() noexcept : Vector3(0, 0, 0)
  {}

  /// Function: Vector3::Vector3< Y>
  ///
  /// Summary:  Convert one vector to another of same size but different underlying type.
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
  Vector3(const Vector3<Y>& vector) noexcept : Vector3(static_cast<T>(vector.GetX()), static_cast<T>(vector.GetY()), static_cast<T>(vector.GetZ()))
  {}

  /// Function: Vector3::Vector3
  ///
  /// Summary:  Constructor.
  ///
  /// Author: jkstpierre.
  ///
  /// Date: 4/5/2020.
  ///
  /// Parameters:
  /// x -         The x coordinate.
  /// y -         The y coordinate.
  /// z -         The z coordinate.
  Vector3(const T& x, const T& y, const T& z) noexcept : Vector3(std::array<T, 3>{x, y, z})
  {}

  /// Function: Vector3::Vector3
  ///
  /// Summary:  Constructor.
  ///
  /// Author: jkstpierre.
  ///
  /// Date: 4/5/2020.
  ///
  /// Parameters:
  /// components -  The components.
  Vector3(const std::array<T, 3>& components) noexcept : Base::Vector<Vector3<T>, T, 3>(components)
  {}

public:
  /// Function: Cross
  ///
  /// Summary:  Cross the given right hand side.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/5/2020
  ///
  /// Parameters:
  /// rhs -   The right hand side.
  ///
  /// Returns:  A Vector3
  Vector3<T> Cross(const Vector3<T>& rhs) const noexcept
  {
    return Vector3<T>(
      (GetY() * rhs.GetZ()) - (GetZ() * rhs.GetY()), 
      (GetZ() * rhs.GetX()) - (GetX() * rhs.GetZ()), 
      (GetX() * rhs.GetY()) - (GetY() * rhs.GetX()));
  }

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
    return Base::Vector<Vector3<T>, T, 3>::GetComponents()[0];
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
    return Base::Vector<Vector3<T>, T, 3>::GetComponents()[1];
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
    return Base::Vector<Vector3<T>, T, 3>::GetComponents()[2];
  }
};

/// Typedef:  Vector3<float> Vector3f
///
/// Summary:  Defines an alias representing the vector 3f.
typedef Vector3<float> Vector3f;

/// Typedef:  Vector3<int> Vector3i
///
/// Summary:  Defines an alias representing the vector 3i.
typedef Vector3<int> Vector3i;
}

#endif

// End of Include\Nexus\Math\Vector3.hpp
