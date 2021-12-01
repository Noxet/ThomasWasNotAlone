#pragma once


class HUD
{
private:
	sf::Font m_font;
	sf::Text m_startText;
	sf::Text m_timeText;
	sf::Text m_levelText;

public:
	HUD();

	sf::Text getMessage() const { return m_startText; }
	sf::Text getLevel() const { return m_levelText; }
	sf::Text getTime() const { return m_timeText; }

	void setLevel(const sf::String& text) { m_levelText.setString(text); }
	void setTime(const sf::String& text) { m_timeText.setString(text); }
};