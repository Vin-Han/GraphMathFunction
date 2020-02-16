#pragma once

#include "NVector3.h"

class NVector4 {
public:
	float x;
	float y;
	float z;
	float w;

	NVector4(void) :x(0), y(0), z(0) ,w(0){}

	NVector4(float x) :x(x), y(x), z(x), w(x) {}
	NVector4(float x, float y, float z, float w) :x(x), y(y), z(z), w(w) {}

	NVector4(const NVector2 vector2) :x(vector2.x), y(vector2.y), z(0), w(0) {}
	NVector4(const NVector2 vector2, const float z) :x(vector2.x), y(vector2.y), z(z), w(0) {}
	NVector4(const NVector2 vector2, const float z,const float w) :x(vector2.x), y(vector2.y), z(z),w(w) {}

	NVector4(const NVector3 vector3) :x(vector3.x), y(vector3.y), z(vector3.z), w(0) {}
	NVector4(const NVector3 vector3, const float w) :x(vector3.x), y(vector3.y), z(vector3.z), w(w) {}

	~NVector4(void) {}

	NVector3 ToVector3() {
		return NVector3(x, y, z);
	}
	NVector2 ToVector2() {
		return NVector2(x, y);
	}

	void		Invert() {
		x = -x;
		y = -y;
		z = -z;
		w = -w;
	}
	NVector4	Inverse() const { return NVector4(-x, -y, -z,-w); }

	void		FromRGBA() {
		if (x > 255.0f) x = 1.0f;
		else if (x < 0.0f) x = 0.0f;
		else x = x / 255.0f;

		if (y > 255.0f) y = 1.0f;
		else if (y < 0.0f) y = 0.0f;
		else y = y / 255.0f;

		if (z > 255.0f) z = 1.0f;
		else if (z < 0.0f) z = 0.0f;
		else z = z / 255.0f;

		if (w > 1.0f) w = 1.0f;
		else if (w < 0.0f) w = 0.0f;
	}
	NVector4	FromRGBA() const {
		NVector4 rbgVector;
		if (x > 255.0f) rbgVector.x = 1.0f;
		else if (x < 0.0f) rbgVector.x = 0.0f;
		else rbgVector.x = x / 255.0f;

		if (y > 255.0f) rbgVector.y = 1.0f;
		else if (y < 0.0f) rbgVector.y = 0.0f;
		else rbgVector.y = y / 255.0f;

		if (z > 255.0f) rbgVector.z = 1.0f;
		else if (z < 0.0f) rbgVector.z = 0.0f;
		else rbgVector.z = z / 255.0f;

		if (w > 1.0f) rbgVector.w = 1.0f;
		else if (w < 0.0f) rbgVector.w = 0.0f;

		return rbgVector;
	}

	void		ToRGBA() {
		if (x > 1.0f) x = 255.0f;
		else if (x < 0.0f) x = 0.0f;
		else x = x * 255.0f;

		if (y > 1.0f) y = 255.0f;
		else if (y < 0.0f) y = 0.0f;
		else y = y * 255.0f;

		if (z > 1.0f) z = 255.0f;
		else if (z < 0.0f) z = 0.0f;
		else z = z * 255.0f;

		if (w > 1.0f) w = 1.0f;
		else if (w < 0.0f) w = 0.0f;
	}
	NVector4	ToRGBA() const {
		NVector4 rbgVector;
		if (x > 1.0f) rbgVector.x = 255.0f;
		else if (x < 0.0f) rbgVector.x = 0.0f;
		else rbgVector.x = x * 255.0f;

		if (y > 1.0f) rbgVector.y = 255.0f;
		else if (y < 0.0f) rbgVector.y = 0.0f;
		else rbgVector.y = y * 255.0f;

		if (z > 1.0f) rbgVector.z = 255.0f;
		else if (z < 0.0f) rbgVector.z = 0.0f;
		else rbgVector.z = z * 255.0f;

		if (w > 1.0f) rbgVector.w = 1.0f;
		else if (w < 0.0f) rbgVector.w = 0.0f;

		return rbgVector;
	}

	inline NVector4		operator+(const NVector4& a) const {
		return NVector4(x + a.x, y + a.y, z + a.z,w + a.w);
	}
	inline void			operator+=(const NVector4& a) {
		x += a.x;
		y += a.y;
		z += a.z;
		w += a.w;
	}

	inline NVector4		operator-(const NVector4& a) const {
		return NVector4(x - a.x, y - a.y, z - a.z,w - a.w);
	}
	inline void			operator-=(const NVector4& a) {
		x -= a.x;
		y -= a.y;
		z -= a.z;
		w -= a.w;
	}

	inline NVector4		operator-() const {
		return NVector4(-x, -y, -z, -w);
	}

	inline NVector4		operator*(const float a) const {
		return NVector4(x * a, y * a, z * a, w * a);
	}
	inline NVector4		operator*(const NVector4& a) const {
		return NVector4(x * a.x, y * a.y, z * a.z,  w * a.w);
	}

	inline NVector4		operator/(const NVector4& a) const {
		if (a.x == 0 || a.y == 0 || a.z == 0 || a.w == 0) {
			std::cout << "Numerator is 0 !" << std::endl;
			return NVector4(x, y, z, w);
		}
		return NVector4(x / a.x, y / a.y, z / a.z, w / a.w);
	};
	inline NVector4		operator/(const float a) const {
		if (a == 0) {
			std::cout << "Numerator is 0 !" << std::endl;
			return NVector4(x, y, z, w);
		}
		return NVector4(x / a, y / a, z / a,w/a);
	};
};