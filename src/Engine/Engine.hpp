#pragma once

#include "Characters/Bob.hpp"
#include "Characters/Thomas.hpp"


class Engine
{
private:
	const int cm_tileSize{ 50 };
	const int cm_vertsInQuad{ 4 };

	const int cm_gravity{ 300 };

	// Our protagonists
	Thomas m_thomas;
	Bob m_bob;

	sf::RenderWindow m_window;

	// The main views
	sf::View m_mainView;	// for full screen game
	sf::View m_leftView;	// split screen
	sf::View m_rightView;

	// background views
	sf::View m_bgMainView;
	sf::View m_bgLeftView;
	sf::View m_bgRightView;

	sf::View m_hudView;

	// background texture and sprite
	sf::Texture m_bgTexture;
	sf::Sprite m_bgSprite;

	bool m_isPlaying{ false };

	// which player is in the current focus
	bool m_player1Focus{ true };

	// start the game in full screen mode
	bool m_splitScreen{ false };

	// total game time, and time left in level (in seconds)
	sf::Time m_gameTimeTotal;
	float m_timeRemaining{ 10 };

	// time for new (or first) level?
	bool m_newLevelRequired{ true };

public:
	Engine();

	void run();

private:
	/**
	 * Game loop private methods
	 */
	void input();
	void update(float dt);
	void render();
};
