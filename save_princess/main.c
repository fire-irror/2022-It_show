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

int main() {
	textcolor(YELLOW2, BLACK);

	return 0;
}