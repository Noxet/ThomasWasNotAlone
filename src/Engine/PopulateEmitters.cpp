#include "tpch.hpp"

#include "Engine.hpp"


void Engine::populateEmitters(std::vector<Vector2f>& soundEmitters, int** arrayLevel)
{
	// make sure the vector is empty
	soundEmitters.clear();

	// keep track of previous emitter so we don't create too many
	FloatRect prevEmitter{};

	for (int x = 0; x < m_levelManager.getLevelSize().x; ++x)
	{
		for (int y = 0; y < m_levelManager.getLevelSize().y; ++y)
		{
			if (arrayLevel[y][x] == 2)
			{
				// Fire detected

				// skip tiles too close to the previous emitter
				if (!FloatRect(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE).intersects(prevEmitter))
				{
					soundEmitters.emplace_back(Vector2f(x * TILE_SIZE, y * TILE_SIZE));

					// Make a large block so the emitters are not close
					prevEmitter.left = x * TILE_SIZE;
					prevEmitter.top = y * TILE_SIZE;
					prevEmitter.width = 6 * TILE_SIZE;
					prevEmitter.height = 6 * TILE_SIZE;
				}
			}
		}
	}
}
