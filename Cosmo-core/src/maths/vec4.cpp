#include "vec4.h"

namespace cosmo { namespace maths {

	
	// Empty vector constructor
	vec4::vec4()
		: vec4(0.0f, 0.0f, 0.0f, 0.0f) {}


	// Vector constructor
	vec4::vec4(const float& _x, const float& _y, const float& _z, const float& _w)
		: x(_x), y(_y), z(_z), w(_w) {}


	// Add two vectors
	vec4&  vec4::add(const vec4& other)
	{
		x += other.x;
		y += other.y;
		z += other.z;
		w += other.w;

		return *this;
	}


	//Subtract two vectors
	vec4& vec4::subs(const vec4& other)
	{
		x -= other.x;
		y -= other.y;
		z -= other.z;
		w -= other.w;

		return *this;
	}


	//
	vec4& vec4::mul(const vec4& other)
	{
		x *= other.x;
		y *= other.y;
		z *= other.z;
		w *= other.w;

		return *this;
	}


	//
	vec4& vec4::div(const vec4& other)
	{
		x /= other.x;
		y /= other.y;
		z /= other.z;
		w /= other.w;

		return *this;
	}


	//
	vec4 operator+(vec4 left, const vec4& right)
	{
		return left.add(right);
	}


	//
	vec4 operator-(vec4 left, const vec4& right)
	{
		return left.subs(right);
	}


	//
	vec4 operator*(vec4 left, const vec4& right)
	{
		return left.mul(right);
	}


	//
	vec4 operator/(vec4 left, const vec4& right)
	{
		return left.div(right);
	}


	//
	vec4& vec4::operator+=(const vec4& other)
	{
		return add(other);
	}
	

	//
	vec4& vec4::operator-=(const vec4& other)
	{
		return subs(other);
	}
	
	
	//
	vec4& vec4::operator*=(const vec4& other)
	{
		return mul(other);
	}
	
	
	//
	vec4& vec4::operator/=(const vec4& other)
	{
		return div(other);
	}



	//
	bool vec4::operator==(const vec4& other)
	{
		return x == other.x and y == other.y and z == other.z and w == other.w;
	}


	//
	bool vec4::operator!=(const vec4& other)
	{
		return !(*this == other);
	}


	//
	std::ostream& operator<<(std::ostream& stream, const vec4& vector)
	{
		stream << "vec4: (" << vector.x << ", " << vector.y << ", " << vector.z << ", " << vector.w << ")";
		return stream;
	}

} }