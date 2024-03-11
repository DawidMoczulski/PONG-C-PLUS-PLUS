#include "Ball.h"
#include <Windows.h>

Ball::Ball() {
	// poczatkowa pozycja pilki
	position[0] = 45.0;
	position[1] = 15.0;
	ballVector[0] = 1;
	ballVector[1] = 0.5;	
}

void Ball::optimize(Player& player) { //optymalizacja wektora pilki
	
	float y = (float)(rand() % 50)/100.0;
	float vector = player.paletteVector;
	if (vector < 0) { y = -y; }
	if (vector == 0) { y = y - 0.25; } // 0.25 * 2 = 0.5  polowa wartosci wektora

	if ( abs(ballVector[1] + y ) <= 0.5){
		ballVector[1] += y;
	}
	else if( ballVector[1] > 0) {
		ballVector[1] = 0.5;
	}
	else {
		ballVector[1] = -0.5;
	}

}

void Ball::restart(int k) {  //ponowne ustawienie pilki

	position[0] = 45.0;
	position[1] = 15.0;
	ballVector[1] = 0;
	if (k == 0) {
		ballVector[0] = 1;
	}
	else {
		ballVector[0] = -1;
	}

}


void Ball::move(Player& a, Player& b, bool& endgame) {

	while (endgame) {  // sprawdzamy czy pilka miesci sie na planszy i wykonujemy ruch
		if (position[0] + ballVector[0] < 88 && position[0] + ballVector[0] > 0
			&& position[1] + ballVector[1] < 30 && position[1] + ballVector[1] > 0) {

			for (int i = 0; i < 2; i++) {
				position[i] += ballVector[i];
			}

		}
		else if (position[1] + ballVector[1] >= 30 || position[1] + ballVector[1] <= 0) {

			ballVector[1] = -ballVector[1];
			for (int i = 0; i < 2; i++) {
				position[i] += ballVector[i];
			}
		}
		else if (position[0] + ballVector[0] <= 0) { //jesli wspolrzedna x jest mniejsza od zera

			if (!a.CheckPosition(position[1])) {
				ballVector[0] = -ballVector[0];     // odbicie pilki
				optimize(a);
			}
			else{
				b.points += 1;                     // punkt dla drugiego gracza
				if (b.Winning()) {
					b.win = false;
					endgame = true;
				}
				restart(0);                        // pilka znow rusza ze srodka planszy
			}

		}else if(position[0] + ballVector[0] >= 88){

			if (!b.CheckPosition(position[1])) {
				ballVector[0] = -ballVector[0];
				optimize(b);
			}
			else {
				a.points += 1;
				if (a.Winning()) {
					a.win = false;
					endgame = true;
				}
				restart(1);

			}
		}
		Sleep(100);

	}

}
