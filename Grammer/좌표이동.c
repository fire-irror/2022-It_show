#include <stdio.h>
#include <Windows.h>


void gotoxy(int x, int y);

int main(void) {
	gotoxy(50, 20);
	printf("A\n");
	printf("��µǾ����ϴ�");
}

void gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
