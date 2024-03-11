#pragma once

enum znak {

	ball = 'O',
	palette = '|',
	center = '!',
	empty = ' ',
	points = '$'
};

class Board
{
	znak pl[30][90];
public:
	Board();
	void SprawdzPilke(float, float);
	void WczytajTablice();
	void Palette(int, int);
	void drukujTablice();
	
};

