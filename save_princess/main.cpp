#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include "console.h"

struct Player {
	int speed;
	float x, y;
	int life;
};

struct Bullet {
	int x, y;
	int is_fired;	//발사 여부
};

const int BULLET_NUM = 50;

int main() {


	struct Player player;
	player.speed = 10;		//TODO: player_speed해결하기.
	player.x = 60;
	player.y = 15;
	player.life = 3;

	struct Bullet bullet;
	int is_fired;
	bullet.x = 0;
	bullet.y = 0;

	long start_time = clock();	// 게임 시작 시간
	long spent_time;			// 게임 진행 시간
	int fired_time = 0;

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
		else if (GetAsyncKeyState(VK_SPACE)) {
			bullet.x = player.x;
			bullet.y = player.y - 1;

		}

		gotoxy(bullet.x, bullet.y);
		printf("▲");

		gotoxy(player.x, player.y);
		printf("■");
		Sleep(50);
	}

	system("pause");
	return 0
}