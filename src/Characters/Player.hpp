#pragma once


class Player
{
protected:
	sf::Sprite m_sprite;

	bool m_isJumping{};
	bool m_isFalling{};
	float m_jumpDuration{};
	// how long has the jump lasted so far?
	float m_timeInJump{};
	// did we just trigger a jump?
	bool m_justJumped{};

	// which direction are we heading?
	bool m_leftPressed{};
	bool m_rightPressed{};

private:
	// px/s the player will fall
	float m_gravity{};
	// px/s the player can move right/left
	float m_speed{ 400 };

	Vector2f m_position;

	// collision boundaries
	FloatRect m_feet;
	FloatRect m_head;
	FloatRect m_right;
	FloatRect m_left;

	sf::Texture m_texture;

public:
	void update(float dt);

	void spawn(Vector2f startPosition, float gravity);

	virtual bool handleInput() = 0;

	FloatRect getPosition() const;
	Vector2f getCenter() const;

	FloatRect getFeet() const { return m_feet; }
	FloatRect getHead() const { return m_head; }
	FloatRect getRight() const { return m_right; }
	FloatRect getLeft() const { return m_left; }

	sf::Sprite getSprite() const { return m_sprite; }

	void stopFalling(float position);
	void stopRight(float position);
	void stopLeft(float position);
	void stopJump();
};

