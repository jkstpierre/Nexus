/// File: Include\Nexus\Math\Vector2f.hpp.
///
/// Summary:  Declares the vector 2f class.

#ifndef __NEXUS_MATH_VECTOR2F_HPP__
#define __NEXUS_MATH_VECTOR2F_HPP__

#include <Nexus\Math\Base\Vector.hpp>

namespace Nexus::Math
{
/// Class:  Vector2
///
/// Summary:  A vector 2.
///
/// Author: jkstpierre
///
/// Date: 4/5/2020
///
/// Typeparams:
/// T -   Generic type parameter.
///
/// See:
/// Base::Vector{Vector2, T, 2} - 
template <typename T>
class Vector2 : public Base::Vector<Vector2<T>, T, 2>
{
public:
  /// Function: Vector2::Vector2
  ///
  /// Summary:  Default constructor.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/5/2020
  Vector2() noexcept : Vector2(0, 0)
  {}

  /// Function: Vector2::Vector2< Y>
  ///
  /// Summary:  Convert vector of one type to another but of the same size.
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
  Vector2(const Vector2<Y>& vector) noexcept : Vector2(static_cast<T>(vector.GetX()), static_cast<T>(vector.GetY()))
  {}

  /// Function: Vector2::Vector2
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
  Vector2(const T& x, const T& y) noexcept : Vector2(std::array<T, 2>{ x, y })
  {}

  /// Function: Vector2::Vector2
  ///
  /// Summary:  Constructor.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/5/2020
  ///
  /// Parameters:
  /// components -  The components.
  Vector2(const std::array<T, 2>& components) noexcept : Base::Vector<Vector2<T>, T, 2>(components) 
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
    return Base::Vector<Vector2<T>, T, 2>::GetComponents()[0];
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
    return Base::Vector<Vector2<T>, T, 2>::GetComponents()[1];
  }
};

/// Typedef:  Vector2<float> Vector2f
///
/// Summary:  Defines an alias representing the vector 2f.
typedef Vector2<float> Vector2f;

/// Typedef:  Vector2<int> Vector2i
///
/// Summary:  Defines an alias representing the vector 2i.
typedef Vector2<int> Vector2i;
}

#endif

// End of Include\Nexus\Math\Vector2f.hpp
