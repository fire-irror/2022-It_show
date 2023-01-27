#include <stdio.h>
#include <Windows.h>
#include "console.h"

struct Player {
	int speed;
	float x, y;
};

int main() {

	struct Player player;
	player.speed = 600;		//TODO: player_speed해결하기.
	player.x = 60, player.y = 15;


	while (1) {

		Clear();

		if (GetAsyncKeyState(VK_LEFT)) {
			player.x--;
			if (player.x < 0) {
				player.x = 0;
			}
		}

		else if (GetAsyncKeyState(VK_RIGHT)) {
			player.x++;
			if (player.x > 119) {
				player.x = 119;
			}
		}
		else if (GetAsyncKeyState(VK_UP)) {
			player.y--;
			if (player.y < 0) {
				player.y = 0;
			}
		}
		else if (GetAsyncKeyState(VK_DOWN)) {
			 player.y++;
			 if (player.y > 29) {
				 player.y = 29;
			 }
		}
		gotoxy(player.x, player.y);
		printf("■");
		Sleep(50);
	}

	system("pause");
	return 0;
}