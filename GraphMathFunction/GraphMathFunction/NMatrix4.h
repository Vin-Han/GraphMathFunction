#pragma once

#include "NVector3.h"
#include "NVector4.h"

static const float		PI = 3.14159265358979323846f;
static const float		PI_OVER_360 = PI / 360.0f;

//Radians to degrees
static inline double RadToDeg(const double deg) {
	return deg * 180.0 / PI;
};

//Degrees to radians
static inline double DegToRad(const double rad) {
	return rad * PI / 180.0;
};

/*
NMatrix4 £º / ------------------\
			|	0	4	8	12	|
			|	1	5	9	13	|
			|	2	6	10	14	|
			|	3	7	11	15	|
			\ ------------------/
*/
class NMatrix4
{
public:
	float	values[16];

	NMatrix4(void);
	NMatrix4(float elements[16]);
	~NMatrix4(void) {}

	//All to zero
	void	ToZero();
	//Set floats[0,5,10,15] to 1;
	void	ToIdentity();



	//Gets the OpenGL position vector (floats 12,13, and 14)
	NVector3 GetPositionVector() const;
	//Sets the OpenGL position vector (floats 12,13, and 14)
	void	SetPositionVector(const NVector3 in);

	//Gets the scale vector (floats 1,5, and 10)
	NVector3 GetScalingVector() const;
	//Sets the scale vector (floats 1,5, and 10)
	void	SetScalingVector(const NVector3& in);



	//Creates a rotation NMatrix that rotates by 'degrees' around the 'axis'
	static NMatrix4 Rotation(float degrees, const NVector3& axis);

	//Creates a scaling NMatrix (puts the 'scale' NVector down the diagonal)
	static NMatrix4 Scale(const NVector3& scale);

	//Creates a translation NMatrix at floats 12, 13, and 14
	static NMatrix4 Translation(const NVector3& translation);




	//Creates a perspective NMatrix, with 'znear' and 'zfar' as the near and 
	//far planes, using 'aspect' and 'fov' as the aspect ratio and vertical
	//field of vision, respectively.
	static NMatrix4 Perspective(float znear, float zfar, float aspect, float fov);

	//Creates an orthographic NMatrix with 'znear' and 'zfar' as the near and 
	//far planes, and so on. Descriptive variable names are a good thing!
	static NMatrix4 Orthographic(float znear, float zfar, float right, float left, float top, float bottom);

	//Builds a view NMatrix suitable for sending straight to the vertex shader.
	//Puts the camera at 'from', with 'lookingAt' centered on the screen, with
	//'up' as the...up axis (pointing towards the top of the screen)
	static NMatrix4 BuildViewNMatrix(const NVector3& from, const NVector3& lookingAt, const NVector3 up = NVector3(0, 1, 0));


	//Multiplies 'this' NMatrix by NMatrix 'a'. Performs the multiplication in 'OpenGL' order (ie, backwards)
	inline NMatrix4 operator*(const NMatrix4& a) const {
		NMatrix4 out;
		//Students! You should be able to think up a really easy way of speeding this up...
		for (unsigned int r = 0; r < 4; ++r) {
			for (unsigned int c = 0; c < 4; ++c) {
				out.values[c + (r * 4)] = 0.0f;
				for (unsigned int i = 0; i < 4; ++i) {
					out.values[c + (r * 4)] += this->values[c + (i * 4)] * a.values[(r * 4) + i];
				}
			}
		}
		return out;
	}

	inline NVector3 operator*(const NVector3& v) const {
		NVector3 vec;

		float temp;

		vec.x = v.x * values[0] + v.y * values[4] + v.z * values[8] + values[12];
		vec.y = v.x * values[1] + v.y * values[5] + v.z * values[9] + values[13];
		vec.z = v.x * values[2] + v.y * values[6] + v.z * values[10] + values[14];

		temp = v.x * values[3] + v.y * values[7] + v.z * values[11] + values[15];

		vec.x = vec.x / temp;
		vec.y = vec.y / temp;
		vec.z = vec.z / temp;

		return vec;
	};

	inline NVector4 operator*(const NVector4& v) const {
		return NVector4(
			v.x * values[0] + v.y * values[4] + v.z * values[8] + v.w * values[12],
			v.x * values[1] + v.y * values[5] + v.z * values[9] + v.w * values[13],
			v.x * values[2] + v.y * values[6] + v.z * values[10] + v.w * values[14],
			v.x * values[3] + v.y * values[7] + v.z * values[11] + v.w * values[15]
		);
	};

	//Handy string output for the NMatrix. Can get a bit messy, but better than nothing!
	inline friend std::ostream& operator<<(std::ostream& o, const NMatrix4& m) {
		o << "Mat4: (";
		o << "\t" << m.values[0] << "," << m.values[1] << "," << m.values[2] << "," << m.values[3] << std::endl;
		o << "\t\t" << m.values[4] << "," << m.values[5] << "," << m.values[6] << "," << m.values[7] << std::endl;
		o << "\t\t" << m.values[8] << "," << m.values[9] << "," << m.values[10] << "," << m.values[11] << std::endl;
		o << "\t\t" << m.values[12] << "," << m.values[13] << "," << m.values[14] << "," << m.values[15] << " )" << std::endl;
		return o;
	}





};

