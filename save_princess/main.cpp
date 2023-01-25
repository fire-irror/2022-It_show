#include <stdio.h>
#include <Windows.h>
#include "console.h"



int main() {

	int x = 60, y = 15;

	while (1) {

		Clear();

		if (GetAsyncKeyState(VK_LEFT)) {
			x--;
		}

		else if (GetAsyncKeyState(VK_RIGHT)) {
			x++;
		}
		else if (GetAsyncKeyState(VK_UP)) {
			y--;
		}
		
		else if (GetAsyncKeyState(VK_DOWN)) {
			y++;
		}
			
		gotoxy(x, y);
		printf("■");
		Sleep(50);
	}

	system("pause");
	return 0;
}