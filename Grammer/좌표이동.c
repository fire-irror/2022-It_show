#include <stdio.h>
#include <Windows.h>


void gotoxy(int x, int y);

int main(void) {
	gotoxy(50, 20);
	printf("A\n");
	printf("출력되었습니다");
}

void gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
