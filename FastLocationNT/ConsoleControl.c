#include"FtLNT.h"
void changeColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void gotoxy(COORD xy)
{
	xy.X += defaultx;
	xy.Y += defaulty;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), xy);
}//콘솔 gotoxy
void down(COORD *xy)
{
	(*xy).Y += 2;
	gotoxy(*xy);
}
void downindex(COORD *xy, int raws)
{
	(*xy).Y += raws;
	gotoxy(*xy);
}
void right(COORD *xy, int maxsize)
{
	(*xy).X += maxsize;
	gotoxy(*xy);
}
void graphdirect(int key, int key2)
{
	COORD xy;
	xy.X = key2*4;
	xy.Y = key;
	gotoxy(xy);
}//그래프 위치로 가는 함수
void graphvertexX(int key)
{
	COORD xy;
	xy.X = key*4;
	xy.Y = 0;
	gotoxy(xy);
}
void graphvertexY(int key)
{
	COORD xy;
	xy.X = 0;
	xy.Y = key;
	gotoxy(xy);
}