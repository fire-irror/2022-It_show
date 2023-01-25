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


void gotoxy(int x, int y) {

}

void PlayerMove() {
	gotoxy(14, 28);
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
			PlayerMove(-1, 0);
		else if (GetAsyncKeyState(VK_RIGHT))
			PlayerMove();
		else if (GetAsyncKeyState(VK_UP))
			PlayerMove(0,-1);
		else if (GetAsyncKeyState(VK_DOWN))
			PlayerMove(0,player.speed);
		else if (GetAsyncKeyState(VK_SPACE))//엔터를 눌렀을 때
			PlayerMove(player.speed,0);
	}
	system.clear(Color::BLACK);
	
	return 0;
}