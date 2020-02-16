#pragma once

#include <iostream>
#include "NMatrix4.h"

#define max(a,b)    (((a) > (b)) ? (a) : (b))
#define min(a,b)    (((a) < (b)) ? (a) : (b))

class NQuaternion{
public:
	float x;
	float y;
	float z;
	float w;

	NQuaternion(void);
	NQuaternion(float x, float y, float z, float w);
	~NQuaternion(void);

	void		Normalise();
	NMatrix4	ToNMatrix() const;


	NQuaternion	Conjugate() const;
	void		GenerateW();//builds 4th component when loading in shortened, 3 component NQuaternions

	static NQuaternion EulerAnglesToQuaternion(float pitch, float yaw, float roll);
	static NQuaternion AxisAngleToQuaterion(const NVector3& NVector, float degrees);

	static void RotatePointByQuaternion(const NQuaternion& q, NVector3& point);

	static NQuaternion FromMatrix(const NMatrix4& m);

	static float Dot(const NQuaternion& a, const NQuaternion& b);

	NQuaternion operator *(const NQuaternion& a) const;
	NQuaternion operator *(const NVector3& a) const;

	inline friend std::ostream& operator<<(std::ostream& o, const NQuaternion& q) {
		o << "Quat(" << q.x << "," << q.y << "," << q.z << "," << q.w << ")" << std::endl;
		return o;
	}

};

