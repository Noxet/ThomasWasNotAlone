#include "tpch.hpp"

#include "Engine.hpp"


void Engine::update(float dt)
{
	if (m_newLevelRequired)
	{
		loadLevel();
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