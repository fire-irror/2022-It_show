#include <stdio.h>
#include<Windows.h> 	//�����쿡�� ���� ��ȯ
#include <stdlib.h>
#include <time.h>
#define YELLOW2 14
#define BLACK 0


// �۾� ����, ������
void textcolor(int t_color, int bg_color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), t_color | bg_color << 4);
};

//���ϴ� ��ǥ x.y�� Ŀ���� �̵���ų �� �ִ�. 
void gotoxy(int x, int y) {
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//Ŀ�� �����
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
	gotoxy(0, 0);
	printf("\n\n\n\n");
	printf("      ****      *    *        *   \n");
	printf("     *         * *    *      *      \n");
	printf("      ****    *****    *    *         \n");
	printf("          *   *     *    *  *         \n");
	printf("     ****   *       *    **        \n");


	printf("SAVE THE PRINCESS");
	//StartMenu();
	return 0;
	
}