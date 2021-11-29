#include "tpch.hpp"

#include "Player.hpp"


void Player::update(float dt)
{
	if (m_rightPressed)
	{
		m_position.x += m_speed * dt;
	}
	else if (m_leftPressed)
	{
		m_position.x -= m_speed * dt;
	}

	if (m_isJumping)
	{
		m_timeInJump += dt;

		if (m_timeInJump < m_jumpDuration)
		{
			m_position.y -= 2 * m_gravity * dt;
		}
		else
		{
			m_isJumping = false;
			m_isFalling = true;
		}
	}
	else if (m_isFalling)
	{
		m_position.y += m_gravity * dt;
	}

	// update all collision bounds
	const FloatRect r = getPosition();

	// feet is 3px in on both sides, and 1px in height
	m_feet.left = r.left + 3;
	m_feet.top = r.top + r.height - 1;
	m_feet.width = r.width - 6;
	m_feet.height = 1;

	m_head.left = r.left;
	m_head.top = r.top + (r.height * 0.3f);
	m_head.width = r.width;
	m_head.height = 1;

	m_right.left = r.left + r.width - 2;
	m_right.top = r.top + (r.height * 0.35f);
	m_right.width = 1;
	m_right.height = r.height * 0.3f;

	m_left.left = r.left;
	m_left.top = r.top + (r.height * 0.35f);
	m_left.width = 1;
	m_left.height = r.height * 0.3f;

	m_sprite.setPosition(m_position);
}


void Player::spawn(Vector2f startPosition, float gravity)
{
	m_position = startPosition;
	m_gravity = gravity;
	m_sprite.setPosition(m_position);
}


FloatRect Player::getPosition() const
{
	return m_sprite.getGlobalBounds();
}


Vector2f Player::getCenter() const
{
	return Vector2f(
		m_position.x + m_sprite.getGlobalBounds().width / 2,
		m_position.y + m_sprite.getGlobalBounds().height / 2
	);
}


void Player::stopFalling(float position)
{
	m_position.y = position - getPosition().height;
	m_sprite.setPosition(m_position);
	m_isFalling = false;
}


void Player::stopRight(float position)
{
	m_position.x = position - m_sprite.getGlobalBounds().width;
	m_sprite.setPosition(m_position);
}


void Player::stopLeft(float position)
{
	m_position.x = position + m_sprite.getGlobalBounds().width;
	m_sprite.setPosition(m_position);
}


void Player::stopJump()
{
	m_isJumping = false;
	m_isFalling = true;
}
