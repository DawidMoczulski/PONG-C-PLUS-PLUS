#include "Bot.h"
#include "Ball.h"
#include <Windows.h>

Bot::Bot() : Player() {}


void Bot::move(Ball& ball, Bot& bot, bool& end) {
	while (end) {

		if (ball.position[1] < bot.palette){  //jesli pilka jest ponizej paletki AI
			bot.paletteVector = -1;           // AI porusza sie w dol
		}
		else if (ball.position[1] > bot.palette) {  //jesli pilka jest powyzej
			bot.paletteVector = 1;                  //porusza sie w gore
		}

		if (bot.palette + bot.paletteVector >= 2 && bot.palette + bot.paletteVector <= 28) {
			bot.palette += bot.paletteVector;
		}
		Sleep(100);
		bot.paletteVector = 0;
    }

}
