#pragma once

#include "NVector2.h"
#include "NVector3.h"
#include "NVector4.h"
#include "NQuaternion.h"
#include "NMatrix4.h"
#include "NMatrix3.h"

inline NVector2	operator*(const float a, const NVector2 v2) {
	NVector2 result = NVector2();
	result.x *= a;
	result.y *= a;
	return result;
}
inline NVector3	operator*(const float a ,const NVector3 v3){
	NVector3 result = NVector3();
	result.x *= a;
	result.y *= a;
	result.z *= a;
	return result;
}
inline NVector4	operator*(const float a, const NVector4 v3) {
	NVector4 result = NVector4();
	result.x *= a;
	result.y *= a;
	result.z *= a;
	result.w *= a;
	return result;
}
