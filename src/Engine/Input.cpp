#include "tpch.hpp"

#include "Engine.hpp"


void Engine::input()
{
	sf::Event event{};

	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Escape)
			{
				m_window.close();
			}
			else if (event.key.code == sf::Keyboard::Enter)
			{
				m_isPlaying = true;
			}
			else if (event.key.code == sf::Keyboard::Q)
			{
				// toggle player
				m_player1Focus = !m_player1Focus;
			}
			else if (event.key.code == sf::Keyboard::E)
			{
				// toggle split/full screen
				m_splitScreen = !m_splitScreen;
			}
		}
	}

	// handle player inputs
	if (m_thomas.handleInput())
	{
		// play jump sound
		m_soundManager.playJump();
	}


	if (m_bob.handleInput())
	{
		// play jump sound
		m_soundManager.playJump();
	}
}