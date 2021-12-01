#include "tpch.hpp"

#include "Engine.hpp"


void Engine::render()
{
	// clear window, set color to white
	m_window.clear(Color::White);

	m_rippleShader.setUniform("uTime", m_gameTimeTotal.asSeconds());

	if (m_splitScreen)
	{
		// draw Thomas' view
		m_window.setView(m_bgLeftView);		// draw background
		m_window.draw(m_bgSprite, &m_rippleShader);
		m_window.setView(m_leftView);		// switch to main view
		
		// draw the level
		m_window.draw(m_vertArrLevel, &m_textureTiles);

		// both players are visible in both views
		m_window.draw(m_thomas.getSprite());
		m_window.draw(m_bob.getSprite());

		if (m_particleSystem.isRunning())
		{
			m_window.draw(m_particleSystem);
		}

		// draw Bob's view
		m_window.setView(m_bgRightView);			// draw background
		m_window.draw(m_bgSprite, &m_rippleShader);
		m_window.setView(m_rightView);				// switch to main view

		// draw the level
		m_window.draw(m_vertArrLevel, &m_textureTiles);

		m_window.draw(m_bob.getSprite());		// draw Bob above Thomas in Bob's view
		m_window.draw(m_thomas.getSprite());

		if (m_particleSystem.isRunning())
		{
			m_window.draw(m_particleSystem);
		}
	}
	else
	{
		// draw background
		m_window.setView(m_bgMainView);
		m_window.draw(m_bgSprite, &m_rippleShader);

		// draw main view
		m_window.setView(m_mainView);

		// draw the level
		m_window.draw(m_vertArrLevel, &m_textureTiles);

		m_window.draw(m_thomas.getSprite());
		m_window.draw(m_bob.getSprite());

		if (m_particleSystem.isRunning())
		{
			m_window.draw(m_particleSystem);
		}
	}

	 // draw HUD
	m_window.setView(m_hudView);
	m_window.draw(m_hud.getTime());
	m_window.draw(m_hud.getLevel());
	if (!m_isPlaying)
	{
		m_window.draw(m_hud.getMessage());
	}

	m_window.display();
}
