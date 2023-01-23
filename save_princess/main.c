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

void PlayerMove() {
	printf("■");
}

int main() {

	struct Player player;
	player.speed_max = 15;
	player.speed = 7;//플레이어 속도
	player.score = 0;//플레이어 점수
	player.life = 10;

	while (1) {
		if (GetAsyncKeyState(VK_LEFT))
			PlayerMove();
		else if (GetAsyncKeyState(VK_RIGHT))
			PlayerMove();
		else if (GetAsyncKeyState(VK_UP))
			PlayerMove();
		else if (GetAsyncKeyState(VK_DOWN))
			PlayerMove();
		else if (GetAsyncKeyState(VK_SPACE))//엔터를 눌렀을 때
			PlayerMove();
	}
	
	return 0;
}