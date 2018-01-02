#include<stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#pragma warning(disable:4996)
#define labbelBone 5000
#define labbelCross 1000
#define labbelempty 2000
#define labbelMax 20
#define labbelCrossend 3000
#define rightPlus 4
#define Ystart 3
#define Xstart 5

typedef struct labbelstruct {
	int **map;
	int size;
}labbel;

void gotoxy(COORD *i);
void drawlabbel();
void drawPicture(int i, int j);
void labbelinit();
void FindLocation(COORD *C_i, int i, int j);
void drawlabbelcross();
void fillLabbel(int i, int j);
void chooseone();