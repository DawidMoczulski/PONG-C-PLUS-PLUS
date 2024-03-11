#pragma once
#include <iostream>
#include "Player.h"

using namespace std;


class Human : public Player
{
public:
	Human();
	void move(Human&, bool&, bool&);
};

