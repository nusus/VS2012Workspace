#include "rotation_matrix.h"
#include "euler_angles.h"
#include "math_util.h"
#include "quaternion.h"
#include "Vector3.h"


tdfom::CRotationMatrix::CRotationMatrix()
{

}

tdfom::CRotationMatrix::~CRotationMatrix()
{

}

void tdfom::CRotationMatrix::Identity()
{
	m_fM11 = 1.0f, m_fM12 = 0.0f, m_fM13 = 0.0f;
	m_fM21 = 0.0f, m_fM22 = 1.0f, m_fM23 = 0.0f;
	m_fM31 = 0.0f, m_fM32 = 0.0f, m_fM33 = 1.0f;
}

void tdfom::CRotationMatrix::Setup( const CEulerAngles& orientation )
{
	float sh, ch, sp, cp, sb, cb;

	SinCos(orientation.m_fHeading, &sh, &ch);
	SinCos(orientation.m_fPitch, &sp, &cp);
	SinCos(orientation.m_fBank, &sb, &cb);

	m_fM11 = ch * cb + sh * sp * sb;
	m_fM12 = -ch * sb + sh * sp * cb;
	m_fM13 = sh * cp;

	m_fM21 = sb * cp;
	m_fM22 = cb * cp;
	m_fM23 = -sp;

	m_fM31 = -sh * cb + ch * sp * sb;
	m_fM32 = sb * sh + ch * sp * cb;
	m_fM33 = ch * cp;
}

void tdfom::CRotationMatrix::FromInertialToObjectQuaternion( const CQuaternion& q )
{
	m_fM11 = 1.0f - 2.0f * (q.m_fY * q.m_fY + q.m_fZ * q.m_fZ ) ;
	m_fM12 = 2.0f * q.m_fX * q.m_fY + 2.0f * q.m_fW * q.m_fZ;
	m_fM13 = 2.0f * (q.m_fX * q.m_fZ - q.m_fW * q.m_fY );

	m_fM21 = 2.0f * (q.m_fX * q.m_fY - q.m_fW * q.m_fZ);
	m_fM22 = 1.0f - 2.0f * (q.m_fX * q.m_fX + q.m_fZ * q.m_fZ);
	m_fM23 = 2.0f * (q.m_fY * q.m_fZ + q.m_fW * q.m_fX);

	m_fM31 = 2.0f * (q.m_fX * q.m_fZ + q.m_fW * q.m_fY);
	m_fM32 = 2.0f * (q.m_fY * q.m_fZ - q.m_fW * q.m_fX);
	m_fM33 = 1.0f - 2.0f * (q.m_fX * q.m_fX + q.m_fY * q.m_fY);
}

void tdfom::CRotationMatrix::FromObjectToInertialQuaternion( const CQuaternion& q )
{
	m_fM11 = 1.0f - 2.0f * (q.m_fY * q.m_fY + q.m_fZ * q.m_fZ);
	m_fM12 = 2.0f * (q.m_fX * q.m_fY - q.m_fW * q.m_fZ);
	m_fM13 = 2.0f * (q.m_fX * q.m_fZ + q.m_fW * q.m_fY);

	m_fM21 = 2.0f * (q.m_fX * q.m_fY + q.m_fW * q.m_fZ);
	m_fM22 = 1.0f - 2.0f * (q.m_fX * q.m_fX + q.m_fZ * q.m_fZ);
	m_fM23 = 2.0f * (q.m_fY * q.m_fZ - q.m_fW * q.m_fX);

	m_fM31 = 2.0f * (q.m_fX * q.m_fZ - q.m_fW * q.m_fY);
	m_fM32 = 2.0f * (q.m_fY * q.m_fZ + q.m_fW * q.m_fX);
	m_fM33 = 1.0f - 2.0f * (q.m_fX * q.m_fX + q.m_fY * q.m_fY);
}

tdfom::CVector3 tdfom::CRotationMatrix::InertialToObejct( const CVector3& vec ) const
{
	return CVector3(m_fM11 * vec.m_fX  + m_fM21 * vec.m_fY + m_fM31 * vec.m_fZ,
		m_fM12 * vec.m_fZ + m_fM22 * vec.m_fY + m_fM32 * vec.m_fZ,
		m_fM13 * vec.m_fX + m_fM23 * vec.m_fY + m_fM33 * vec.m_fZ);
}

tdfom::CVector3 tdfom::CRotationMatrix::ObejctToInertial( const CVector3& vec ) const
{
	return CVector3(m_fM11 * vec.m_fX  + m_fM12 * vec.m_fY + m_fM13 * vec.m_fZ,
		m_fM21 * vec.m_fZ + m_fM22 * vec.m_fY + m_fM23 * vec.m_fZ,
		m_fM31 * vec.m_fX + m_fM32 * vec.m_fY + m_fM33 * vec.m_fZ);
}
