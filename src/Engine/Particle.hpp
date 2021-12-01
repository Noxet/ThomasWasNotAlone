#pragma once


class Particle
{
private:
	Vector2f m_position;
	Vector2f m_velocity;

public:
	Particle(Vector2f direction);

	void update(float dt);
	void setPosition(Vector2f position);
	Vector2f getPosition() const { return m_position; }
};