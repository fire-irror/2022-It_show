#include <windows.h>

void Clear(void);	
//ȭ���� ����� Ŀ�� ��ġ 0,0 �̵���Ű�� �Լ�

void gotoxy(int _x, int _y);	
//Ŀ�� ��ġ ����

void SetTitle(char* _szConsoleName); 
//consoleâ ���� �ٲٱ�

void SetColor(unsigned char _BgColor, unsigned char _TextColor);
//���, ���ڻ� ����

void SetConsoleSize(int _col, int _lines);
//�ܼ� ������ 

void clearScreen() {
    system("cls");
}