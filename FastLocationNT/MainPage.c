#include "FtLNT.h"
void gotoxy(COORD xy)
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),xy);
}//콘솔 gotoxy
void mainPage()
{
	COORD CTRL;

	CTRL.X = 10;
	CTRL.Y = 3;
	
	gotoxy(CTRL);
	printf("Shortest Path");
	CTRL.Y += 5;
	gotoxy(CTRL);
	printf("1. 정점 입력");
	CTRL.Y += 2;
	gotoxy(CTRL);
	printf("2. 간선 입력");
	CTRL.Y += 2;
	gotoxy(CTRL);
	printf("3. 모든 정점 출력");
	CTRL.Y += 2;
	gotoxy(CTRL);
	printf("4. 최단경로 출력");
	CTRL.Y += 2;
	gotoxy(CTRL);
	printf("5. 정점 to 정점");
	CTRL.Y += 2;
	gotoxy(CTRL);
	printf("작업을 선택 : ");
	scanf(" %d",&chooseDivice);
}
//1,2,3,4,5 번 선택지 출력 함수