#pragma once
#include <iostream>

using namespace std;

class Player{
public:
	bool win;
	int points;
	int palette;
	int paletteVector;
	Player();
	bool Winning();
	int CheckPosition(float);
};

