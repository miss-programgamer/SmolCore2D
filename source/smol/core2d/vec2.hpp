#ifndef SMOL_CORE2D_VEC2_DEFINED
#define SMOL_CORE2D_VEC2_DEFINED


#include <cmath>
#include <numbers>
#include <compare>


namespace Smol::Core2D
{
	// A 2D vector represented by values on two axes.
	template<typename T>
	struct Vec2
	{
		friend auto operator<=>(const Vec2&, const Vec2&) = default;
		
		
		// Horizontal position/offset.
		T x;
		
		// Vertical position/offset.
		T y;
		
		
		// Construct a zero vector.
		constexpr Vec2() noexcept(noexcept(T())):
			x(0), y(0)
		{}
		
		// Construct a vector where both values are the one given.
		constexpr explicit Vec2(T value) noexcept(noexcept(T())):
			x(value), y(value)
		{}
		
		// Construct a vector composed of x and y.
		constexpr Vec2(T x, T y) noexcept(noexcept(T())):
			x(x), y(y)
		{}
		
		
		// Get a vector rotated by the given angle.
		inline Vec2 GetRotated(float angle) const
		{
			const float sin = std::sin(angle * float(std::numbers::pi) / 180.0f);
			const float cos = std::cos(angle * float(std::numbers::pi) / 180.0f);
			return { cos * x - sin * y, sin * x + cos * y };
		}
		
		
		// Get the length of this vector.
		constexpr T GetLength() const
		{ return std::sqrt(x * x + y * y); }
		
		// Get the square of the length of this vector.
		constexpr T GetLengthSqr() const
		{ return x * x + y * y; }
		
		// Get the normal of this vector.
		inline Vec2 GetNormal() const
		{
			const float length = std::sqrt(x*x + y*y);
			return Vec2(x / length, y / length);
		}
		
		// Get a tangent by rotating this vector counter-clockwise 90 degrees.
		constexpr Vec2<T> GetTangentCC() const
		{ return { -y, x }; }
		
		// Get a tangent by rotating this vector clockwise 90 degrees.
		constexpr Vec2<T> GetTangentCW() const
		{ return { y, -x }; }
		
		
		// Get a vector member value by index.
		constexpr T operator[](size_t index) const
		{ return (&x)[index]; }
		
		
		// Get the dot product of this vector and another.
		static constexpr T Dot(const Vec2<T>& lhs, const Vec2<T>& rhs)
		{ return { lhs.x * rhs.x + lhs.y * rhs.y }; }
	};
	
	
	template<typename T>
	constexpr Vec2<T> operator-(const Vec2<T>& vec)
	{ return { -vec.x, -vec.y }; }
	
	
	template<typename T>
	constexpr Vec2<T> operator+(const Vec2<T>& lhs, const Vec2<T>& rhs)
	{ return { lhs.x + rhs.x, lhs.y + rhs.y }; }
	
	template<typename T>
	constexpr Vec2<T> operator-(const Vec2<T>& lhs, const Vec2<T>& rhs)
	{ return { lhs.x - rhs.x, lhs.y - rhs.y }; }
	
	template<typename T>
	constexpr Vec2<T> operator*(const Vec2<T>& lhs, const Vec2<T>& rhs)
	{ return { lhs.x * rhs.x, lhs.y * rhs.y }; }
	
	template<typename T>
	constexpr Vec2<T> operator/(const Vec2<T>& lhs, const Vec2<T>& rhs)
	{ return { lhs.x / rhs.x, lhs.y / rhs.y }; }
	
	
	template<typename T>
	constexpr Vec2<T> operator*(const T& lhs, const Vec2<T>& rhs)
	{ return { lhs * rhs.x, lhs * rhs.y }; }
	
	template<typename T>
	constexpr Vec2<T> operator*(const Vec2<T>& lhs, const T& rhs)
	{ return { lhs.x * rhs, lhs.y * rhs }; }
	
	template<typename T>
	constexpr Vec2<T> operator/(const Vec2<T>& lhs, const T& rhs)
	{ return { lhs.x / rhs, lhs.y / rhs }; }
	
	
	template<typename T>
	constexpr Vec2<T>& operator+=(Vec2<T>& lhs, const Vec2<T>& rhs)
	{ lhs = lhs + rhs; return lhs; }
	
	template<typename T>
	constexpr Vec2<T>& operator-=(Vec2<T>& lhs, const Vec2<T>& rhs)
	{ lhs = lhs - rhs; return lhs; }
	
	template<typename T>
	constexpr Vec2<T>& operator*=(Vec2<T>& lhs, const Vec2<T>& rhs)
	{ lhs = lhs * rhs; return lhs; }
	
	template<typename T>
	constexpr Vec2<T>& operator/=(Vec2<T>& lhs, const Vec2<T>& rhs)
	{ lhs = lhs / rhs; return lhs; }
	
	
	template<typename T>
	constexpr Vec2<T>& operator*=(Vec2<T>& lhs, const T& rhs)
	{ lhs = lhs * rhs; return lhs; }
	
	template<typename T>
	constexpr Vec2<T>& operator/=(Vec2<T>& lhs, const T& rhs)
	{ lhs = lhs / rhs; return lhs; }
}


#endif // SMOL_CORE2D_VEC2_DEFINED