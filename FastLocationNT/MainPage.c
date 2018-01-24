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
	printf("1. 그래프 구성");
	down(&CTRL);
	printf("2. 출력");
	down(&CTRL);
	printf("3. 응용");
	down(&CTRL);
	printf("4. 종료");

	chooseDivice[0]=_getch() - 48;
}
//1,2,3,4,5 번 선택지 출력 함수
void graphinitprint()
{
	COORD xy;
	xy.X = 0;
	xy.Y = 0;
	system("cls");
	gotoxy(xy);
	printf("그래프 구성 \n");
	down(&xy);
	printf("1. 직접 구성");
	down(&xy);
	printf("2. random 생성");
	down(&xy);
	printf("3. 종료");
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
		printf("정확한 값을 입력해주세요\n");
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
		printf("1. Tabel출력");
		down(&xy);
		printf("2. Graph출력");
		down(&xy);
		printf("3. 뒤로가기");
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
		printf("수동입력");
		xy.X += 1;
		down(&xy);
		printf("1. 정점입력");
		down(&xy);
		printf("2. 간선입력");
		down(&xy);
		printf("3. 입력확인");
		down(&xy);
		printf("4. 그래프 완성");
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
			printf("1. 문자 입력");
			down(&xy);
			printf("2. 키 입력");
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
			printf("정확한 값을 입력해 주세요 :");
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
		printf("3. 최단경로");
		down(&xy);
		printf("4. 사이클");
		down(&xy);
		printf("5. 알고리즘");
		chooseDivice[1] = _getch() - 48;

		command = NULL;
		switch (chooseDivice[1])
		{
		case 1:
			break;
		case 2:
			break;
		case 3:
			printf("1. 정점 Value 입력");
			printf("2. 정점 Key 입력");
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
				printf("제대로 된 값을 입력해주세요");
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
			printf("제대로 된 값을 입력해주세요.\n");
			break;
		}
		if (command != NULL)
		{
			system("cls");
			command();
		}
	}
}