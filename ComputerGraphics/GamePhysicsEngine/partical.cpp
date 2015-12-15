#include "partical.h"

#include <assert.h>

using namespace game_physics_engine;


game_physics_engine::CPartical::CPartical()
{

}

game_physics_engine::CPartical::~CPartical()
{

}

void game_physics_engine::CPartical::Integrate(const real duration )
{
	if (m_fInverseMass <= 0)
	{
		return;
	}
	assert(duration > 0);
	if (duration <= 0)
	{
		return;
	}
	m_position.AddScaledVector(m_velocity, duration);
	CVector3 resultingAcc = m_acceleration;
	resultingAcc.AddScaledVector(m_forceAccum, m_fInverseMass);
	m_velocity.AddScaledVector(resultingAcc, duration);
	//notice here: there is a damping force effecting the acceleration calculating.
	m_velocity *= real_pow(m_fDamping, duration);
}

void game_physics_engine::CPartical::SetMass( const real mass )
{
	assert(mass != 0);
	if (0 == mass)
	{
		return;
	}
	m_fInverseMass = ((real)1.0) / mass;
}

real game_physics_engine::CPartical::GetMass() const
{
	if (0 == m_fInverseMass)
	{
		return REAL_MAX;
	}
	else
	{
		return ((real)1.0) / m_fInverseMass;
	}
}

void game_physics_engine::CPartical::SetInverseMass( const real inverseMass )
{
	assert(inverseMass >= 0.0f);
	if (inverseMass < 0.0f)
	{
		return;
	}
	m_fInverseMass = inverseMass;
}

real game_physics_engine::CPartical::GetInverseMass() const
{
	return m_fInverseMass;
}

bool game_physics_engine::CPartical::HasFiniteMass() const
{
	return m_fInverseMass >= 0.0f;
}

void game_physics_engine::CPartical::SetDamping( const real damping )
{
	m_fDamping = damping;
}

real game_physics_engine::CPartical::GetDamping() const
{
	return m_fDamping;
}

void game_physics_engine::CPartical::SetPosition( const CVector3& position )
{
	m_position = position;
}

void game_physics_engine::CPartical::GetPosition( CVector3* pPosition ) const
{
	*pPosition = m_position;
}

void game_physics_engine::CPartical::SetVelocity( const CVector3& velocity )
{
	m_velocity = velocity;
}

void game_physics_engine::CPartical::GetVelocity( CVector3* pVelocity ) const
{
	*pVelocity = m_velocity;
}

void game_physics_engine::CPartical::SetAcceleration( const CVector3& acceleration )
{
	m_acceleration = acceleration;
}

void game_physics_engine::CPartical::GetAcceleration( CVector3* pAcceleration ) const
{
	*pAcceleration = m_acceleration;
}

void game_physics_engine::CPartical::ClearAccumulator()
{
	m_forceAccum.Clear();
}

void game_physics_engine::CPartical::AddForce( const CVector3& force )
{
	m_forceAccum += force;
}

game_physics_engine::CVector3 game_physics_engine::CPartical::GetAcceleration() const
{
	return m_acceleration;
}

void game_physics_engine::CPartical::SetAcceleration( const real x, const real y, const real z )
{
	m_acceleration.m_fX = x;
	m_acceleration.m_fY = y;
	m_acceleration.m_fZ = z;
}

game_physics_engine::CVector3 game_physics_engine::CPartical::GetVelocity() const
{
	return m_velocity;
}

void game_physics_engine::CPartical::SetVelocity( const real x, const real y, const real z )
{
	m_velocity.m_fX = x;
	m_velocity.m_fY = y;
	m_velocity.m_fZ = z;
}

game_physics_engine::CVector3 game_physics_engine::CPartical::GetPosition() const
{
	return m_position;
}

void game_physics_engine::CPartical::SetPosition( const real x, const real y, const real z )
{
	m_position.m_fX = x;
	m_position.m_fY = y;
	m_position.m_fZ = z;
}
