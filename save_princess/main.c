#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

#define SCREEN_WIDTH 100
#define SCREEN_HEIGHT 25
#define MAX_STARS 10

void Clearscreen(void)
{
    system("cls");
}

void gotoxy(int _x, int _y)
{
    COORD pos = { _x,_y };

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//떨어지는 별
struct star {
    int x;
    int y;
    int speed;
};

struct star stars[MAX_STARS];


void initStars() {
    int i;
    for (i = 0; i < MAX_STARS; i++) {
        stars[i].x = rand() % SCREEN_WIDTH;
        stars[i].y = rand() % SCREEN_HEIGHT;
        stars[i].speed = rand() % 5 + 1;
    }
}

void updateStars() {
    int i;
    for (i = 0; i < MAX_STARS; i++) {
        stars[i].y += stars[i].speed;
        if (stars[i].y >= SCREEN_HEIGHT) {
            stars[i].x = rand() % SCREEN_WIDTH;
            stars[i].y = 0;
            stars[i].speed = rand() % 5 + 1;
        }
    }
}

void drawStars() {
    int i;
    for (i = 0; i < MAX_STARS; i++) {
        gotoxy(stars[i].x, stars[i].y);
        putchar('*');
    }
}


//공격
void SetColor(unsigned char _BgColor, unsigned char _TextColor)
{
    if (_BgColor > 15 || _TextColor > 15)
        return;

    unsigned short ColorNum = (_BgColor << 4) | _TextColor;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ColorNum);
}
struct Player {
    int speed;
    float x, y;
    int life;
};

struct Bullet {
    int x, y;
    int is_fired;   //발사 여부
};

const int BULLET_NUM = 50;

int main() {


    struct Player player;
    player.speed = 10;      //TODO: player_speed해결하기.
    player.x = 60;
    player.y = 15;
    player.life = 3;

    struct Bullet bullet;
    bullet.is_fired = 0;
    bullet.x = 0;
    bullet.y = 0;

    long start_time = clock();   // 게임 시작 시간
    long spent_time;         // 게임 진행 시간
    int fired_time = 0;

    srand(time(NULL));


    while (1) {

        Clearscreen();
        initStars();
        while (1) {
            updateStars();
            drawStars();
            Sleep(500);

            Clearscreen();
            if (GetAsyncKeyState(VK_LEFT)) {
                player.x--;
                if (player.x < 0) {
                    player.x = 0;
                }
            }

            if (GetAsyncKeyState(VK_RIGHT)) {
                player.x++;
                if (player.x > 119) {
                    player.x = 119;
                }
            }
            if (GetAsyncKeyState(VK_UP)) {
                player.y--;
                if (player.y < 0) {
                    player.y = 0;
                }
            }
            if (GetAsyncKeyState(VK_DOWN)) {
                player.y++;
                if (player.y > 29) {
                    player.y = 29;
                }
            }
            if (GetAsyncKeyState(VK_SPACE)) {
                bullet.x = player.x;
                bullet.y = player.y - 1;
                bullet.is_fired = 1;   //화살이 발사 될때

            }
            if (bullet.is_fired)   //화살 발사 여부
            {
                gotoxy(bullet.x, bullet.y);
                printf("▲");
                bullet.y--;
                if (bullet.y < 0) {
                    bullet.is_fired = 0;
                }
            }
            gotoxy(player.x, player.y);
            printf("■");
            Sleep(50);

        }

    }

    system("pause");
    return 0;
}