#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include "console.h"

#define WIDTH 130
#define HEIGHT 30
#define MAX_STARS 50

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

struct star {
	int x;
	int y;
	int speed;
};

struct star stars[MAX_STARS];


//별들의 초기 위치와 속도 초기화
void makeStars() {
	int i;
	for (i = 0; i < MAX_STARS; i++) {
		stars[i].x = rand() % WIDTH;
		stars[i].y = rand() % HEIGHT;
		stars[i].speed = rand() % 5 + 1;
	}
}
//별들의 위치 업데이트
void updateStars() {
	int i;
	for (i = 0; i < MAX_STARS; i++) {
		stars[i].y += stars[i].speed;
		if (stars[i].y >= HEIGHT) {
			stars[i].x = rand() % WIDTH;
			stars[i].y = 0;
			stars[i].speed = rand() % 5 + 1;
		}
	}
}
//별 그리기
void drawStars() {
	int i;
	for (i = 0; i < MAX_STARS; i++) {
		gotoxy(stars[i].x, stars[i].y);
		putchar('*');
	}
}
const int BULLET_NUM = 50;

int main() {
	

	struct Player player;
	player.speed = 10;		//TODO: player_speed해결하기.
	player.x = 60;
	player.y = 15;
	player.life = 3;
	player.score = 0;


	struct Bullet bullet;	//TODO: bullet 여러발 나가도록 구현.
	bullet.is_fired = 0; 
	bullet.x = 0;
	bullet.y = 0;
	bullet.delay;

	/*for (int i = 0; i < BULLET_NUM; i++)
	{
		gotoxy(60, 15);
		bullet[i].is_fired = 0;
	}*/


	srand(time(NULL));

	long start_time = clock();	// 게임 시작 시간
	long spent_time;			// 게임 진행 시간
	int fired_time = 0;

	struct Item item[2];
	item[0].delay = 25000;
	item[1].delay = 20000;

	while (1) {
		//clearScreen();
		makeStars();
		while (1) {
			//clearScreen();
			updateStars();
			drawStars();
			Sleep(500);
		}
	}

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
			
			if (!bullet.is_fired)	//화살이 발사 되지 않을 때 
			{
				bullet.x = player.x;
				bullet.y = player.y - 1;
				bullet.is_fired = 1;	//화살이 발사 될때
			}
		}
		if (bullet.is_fired)	//화살 발사 여부
		{
			gotoxy(bullet.x, bullet.y);
			printf("▲");
			bullet.y--;
			if (bullet.y < 0)
			{
				bullet.is_fired = 0;
			}
		}
		gotoxy(player.x, player.y);
		printf("■");
		Sleep(50);
	}

	system("pause");
	return 0;
}

