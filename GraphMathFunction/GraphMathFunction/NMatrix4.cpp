#include "NMatrix4.h"

NMatrix4::NMatrix4(void){
	ToZero();
}

NMatrix4::NMatrix4(float elements[16]){
	for (size_t i = 0; i < 16; i++){
		values[i] = elements[i];
	}
}

void NMatrix4::ToZero(){
	for (float temp : values) {
		temp = 0;
	}
}

void NMatrix4::ToIdentity(){
	ToZero();
	values[0] = 1.0f;
	values[5] = 1.0f;
	values[10] = 1.0f;
	values[15] = 1.0f;
}

NVector3 NMatrix4::GetPositionVector() const{
	return NVector3(values[12], values[13], values[14]);
}

void NMatrix4::SetPositionVector(const NVector3 in){
	values[12] = in.x;
	values[13] = in.y;
	values[14] = in.z;
}

NVector3 NMatrix4::GetScalingVector() const{
	return NVector3(values[0], values[5], values[10]);
}

void NMatrix4::SetScalingVector(const NVector3& in){
	values[0] = in.x;
	values[5] = in.y;
	values[10] = in.z;
}

NMatrix4 NMatrix4::Rotation(float degrees, const NVector3& inaxis) {
	NMatrix4 m;

	NVector3 axis = inaxis;

	axis.Normalise();

	float c = cos((float)DegToRad(degrees));
	float s = sin((float)DegToRad(degrees));

	m.values[0] = (axis.x * axis.x) * (1.0f - c) + c;
	m.values[1] = (axis.y * axis.x) * (1.0f - c) + (axis.z * s);
	m.values[2] = (axis.z * axis.x) * (1.0f - c) - (axis.y * s);

	m.values[4] = (axis.x * axis.y) * (1.0f - c) - (axis.z * s);
	m.values[5] = (axis.y * axis.y) * (1.0f - c) + c;
	m.values[6] = (axis.z * axis.y) * (1.0f - c) + (axis.x * s);

	m.values[8] = (axis.x * axis.z) * (1.0f - c) + (axis.y * s);
	m.values[9] = (axis.y * axis.z) * (1.0f - c) - (axis.x * s);
	m.values[10] = (axis.z * axis.z) * (1.0f - c) + c;

	return m;
}

NMatrix4 NMatrix4::Scale(const NVector3& scale) {
	NMatrix4 m;

	m.values[0] = scale.x;
	m.values[5] = scale.y;
	m.values[10] = scale.z;

	return m;
}

NMatrix4 NMatrix4::Translation(const NVector3& translation) {
	NMatrix4 m;

	m.values[12] = translation.x;
	m.values[13] = translation.y;
	m.values[14] = translation.z;

	return m;
}

NMatrix4 NMatrix4::Perspective(float znear, float zfar, float aspect, float fov) {
	NMatrix4 m;

	const float h = 1.0f / tan(fov * PI_OVER_360);
	float neg_depth = znear - zfar;

	m.values[0] = h / aspect;
	m.values[5] = h;
	m.values[10] = (zfar + znear) / neg_depth;
	m.values[11] = -1.0f;
	m.values[14] = 2.0f * (znear * zfar) / neg_depth;
	m.values[15] = 0.0f;

	return m;
}

NMatrix4 NMatrix4::Orthographic(float znear, float zfar, float right, float left, float top, float bottom) {
	NMatrix4 m;

	m.values[0] = 2.0f / (right - left);
	m.values[5] = 2.0f / (top - bottom);
	m.values[10] = -2.0f / (zfar - znear);

	m.values[12] = -(right + left) / (right - left);
	m.values[13] = -(top + bottom) / (top - bottom);
	m.values[14] = -(zfar + znear) / (zfar - znear);
	m.values[15] = 1.0f;

	return m;
}

NMatrix4 NMatrix4::BuildViewNMatrix(const NVector3& from, const NVector3& lookingAt, const NVector3 up)
{
	NMatrix4 r;
	r.SetPositionVector(NVector3(-from.x, -from.y, -from.z));

	NMatrix4 m;

	NVector3 f = (lookingAt - from);
	f.Normalise();

	NVector3 s = NVector3::Cross(f, up);
	NVector3 u = NVector3::Cross(s, f);

	s.Normalise();
	u.Normalise();

	m.values[0] = s.x;
	m.values[4] = s.y;
	m.values[8] = s.z;

	m.values[1] = u.x;
	m.values[5] = u.y;
	m.values[9] = u.z;

	m.values[2] = -f.x;
	m.values[6] = -f.y;
	m.values[10] = -f.z;

	return m * r;
}
