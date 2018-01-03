#include "lb1.h"

labbel *labbelmap;

void gotoxy(COORD *i)
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *i);
}

void chooseone()
{
	COORD TEXT;
	int index;
	int for_i;
	int save;
	printf("Choose one :");
	scanf("%d", &save);
	index = (save - 1) * 2;
	//i값
	for (for_i = 0; for_i < labbelMax; for_i++)
	{
		fillLabbel(index, for_i);
		if (labbelmap->map[index][for_i] == labbelCross)
		{
			index = index + 2;
		}
		else if (labbelmap->map[index][for_i] == labbelCrossend)
		{
			index = index - 2;
		}
	}
	TEXT.Y = Ystart + labbelMax + 2;
	TEXT.X = Xstart + (labbelmap->size / 2);
	gotoxy(&TEXT);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	printf("%d에서 사다리 %d 가 선택!", save, (index / 2) + 1);
}

void fillLabbel(int i, int j)
{
	COORD C_xy;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 18);
	FindLocation(&C_xy, i, j + 1);
	gotoxy(&C_xy);
	drawPicture(i, j);
}//if(처리 i%2 == 0 인경우에 FillLabel)
void FindLocation(COORD *C_i, int i, int j)
{
	(*C_i).X = Xstart + rightPlus*i;
	(*C_i).Y = Ystart + j;
}//return 값은 COORD의 xy값 확인
void drawlabbelcross()
{
	int count, i;
	int randx, randy;
	COORD M;
	M.Y = labbelMax + 5;
	M.X = labbelmap->size;

	gotoxy(&M);
	srand((int)time(NULL));


	printf("몇개의 연결 구간 : ");
	scanf("%d", &count);
	for (i = 0; i < count; i++)
	{
		randy = rand() % labbelMax;
		randx = rand() % (labbelmap->size);
		while (randx % 2 != 0 || randx >= labbelmap->size - 2)
		{
			randx = rand() % labbelmap->size;
		}
		while (randy >= (labbelMax - 2) || randy <= 1 || labbelmap->map[randx][randy] == labbelCross || labbelmap->map[randx + 2][randy] == labbelCrossend)
		{
			randy = rand() % labbelMax;
		}//y값이 사다리의 2칸 아래인경우, y값이 1이하로 내려가는경우, xy값이 이미 설정이 되어있는경우(다리로)
		labbelmap->map[randx][randy] = labbelCross;
		labbelmap->map[randx + 2][randy] = labbelCrossend;
	}

}//사다리 연결하는 구간
void drawlabbel()
{
	COORD k;

	int i, j;
	k.Y = 1;
	k.X = labbelmap->size + 2;
	gotoxy(&k);
	printf("★사다리 타기★");

	k.X = Xstart;
	k.Y = Ystart;

	for (i = 0; i < labbelmap->size; i++)
	{
		if (i % 2 == 0)
		{
			gotoxy(&k);
			printf("%d번", (i / 2) + 1);
			k.Y++;
		}
		for (j = 0; j < labbelMax; j++)
		{
			gotoxy(&k);
			drawPicture(i, j);
			k.Y++;
		}
		if (i % 2 == 0)
		{
			gotoxy(&k);
			printf("%d번", (i / 2) + 1);
		}
		k.X = k.X + rightPlus;
		k.Y = Ystart;
	}
}//사다리 전체 그리기 구간
void drawPicture(int i, int j)
{
	COORD labbelCrossfind;
	if (labbelmap->map[i][j] == labbelBone)
	{
		printf("│");
	}
	else if (labbelmap->map[i][j] == labbelCross)
	{
		printf("├───────┤");
	}
	else if (labbelmap->map[i][j] == labbelCrossend)
	{
		FindLocation(&labbelCrossfind, i - 2, j + 1);
		gotoxy(&labbelCrossfind);
		printf("├───────┤");
	}
	else if (labbelmap->map[i][j] == labbelempty)
	{
		return;
	}
}//2차원 배열의 각 값을 확인하여 STD_OUTPUT_HANDLE에 출력
void labbelinit() {
	int size;
	int i, j;
	printf("몇개의 사다리 : ");
	scanf("%d", &size);
	size = (size >= 10) ? 9 : size;
	labbelmap = (labbel*)malloc(sizeof(labbel));
	labbelmap->map = (int**)malloc(sizeof(int*)*size * 2);
	labbelmap->size = size * 2;
	for (i = 0; i < size * 2; i++)
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
}//사다리의 초기화
void main()
{
	labbelinit();
	drawlabbel();
	drawlabbelcross();
	system("cls");
	drawlabbel();
	chooseone();
	system("pause");
}