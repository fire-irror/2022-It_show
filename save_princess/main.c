#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include "console.h"
# include "console.c"

#define WIDTH 130
#define HEIGHT 30
#define MAX_STARS 50
#define MAX_BULLETS 50

//플레이어
struct Player {
	int speed;
	float x, y;
	int life;
	int score;
};


//총알
struct Bullet {
	int x, y;
	int is_fired;	//발사 여부
	int delay;
};

//플레이어 아이템
struct Item {
	int delay;
	int is_presented;
	int presented_time;
};

// 적
struct star {
	int x;
	int y;
	int speed;
};

struct Bullet bullets[MAX_BULLETS];

// 총알 여러발 구현
void makeBullet() {
	for (int i = 0; i < MAX_BULLETS; i++)
	{
		gotoxy(bullets[i].x, bullets[i].y);
		bullets[i].is_fired= 0;
	}

}
//struct star stars[MAX_STARS];


//적들의 초기 위치와 속도 초기화
/*void makeStars() {
	int i;
	for (i = 0; i < MAX_STARS; i++) {
		stars[i].x = rand() % WIDTH;
		stars[i].y = rand() % HEIGHT;
		stars[i].speed = rand() % 5 + 1;
	}
}
//적들의 위치 업데이트
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
//적 그리기
/*void drawStars() {
	int i;
	for (i = 0; i < MAX_STARS; i++) {
		gotoxy(stars[i].x, stars[i].y);
		putchar('*');
	}
}*/

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


	srand(time(NULL));

	long start_time = clock();	// 게임 시작 시간
	long spent_time;			// 게임 진행 시간
	int fired_time = 0;
	
	/*while (1) {
		clearScreen();
		makeStars();
		while (1)
		{
			clearScreen();
			updateStars();
			drawStars();
			Sleep(500);
		}
	}*/

	/*struct Item item[2];
	item[0].delay = 25000;
	item[1].delay = 20000;


	for (int i = 0; i < 2; i++)
	{
		item[i].is_presented = 0;
		item[i].presented_time = 0;
		printf("★");
	}*/

	while (1) 
	{

		if (GetAsyncKeyState(VK_LEFT)) 
		{
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
			gotoxy(player.x, player.y);
			printf("■");
			Sleep(50);
		}
	}

	system("pause");
	return 0;
}

