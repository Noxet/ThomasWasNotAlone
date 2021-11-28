#include "tpch.hpp"

#include "Engine.hpp"


Engine::Engine()
{
	Vector2u resolution;
	resolution.x = sf::VideoMode::getDesktopMode().width;
	resolution.y = sf::VideoMode::getDesktopMode().height;

	m_window.create(sf::VideoMode(resolution.x, resolution.y), "Thomas was not Late", sf::Style::Fullscreen);

	// init full screen view
	m_mainView.setSize(Vector2f(resolution));
	m_hudView.reset(FloatRect(0, 0, resolution.x, resolution.y));

	// init split screen views, leave a small gap for a "border" to clearly split the views
	m_leftView.setViewport(FloatRect(0.001f, 0.001f, 0.498f, 0.998f));
	m_rightView.setViewport(FloatRect(0.5f, 0.001f, 0.499f, 0.998f));
	m_bgLeftView.setViewport(FloatRect(0.001f, 0.001f, 0.498f, 0.998f));
	m_bgRightView.setViewport(FloatRect(0.5f, 0.001f, 0.499f, 0.998f));

	m_bgTexture = TextureHolder::getTexture("../assets/gfx/background.png");
	m_bgSprite.setTexture(m_bgTexture);
}


void Engine::run()
{
	sf::Clock clock;
	sf::Time dt{};

	while (m_window.isOpen())
	{
		dt = clock.restart();
		m_gameTimeTotal += dt;

		input();
		update(dt.asSeconds());
		render();
	}
}
