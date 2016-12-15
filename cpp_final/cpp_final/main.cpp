#include"Time.h"
#include"Key.h"
#include"KeyEvent.h"
#include<iomanip>
#include<list>

void temp1(list<int>& b) {
	int a = 1;

	b.insert(b.begin(), a);
}

int main() {
	Time temp;
	Key cursor;
	int i = 0;
	KeyEvent k;
	while (i != 13) {
		i = k.getkey();
		cursor.move(i);
	}

	list<int> a;
	int* in = new int(0);

	a.insert(a.begin(), *in);

	delete in;

	temp1(a);

	cout << endl;
	cout << endl;
	cout << setfill('0') << setw(8) << right<< *(a.begin())+120 << endl;
}