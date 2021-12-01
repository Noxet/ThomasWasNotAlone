#include "tpch.hpp"

#include "Particle.hpp"


Particle::Particle(Vector2f direction)
{
	m_velocity = direction;
}


void Particle::update(float dt)
{
	m_position += m_velocity * dt;
}


void Particle::setPosition(Vector2f position)
{
	m_position = position;
}
