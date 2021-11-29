#pragma once


class LevelManager
{
private:
	Vector2i m_levelSize;
	Vector2f m_startPosition;

	float m_timeModifier{ 1 };
	float m_baseTimeLimit{};

	int m_currentLevel{ 0 };
	const int NUM_LEVELS{ 4 };

public:
	const int TILE_SIZE{ 50 };
	const int VERTS_IN_QUAD{ 4 };

	float getTimeLimit() const { return m_baseTimeLimit * m_timeModifier; }

	Vector2f getStartPosition() const { return m_startPosition; }

	int** nextLevel(sf::VertexArray& rVaLevel);

	Vector2i getLevelSize() const { return m_levelSize; }
	int getCurrentLevel() const { return m_currentLevel; }
};