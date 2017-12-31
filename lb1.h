#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#define labbelBone 5000
#define labbelCross 1000
#define labbelempty 2000
#define labbelMax 20

typedef struct labbelstruct {
	int **map;
	int size;
}labbel;

void gotoxy(COORD *i);
void drawlabbel();
void drawPicture(int i, int j);
void labbelinit();