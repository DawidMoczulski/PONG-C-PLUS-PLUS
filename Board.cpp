#include "Board.h"
#include <iostream>

Board::Board() { // konstruktor tablicy

	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 90; j++) {
			pl[i][j] = empty;
		}
	}

	for (int k = 0; k < 30; k += 3) {
		pl[k][45] = center;
	}
}

void Board::SprawdzPilke(float x, float y) { //sprawdzenie czy pilka znajduje sie w poprawnym polozeniu
	if (x > 88.0) { x = 88.0; }
	if (y > 30.0) { x = 30.0; }
	if (x < 0) { x = 0.0; }
	if (y < 0) { x = 0.0; }

	pl[(int)y][(int)x] = ball;
}

void Board::Palette(int y1, int y2) {   //ustawiamy pozycje paletek

	for (int i = 0; i < 3; i++) {
		pl[i - 1 + y1][1] = palette;
		pl[i - 1 + y2][88] = palette;
	}
}

void Board::WczytajTablice() {

	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 90; j++) {
			pl[i][j] = empty;
		}
	}

	for (int k = 0; k < 30; k+=2) {
		pl[k][45] = center;
	}
}

void Board::drukujTablice() {
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 90; j++) {
			std::cout << (char)pl[i][j];
		}
		std::cout << "\n"; 
	}
	std::cout << std::endl;
}



