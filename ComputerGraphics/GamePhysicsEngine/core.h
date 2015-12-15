#ifndef core_h__
#define core_h__

#include "precision.h"

#include <math.h>

namespace game_physics_engine {


	class CVector3
	{

	public:
		real m_fX;
		real m_fY;
		real m_fZ;

	private:
		real m_padding;

	public:
		CVector3() :
			m_fX(0),
			m_fY(0),
			m_fZ(0) 
		{}

		CVector3(real x, real y, real z) :
			m_fX(x),
			m_fY(y),
			m_fZ(z)
		{}
		~CVector3();

		void Invert() 
		{
			m_fX = -m_fX;
			m_fY = -m_fY;
			m_fZ = -m_fZ;
		}

		real Magnitude() const 
		{
			return real_sqrt(m_fX * m_fX + m_fY * m_fY + m_fZ* m_fZ);
		}

		real SquareMagnitude() const
		{
			return m_fX * m_fX + m_fY * m_fY + m_fZ * m_fZ;
		}

		void Normalize() 
		{
			real len = Magnitude();
			if (len > 0)
			{
				(*this) *= (((real)1) / len);
			}
		}

		void operator*=(const real value) 
		{
			m_fX *= value;
			m_fY *= value;
			m_fZ *= value;
		}

		CVector3 operator*(const real value) const
		{
			CVector3 ret(*this);
			ret *= value;
			return ret;
		}

		void operator+=(const CVector3 rhs) 
		{
			m_fX += rhs.m_fX;
			m_fY += rhs.m_fY;
			m_fZ += rhs.m_fZ;
		}

		CVector3 operator+(const CVector3 rhs) const
		{
			CVector3 ret(*this);
			ret += rhs;
			return rhs;

		}

		void operator-=(const CVector3 rhs)
		{
			m_fX -= rhs.m_fX;
			m_fY -= rhs.m_fY;
			m_fZ -= rhs.m_fZ;
		}

		CVector3 operator-(const CVector3 rhs) const 
		{
			CVector3 ret(*this);
			ret -= rhs;
			return ret;
		}

		void AddScaledVector(const CVector3& rhs, real scale) 
		{
			m_fX += rhs.m_fX * scale;
			m_fY += rhs.m_fY * scale;
			m_fZ += rhs.m_fZ * scale;
		}

		CVector3 ComponentProduct(const CVector3& rhs) const
		{
			return CVector3(m_fX * rhs.m_fX, m_fY * rhs.m_fY, m_fZ * rhs.m_fZ);
		}

		void ComponentProduceUpdate(const CVector3& rhs)
		{
			*this = ComponentProduct(rhs);
		}

		CVector3 VectorProduct(const CVector3& rhs) const
		{
			return CVector3(
				m_fY * rhs.m_fZ - m_fZ * rhs.m_fY,
				m_fZ * rhs.m_fX - m_fX * rhs.m_fZ,
				m_fX * rhs.m_fY - m_fY * rhs.m_fX
				);
		}

		void operator%=(const CVector3& rhs)
		{
			*this =  VectorProduct(rhs);
		}

		void operator*=(const CVector3& rhs)
		{
			this->operator%=(rhs);
		}

		CVector3 operator%(const CVector3& rhs) const
		{
			CVector3 ret(*this);
			ret %= rhs;
			return ret;
		}

		CVector3 operator*(const CVector3& rhs) const
		{
			CVector3 ret(*this);
			ret *= rhs;
			return ret;
		}

		CVector3 VectorProductUpdate(const CVector3& rhs) const
		{
			CVector3 ret(*this);
			ret = VectorProduct(rhs);
			return ret;
		}

		void Clear()
		{
			m_fX = m_fY = m_fZ = 0;
		}


	private:

	};
}

#endif // core_h__
