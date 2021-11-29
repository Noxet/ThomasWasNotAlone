#include "tpch.hpp"

#include "Engine.hpp"


void Engine::render()
{
	// clear window, set color to white
	m_window.clear(Color::White);

	if (m_splitScreen)
	{
		// draw Thomas' view
		m_window.setView(m_bgLeftView);		// draw background
		m_window.draw(m_bgSprite);
		m_window.setView(m_leftView);		// switch to main view
		
		// draw the level
		m_window.draw(m_vertArrLevel, &m_textureTiles);

		// both players are visible in both views
		m_window.draw(m_thomas.getSprite());
		m_window.draw(m_bob.getSprite());

		// draw Bob's view
		m_window.setView(m_bgRightView);			// draw background
		m_window.draw(m_bgSprite);
		m_window.setView(m_rightView);				// switch to main view

		// draw the level
		m_window.draw(m_vertArrLevel, &m_textureTiles);

		m_window.draw(m_bob.getSprite());		// draw Bob above Thomas in Bob's view
		m_window.draw(m_thomas.getSprite());
	}
	else
	{
		// draw background
		m_window.setView(m_bgMainView);
		m_window.draw(m_bgSprite);

		// draw the level
		m_window.draw(m_vertArrLevel, &m_textureTiles);

		// draw main view
		m_window.setView(m_mainView);
		m_window.draw(m_thomas.getSprite());
		m_window.draw(m_bob.getSprite());
	}

	 // draw HUD
	m_window.setView(m_hudView);

	m_window.display();
}
