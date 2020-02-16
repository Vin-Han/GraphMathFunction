#pragma once
#include <iostream>
#include <cmath>

class NVector2{
public:
	float x;
	float y;

	NVector2(void) :x(0), y(0) {}
	NVector2(const float x) :x(x), y(x) {}
	NVector2(const float x, const float y):x(x),y(y) {}
	~NVector2(void) {}

	void		ToZero()	{ x = y = 0.0f;}
	float		Length() const { return sqrt(x * x) + (y * y);}
	void		Normalise() {
		float length = Length();
		if (length != 0.0f) {
			length = 1.0f / length;
			x = x * length;
			y = y * length;
		}
	}
	void		Invert() {
		x = -x;
		y = -y;
	}
	NVector2	Inverse() const { return NVector2(-x, -y); }


	static float	Dot(const NVector2& a, const NVector2& b) {
		return (a.x * b.x) + (a.y * b.y);
	}

	inline friend std::ostream& operator<<(std::ostream& o, const NVector2& v) {
		o << "NVector2 £º (" << v.x << "," << v.y << ")" << std::endl;
		return o;
	}

	inline NVector2  operator+(const NVector2& a) const {
		return NVector2(x + a.x, y + a.y);
	}
	inline void operator+=(const NVector2& a) {
		x += a.x;
		y += a.y;
	}

	inline NVector2  operator-(const NVector2& a) const {
		return NVector2(x - a.x, y - a.y);
	}
	inline void operator-=(const NVector2& a) {
		x -= a.x;
		y -= a.y;
	}

	inline NVector2  operator*(const NVector2& a) const {
		return NVector2(x * a.x, y * a.y);
	}
	inline NVector2  operator*(const float& a) const {
		return NVector2(x * a, y * a);
	}

	inline NVector2  operator/(const NVector2& a) const {
		return NVector2(x / a.x, y / a.y);
	};
	inline NVector2  operator/(const float& a) const {
		if (a == 0){
			std::cout << "Numerator is 0 !" << std::endl;
			return NVector2(x, y);
		}
		return NVector2(x/a, y/a);
	}

	inline NVector2  operator-() const {
		return NVector2(-x, -y);
	}

	inline bool		 operator==(const NVector2& a)const { 
		return (a.x == x && a.y == y) ? true : false; 
	}
	inline bool		 operator!=(const NVector2& a)const { 
		return (a.x == x && a.y == y) ? false : true;
	}
};