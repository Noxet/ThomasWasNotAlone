#include "tpch.hpp"

#include "LevelManager.hpp"

#include <iostream>
#include <fstream>


int** LevelManager::nextLevel(sf::VertexArray& rVaLevel)
{
	++m_currentLevel;

	m_levelSize.x = 0;
	m_levelSize.y = 0;

	if (m_currentLevel > NUM_LEVELS)
	{
		m_currentLevel = 1;
		m_timeModifier -= 0.1f;
	}

	std::string levelToLoad;
	switch(m_currentLevel)
	{
	case 1:
		levelToLoad = "../assets/levels/level1.txt";
		m_startPosition.x = 100;
		m_startPosition.y = 100;
		m_baseTimeLimit = 30.f;
		break;

	case 2:
		levelToLoad = "../assets/levels/level2.txt";
		m_startPosition.x = 100;
		m_startPosition.y = 3600;
		m_baseTimeLimit = 100.f;
		break;

	case 3:
		levelToLoad = "../assets/levels/level3.txt";
		m_startPosition.x = 1250;
		m_startPosition.y = 0;
		m_baseTimeLimit = 30.f;
		break;

	case 4:
		levelToLoad = "../assets/levels/level4.txt";
		m_startPosition.x = 50;
		m_startPosition.y = 200;
		m_baseTimeLimit = 50.f;
		break;

	default:
		// TODO: properly log this
		std::cerr << "[Error] - Level " << m_currentLevel << " does not exist" << std::endl;
	}

	// load the level
	std::ifstream inputFile(levelToLoad);
	std::string s;

	// count the size of the level
	while (std::getline(inputFile, s))
	{
		++m_levelSize.y;
	}

	m_levelSize.x = s.length();

	// go to start of file
	inputFile.clear();
	inputFile.seekg(0, std::ios::beg);

	// allocate the level array
	int** arrLevel = new int* [m_levelSize.y];
	for (int i = 0; i < m_levelSize.y; ++i)
	{
		arrLevel[i] = new int[m_levelSize.x];
	}

	std::string row;
	int y = 0;
	while (inputFile >> row)
	{
		for (int x = 0; x < row.length(); ++x)
		{
			const char val = row[x];
			arrLevel[y][x] = atoi(&val);
		}

		++y;
	}

	inputFile.close();

	rVaLevel.setPrimitiveType(sf::Quads);
	rVaLevel.resize(m_levelSize.x * m_levelSize.y * VERTS_IN_QUAD);

	int currentVertex = 0;

	for (int x = 0; x < m_levelSize.x; ++x)
	{
		for (int y = 0; y < m_levelSize.y; ++y)
		{
			// position each vertex in the quad
			rVaLevel[currentVertex + 0].position = Vector2f(x * TILE_SIZE, y * TILE_SIZE);
			rVaLevel[currentVertex + 1].position = Vector2f(TILE_SIZE + (x * TILE_SIZE), y * TILE_SIZE);
			rVaLevel[currentVertex + 2].position = Vector2f(TILE_SIZE + (x * TILE_SIZE), TILE_SIZE + (y * TILE_SIZE));
			rVaLevel[currentVertex + 3].position = Vector2f(x * TILE_SIZE, TILE_SIZE + (y * TILE_SIZE));

			// which tile from the sprite sheet we should use
			const int verticalOffset = arrLevel[y][x] * TILE_SIZE;

			rVaLevel[currentVertex + 0].texCoords = Vector2f(0, 0 + verticalOffset);
			rVaLevel[currentVertex + 1].texCoords = Vector2f(TILE_SIZE, 0 + verticalOffset);
			rVaLevel[currentVertex + 2].texCoords = Vector2f(TILE_SIZE, TILE_SIZE + verticalOffset);
			rVaLevel[currentVertex + 3].texCoords = Vector2f(0, TILE_SIZE + verticalOffset);

			currentVertex += VERTS_IN_QUAD;
		}
	}

	return arrLevel;
}
