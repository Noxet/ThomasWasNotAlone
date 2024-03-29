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

	// Are we going to play fire sound?
	for (auto it = m_fireEmitters.begin(); it != m_fireEmitters.end(); ++it)
	{
		// get the emitter position
		const float posX = it->x;
		const float posY = it->y;

		// check if the emitter is near the player, e.g., within 500px
		FloatRect localRect(posX - 250, posY - 250, 500, 500);
		if (m_thomas.getPosition().intersects(localRect))
		{
			// close enough
			m_soundManager.playFire(Vector2f(posX, posY), m_thomas.getCenter());
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

	// update HUD?
	m_timeSinceLastHUDUpdate += dt;

	if (m_timeSinceLastHUDUpdate > m_timePerHUDUpdate)
	{
		m_timeSinceLastHUDUpdate = 0;

		std::stringstream ssTime;
		ssTime << static_cast<int>(m_timeRemaining);
		m_hud.setTime(ssTime.str());

		std::stringstream ssLevel;
		ssLevel << m_levelManager.getCurrentLevel();
		m_hud.setLevel(ssLevel.str());
	}

	if (m_particleSystem.isRunning())
	{
		m_particleSystem.update(dt);
	}
}