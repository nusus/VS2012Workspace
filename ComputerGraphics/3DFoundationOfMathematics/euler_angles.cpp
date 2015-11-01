#include <math.h>

#include "math_util.h"
#include "euler_angles.h"
#include "quaternion.h"
#include "matrix4x3.h"
#include "rotation_matrix.h"


const tdfom::EulerAngles tdfom::g_kEulerAnglesIdentity(0.0f, 0.0f, 0.0f);

void tdfom::EulerAngles::Canonize()
{
	pitch_ = tdfom::WrapPI(pitch_);
	if(pitch_ < -tdfom::g_kPIOver2){
		pitch_ = -tdfom::g_kPI - pitch_;
		heading_ += tdfom::g_kPI;
		bank_ += tdfom::g_kPI;
	}else if(pitch_ > tdfom::g_kPIOver2)
	{
		pitch_ = tdfom::g_kPI - pitch_;
		heading_ +=tdfom::g_kPI;
		bank_ += tdfom::g_kPI;
	}

	if(fabs(pitch_) > tdfom::g_kPIOver2 - 1e-4){
		heading_ += bank_;
		bank_ = 0.0f;
	}else
	{
		bank_ = tdfom::WrapPI(bank_);
	}

	heading_ = tdfom::WrapPI(heading_);

}

void tdfom::EulerAngles::FromObjectToInertialQuaternion( const Quaternion& q )
{

}

void tdfom::EulerAngles::FromInertialToObjectQuaternion( const Quaternion& q )
{

}

void tdfom::EulerAngles::FromObjectToWorldMatrix( const Matrix4x3& m )
{

}

void tdfom::EulerAngles::FromWorldToObjectMatrix( const Matrix4x3& m )
{

}

void tdfom::EulerAngles::FromRotationMatrix( const RotationMatrix& rm )
{

}
