#include "tpch.hpp"

#include "Engine.hpp"


void Engine::loadLevel()
{
	m_isPlaying = false;

	// deallocate previous memory
	for (int i = 0; i < m_levelManager.getLevelSize().y; ++i)
	{
		delete[] m_arrLevel[i];
	}
	delete[] m_arrLevel;

	// load the next level
	m_arrLevel = m_levelManager.nextLevel(m_vertArrLevel);

	// setup sound emitters
	populateEmitters(m_fireEmitters, m_arrLevel);

	m_timeRemaining = m_levelManager.getTimeLimit();

	m_thomas.spawn(m_levelManager.getStartPosition(), GRAVITY);
	m_bob.spawn(m_levelManager.getStartPosition(), GRAVITY);

	m_newLevelRequired = false;
}
