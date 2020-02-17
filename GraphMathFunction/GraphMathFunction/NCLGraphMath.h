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
		Ex: NVector4 tempa = NVector4( NVector3( 1, 2, 3), 4 );
			NVector4 tempb = NVector4( NVector3( 1, 2, 3) );			---> it will be (1, 2, 3, 0)

	2.Allow downgrade a Nvector
		Ex: NVector2 tempa = NVector4 tempb.ToVector2();

	3.Allow some multiplication with any order
		Ex: (float * vector) & (vector * vector)

	4.Invert will change itself while Inverse will return a new value
		Ex: NVector4 tempa.Invert();
			NVector2 tempb = NVector4 tempa.Inverse();

	5.RGB & RGBA in NVector3 and NVector4
		ToRGB will zoom a NVector3 from (0~1, 0~1, 0~1) to (0~255, 0~255, 0~255)
		FromRGB will zoom a NVector3 from (0~255, 0~255, 0~255) to (0~1, 0~1, 0~1)

		ToRGBA will zoom a NVector4 from (0~1, 0~1, 0~1, 0~1) to (0~255, 0~255, 0~1)
		FromRGBA will zoom a NVector4 from (0~255, 0~255, 0~255, 0~1) to (0~1, 0~1, 0~1)

	6.Division check, numerator will check if =0, and will send error massange

	7.New constructor for every Nvector allow building will same value
		Ex: NVector4 temp(1)			---> it will be (1,1,1,1)
			NVector3 temp(3)			---> it will be (3,3,3)
*/
#pragma endregion
