#include"FtLNT.h"
void insertVertex()
{
	COORD xy;
	char insertValue[MAX];
	
	xy.X = 0;
	xy.Y = 0;

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
		xy.Y += 1;
		gotoxy(xy);
		printf("������ �����մϴ�.\n");
		return;
	}
	return;
}//���� ����
void insertEdge()
{
	char A[MAX],B[MAX];
	int weight;
	Vertex *connect1;
	Vertex *connect2;
	COORD xy;
	xy.X = 0;
	xy.Y = 0;
	
	gotoxy(xy);

	connect1 = drawgraph->VArray;
	connect2 = drawgraph->VArray;

	printf("����1 �Է� :");
	scanf("%s", &A);
	down(&xy);
	printf("����2 �Է� :");
	scanf("%s", &B);
	connect1 = findElem(A);
	connect2 = findElem(B);
	down(&xy);
	printf("���� weight �Է� : ");
	scanf("%d", &weight);
	if (connect1 == NULL || connect2 == NULL)
	{
		xy.Y+=1;
		gotoxy(xy);
		printf("������ �����ϴ�. �� �Է� ��Ź�帳�ϴ�.\n");
		system("pause");
		return;
	}
	if(Edgecheck(connect1, connect2))
	{
		if (weight != 0)
		{
			Edgeinputofweight(connect1, connect2, weight);
		}
		else
		{
			Edgeinput(connect1, connect2);
		}
		insertlink(connect1,connect2);
		insertlink(connect2,connect1);		
	}//����Ǿ��ִ� ������ ���°�쿡�� ����
	else
	{
		xy.Y +=1;
		gotoxy(xy);
		printf("������ �����մϴ�.");
		system("pause");
		return;
	}
	return;
}//���� ����
void insertEdgeAboutKey()
{
	int key1, key2,weight;
	Vertex *ver1, *ver2;
	COORD xy;
	xy.X = 0;
	xy.Y = 0;
	gotoxy(xy);
	printf("1�� Key �� �Է� :");
	scanf(" %d", &key1);
	down(&xy);
	printf("2�� key �� �Է� :");
	scanf(" %d", &key2);
	down(&xy);
	printf("weight �Է� : ");
	scanf(" %d", &weight);
	ver1 = FindAboutKey(key1);
	ver2 = FindAboutKey(key2);
	if (ver1 != NULL && ver2 != NULL &&Edgecheck(ver1, ver2))
	{
		if (weight != 0)
		{
			Edgeinputofweight(ver1, ver2, weight);
		}
		else
			Edgeinput(ver1, ver2);
		insertlink(ver1, ver2);
		insertlink(ver2, ver1);
	}
	else if (ver1 == NULL)
	{
		printf("key>> %d�� �������� �ʽ��ϴ�.\n", key1);
		system("pause");
		return;
	}
	else if (ver2 == NULL)
	{
		printf("key>> %d�� �������� �ʽ��ϴ�.\n", key2);
		system("pause");
		return;
	}
	else
	{
		printf("�����ϴ� �����Դϴ�.");
		system("pause");
		return;
	}
}//Ű�� �̿��� ��������
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
			printf("Connect>> %s weight >> %d", opposite(k, mv_pointer)->value,mv_pointer->EdgeInfo->value);
			mv_pointer = mv_pointer->next;
			printf("\n");
		}
		k = k->next;
		printf("\n");
	} 
	system("pause");
}

int CycleCheck(){
}
int PrimAlgo() {

}
