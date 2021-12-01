#pragma once

#include "Particle.hpp"


class ParticleSystem : public sf::Drawable
{
private:
	std::vector<Particle> m_particles;
	sf::VertexArray m_vertices;
	float m_duration{};
	bool m_isRunning{ false };

public:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	void init(int count);
	void emitParticles(Vector2f position);
	void update(float dt);
	bool isRunning() const;
};
