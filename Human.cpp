#include "Human.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>


Human::Human() : Player() {}

void Human::move(Human& human, bool& exit, bool& endgame) {

	char qwerty_key = _getch();

		while(endgame) {
			if (_kbhit) qwerty_key = _getch();
			switch (qwerty_key) {
			case 'w':
				if (human.palette < 30) { human.paletteVector = -1; }

				if (human.palette + human.paletteVector < 29 && human.palette + human.paletteVector > 0) {
					human.palette += human.paletteVector;
				}
				Sleep(100);
				paletteVector = 0;
				break;

			case 's':
				if (human.palette < 30) { human.paletteVector = 1; }

				if (human.palette + human.paletteVector < 29 && human.palette + human.paletteVector > 0) {
					human.palette += human.paletteVector;
				}
				Sleep(100);
				paletteVector = 0;
				break;

			case 27:
				exit = false;
				endgame = false;
				break;

			default:
				break;
			}

		}
		    
}



