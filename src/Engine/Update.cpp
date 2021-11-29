#include "tpch.hpp"

#include "Engine.hpp"


void Engine::update(float dt)
{
	if (m_newLevelRequired)
	{
		m_thomas.spawn(Vector2f(0, 0), cm_gravity);
		m_bob.spawn(Vector2f(100, 0), cm_gravity);

		m_timeRemaining = 10;
		m_newLevelRequired = false;
	}

	if (m_isPlaying)
	{
		m_timeRemaining -= dt;

		m_thomas.update(dt);
		m_bob.update(dt);

		if (m_timeRemaining <= 0)
		{
			// OOT?
			m_newLevelRequired = true;
		}
	}

	if (m_splitScreen)
	{
		m_leftView.setCenter(m_thomas.getCenter());
		m_rightView.setCenter(m_bob.getCenter());
	}
	else
	{
		if (m_player1Focus)
		{
			m_mainView.setCenter(m_thomas.getCenter());
		}
		else
		{
			m_mainView.setCenter(m_bob.getCenter());
		}
	}
}