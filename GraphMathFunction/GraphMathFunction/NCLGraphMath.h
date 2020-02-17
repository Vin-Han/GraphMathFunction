#pragma once

#include "NVector2.h"
#include "NVector3.h"
#include "NVector4.h"
#include "NMatrix4.h"
#include "NQuaternion.h"
#include "OtherCommonFunction.h"

#pragma region NewFeature & Recheck 16/02/2020 by YiHan
/*
	1.Allow using low level vestor to build high level vector
		Ex: NVector4 temp4 = NVector4( NVector3( 1, 2, 3), 4);

	2.Allow downgrade a Nvector
		Ex: NVector2 temp2 = NVector4 temp4.ToVector2();

	3.Allow some multiplication with any order
		Ex: (float * vector) & (vector * vector)

	4.Invert will change itself while Inverse will return a new value
		Ex: NVector4 temp2.Invert();
			NVector2 temp22 = NVector4 temp2.Inverse();

	5.RGB & RGBA in NVector3 and NVector4
		ToRGB will zoom a NVector3 from (0~1, 0~1, 0~1) to (0~255, 0~255, 0~255)
		FromRGB will zoom a NVector3 from (0~255, 0~255, 0~255) to (0~1, 0~1, 0~1)

		ToRGBA will zoom a NVector4 from (0~1, 0~1, 0~1, 0~1) to (0~255, 0~255, 0~1)
		FromRGBA will zoom a NVector4 from (0~255, 0~255, 0~255, 0~1) to (0~1, 0~1, 0~1)

	6.Division check, numerator will check if =0, and will send error massange
*/
#pragma endregion
