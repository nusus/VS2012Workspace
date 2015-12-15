#include "euler_angles.h"
#include "math_util.h"
#include "quaternion.h"
#include "matrix4x3.h"
#include "rotation_matrix.h"

const tdfom::CEulerAngles g_kEulerAnglesIdentity(0.0f, 0.0f, 0.0f);

void tdfom::CEulerAngles::Canonize()
{
	//first, we transfer m_fPitch between -pi and pi
	m_fPitch = WrapPI(m_fPitch);

	//now, we transfer m_fPitch between -pi/2 and pi/2
	if (m_fPitch < -g_kPIOver2)
	{
		m_fPitch = -g_kPI - m_fPitch;
		m_fHeading += g_kPI;
		m_fBank += g_kPI;
	}
	else if (m_fPitch > g_kPIOver2)
	{
		m_fPitch = g_kPI - m_fPitch;
		m_fHeading += g_kPI;
		m_fBank += g_kPI;
	}

	//现在我们检查万象锁的情况，我们允许存在一定的误差
	if (fabs(m_fPitch) > g_kPIOver2 - 1e-4)
	{
		m_fHeading += m_fBank;
		m_fBank = 0.0f;
	} 
	else
	{
		m_fBank = WrapPI(m_fBank);
	}

	m_fHeading = WrapPI(m_fHeading);
}

void tdfom::CEulerAngles::FromObjectToInertialQuaternion( const CQuaternion& q )
{
	float sp = -2.0f * (q.m_fY * q.m_fZ + q.m_fW * q.m_fX);

	if (fabs(sp) > 0.9999f)
	{
		m_fPitch = g_kPIOver2 * sp;//这里pitch就是pi/2
		m_fHeading = atan2(-q.m_fX * q.m_fZ + q.m_fW * q.m_fY, 0.5f - q.m_fY * q.m_fY - q.m_fZ * q.m_fZ);
		m_fBank = 0.0f;
	}
	else 
	{
		m_fPitch = asin(sp);
		m_fHeading = atan2(q.m_fX * q.m_fZ + q.m_fW * q.m_fY, 0.5f - q.m_fX * q.m_fX -q.m_fY * q.m_fY);
		m_fBank = atan2(q.m_fX * q.m_fY + q.m_fW * q.m_fZ, 0.5f - q.m_fX * q.m_fX - q.m_fZ * q.m_fZ);
	}
}

void tdfom::CEulerAngles::FromInertialToObjectQuaternion( const CQuaternion& q )
{
	float sp = -2.0f * (q.m_fY * q.m_fZ + q.m_fW * q.m_fX);

	if (fabs(sp) > 0.9999f)
	{
		m_fPitch = g_kPIOver2 * sp;//这里pitch就是pi/2
		m_fHeading = atan2(-q.m_fX * q.m_fZ - q.m_fW * q.m_fY, 0.5f - q.m_fY * q.m_fY - q.m_fZ * q.m_fZ);
		m_fBank = 0.0f;
	}
	else 
	{
		m_fPitch = asin(sp);
		m_fHeading = atan2(q.m_fX * q.m_fZ - q.m_fW * q.m_fY, 0.5f - q.m_fX * q.m_fX -q.m_fY * q.m_fY);
		m_fBank = atan2(q.m_fX * q.m_fY - q.m_fW * q.m_fZ, 0.5f - q.m_fX * q.m_fX - q.m_fZ * q.m_fZ);
	}
}

void tdfom::CEulerAngles::FromObjectToWorldMatrix( const CMatrix4x3& m )
{
	float sp = -m.m_fM32;

	if (fabs(sp) > 0.9999f)
	{
		m_fPitch = g_kPIOver2 * sp;
		m_fHeading = atan2(-m.m_fM23, m.m_fM11);
		m_fBank = 0.0f;
	}
	else
	{
		m_fHeading = atan2(m.m_fM31, m.m_fM33);
		m_fPitch = asin(sp);
		m_fBank = atan2(m.m_fM12, m.m_fM22);
	}
}

void tdfom::CEulerAngles::FromWorldToObjectMatrix( const CMatrix4x3& m )
{
	float sp = -m.m_fM23;

	if (fabs(sp) > 0.99999f)
	{
		m_fPitch = g_kPIOver2 * sp;
		m_fHeading = atan2(-m.m_fM31, m.m_fM11);
		m_fBank = 0.0f;
	}
	else
	{
		m_fHeading = atan2(m.m_fM13, m.m_fM33);
		m_fPitch = asin(sp);
		m_fBank = atan2(m.m_fM21, m.m_fM22);
	}
}

void tdfom::CEulerAngles::FromRotationMatrix( const CRotationMatrix& rm )
{
	float sp = -rm.m_fM23;

	if (fabs(sp) > 0.99999f)
	{
		m_fPitch = g_kPIOver2 * sp;
		m_fHeading  = atan2(-rm.m_fM31, rm.m_fM11);
		m_fBank = 0.0f;
	}
	else
	{
		m_fHeading = atan2(rm.m_fM13, rm.m_fM33);
		m_fPitch = asin(sp);
		m_fBank = atan2(rm.m_fM21, rm.m_fM22);
	}
}
