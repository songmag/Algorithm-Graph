#include "FtLNT.h"

void mainPage()
{
	COORD CTRL;
	CTRL.X = 0;
	CTRL.Y = 0;
	system("cls");
	gotoxy(CTRL);
	printf("Shortest Path");
	down(&CTRL);
	printf("1. �׷��� ����");
	down(&CTRL);
	printf("2. ���");
	down(&CTRL);
	printf("3. ����");
	down(&CTRL);
	printf("4. ����");

	chooseDivice[0]=_getch() - 48;
}
//1,2,3,4,5 �� ������ ��� �Լ�
void graphinitprint()
{
	COORD xy;
	xy.X = 0;
	xy.Y = 0;
	system("cls");
	gotoxy(xy);
	printf("�׷��� ���� \n");
	down(&xy);
	printf("1. ���� ����");
	down(&xy);
	printf("2. random ����");
	down(&xy);
	printf("3. ����");
	chooseDivice[1] = _getch() - 48;
	switch (chooseDivice[1])
	{
	case 1:
		handdraw();
		break;
	case 2:
		randominsertVertex();
		return;
	case 3:
		return;
	default:
		system("cls");
		printf("��Ȯ�� ���� �Է����ּ���\n");
		system("pause");
		break;
	}
}
void graphprintchoose()
{
	COORD xy;
	Divice command;
	while (1) {
		xy.X = 0;
		xy.Y = 0;

		command = NULL;
		system("cls");
		gotoxy(xy);
		printf("\n");
		down(&xy);
		printf("1. Tabel���");
		down(&xy);
		printf("2. Graph���");
		down(&xy);
		printf("3. �ڷΰ���");
		chooseDivice[1] = _getch() - 48;
		switch (chooseDivice[1])
		{
		case 1:
			command = makeTable;
			break;
		case 2:
			break;
		case 3:
			return;
		}
		if (command != NULL)
		{
			system("cls");
			command();
		}
	}
}

void handdraw()
{
	COORD xy;
	Divice command;
	int seed_Edge;
	while(1)
	{
		system("cls");
		xy.X = 0;
		xy.Y = 0;
		gotoxy(xy);
		seed_Edge = 0;
		printf("�����Է�");
		xy.X += 1;
		down(&xy);
		printf("1. �����Է�");
		down(&xy);
		printf("2. �����Է�");
		down(&xy);
		printf("3. �Է�Ȯ��");
		down(&xy);
		printf("4. �׷��� �ϼ�");
		command= NULL;
		chooseDivice[2] =_getch()-48;
		switch (chooseDivice[2])
		{
		case 1:
			command = insertVertex;
			break;
		case 2:
			system("cls");
			xy.X = 0;
			xy.Y = 0;
			gotoxy(xy);
			printf("1. ���� �Է�");
			down(&xy);
			printf("2. Ű �Է�");
			seed_Edge=_getch() - 48;
			if (seed_Edge == 1)
			{
				command = insertEdge;
			}
			else if (seed_Edge == 2)
			{
				command = insertEdgeAboutKey;
			}
			break;
		case 3:
			command = printAll;
			break;
		case 4:
			return;
		default:
			system("cls");
			printf("��Ȯ�� ���� �Է��� �ּ��� :");
			system("pause");
			break;
		}
		if (command != NULL)
		{
			system("cls");
			command();
		}
	}
}
void application()
{
	COORD xy;
	Divice command;
	while (1) 
	{
		xy.X = 0;
		xy.Y = 0;
		system("cls");
		gotoxy(xy);
		printf("application");
		xy.X += 1; 
		down(&xy);
		printf("1. DFS");
		down(&xy);
		printf("2. BFS");
		down(&xy);
		printf("3. �ִܰ��");
		down(&xy);
		printf("4. ����Ŭ");
		down(&xy);
		printf("5. �˰���");
		chooseDivice[1] = _getch() - 48;

		command = NULL;
		switch (chooseDivice[1])
		{
		case 1:
			break;
		case 2:
			break;
		case 3:
			printf("1. ���� Value �Է�");
			printf("2. ���� Key �Է�");
			chooseDivice[1] = _getch() - 48;
			if (chooseDivice[1] == 1)
			{
				command = FastLocationValue;
			}
			else if (chooseDivice[1] == 2)
			{
				command = FastLocationKey;
			}
			else
			{
				printf("����� �� ���� �Է����ּ���");
				break;
			}
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			return;
		default:
			system("cls");
			printf("����� �� ���� �Է����ּ���.\n");
			break;
		}
		if (command != NULL)
		{
			system("cls");
			command();
		}
	}
}