#include <iostream>
#include <thread>
#include <Windows.h>
#include <fstream>
#include <string>
#include "Menedzer.h"
#include "Ball.h"
#include "Board.h"
#include "Bot.h"
#include "Human.h"
#include "Player.h"


void Menedzer::Cursor(bool Flag) {

	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = Flag;
	SetConsoleCursorInfo(out, &cursorInfo);
}

int Menedzer::Start() {
	
	char znak;
	char load;
	int a = 0;
	bool exit = true;
	bool end = true;
	Human human;
	Bot bot;
	Board board;
	Ball pilka;

	do {
		cout << "Do you want load your last game? (y/n)" << endl;
		cin >> load;
		if (load != 'y' && load != 'n') { cout << "Choose y or n" << endl; }

	} while (load != 'y' && load != 'n');

	if (load == 'y') {
		loadGame(pilka, human, bot);
	}

	system("cls");
	Cursor(false);

	// thread nazwa(Metoda , obiekt metody, argumenty metody ..... )

	thread mainThr(&Ball::move, &pilka, ref(human), ref(bot), ref(end));
	thread moveThr1(&Human::move, &human, ref(human), ref(exit), ref(end));
	thread moveThr2(&Bot::move, &bot, ref(pilka), ref(bot), ref(end));

	do {
		board.WczytajTablice();
		board.Palette(human.palette, bot.palette);
		board.SprawdzPilke(pilka.position[0], pilka.position[1]);
		board.drukujTablice();
		cout << endl;
		cout << "    YOUR POINTS: " << human.points << "                                         ENEMY POINTS: " 
			<< bot.points << endl;
			if (load == 'y') {
			system("pause");
			load = 'n';
		}
		Sleep(100);
		system("cls");

	} while (human.win == true && bot.win == true && exit == true);

	end = false;
	mainThr.join();
	moveThr1.join();
	moveThr2.join();

	Cursor(true);


	if (!exit) {
		saveGame(pilka, human, bot);
		cout << "Succesfully saved" << endl;
	}

	if (! human.win) {
		cout << "Congratulations. You win!" << endl;
	}

	if (! bot.win) {
		cout << "You Lost:(Good Luck next time!" << endl;
	}

	do {
		cout << "Do you want play again ? (y / n)" << endl;
		cin >> znak;
		cin.clear();
		if (znak == 'y') {
			system("cls");
			return 1; 
		}
		else cout << "You have played PONG." << endl;

	} while (znak != 'y' && znak != 'n');

}


void Menedzer::saveGame(Ball& ball, Player& human, Player& bot) { //zapisanie do pliku
		ofstream saveFile("YourSave.txt");

		saveFile << ball.position[0] << endl << ball.position[1] << endl;	
		saveFile << ball.ballVector[0] << endl << ball.ballVector[1] << endl;		
		saveFile << human.palette << endl << human.points << endl;
		saveFile << bot.palette << endl << bot.points << endl;
		saveFile.close();
	
}


void Menedzer::loadGame(Ball& ball, Player& human, Player& bot){  // wczytanie z pliku
	int i = 1;
	string znak;
	ifstream saveFile("YourSave.txt");

	while (getline(saveFile, znak, '\n')) {

		switch (i) {

		 case 1:
			ball.position[0] = stof(znak);
			break;
		 case 2:
			 ball.position[1] = stof(znak);
			 break;
		 case 3:
			 ball.ballVector[0] = stof(znak);
			 break;
		 case 4:
			 ball.ballVector[1] = stof(znak);
			 break;
		 case 5:
			 human.palette = stof(znak);
			 break;
		 case 6:
			 human.points = stof(znak);
			 break;
		 case 7:
			 bot.palette = stof(znak);
			 break;
		 case 8:
			 bot.points = stof(znak);
			 break;
		}
		i++;
	}
	saveFile.close();

}


