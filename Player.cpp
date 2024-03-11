#include "Player.h"

Player::Player() {
	points = 0;
	palette = 15;
	paletteVector = 0;
	win = true;
}


bool Player::Winning() {   // sprawdzenie warunku zwyciestwa

	if (points == 10) {
		return true;
	}
	return false;
}

int Player::CheckPosition(float ball) { //sprawdzamy czy pilka dotyka paletki

	if( (palette - 2 <= (int)ball) && (palette + 2 >= (int)ball) ){ return 0; }
	return 1;
}
