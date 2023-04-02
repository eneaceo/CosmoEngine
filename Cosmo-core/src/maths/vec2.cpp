#include "vec2.h"

namespace cosmo { namespace maths {

	
	// Empty vector constructor
	vec2::vec2()
		: vec2(0.0f, 0.0f) {}


	// Vector constructor
	vec2::vec2(const float& _x, const float& _y)
		: x(_x), y(_y) {}


	// Add two vectors
	vec2&  vec2::add(const vec2& other)
	{
		x += other.x;
		y += other.y;

		return *this;
	}


	//Subtract two vectors
	vec2& vec2::subs(const vec2& other)
	{
		x -= other.x;
		y -= other.y;

		return *this;
	}


	//
	vec2& vec2::mul(const vec2& other)
	{
		x *= other.x;
		y *= other.y;

		return *this;
	}


	//
	vec2& vec2::div(const vec2& other)
	{
		x /= other.x;
		y /= other.y;

		return *this;
	}


	//
	vec2 operator+(vec2 left, const vec2& right)
	{
		return left.add(right);
	}


	//
	vec2 operator-(vec2 left, const vec2& right)
	{
		return left.subs(right);
	}


	//
	vec2 operator*(vec2 left, const vec2& right)
	{
		return left.mul(right);
	}


	//
	vec2 operator/(vec2 left, const vec2& right)
	{
		return left.div(right);
	}


	//
	vec2& vec2::operator+=(const vec2& other)
	{
		return add(other);
	}
	

	//
	vec2& vec2::operator-=(const vec2& other)
	{
		return subs(other);
	}
	
	
	//
	vec2& vec2::operator*=(const vec2& other)
	{
		return mul(other);
	}
	
	
	//
	vec2& vec2::operator/=(const vec2& other)
	{
		return div(other);
	}



	//
	bool vec2::operator==(const vec2& other)
	{
		return x == other.x and y == other.y;
	}


	//
	bool vec2::operator!=(const vec2& other)
	{
		return !(*this == other);
	}


	//
	std::ostream& operator<<(std::ostream& stream, const vec2& vector)
	{
		stream << "vec2: (" << vector.x << ", " << vector.y << ")";
		return stream;
	}

} }