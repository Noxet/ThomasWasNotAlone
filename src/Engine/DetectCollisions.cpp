#include "tpch.hpp"

#include "Engine.hpp"


bool Engine::detectCollisions(Player& character)
{
	bool reachedGoal = false;

	FloatRect detectionZone = character.getPosition();

	// test each block
	FloatRect block;
	block.width = TILE_SIZE;
	block.height = TILE_SIZE;

	/*
	 * build a zone around character to detect collisions,
	 * to avoid checking collision on a block hundreds of pixels away
	 */
	int startX = (int)(detectionZone.left / TILE_SIZE) - 1;
	int endX = (int)(detectionZone.left / TILE_SIZE) + 2;
	int startY = (int)(detectionZone.top / TILE_SIZE) - 1;
	int endY = (int)(detectionZone.top / TILE_SIZE) + 3;

	// cap values
	if (startX < 0) startX = 0;
	if (endX >= m_levelManager.getLevelSize().x) endX = m_levelManager.getLevelSize().x;
	if (startY < 0) startY = 0;
	if (endY >= m_levelManager.getLevelSize().y) endY = m_levelManager.getLevelSize().y;

	// check if player is out of the map
	FloatRect level(0, 0, m_levelManager.getLevelSize().x * TILE_SIZE, m_levelManager.getLevelSize().y * TILE_SIZE);

	if (!character.getPosition().intersects(level))
	{
		// re-spawn character
		character.spawn(m_levelManager.getStartPosition(), GRAVITY);
		return false;
	}

	// check against all local blocks
	for (int x = startX; x < endX; ++x)
	{
		for (int y = startY; y < endY; ++y)
		{
			block.left = x * TILE_SIZE;
			block.top = y * TILE_SIZE;

			// hit fire or water?
			if (m_arrLevel[y][x] == 2 || m_arrLevel[y][x] == 3)
			{
				if (character.getHead().intersects(block))
				{
					// re-spawn
					character.spawn(m_levelManager.getStartPosition(), GRAVITY);
					if (m_arrLevel[y][x] == 2)
					{
						// hit fire, play sound
					}
					else
					{
						// hit water, play sound
					}
				}
			}

			// hit regular block?
			if (m_arrLevel[y][x] == 1)
			{
				if (character.getRight().intersects(block))
				{
					character.stopRight(block.left);
				}
				else if (character.getLeft().intersects(block))
				{
					character.stopLeft(block.left);
				}

				if (character.getFeet().intersects(block))
				{
					character.stopFalling(block.top);
				}
				else if (character.getHead().intersects(block))
				{
					character.stopJump();
				}
			}

			if (m_arrLevel[y][x] == 4)
			{
				reachedGoal = true;
			}
		}
	}

	return reachedGoal;
}
