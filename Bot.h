#pragma once
#include "Player.h"
#include "Ball.h"

class Bot : public Player
{
public:
	Bot();
	void move(Ball&, Bot&, bool&);
};

