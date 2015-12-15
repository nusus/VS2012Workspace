#ifndef partical_h__
#define partical_h__

#include "core.h"

namespace game_physics_engine 
{
	class CPartical
	{
	protected:
		CVector3 m_position;
		CVector3 m_velocity;
		CVector3 m_acceleration;
		CVector3 m_forceAccum;

		real m_fDamping;
		real m_fInverseMass;
	public:
		CPartical();
		~CPartical();

		void Integrate(const real duration);

		void SetMass(const real mass);
		real GetMass() const;

		void SetInverseMass(const real inverseMass);
		real GetInverseMass() const;

		bool HasFiniteMass() const;

		void SetDamping(const real damping);
		real GetDamping() const;

		void SetPosition(const CVector3& position);
		void SetPosition(const real x, const real y, const real z);

		void GetPosition(CVector3* pPosition) const;
		CVector3 GetPosition() const;

		void SetVelocity(const CVector3& velocity);
		void SetVelocity(const real x, const real y, const real z);

		void GetVelocity(CVector3* pVelocity) const;
		CVector3 GetVelocity() const;

		void SetAcceleration(const CVector3& acceleration);
		void SetAcceleration(const real x, const real y, const real z);

		void GetAcceleration(CVector3* pAcceleration) const;
		CVector3 GetAcceleration() const;
		
		void ClearAccumulator();

		void AddForce(const CVector3& force);
	private:

	};

}
#endif // partical_h__
