#include "tpch.hpp"

#include "Engine.hpp"

#include <iostream>


Engine::Engine()
{
	Vector2u resolution;
	resolution.x = sf::VideoMode::getDesktopMode().width;
	resolution.y = sf::VideoMode::getDesktopMode().height;

	m_window.create(sf::VideoMode(resolution.x, resolution.y), "Thomas was not Late", sf::Style::Fullscreen);

	// init full screen view
	m_mainView.setSize(Vector2f(resolution));
	m_hudView.reset(
		FloatRect(0, 0, static_cast<float>(resolution.x), static_cast<float>(resolution.y))
	);

	// init split screen views, leave a small gap for a "border" to clearly split the views
	m_leftView.setViewport(FloatRect(0.001f, 0.001f, 0.498f, 0.998f));
	m_rightView.setViewport(FloatRect(0.5f, 0.001f, 0.499f, 0.998f));
	m_bgLeftView.setViewport(FloatRect(0.001f, 0.001f, 0.498f, 0.998f));
	m_bgRightView.setViewport(FloatRect(0.5f, 0.001f, 0.499f, 0.998f));

	// check if we can use shaders on our GPU
	if (!sf::Shader::isAvailable())
	{
		// TODO: add real logging
		std::cerr << "Shaders are not available on the current GPU" << std::endl;
		m_window.close();
	}

	m_bgTexture = TextureHolder::getTexture("../assets/gfx/background.png");
	m_bgSprite.setTexture(m_bgTexture);

	m_textureTiles = TextureHolder::getTexture("../assets/gfx/tiles_sheet.png");
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
