#include <stdio.h>
#include<Windows.h> 	//À©µµ¿ì¿¡¼­ »ö±ò ÀüÈ¯
#include <stdlib.h>
#include <time.h>
#define YELLOW2 14
#define BLACK 0


// ±Û¾¾ »ö±ò, ¹è°æ»ö±ò
void textcolor(int t_color, int bg_color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), t_color | bg_color << 4);
};

int main() {
	textcolor(YELLOW2, BLACK);

	return 0;
}