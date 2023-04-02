#include "vec3.h"

namespace cosmo { namespace maths {

	
	// Empty vector constructor
	vec3::vec3()
		: vec3(0.0f, 0.0f, 0.0f) {}


	// Vector constructor
	vec3::vec3(const float& _x, const float& _y, const float& _z)
		: x(_x), y(_y), z(_z) {}


	// Add two vectors
	vec3&  vec3::add(const vec3& other)
	{
		x += other.x;
		y += other.y;
		z += other.z;

		return *this;
	}


	//Subtract two vectors
	vec3& vec3::subs(const vec3& other)
	{
		x -= other.x;
		y -= other.y;
		z -= other.z;

		return *this;
	}


	//
	vec3& vec3::mul(const vec3& other)
	{
		x *= other.x;
		y *= other.y;
		z *= other.z;

		return *this;

	}


	//
	vec3& vec3::div(const vec3& other)
	{
		x /= other.x;
		y /= other.y;
		z /= other.z;

		return *this;
	}


	//
	vec3 operator+(vec3 left, const vec3& right)
	{
		return left.add(right);
	}


	//
	vec3 operator-(vec3 left, const vec3& right)
	{
		return left.subs(right);
	}


	//
	vec3 operator*(vec3 left, const vec3& right)
	{
		return left.mul(right);
	}


	//
	vec3 operator/(vec3 left, const vec3& right)
	{
		return left.div(right);
	}


	//
	vec3& vec3::operator+=(const vec3& other)
	{
		return add(other);
	}
	

	//
	vec3& vec3::operator-=(const vec3& other)
	{
		return subs(other);
	}
	
	
	//
	vec3& vec3::operator*=(const vec3& other)
	{
		return mul(other);
	}
	
	
	//
	vec3& vec3::operator/=(const vec3& other)
	{
		return div(other);
	}



	//
	bool vec3::operator==(const vec3& other)
	{
		return x == other.x and y == other.y and z == other.z;
	}


	//
	bool vec3::operator!=(const vec3& other)
	{
		return !(*this == other);
	}


	//
	std::ostream& operator<<(std::ostream& stream, const vec3& vector)
	{
		stream << "vec3: (" << vector.x << ", " << vector.y << ", " << vector.z << ")";
		return stream;
	}

} }