#include <stdio.h>
#include<Windows.h> 	//윈도우에서 색깔 전환
#include <stdlib.h>
#include <time.h>
#define YELLOW2 14
#define BLACK 0


// 글씨 색깔, 배경색깔
void textcolor(int t_color, int bg_color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), t_color | bg_color << 4);
};

//원하는 좌표 x.y로 커서를 이동시킬 수 있다. 
void gotoxy(int x, int y) {
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//커서 숨기기
void removeCursor(void)
{
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
	cursorInfo.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

int main() {
	textcolor(YELLOW2, BLACK);
	removeCursor();
	gotoxy(8, 20);
	printf("SAVE THE PRINCESS");

	return 0;
}