#pragma once
#include<Windows.h>
#include<iostream>
using namespace std;

class KeyEvent {
public:
	KeyEvent() {
		h = GetStdHandle(STD_INPUT_HANDLE);
		EventCount = 1;
	}
	int getkey() {
		ReadConsoleInput(h, &rec, 1, &NumRead);
		if (rec.EventType == KEY_EVENT) {
			if (rec.Event.KeyEvent.bKeyDown) {
				downKey = rec.Event.KeyEvent.wVirtualKeyCode;
				return downKey;
			}
			else {
				return -1;
			}
		}

		return -1;
	}

private:
	HANDLE h;
	COORD KeyWhere;
	DWORD EventCount;
	INPUT_RECORD rec;
	DWORD NumRead;
	int downKey;
};
