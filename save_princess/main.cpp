#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include "console.h"

struct Player {
	int speed;
	float x, y;
	int life;
	int score;
};

struct Bullet {
	int x, y;
	int is_fired;	//발사 여부
	int delay;
};

struct Item {
	int delay;
	int is_presented;
	int presented_time;
};

const int BULLET_NUM = 50;

int main() {
	

	struct Player player;
	player.speed = 10;		//TODO: player_speed해결하기.
	player.x = 60;
	player.y = 15;
	player.life = 3;
	player.score = 0;


	struct Bullet bullet[BULLET_NUM];	//TODO: bullet 여러발 나가도록 구현.
	bullet[BULLET_NUM].is_fired = 0; 
	bullet[BULLET_NUM].x = 0;
	bullet[BULLET_NUM].y = 0;
	bullet[BULLET_NUM].delay;

	for (int i = 0; i < BULLET_NUM; i++)
	{
		gotoxy(60, 15);
		bullet[i].is_fired = 0;
	}


	srand(time(NULL));

	long start_time = clock();	// 게임 시작 시간
	long spent_time;			// 게임 진행 시간
	int fired_time = 0;

	struct Item item[2];
	item[0].delay = 25000;
	item[1].delay = 20000;

	for (int i = 0; i < 2; i++)
	{
		item[i].is_presented = 0;
		item[i].presented_time = 0;
		printf("★");
	}

	while (1) {

		Clear();

		if (GetAsyncKeyState(VK_LEFT)) {
			player.x--;
			if (player.x < 0) {
				player.x = 0;
			}
		}

		if (GetAsyncKeyState(VK_RIGHT)) {
			player.x++;
			if (player.x > 119) {
				player.x = 119;
			}
		}
		if (GetAsyncKeyState(VK_UP)) {
			player.y--;
			if (player.y < 0) {
				player.y = 0;
			}
		}
		if (GetAsyncKeyState(VK_DOWN)) {
			player.y++;
			if (player.y > 29) {
				player.y = 29;
			}
		}
		if (GetAsyncKeyState(VK_SPACE)) {
			
			if (!bullet[BULLET_NUM].is_fired)	//화살이 발사 되지 않을 때 
			{
				bullet[BULLET_NUM].x = player.x;
				bullet[BULLET_NUM].y = player.y - 1;
				bullet[BULLET_NUM].is_fired = 1;	//화살이 발사 될때
			}
		}
		if (bullet[BULLET_NUM].is_fired)	//화살 발사 여부
		{
			gotoxy(bullet[BULLET_NUM].x, bullet[BULLET_NUM].y);
			printf("▲");
			bullet[BULLET_NUM].y--;
			if (bullet[BULLET_NUM].y < 0)
			{
				bullet[BULLET_NUM].is_fired = 0;
			}
		}
		gotoxy(player.x, player.y);
		printf("■");
		Sleep(50);
	}

	system("pause");
	return 0;
}