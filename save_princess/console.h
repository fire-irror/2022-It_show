#include <windows.h>

void Clear(void);	
//화면을 지우고 커서 위치 0,0 이동시키는 함수

void gotoxy(int _x, int _y);	
//커서 위치 변경

void SetTitle(char* _szConsoleName); 
//console창 제목 바꾸기

void SetColor(unsigned char _BgColor, unsigned char _TextColor);
//배경, 글자색 변경

void SetConsoleSize(int _col, int _lines);
//콘솔 사이즈 

void clearScreen() {
    system("cls");
}