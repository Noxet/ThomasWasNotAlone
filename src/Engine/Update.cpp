#include "tpch.hpp"

#include "Engine.hpp"


void Engine::update(float dt)
{
	if (m_isPlaying)
	{
		m_timeRemaining -= dt;

		if (m_timeRemaining <= 0)
		{
			// OOT?
			m_newLevelRequired = true;
		}
	}
}