#include "tpch.hpp"

#include "Thomas.hpp"


Thomas::Thomas()
{
	m_sprite = sf::Sprite(TextureHolder::getTexture("../assets/gfx/thomas.png"));

	m_jumpDuration = 0.45f;
}


bool Thomas::handleInput()
{
	m_justJumped = false;

	if (Keyboard::isKeyPressed(Keyboard::W))
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

	m_leftPressed = Keyboard::isKeyPressed(Keyboard::A) ? true : false;
	m_rightPressed = Keyboard::isKeyPressed(Keyboard::D) ? true : false;

	return m_justJumped;
}
