#pragma once
#include "Ball.h"
#include "Player.h"

using namespace std;

class Menedzer
{
	int players;
	void Cursor(bool);
public:

	int Start();
	void saveGame(Ball&, Player&, Player&);
	void loadGame(Ball&, Player&, Player&);
};

