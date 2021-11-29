#include "tpch.hpp"

#include "Bob.hpp"


Bob::Bob()
{
	m_sprite = sf::Sprite(TextureHolder::getTexture("../assets/gfx/bob.png"));

	m_jumpDuration = 0.25f;
}


bool Bob::handleInput()
{
	m_justJumped = false;

	if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		// only jump if we are not already jumping or falling
		if (!m_isJumping && !m_isFalling)
		{
			m_isJumping = true;
			m_justJumped = true;
			m_timeInJump = 0;
		}
	}
	else
	{
		m_isJumping = false;
		m_isFalling = true;
	}

	m_leftPressed = Keyboard::isKeyPressed(Keyboard::Left) ? true : false;
	m_rightPressed = Keyboard::isKeyPressed(Keyboard::Right) ? true : false;

	return m_justJumped;
}
