#include"FtLNT.h"


void insertVertex(COORD xy)
{
	char insertValue[MAX];
	gotoxy(xy);
	printf("���� �Է��Ͻÿ� : ");
	scanf("%s",&insertValue);
	if (vertexcheck(insertValue))
	{
		if (drawgraph->insertV == (Vertex*)drawgraph->Vptr->TAIL)
			vertexinit(insertValue);
		else
		{
			//�����ϰ� �ִ°��
			//insertbetween(drawgraph->insertV->next,(drawgraph->insertV->next->key)-1);
		}
	}
	else
	{
		xy.Y =xy.Y + 1;
		gotoxy(xy);
		printf("������ �����մϴ�.\n");
		return;
	}
	return;
}//���� ����
void insertEdge(COORD xy)
{
	char A[MAX],B[MAX];
	Vertex *connect1;
	Vertex *connect2;

	gotoxy(xy);

	connect1 = drawgraph->VArray;
	connect2 = drawgraph->VArray;

	printf("����1 �Է� :");
	scanf("%s", &A);
	xy.Y = xy.Y + 2;
	gotoxy(xy);
	printf("����2 �Է� :");
	scanf("%s", &B);
	connect1 = findElem(A);
	connect2 = findElem(B);
	if (connect1 == NULL || connect2 == NULL)
	{
		xy.Y++;
		gotoxy(xy);
		printf("������ �����ϴ�. �� �Է� ��Ź�帳�ϴ�.\n");
		system("pause");
		return;
	}
	if(Edgecheck(connect1, connect2))
	{
		Edgeinput(connect1, connect2);
		insertlink(connect1,connect2);
		insertlink(connect2,connect1);		
	}//����Ǿ��ִ� ������ ���°�쿡�� ����
	else
	{
		xy.Y++;
		gotoxy(xy);
		printf("������ �����մϴ�.");
		system("pause");
		return;
	}
	return;
}//���� ����
void printAll()
{
	Link *mv_pointer;
	Vertex *k;
	k = drawgraph->VArray->next;
	while (k != NULL)
	{
		printf("Key >> %d, Value >> %s \n",
			k->key, k->value);
		mv_pointer = k->HEAD->next;
		while (mv_pointer != NULL)
		{
			printf("Connect>> %s", opposite(k, mv_pointer)->value);
			mv_pointer = mv_pointer->next;
		}
		k = k->next;
		printf("\n");
	} 
	system("pause");
}
void FastLocation()
{
	Qinit();
	while (!Empty())
	{
		printf("%d\n", pop());
	}
	system("pause");
}

