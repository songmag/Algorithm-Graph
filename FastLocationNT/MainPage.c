#include "FtLNT.h"
void gotoxy(COORD xy)
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),xy);
}//�ܼ� gotoxy
void mainPage()
{
	COORD CTRL;

	CTRL.X = 10;
	CTRL.Y = 3;
	
	gotoxy(CTRL);
	printf("Shortest Path");
	CTRL.Y += 5;
	gotoxy(CTRL);
	printf("1. ���� �Է�");
	CTRL.Y += 2;
	gotoxy(CTRL);
	printf("2. ���� �Է�");
	CTRL.Y += 2;
	gotoxy(CTRL);
	printf("3. ��� ���� ���");
	CTRL.Y += 2;
	gotoxy(CTRL);
	printf("4. �ִܰ�� ���");
	CTRL.Y += 2;
	gotoxy(CTRL);
	printf("5. ���� to ����");
	CTRL.Y += 2;
	gotoxy(CTRL);
	printf("�۾��� ���� : ");
	scanf(" %d",&chooseDivice);
}
//1,2,3,4,5 �� ������ ��� �Լ�