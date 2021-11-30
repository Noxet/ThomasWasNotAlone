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

		if (detectCollisions(m_thomas) && detectCollisions(m_bob))
		{
			m_newLevelRequired = true;

			// play goal sound
			m_soundManager.playReachGoal();
		}
		else
		{
			// detectCollisions was only run for thomas in the if statement
			detectCollisions(m_bob);
		}

		// check collision between the players
		if (m_bob.getFeet().intersects(m_thomas.getHead()))
		{
			m_bob.stopFalling(m_thomas.getHead().top);
		}
		else if (m_thomas.getFeet().intersects(m_bob.getHead()))
		{
			m_thomas.stopFalling(m_bob.getHead().top);
		}

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