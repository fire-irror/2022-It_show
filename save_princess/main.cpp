#include <stdio.h>
#include <Windows.h>
#include "console.h"

struct Player {
	int speed;
	float x, y;
};

int main() {

	struct Player player;
	player.speed = 600;
	player.x = 60, player.y = 15;


	while (1) {

		Clear();// TODO: 얘가 0,0으로 이동시키는 걸 막아야한다. 

		if (GetAsyncKeyState(VK_LEFT)) {
			player.speed* player.x--;
		}

		else if (GetAsyncKeyState(VK_RIGHT)) {
			player.speed* player.x++;
		}
		else if (GetAsyncKeyState(VK_UP)) {
			player.speed* player.y--;
		}
		else if (GetAsyncKeyState(VK_DOWN)) {
			player.speed* player.y++;

		}
		gotoxy(player.x, player.y);
		printf("■");
		Sleep(50);
	}

	system("pause");
	return 0;
}