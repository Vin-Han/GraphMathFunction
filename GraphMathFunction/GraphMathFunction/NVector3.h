#pragma once

#include <cmath>
#include <iostream>
#include"NVector2.h"

class NVector3 {
public:
	float x;
	float y;
	float z;

	NVector3(void):x(0),y(0),z(0) {}
	NVector3(const float x) :x(x), y(x), z(x) {}
	NVector3(const float x, const float y, const float z) :x(x), y(y), z(z) {}
	NVector3(const NVector2 vector2) :x(vector2.x), y(vector2.y), z(0) {}
	NVector3(const NVector2 vector2, const float z) :x(vector2.x), y(vector2.y), z(z) {}

	~NVector3(void) {}

	void		ToZero() { x = y = z = 0.0f;}
	float		Length() const { return sqrt((x * x) + (y * y) + (z * z));}
	void		Normalise() {
		float length = Length();

		if (length != 0.0f) {
			length = 1.0f / length;
			x = x * length;
			y = y * length;
			z = z * length;
		}
	}
	NVector2	ToVector2() const {
		return NVector2(x, y);
	}

	void		Invert() {
		x = -x;
		y = -y;
		z = -z;
	}
	NVector3	Inverse() const { return NVector3(-x, -y, -z);}
	/*
	void		FromRGB() {
		if (x > 255.0f) x = 1.0f;
		else if (x < 0.0f) x = 0.0f;
		else x = x / 255.0f;

		if (y > 255.0f) y = 1.0f;
		else if (y < 0.0f) y = 0.0f;
		else y = y / 255.0f;

		if (z > 255.0f) z = 1.0f;
		else if (z < 0.0f) z = 0.0f;
		else z = z / 255.0f;
	}
	*/
	NVector3	FromRGB() const {
		NVector3 rbgVector;
		if (x > 255.0f) rbgVector.x = 1.0f;
		else if (x < 0.0f) rbgVector.x = 0.0f;
		else rbgVector.x = x / 255.0f;

		if (y > 255.0f) rbgVector.y = 1.0f;
		else if (y < 0.0f) rbgVector.y = 0.0f;
		else rbgVector.y = y / 255.0f;

		if (z > 255.0f) rbgVector.z = 1.0f;
		else if (z < 0.0f) rbgVector.z = 0.0f;
		else rbgVector.z = z / 255.0f;
		return rbgVector;
	}
	/*
	void		ToRGB() {
		if (x > 1.0f) x = 255.0f;
		else if (x < 0.0f) x = 0.0f;
		else x = x * 255.0f;

		if (y > 1.0f) y = 255.0f;
		else if (y < 0.0f) y = 0.0f;
		else y = y * 255.0f;

		if (z > 1.0f) z = 255.0f;
		else if (z < 0.0f) z = 0.0f;
		else z = z * 255.0f;
	}
	*/
	NVector3	ToRGB() const {
		NVector3 rbgVector;
		if (x > 1.0f) rbgVector.x = 255.0f;
		else if (x < 0.0f) rbgVector.x = 0.0f;
		else rbgVector.x = x * 255.0f;

		if (y > 1.0f) rbgVector.y = 255.0f;
		else if (y < 0.0f) rbgVector.y = 0.0f;
		else rbgVector.y = y * 255.0f;

		if (z > 1.0f) rbgVector.z = 255.0f;
		else if (z < 0.0f) rbgVector.z = 0.0f;
		else rbgVector.z = z * 255.0f;
		return rbgVector;
	}

	static float	Dot(const NVector3& a, const NVector3& b) { 
		return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
	}
	static NVector3	Cross(const NVector3& a, const NVector3& b) {
		return NVector3((a.y * b.z) - (a.z * b.y), (a.z * b.x) - (a.x * b.z), (a.x * b.y) - (a.y * b.x));
	}

	inline friend std::ostream& operator<<(std::ostream& o, const NVector3& v) {
		o << "NVector3 £º (" << v.x << "," << v.y << "," << v.z << ")" << std::endl;
		return o;
	}

	inline NVector3		operator+(const NVector3& a) const {
		return NVector3(x + a.x, y + a.y, z + a.z);
	}
	inline void			operator+=(const NVector3& a) {
		x += a.x;
		y += a.y;
		z += a.z;
	}

	inline NVector3		operator-(const NVector3& a) const {
		return NVector3(x - a.x, y - a.y, z - a.z);
	}
	inline void			operator-=(const NVector3& a) {
		x -= a.x;
		y -= a.y;
		z -= a.z;
	}

	inline NVector3		operator-() const {
		return NVector3(-x, -y, -z);
	}

	inline NVector3		operator*(const float a) const {
		return NVector3(x * a, y * a, z * a);
	}
	inline NVector3		operator*(const NVector3& a) const {
		return NVector3(x * a.x, y * a.y, z * a.z);
	}

	inline NVector3		operator/(const NVector3& a) const {
		if (a.x == 0 || a.y == 0 || a.z == 0 ) {
			std::cout << "Numerator is 0 !" << std::endl;
			return NVector3(x, y, z);
		}
		return NVector3(x / a.x, y / a.y, z / a.z);
	};
	inline NVector3		operator/(const float a) const {
		if (a == 0) {
			std::cout << "Numerator is 0 !" << std::endl;
			return NVector3(x, y, z);
		}
		return NVector3(x / a, y / a, z / a);
	};

	inline bool			operator==(const NVector3& A)const { return (A.x == x && A.y == y && A.z == z) ? true : false; };
	inline bool			operator!=(const NVector3& A)const { return (A.x == x && A.y == y && A.z == z) ? false : true; };
};

