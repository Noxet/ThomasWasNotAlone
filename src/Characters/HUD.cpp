#include "tpch.hpp"

#include "HUD.hpp"


HUD::HUD()
{
	const Vector2u resolution(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height);

	m_font.loadFromFile("../assets/fonts/Roboto-Light.ttf");

	// text in pause mode
	m_startText.setFont(m_font);
	m_startText.setCharacterSize(100);
	m_startText.setFillColor(Color::White);
	m_startText.setString("Press Enter when ready!");
	// center origin
	const FloatRect textRect = m_startText.getLocalBounds();
	m_startText.setOrigin(textRect.left + textRect.width / 2, textRect.top + textRect.height / 2);
	m_startText.setPosition(resolution.x / 2.f, resolution.y / 2.f);

	// time
	m_timeText.setFont(m_font);
	m_timeText.setCharacterSize(75);
	m_timeText.setFillColor(Color::White);
	m_timeText.setPosition(resolution.x - 150, 0);
	m_timeText.setString("------");

	// which level
	m_levelText.setFont(m_font);
	m_levelText.setCharacterSize(75);
	m_levelText.setFillColor(Color::White);
	m_levelText.setPosition(25, 0);
	m_levelText.setString("1");
}
