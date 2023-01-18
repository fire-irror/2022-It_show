#include <stdio.h>
#include <Windows.h>

#define cls system("cls") 

struct Player {
	int speed;
	int score;
	int life;
	float x, y;
	int speed_max;
};

void playerDraw() {
	printf("■");
}

int main() {

	struct Player player;
	player.speed_max = 15;
	player.speed = 7;//플레이어 속도
	player.score = 0;//플레이어 점수
	player.life = 10;
	
	system("cls");
	playerDraw();
}