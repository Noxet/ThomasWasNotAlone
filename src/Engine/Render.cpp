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

		// draw Bob's view
		m_window.setView(m_bgRightView);	// draw background
		m_window.draw(m_bgSprite);
		m_window.setView(m_rightView);		// switch to main view
	}
	else
	{
		// draw background
		m_window.setView(m_bgMainView);
		m_window.draw(m_bgSprite);

		// draw main view
		m_window.setView(m_mainView);
	}

	 // draw HUD
	m_window.setView(m_hudView);

	m_window.display();
}