#include "tpch.hpp"

#include "ParticleSystem.hpp"


void ParticleSystem::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_vertices, states);
}


void ParticleSystem::init(int count)
{
	m_vertices.setPrimitiveType(sf::Points);
	m_vertices.resize(count);

	for (int i = 0; i < count; ++i)
	{
		const float angle = (rand() % 360) * 3.14f / 180.f;
		const float speed = (rand() % 600) + 600.f;

		const Vector2f direction(cos(angle) * speed, sin(angle) * speed);
		m_particles.emplace_back(Particle(direction));
	}
}


void ParticleSystem::emitParticles(Vector2f position)
{
	// emit the particles for a duration of time
	m_isRunning = true;
	m_duration = 2;

	int currentVertex = 0;
	for (auto& i : m_particles)
	{
		m_vertices[currentVertex++].color = Color::Yellow;
		// all particles start at the same position but have different velocities
		i.setPosition(position);
	}
}


void ParticleSystem::update(float dt)
{
	m_duration -= dt;

	// update every single particle
	int currentVertex = 0;
	for (auto& i : m_particles)
	{
		i.update(dt);

		// update the vertex array
		m_vertices[currentVertex++].position = i.getPosition();
	}

	if (m_duration < 0)
	{
		m_isRunning = false;
	}
}


bool ParticleSystem::isRunning() const
{
	return m_isRunning;
}
