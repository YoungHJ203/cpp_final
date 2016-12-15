#pragma once
#include<Windows.h>

class Key {
public:
	Key() {
		this->x = 0;
		this->y = 0;
	}

	void move(int direction) {
		switch (direction) {
		case 37: {
			this->x--;
			break; }
		case 38: {
			this->y--;
			break; }
		case 39: {
			this->x++;
			break; }
		case 40: {
			this->y++;
			break; }
		}

		this->gotoxy(x, y);
	}


private:
	void gotoxy(int x, int y) {
		COORD pos = { x,y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	}

	int x;
	int y;
};