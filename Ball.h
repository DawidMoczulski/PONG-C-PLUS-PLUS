#pragma once
#include <iostream>
#include "Player.h"

using namespace std;


class Ball
{
public:
	Ball();
	float ballVector[2];
	float position[2];
	void move(Player&, Player&, bool&);
	void restart(int);
	void optimize(Player&);	
};

