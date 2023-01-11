#include <stdio.h>
#include <windows.h>
#include <stralign.h>
#include <stdlib.h>

#define YELLOW2 14
#define BLACK 0
#define pause system("pause > nul")    //그냥 내가 많이 쓰는 커맨드를 줄여준 것이다.
#define cls system("cls") 

void SetColor(int color);
void CursorView(char show);
void gotoxy(int x, int y);

void textcolor(int t_color, int bg_color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), t_color | bg_color << 4);
};

void titleDraw() {
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
	printf("\n\n\n\n");
	printf("      ****      *    *       *  ******                              \n");
	printf("     *         * *    *     *   *                                   \n");
	printf("      ****    *****    *   *    ******                              \n");
	printf("          *  *     *    * *     *                                   \n");
	printf("     ****   *       *    *      ******                              \n");
	printf("SAVE THE PRINCESS");
	printf("\n\n\n\n");
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
}
void SetColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void CursorView(char show)
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;

	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

void gotoxy(int x, int y) {

	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

	
	void mainPtr(void);

	int main(void) {
		CursorView(0);    //커서의 깜빡임을 숨겨준다.
		system("COLOR 0F");    //화면 배경을 검정, 글씨 색깔을 하얀색으로 설정해 준다.
		mainPtr();
		pause;
		
		
		gotoxy(8, 20);
		titleDraw();

		int POS = 4;	//0 - 새로 하기, 1 - 이어 하기, 2 - 랭킹 보기, 3 - 게임 종료
		CursorView(0);
		system("COLOR 0F");
		mainPtr();
		while (1) {
			if (GetAsyncKeyState(VK_LEFT))
				if (POS == 0) POS = 3;
				else POS -= 1;
			else if (GetAsyncKeyState(VK_RIGHT))
				if (POS == 3) POS = 0;
				else POS += 1;
			else if (GetAsyncKeyState(VK_RETURN))//엔터를 눌렀을 때
				break;
			switch (POS) {
			case 0:
				SetColor(11);
				gotoxy(10, 4); printf("게임하기");
				SetColor(15);
				gotoxy(35, 4); printf("게임방법");
				gotoxy(60, 4); printf("랭킹보기");
				gotoxy(85, 4); printf("게임종료");
				break;
			case 1:
				gotoxy(10, 4); printf("게임하기");
				SetColor(11);
				gotoxy(35, 4); printf("게임방법");
				SetColor(15);
				gotoxy(60, 4); printf("랭킹보기");
				gotoxy(85, 4); printf("게임종료");
				break;
			case 2:
				gotoxy(10, 4); printf("게임하기");
				gotoxy(35, 4); printf("게임방법");
				SetColor(11);
				gotoxy(60, 4); printf("랭킹보기");
				SetColor(15);
				gotoxy(85, 4); printf("게임종료");
				break;
			case 3:
				gotoxy(10, 4); printf("게임하기");
				gotoxy(35, 4); printf("게임방법");
				gotoxy(60, 4); printf("랭킹보기");
				SetColor(11);
				gotoxy(85, 4); printf("게임종료");
				SetColor(15);
				break;
			default: break;
			}
			Sleep(100);
		}
		cls;
		if (POS == 0) puts("게임하기를 눌렀습니다.");
		else if (POS == 1) puts("게임방법를 눌렀습니다.");
		else if (POS == 2) puts("랭킹 보기를 눌렀습니다.");
		return 0;
	}

	void mainPtr(void) {
		system("mode con: cols=106 lines=9");   //참고로 cols 2단위가 특수문자 또는 한글 1글자다.
		system("title Save the princess - 메인");
		gotoxy(10, 4); printf("게임하기");
		gotoxy(35, 4); printf("게임방법");
		gotoxy(60, 4); printf("랭킹보기");
		gotoxy(85, 4); printf("게임종료");
		return;
	}