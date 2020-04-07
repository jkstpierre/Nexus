/// File: Include\Nexus\Math\Base\Vector.hpp.
///
/// Summary:  Declares the vector class.

#ifndef __NEXUS_MATH_BASE_VECTOR_HPP__
#define __NEXUS_MATH_BASE_VECTOR_HPP__

#include <array>
#include <cmath>

namespace Nexus::Math::Base
{
/// Class:  Vector
///
/// Summary:  A vector.
///
/// Author: jkstpierre.
///
/// Date: 4/5/2020.
///
/// Typeparams:
/// V -         Templated vector class.
/// T -         Base vector type.
/// N -         Number of elements in the vector.
template <class V, typename T, size_t N>
class Vector
{
private:
  /// Summary:  The components.
  std::array<T, N> mComponents;

protected:
  /// Function: Vector::Vector
  ///
  /// Summary:  Default constructor.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/5/2020
  Vector() noexcept = delete;

  /// Function: Vector::Vector
  ///
  /// Summary:  Constructor.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/5/2020
  ///
  /// Parameters:
  /// components -  The components.
  Vector(const std::array<T, N>& components) noexcept : mComponents(components)
  {
    // Ensure V is a vector
    static_assert(std::is_base_of<Vector<V, T, N>, V>::value);
  }

public:
  /// Function: ==
  ///
  /// Summary:  Equality operator.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/5/2020
  ///
  /// Parameters:
  /// rhs -   The right hand side.
  ///
  /// Returns:  True if the parameters are considered equivalent.
  bool operator ==(const V& rhs) const noexcept
  {
    bool r = true;

    for ( size_t i = 0; i < N && r; i++ )
    {
      r = mComponents.at(i) == rhs.mComponents.at(i);
    }

    return r;
  }

  /// Function: !=
  ///
  /// Summary:  Inequality operator.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/5/2020
  ///
  /// Parameters:
  /// rhs -   The right hand side.
  ///
  /// Returns:  True if the parameters are not considered equivalent.
  bool operator !=(const V& rhs) const noexcept
  {
    return !(static_cast<const V&>(*this) == rhs);
  }

  /// Function: +
  ///
  /// Summary:  Addition operator.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/5/2020
  ///
  /// Parameters:
  /// rhs -   The right hand side.
  ///
  /// Returns:  The result of the operation.
  V operator +(const V& rhs) const noexcept
  {
    std::array<T, N> components;

    for ( size_t i = 0; i < N; i++ )
    {
      components[i] = mComponents.at(i) + rhs.mComponents.at(i);
    }

    return V(components);
  }

  /// Function: +=
  ///
  /// Summary:  Addition assignment operator.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/5/2020
  ///
  /// Parameters:
  /// rhs -   The right hand side.
  ///
  /// Returns:  The result of the operation.
  V& operator +=(const V& rhs) noexcept
  {
    static_cast<V&>(*this) = static_cast<V&>(*this) + rhs;

    return static_cast<V&>(*this);
  }

  /// Function: -
  ///
  /// Summary:  Subtraction operator.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/5/2020
  ///
  /// Parameters:
  /// rhs -   The right hand side.
  ///
  /// Returns:  The result of the operation.
  V operator -(const V& rhs) const noexcept
  {
    std::array<T, N> components;
    for ( size_t i = 0; i < N; i++ )
    {
      components[i] = mComponents.at(i) - rhs.mComponents.at(i);
    }

    return V(components);
  }

  /// Function: -=
  ///
  /// Summary:  Subtraction assignment operator.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/5/2020
  ///
  /// Parameters:
  /// rhs -   The right hand side.
  ///
  /// Returns:  The result of the operation.
  V& operator -=(const V& rhs) noexcept
  {
    static_cast<V&>(*this) = static_cast<V&>(*this) - rhs;

    return static_cast<V&>(*this);
  }

  /// Function: *
  ///
  /// Summary:  Multiplication operator.
  ///
  /// Author: jkstpierre.
  ///
  /// Date: 4/5/2020.
  ///
  /// Parameters:
  /// rhs -   The right hand side.
  ///
  /// Returns:  The result of the operation.
  V operator*(const T& rhs) const noexcept
  {
    std::array<T, N> components;

    for ( size_t i = 0; i < N; i++ )
    {
      components[i] = mComponents.at(i) * rhs;
    }

    return V(components);
  }

  /// Function: *=
  ///
  /// Summary:  Multiplication assignment operator.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/5/2020
  ///
  /// Parameters:
  /// rhs -   The right hand side.
  ///
  /// Returns:  The result of the operation.
  V& operator*=(const T& rhs) noexcept
  {
    static_cast<V&>(*this) = static_cast<V&>(*this) * rhs;

    return static_cast<V&>(*this);
  }

public:
  /// Function: Magnitude
  ///
  /// Summary:  Calculates the magnitude.
  ///
  /// Author: jkstpierre.
  ///
  /// Date: 4/5/2020.
  ///
  /// Returns:  The calculated magnitude.
  float Magnitude() const noexcept
  {
    T s = 0;

    for ( size_t i = 0; i < N; i++ )
    {
      s += mComponents.at(i) * mComponents.at(i);
    }

    return sqrtf(s);
  }

  /// Function: Dot
  ///
  /// Summary:  Computes the dot product.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/5/2020
  ///
  /// Parameters:
  /// rhs -   The right hand side.
  ///
  /// Returns:  A double.
  T Dot(const V& rhs) const noexcept
  {
    T r = 0;
    
    for ( size_t i = 0; i < N; i++ )
    {
      r += mComponents.at(i) * rhs.mComponents.at(i);
    }

    return r;
  }

  /// Function: Normalize
  ///
  /// Summary:  Computes the normalization vector.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/7/2020
  ///
  /// Returns:  A V.
  V Normalize() const noexcept
  {
    return static_cast<const V&>(*this) * (1 / Magnitude());
  }

public:
  /// Function: GetComponents
  ///
  /// Summary:  Gets the components.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/5/2020
  ///
  /// Returns:  Null if it fails, else the components.
  const T* GetComponents() const noexcept
  {
    return mComponents.data();
  }

  /// Function: GetSize
  ///
  /// Summary:  Gets the size.
  ///
  /// Author: jkstpierre
  ///
  /// Date: 4/5/2020
  ///
  /// Returns:  The size.
  size_t GetSize() const noexcept
  {
    return mComponents.size();
  }
};
}

#endif

// End of Include\Nexus\Math\Base\Vector.hpp
