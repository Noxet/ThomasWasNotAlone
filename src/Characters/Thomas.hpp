#pragma once

#include "Player.hpp"


class Thomas : public Player
{
public:
	Thomas();

	virtual bool handleInput() override;
};
