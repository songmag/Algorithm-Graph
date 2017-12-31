#include "lb1.h"

labbel *labbelmap;

void gotoxy(COORD *i)
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *i);
}
void drawlabbelcross()
{
	int count, i;
	int randx,randy;

	srand((int)time(NULL));
	printf("몇개의 연결 구간 : ");
	scanf("%d", &count);
	for (i = 0; i < count; i++)
	{
		randy = rand() % labbelMax;
		randx = rand() % (labbelmap->size);
		while (randx % 2 != 0 && randx >= labbelmap->size-1)
		{
			randx = rand() % labbelmap->size;
		}
		labbelmap->map[randx][randy] = labbelCross;
		labbelmap->map[randx + 2][randy] = labbelCrossend;
	}
}
void drawlabbel()
{
	COORD k;
	
	int i,j;

	k.X = 5;
	k.Y = 5;
	gotoxy(&k);

	for (i = 0; i < labbelmap->size; i++)
	{
		if (i % 2 == 0)
		{
			gotoxy(&k);
			printf("%d번", i / 2+1);
			k.Y++;
		}
		for (j = 0; j < labbelMax;j++)
		{
			gotoxy(&k);
			drawPicture(i, j);
			k.Y++;
		}
		if (i % 2 == 0)
		{
			gotoxy(&k);
			printf("%d번", i / 2+1);
		}
		k.X=k.X+4;
		k.Y = 5;
	}
	
}
void drawPicture(int i,int j)
{
	if (labbelmap->map[i][j] == labbelBone)
	{
		printf("★");
	}
	else if (labbelmap->map[i][j] == labbelCross)
	{
		printf("□□□□□");
	}
	else if (labbelmap->map[i][j] == labbelempty)
	{
		return;
	}
}
void labbelinit() {
	int size;
	int i,j;
	printf("몇개의 사다리 : ");
	scanf("%d", &size);
	labbelmap = (labbel*)malloc(sizeof(labbel));
	labbelmap->map = (int**)malloc(sizeof(int*)*size*2);
	labbelmap->size = size*2;
	for (i = 0; i < size*2; i++)
	{
		labbelmap->map[i] = (int*)malloc(sizeof(int)*labbelMax);
		if (i % 2 == 0)
		{
			for (j = 0; j < labbelMax; j++)
			{
				labbelmap->map[i][j] = labbelBone;
			}
		}
	}
	system("cls");
}
void main()
{
	labbelinit();
	drawlabbel();
	drawlabbelcross();
	system("cls");
	drawlabbel();

	system("pause");
}