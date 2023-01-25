#include <stdio.h>
#include <windows.h>

int  main(void) {
	for (int i = 0; i < 3; i++) {
		printf("Hello");
		Sleep(1000);	//1초 시간 지연되면서 hello가 1초에 하나씩 3번 나온다.
	}
	return 0;
}