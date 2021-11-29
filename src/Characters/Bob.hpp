#pragma once

#include "Player.hpp"


class Bob : public Player
{
public:
	Bob();

	virtual bool handleInput() override;
};

