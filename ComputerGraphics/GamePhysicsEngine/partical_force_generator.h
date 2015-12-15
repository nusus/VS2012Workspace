#ifndef partical_force_generator_h__
#define partical_force_generator_h__

#include "core.h"
#include "partical.h"

#include <vector>

namespace game_physics_engine
{
	class CParticalForceGenerator
	{
	public:
		CParticalForceGenerator();
		~CParticalForceGenerator();

		virtual void UpdateForce(CPartical* pPartical, const real duration) = 0 ;

	private:

	};

	class CParticalForceRegistry
	{
	protected:
		struct SParticalForceRegistration
		{
			CPartical* pPartical;
			CParticalForceGenerator* pParticalForceGenerator;
			SParticalForceRegistration(CPartical* pPartical, CParticalForceGenerator* pParticalForceGenerator):
				pPartical(pPartical),
				pParticalForceGenerator(pParticalForceGenerator)
			{
			}
			SParticalForceRegistration(){}
		};

		typedef std::vector<SParticalForceRegistration> Registry;
		Registry m_registrations;
	public:
		CParticalForceRegistry();
		~CParticalForceRegistry();


		void Add(CPartical* pPartical, CParticalForceGenerator* pFg);

		void Remove(CPartical* pPartical, CParticalForceGenerator* pFg);

		void Clear();

		void UpdateForce(const real fDuration);
	private:

	};

	class CParticalGravity : public CParticalForceGenerator
	{
	public:
		CParticalGravity();
		CParticalGravity(const CVector3& gravity):
			m_gravity(gravity) {}
		~CParticalGravity(){};

		virtual void UpdateForce( CPartical* pPartical, const real duration );


	protected:
		
	private:
		CVector3 m_gravity;
	};

	class CParticalDrag : public CParticalForceGenerator
	{
	public:
		CParticalDrag();
		CParticalDrag(real k1, real k2);
		~CParticalDrag();

		virtual void UpdateForce( CPartical* pPartical, const real duration );

	protected:
		
	private:
		real m_k1;
		real m_k2;
	};

	class CParticalSpring : public CParticalForceGenerator
	{
	public:
		CParticalSpring();
		CParticalSpring(CPartical* pOther, real fSpringConstant, real fRestLength) :
			m_pOther(pOther),
			m_fSpringConstant(fSpringConstant),
			m_fRestLength(fRestLength) {}
		~CParticalSpring();

		virtual void UpdateForce(CPartical* pPartical, real fDuration);
	private:
		CPartical* m_pOther;
		real m_fSpringConstant;
		real m_fRestLength;
	};

	class CParticalAnchoredSpring : public CParticalForceGenerator
	{
	public:
		CParticalAnchoredSpring();
		CParticalAnchoredSpring(CVector3* pAnchor, real fSpringConstant, real fRestLength);
		~CParticalAnchoredSpring();

		virtual void UpdateForce(CPartical* pOther, real fDuration);
	protected:
		
	private:
		CVector3* m_pAnchor;
		real m_fSpringConstant;
		real m_fRestLength;
	};


	class CParticalBungee : public CParticalForceGenerator
	{
	public:
		CParticalBungee();
		CParticalBungee(CPartical* pPartical, real fRestLength, real fSpringConstant);
		~CParticalBungee();

		virtual void UpdateForce( CPartical* pPartical, const real duration );

		
	protected:
		
	private:

		CPartical* m_pOther;
		real m_fRestLength;
		real m_fSpringConstant;
	};
	

	class CParticalBuoyancy : public CParticalForceGenerator
	{
	public:
		CParticalBuoyancy();
		CParticalBuoyancy(const real fMaxDepth, 
			const real fVolume,
			const real fWaterHeight,
			const real fLiquidDensity);
		~CParticalBuoyancy();

		virtual void UpdateForce( CPartical* pPartical, const real duration );

	protected:
		
	private:

		real m_fMaxDepth;
		real m_fVolume;
		real m_fWaterHeight;
		real m_fLiquidDensity;
	};

	class CParticalFakeSpring : public CParticalForceGenerator
	{
	public:
		CParticalFakeSpring();
		CParticalFakeSpring(CVector3* pAnchor, real fDamping, real fSpringConstant);
		~CParticalFakeSpring();

		virtual void UpdateForce( CPartical* pPartical, const real duration );

	protected:
		
	private:
		CVector3* m_pAnchor;
		real m_fDamping;
		real m_fSpringConstant;
	};
}
#endif // partical_force_generator_h__
