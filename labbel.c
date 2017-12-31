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
	COORD M;
	M.Y = labbelMax+5;
	M.X = labbelmap->size;

	gotoxy(&M);
	srand((int)time(NULL));


	printf("��� ���� ���� : ");
	scanf("%d", &count);
	for (i = 0; i < count; i++)
	{
		randy = rand() % labbelMax;
		randx = rand() % (labbelmap->size);
		while (randx % 2 != 0 || randx >= labbelmap->size-2)
		{
			randx = rand() % labbelmap->size;
		}
		while (randy >= (labbelMax-2) || randy <= 1 || labbelmap->map[randx][randy] == labbelCross || labbelmap->map[randx+2][randy] == labbelCrossend)
		{
			randy = rand() % labbelMax;
		}//y���� ��ٸ��� 2ĭ �Ʒ��ΰ��, y���� 1���Ϸ� �������°��, xy���� �̹� ������ �Ǿ��ִ°��(�ٸ���)
		labbelmap->map[randx][randy] = labbelCross;
		labbelmap->map[randx + 2][randy] = labbelCrossend;
	}
}//��ٸ� �����ϴ� ����
void drawlabbel()
{
	COORD k;
	
	int i,j;
	k.Y = 1;
	k.X = labbelmap->size+2;
	gotoxy(&k);
	printf("�ڻ�ٸ� Ÿ���");

	k.X = 5;
	k.Y = 3;
	gotoxy(&k);

	for (i = 0; i < labbelmap->size; i++)
	{
		if (i % 2 == 0)
		{
			gotoxy(&k);
			printf("%d��", i / 2+1);
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
			printf("%d��", i / 2+1);
		}
		k.X=k.X+4;
		k.Y = 3;
	}
}//��ٸ� ��ü �׸��� ����
void drawPicture(int i,int j)
{
	if (labbelmap->map[i][j] == labbelBone)
	{
		printf("��");
	}
	else if (labbelmap->map[i][j] == labbelCross)
	{
		printf("����������");
	}
	else if (labbelmap->map[i][j] == labbelempty)
	{
		return;
	}
}//2���� �迭�� �� ���� Ȯ���Ͽ� STD_OUTPUT_HANDLE�� ���
void labbelinit() {
	int size;
	int i,j;
	printf("��� ��ٸ� : ");
	scanf("%d", &size);
	size = (size >= 10) ? 9 : size;
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
}//��ٸ��� �ʱ�ȭ
void main()
{
	labbelinit();
	drawlabbel();
	drawlabbelcross();
	system("cls");
	drawlabbel();
	system("pause");
}