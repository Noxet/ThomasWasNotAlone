#pragma once

#include "LevelManager.hpp"
#include "Characters/Bob.hpp"
#include "Characters/Thomas.hpp"


class Engine
{
private:
	const int TILE_SIZE{ 50 };
	const int VERTS_IN_QUAD{ 4 };

	const int GRAVITY{ 300 };

	// Our protagonists
	Thomas m_thomas;
	Bob m_bob;

	LevelManager m_levelManager;

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

	// vertex array and texture for the levels
	sf::VertexArray m_vertArrLevel;
	int** m_arrLevel = nullptr;
	sf::Texture m_textureTiles;

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

	void loadLevel();
};
