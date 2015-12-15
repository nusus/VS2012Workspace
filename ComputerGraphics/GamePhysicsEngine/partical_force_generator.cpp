#include "partical_force_generator.h"

#include <algorithm>
#include <assert.h>


game_physics_engine::CParticalForceRegistry::CParticalForceRegistry()
{

}

game_physics_engine::CParticalForceRegistry::~CParticalForceRegistry()
{

}

void game_physics_engine::CParticalForceRegistry::Add( CPartical* pPartical, CParticalForceGenerator* pFg )
{
	SParticalForceRegistration registration;
	registration.pPartical = pPartical;
	registration.pParticalForceGenerator = pFg;
	m_registrations.push_back(registration);
}

void game_physics_engine::CParticalForceRegistry::Remove( CPartical* pPartical, CParticalForceGenerator* pFg )
{
	m_registrations.erase(
		std::remove(
		m_registrations.begin(), 
		m_registrations.end(), 
		SParticalForceRegistration(pPartical, pFg)
		),
		m_registrations.end()
		);
}

void game_physics_engine::CParticalForceRegistry::Clear()
{
	m_registrations.clear();
}

void game_physics_engine::CParticalForceRegistry::UpdateForce( const real fDuration )
{
	for (std::vector<SParticalForceRegistration>::iterator itr = m_registrations.begin();
		itr != m_registrations.end();
		++itr)
	{
		(*itr).pParticalForceGenerator->UpdateForce((*itr).pPartical, fDuration);
	}
}

game_physics_engine::CParticalGravity::CParticalGravity()
{

}

void game_physics_engine::CParticalGravity::UpdateForce( CPartical* pPartical, const real duration )
{
	if (!pPartical->HasFiniteMass())
	{
		return;
	}
	pPartical->AddForce(this->m_gravity * pPartical->GetMass());
}

game_physics_engine::CParticalForceGenerator::CParticalForceGenerator()
{

}

game_physics_engine::CParticalForceGenerator::~CParticalForceGenerator()
{

}

game_physics_engine::CParticalDrag::CParticalDrag()
{

}

game_physics_engine::CParticalDrag::CParticalDrag( real k1, real k2 ):
	m_k1(k1),
	m_k2(k2)
{

}

game_physics_engine::CParticalDrag::~CParticalDrag()
{

}

void game_physics_engine::CParticalDrag::UpdateForce( CPartical* pPartical, const real duration )
{
	CVector3 force = pPartical->GetVelocity();
	real dragCoeff = force.Magnitude();
	dragCoeff = m_k1 * dragCoeff + m_k2 * dragCoeff * dragCoeff;
	force.Normalize();
	force *= -dragCoeff;
	pPartical->AddForce(force);
}

void game_physics_engine::CParticalSpring::UpdateForce( CPartical* pPartical, real fDuration )
{
	CVector3 force;
	force = pPartical->GetPosition();
	force -= m_pOther->GetPosition();

	real fMagnitude = force.Magnitude();
	//that is what written on the book, but I think it is wrong.
	//fMagnitude = real_abs(fMagnitude - m_fRestLength);
	fMagnitude = m_fRestLength - fMagnitude;
	fMagnitude *= m_fSpringConstant;

	force.Normalize();
	force *= -fMagnitude;
	pPartical->AddForce(force);
}

game_physics_engine::CParticalAnchoredSpring::CParticalAnchoredSpring()
{

}

game_physics_engine::CParticalAnchoredSpring::~CParticalAnchoredSpring()
{

}

void game_physics_engine::CParticalAnchoredSpring::UpdateForce( CPartical* pOther, real fDuration )
{
	CVector3 force;
	force = pOther->GetPosition();
	force -= *m_pAnchor;

	real fMagnitude = force.Magnitude();
	//that is what written on the book, but I think it is wrong.
	//fMagnitude = real_abs(fMagnitude - m_fRestLength);
	fMagnitude = m_fRestLength - fMagnitude;
	fMagnitude *= m_fSpringConstant;

	force.Normalize();
	force *= -fMagnitude;
	pOther->AddForce(force);
}

game_physics_engine::CParticalAnchoredSpring::CParticalAnchoredSpring( CVector3* pAnchor, real fSpringConstant, real fRestLength ):
	m_pAnchor(pAnchor),
	m_fSpringConstant(fSpringConstant),
	m_fRestLength(fRestLength)
{

}

game_physics_engine::CParticalBungee::CParticalBungee()
{

}

game_physics_engine::CParticalBungee::~CParticalBungee()
{

}

game_physics_engine::CParticalBungee::CParticalBungee( CPartical* pPartical, real fRestLength, real fSpringConstant ):
	m_pOther(pPartical),
	m_fRestLength(m_fRestLength),
	m_fSpringConstant(m_fSpringConstant)
{

}

void game_physics_engine::CParticalBungee::UpdateForce( CPartical* pPartical, const real duration )
{
	assert(pPartical != nullptr);
	if (pPartical == NULL)
	{
		return;
	}

	CVector3 force = pPartical->GetPosition();
	force -= m_pOther->GetPosition();
	real magnitude = force.Magnitude();
	if (magnitude <= m_fRestLength)
	{
		return;
	}

	magnitude -= m_fRestLength;
	magnitude *= m_fSpringConstant;
	force.Normalize();
	force *= -magnitude;
	pPartical->AddForce(force);
}

game_physics_engine::CParticalBuoyancy::CParticalBuoyancy()
{

}

game_physics_engine::CParticalBuoyancy::~CParticalBuoyancy()
{

}

game_physics_engine::CParticalBuoyancy::CParticalBuoyancy( const real fMaxDepth, const real fVolume, const real fWaterHeight, const real fLiquidDensity ) :
	m_fMaxDepth(fMaxDepth),
	m_fLiquidDensity(fLiquidDensity),
	m_fVolume(fVolume),
	m_fWaterHeight(fWaterHeight)
{

}

void game_physics_engine::CParticalBuoyancy::UpdateForce( CPartical* pPartical, const real duration )
{
	real depth = pPartical->GetPosition().m_fY;
	if (depth >= m_fWaterHeight + m_fMaxDepth / 2)
	{
		return;
	}
	CVector3 force(0, 0, 0);

	if (depth <= m_fWaterHeight - m_fMaxDepth /2)
	{
		force.m_fY = m_fLiquidDensity * m_fVolume;
		pPartical->AddForce(force);
		return;
	}

	force.m_fY = m_fLiquidDensity * m_fVolume * (m_fMaxDepth / 2 - (depth - m_fWaterHeight)) / m_fMaxDepth;
	pPartical->AddForce(force);

}

game_physics_engine::CParticalFakeSpring::CParticalFakeSpring()
{

}

game_physics_engine::CParticalFakeSpring::~CParticalFakeSpring()
{

}

game_physics_engine::CParticalFakeSpring::CParticalFakeSpring( CVector3* pAnchor, real fDamping, real fSpringConstant )
	:m_pAnchor(pAnchor),
	m_fDamping(fDamping),
	m_fSpringConstant(fSpringConstant)
{

}

void game_physics_engine::CParticalFakeSpring::UpdateForce( CPartical* pPartical, const real duration )
{
	if (!pPartical->HasFiniteMass())
	{
		return;
	}

	CVector3 position = pPartical->GetPosition();
	position -= *m_pAnchor;

	real gamma = 0.5f * (real_sqrt(4 * m_fSpringConstant - m_fDamping * m_fDamping));
	CVector3 c = position * (m_fDamping / (2 * gamma)) + pPartical->GetVelocity() * (1.0f / gamma);

	CVector3 target = position * real_cos(gamma * duration) + c * real_sin(gamma * duration);
	target *= real_exp(-0.5f * duration * m_fDamping);

	CVector3 accel = (target - position) * (1.0f / duration * duration) - pPartical->GetVelocity() * duration;
	pPartical->AddForce(accel * pPartical->GetMass());
}
