/********************************************************************
	created:	2015/11/01
	created:	1:11:2015   22:27
	filename: 	F:\VSWorkspace\VS2012Workspace\ComputerGraphics\3DFoundationOfMathematics\CVector3.h
	file path:	F:\VSWorkspace\VS2012Workspace\ComputerGraphics\3DFoundationOfMathematics
	file base:	CVector3
	file ext:	h
	author:		zengli
	
	purpose:	
*********************************************************************/
#ifndef CVector3_h__
#define CVector3_h__

#include <cfloat>

namespace tdfom {

	//************************************
	// Description:卡马克开方法
	// Method:    CarmackSqrt
	// FullName:  tdfom::CarmackSqrt
	// Access:    public 
	// Returns:   float
	// Qualifier:
	// Parameter: float number
	//************************************
	float CarmackSqrt(float number);

	class CVector3
	{
	public:
		float m_fX, m_fY, m_fZ;
	public:
		CVector3() {}
		CVector3(const CVector3& rhs) :
			m_fX(rhs.m_fX),
			m_fY(rhs.m_fY),
			m_fZ(rhs.m_fZ) {}
		CVector3(float x, float y, float z) :
			m_fX(x),
			m_fY(y),
			m_fZ(z) {}

		~CVector3();


		CVector3& operator=(const CVector3& rhs) {
			m_fX = rhs.m_fX;
			m_fY = rhs.m_fY;
			m_fZ = rhs.m_fZ;
			return *this;
		}

		bool operator == (const CVector3& rhs) const {
			return (m_fX == rhs.m_fX) && (m_fY == rhs.m_fY) && (m_fZ == rhs.m_fZ);
		}
		bool operator!=(const CVector3& rhs) const {
			return m_fX != rhs.m_fX || m_fY != rhs.m_fY || m_fZ != rhs.m_fZ;
		}

		void Zero() {
			m_fX = m_fY = m_fZ = 0.0f;
		}

		CVector3 operator - () const {
			return CVector3(-m_fX, -m_fY, -m_fZ);
		}

		CVector3 operator+(const CVector3& rhs) const {
			return CVector3(m_fX + rhs.m_fX, m_fY + rhs.m_fY, m_fZ + rhs.m_fZ);
		}


		CVector3 operator-(const CVector3& rhs) const {
			return CVector3(m_fX - rhs.m_fX, m_fY - rhs.m_fY, m_fZ - rhs.m_fZ);
		}

		CVector3 operator*(float a) const {
			return CVector3(m_fX * a, m_fY * a, m_fZ * a);
		}

		CVector3 operator/(float a) const {
			float one_over_a = 1.0f / a;
			return CVector3(m_fX * one_over_a, m_fY * one_over_a, m_fZ * one_over_a);
		}

		CVector3& operator+=(const CVector3& rhs) {
			m_fX += rhs.m_fX;
			m_fY += rhs.m_fY;
			m_fZ += rhs.m_fZ;
			return *this;
		}

		CVector3& operator-=(const CVector3& rhs) {
			m_fX -= rhs.m_fX;
			m_fY -= rhs.m_fY;
			m_fZ -= rhs.m_fZ;
			return *this;
		}

		CVector3& operator *=(float a) {
			m_fX *= a;
			m_fY *= a;
			m_fZ *= a;
			return *this;
		}

		CVector3& operator/=(float a) {
			float one_over_a = 1.0f / a;
			m_fX *= one_over_a;
			m_fY *= one_over_a;
			m_fZ *= one_over_a;
			return *this;
		}

		void Normalize() {
			float sq = m_fX * m_fX + m_fY * m_fY + m_fZ *m_fZ;
			if (sq > 0.00f) {
				float one_over_sq = 1.0f / tdfom::CarmackSqrt(sq);
				m_fX *= one_over_sq;
				m_fY *= one_over_sq;
				m_fZ *= one_over_sq;
			}
		}

		float operator*(const CVector3& rhs) const {
			return m_fX * rhs.m_fX + m_fY * rhs.m_fY + m_fZ * rhs.m_fZ;
		}
	private:

	};

	inline float VectorMag(const CVector3& rhs) {
		return rhs.m_fX * rhs.m_fX + rhs.m_fY * rhs.m_fY + rhs.m_fZ * rhs.m_fZ;
	}

	inline CVector3 CrossProduct(const CVector3& lhs, const CVector3& rhs) {
		return CVector3(
			lhs.m_fY * rhs.m_fZ - lhs.m_fZ * rhs.m_fY,
			lhs.m_fZ * rhs.m_fX - lhs.m_fX * rhs.m_fZ,
			lhs.m_fX * rhs.m_fY - lhs.m_fY * rhs.m_fX
			);
	}

	inline CVector3 operator*(float k, const CVector3& rhs) {
		return CVector3(
			rhs.m_fX * k,
			rhs.m_fY * k,
			rhs.m_fZ * k
			);
	}

	inline float Distance(const CVector3& lhs, const CVector3& rhs) {
		float x = lhs.m_fX - rhs.m_fX;
		float y = lhs.m_fY - rhs.m_fY;
		float z = lhs.m_fZ - rhs.m_fZ;
		return CarmackSqrt(x*x + y*y + z*z);
	}

	float CarmackSqrt(float number) {
		long i;
		float x, y;
		const float f = 1.5F;
		x = number * 0.5F;
		y = number;
		i = *(long *)&y;
		i = 0x5f3759df - (i >> 1);
		y = *(float *)&i;
		y = y* (f - (x * y * y));
		y = y * (f - (x * y * y));
		return number * y;
	}

	extern const CVector3 kZeroVector;
}
#endif // CVector3_h__