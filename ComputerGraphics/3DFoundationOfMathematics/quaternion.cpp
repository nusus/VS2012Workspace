#include <math.h>
#include "quaternion.h"
#include <assert.h>
#include "Vector3.h"
#include "math_util.h"
#include "euler_angles.h"


const tdfom::CQuaternion g_kQuaternoinIdentity = {
	1.0f, 0.0f, 0.0f, 0.0f
};

tdfom::CQuaternion::CQuaternion()
{

}

tdfom::CQuaternion::~CQuaternion()
{

}

void tdfom::CQuaternion::SetToRotateAboutX( float theta )
{
	float thetaOver2 = theta * 0.5f;

	m_fW = cos(thetaOver2);
	m_fX = sin(thetaOver2);
	m_fY = 0.0f;
	m_fZ = 0.0f;
}

void tdfom::CQuaternion::SetToRotateAboutY( float theta )
{
	float thetaOver2 = theta * 0.5f;

	m_fW = cos(thetaOver2);
	m_fX = 0.0f;
	m_fY = sin(thetaOver2);
	m_fZ = 0.0f;
}

void tdfom::CQuaternion::SetToRotateAboutZ( float theta )
{
	float thetaOver2 = theta * 0.5f;

	m_fW = cos(thetaOver2);
	m_fX = 0.0f;
	m_fY = 0.0f;
	m_fZ = sin(thetaOver2);
}

void tdfom::CQuaternion::SetToRotateAboutAxis( const CVector3& axis, float theta )
{
	assert(fabs(VectorMag(axis) - 1.0f) < 0.01f);

	float thetaOver2 = theta * 0.5f;
	float sinThetaOver2 = sin(thetaOver2);

	m_fW = cos(thetaOver2);
	m_fX = axis.m_fX * sinThetaOver2;
	m_fY = axis.m_fY * sinThetaOver2;
	m_fZ = axis.m_fZ * sinThetaOver2;
}

void tdfom::CQuaternion::SetToRotateObjectToInertial( const CEulerAngles& orientation )
{
	float sp, sb, sh;
	float cp, cb, ch;
	SinCos(orientation.m_fPitch * 0.5f, &sp, &cp);
	SinCos(orientation.m_fHeading * 0.5f, &sh, &ch);
	SinCos(orientation.m_fBank * 0.5f, &sb, &cb);

	m_fW = ch * cp * cb + sh * sp * sb;
	m_fX = ch * sp * cb + sh * cp * sb;
	m_fY = -ch * sp * sb + sh * cp * cb;
	m_fZ = -sh * sp * cb + ch * cp * sb;
}

void tdfom::CQuaternion::SetToRotateInertialToObject( const CEulerAngles& orientation )
{
	float sp, sb, sh;
	float cp, cb, ch;
	SinCos(orientation.m_fPitch * 0.5f, &sp, &cp);
	SinCos(orientation.m_fHeading *0.5f, &sh, &ch);
	SinCos(orientation.m_fBank *0.5f, &sb, &cb);

	m_fW = ch * cp * cb + sh * sp * sb;
	m_fX = -ch * sp * cb - sh * cp * sb;
	m_fY = ch * sp * sb - sh * cb * cp;
	m_fZ = sh * sp * cb - ch * cp * sb;
}

void tdfom::CQuaternion::Normalize()
{
	float mag = CarmackSqrt(m_fW * m_fW + m_fX * m_fX + m_fY * m_fY + m_fZ * m_fZ);

	if (mag > 0.0f)
	{
		float oneOverMag = 1.0f / mag;
		m_fW *= oneOverMag;
		m_fX *= oneOverMag;
		m_fY *= oneOverMag;
		m_fZ *= oneOverMag;
	}
	else
	{
		assert(false);
		Identity();
	}
}

float tdfom::CQuaternion::GetRotationAngle() const
{
	float thetaOver2 = SafeAcos(m_fW);
	return thetaOver2 * 2.0f;
}

tdfom::CVector3 tdfom::CQuaternion::GetRotationAxis() const
{
	float sinThetaOver2Sq = 1.0f - m_fW * m_fW;
	if (sinThetaOver2Sq <= 0.0f)
	{
		return CVector3(1.0f, 0.0f, 0.0f);
	}

	float oneOverSinThetaOver2 = 1.0f / CarmackSqrt(sinThetaOver2Sq);

	return CVector3(
		m_fX * oneOverSinThetaOver2,
		m_fY * oneOverSinThetaOver2,
		m_fZ * oneOverSinThetaOver2
		);
}

tdfom::CQuaternion& tdfom::CQuaternion::operator*=( const CQuaternion& rhs )
{
	*this = *this * rhs;
	return *this;
}

tdfom::CQuaternion tdfom::CQuaternion::operator*( const CQuaternion& rhs ) const
{
	//强行使用返回值优化
	return CQuaternion(
		m_fW * rhs.m_fW - m_fX * rhs.m_fX - m_fY * rhs.m_fY - m_fZ * rhs.m_fZ,
		m_fW * rhs.m_fX + m_fX * rhs.m_fW + m_fZ * rhs.m_fY - m_fY * rhs.m_fZ,
		m_fW * rhs.m_fY + m_fY * rhs.m_fW + m_fX * rhs.m_fZ - m_fZ * rhs.m_fX,
		m_fW * rhs.m_fX + m_fZ * rhs.m_fW + m_fY * rhs.m_fX - m_fX * rhs.m_fY
		);

}

extern float tdfom::DotProduct( const CQuaternion& lhs, const CQuaternion& rhs )
{
	return lhs.m_fW * rhs.m_fW + lhs.m_fX * rhs.m_fX + lhs.m_fY * rhs.m_fY + lhs.m_fZ * rhs.m_fZ;
}

extern tdfom::CQuaternion tdfom::Slerp( const CQuaternion& begin, const CQuaternion& end, float t )
{
	if (t <= 0.0f)
	{
		return begin;
	}

	if (t >= 1.0f)
	{
		return end;
	}

	float cosOmega = DotProduct(begin, end);

	float beginW = begin.m_fW;
	float beginX = begin.m_fX;
	float beginY = begin.m_fY;
	float beginZ = begin.m_fZ;
	if (cosOmega < 0.0f)
	{
		beginW = -beginW;
		beginX = -beginX;
		beginY = -beginY;
		beginZ = -beginZ;
		cosOmega = -cosOmega;
	}
	assert(cosOmega < 1.1f);

	float k0, k1;
	if (cosOmega > 0.9999f)
	{
		k0 = 1.0f - t;
		k1 = t;
	} 
	else
	{
		float sinOmega = CarmackSqrt(1.0f - cosOmega * cosOmega);

		float omega = atan2(sinOmega, cosOmega);

		float oneOverSinOmega = 1.0f / sinOmega;

		k0 = sin((1.0f - t) * omega) * oneOverSinOmega;
		k1 = sin(t * omega) * oneOverSinOmega;
	}

	return CQuaternion(
		k0 * begin.m_fW + k1 * end.m_fW,
		k0 * begin.m_fX + k1 * end.m_fX,
		k0 * begin.m_fY + k1 * end.m_fY,
		k0 * begin.m_fZ + k1 * end.m_fZ
		);

}

extern tdfom::CQuaternion tdfom::Conjugate( const CQuaternion& val )
{
	return CQuaternion(
		val.m_fW,
		-val.m_fX,
		-val.m_fY,
		-val.m_fZ);
}

extern tdfom::CQuaternion tdfom::Pow( const CQuaternion& lhs, float exponent )
{
	if (fabs(lhs.m_fW) > 0.9999f)
	{
		return lhs;
	}

	float alpha = acos(lhs.m_fW);

	float newAlpha = alpha * exponent;

	float mult = sin(newAlpha) / sin(alpha);
	return CQuaternion(
		cos(newAlpha),
		lhs.m_fX * mult,
		lhs.m_fY * mult,
		lhs.m_fZ * mult);
}
