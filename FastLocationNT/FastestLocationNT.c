#include"FtLNT.h"


void Edgeinput(Vertex *first, Vertex *second)
{
	Edge* make;
	srand(time(NULL));

	make = (Edge*)malloc(sizeof(Edge));
	
	drawgraph->Esize += 1;
	make->connect1 = first;
	make->connect2 = second;
	make->value = (rand() % 10) + 1;
	make->next = NULL;
	make->front = drawgraph->insertE;

	drawgraph->insertE->next = make;
	drawgraph->insertE = make;
	drawgraph->Eptr->TAIL = make;
}//������ �Ź� ���� �ԷµǹǷ� tail�� ���� �ʿ�
void insertVertex()
{
	char insertValue[MAX];
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
		printf("������ �����մϴ�.\n");
		return;
	}
	return;
}//���� ����
void vertexinit(char *value)
{
	Vertex *make;
	make = (Vertex*)malloc(sizeof(Vertex));

	make->front = drawgraph->insertV;
	make->HEAD = (Link*)malloc(sizeof(Link));
	make->HEAD->Ptr = (PTR*)malloc(sizeof(PTR));
	make->HEAD->Ptr->HEAD = make->HEAD;
	make->HEAD->Ptr->TAIL = make->HEAD;
	make->HEAD->next = NULL;
	drawgraph->Vsize += 1;
	make->key = drawgraph->Vsize + 1;
	make->label = INFINITE;
	make->linksize = 0;
	strcpy(make->value, value);
	drawgraph->insertV->next = make;
	drawgraph->insertV = make;
	make->next = NULL;
	drawgraph->Vptr->TAIL = make;
}//���Խ� �ʱ�ȭ(�Ź� ���� �ԷµǴ°��)
void insertbetween(Vertex *nextvertex,int key)
{
	Vertex *make;
	make = (Vertex*)malloc(sizeof(Vertex));
	make->key = key;
	drawgraph->Vsize += 1;

	make->HEAD = (Link*)malloc(sizeof(Link));
	make->HEAD->Ptr = (PTR*)malloc(sizeof(PTR));

	make->HEAD->Ptr->HEAD = make->HEAD;
	make->HEAD->Ptr->TAIL = make->HEAD;
	make->HEAD->next = NULL;
	make->label = FRESH;
	make->linksize = 0;

	//������ ����
	drawgraph->insertV->next = make;
	make->next = nextvertex;
	nextvertex->front = drawgraph->insertV;
}//KEY���� 2���� �̻��� ���� ���̿� INSERT�� �ϴ°��
void GraphDevice(Divice work)
{
	work();
}
void insertEdge()
{
	char A[MAX],B[MAX];
	Vertex *connect1;
	Vertex *connect2;
	connect1 = drawgraph->VArray;
	connect2 = drawgraph->VArray;

	printf("����1 �Է� :");
	scanf("%s", &A);
	printf("\n����2 �Է� :");
	scanf("%s", &B);
	connect1 = findElem(A);
	connect2 = findElem(B);
	if (connect1 == NULL || connect2 == NULL)
	{
		printf("������ �����ϴ�. �� �Է� ��Ź�帳�ϴ�.\n");
		insertEdge();
		return;
	}
	if(Edgecheck(connect1, connect2))
	{
		insertlink(connect1);
		insertlink(connect2);
		Edgeinput(connect1,connect2);
	}//����Ǿ��ִ� ������ ���°�쿡�� ����
	else
	{
		printf("������ �����մϴ�.");
		return;
	}
	return;
}//���� ����
Vertex* findElem(char *value) {
	Vertex *node;
	node = (Vertex*)drawgraph->VArray;
	while (node != NULL && strcmp(node->value, value))
	{
		node = node->next;
	}//strcmp�� ��� ������ 0, ũ�� ���, ������ ����
	if (node == NULL)
	{
		return NULL;
	}//node �� npt�̸� null ����
	return node;
}
void insertlink(Vertex *insertvertex)
{
	Link *make,*mv_linkptr;
	int key;
	make = (Link*)malloc(sizeof(Link));
	make->EdgeInfo = drawgraph->insertE;

	mv_linkptr = insertvertex->HEAD;
	while (mv_linkptr != (Link*)(insertvertex->HEAD->Ptr->TAIL))
	{
		key = opposite(insertvertex, mv_linkptr->next)->key;
		if (insertvertex->key < key)
		{
			make->next = mv_linkptr->next;
			mv_linkptr->next = make;
			return;
		}
		mv_linkptr = mv_linkptr->next;
	}
 	make->next = NULL;
	mv_linkptr->next = make;
	insertvertex->HEAD->Ptr->TAIL = make;
}
int vertexcheck(char *value)
{
	Vertex* checkPointer;
	checkPointer = findElem(value);
	return (checkPointer == NULL)? 1 : 0;
}//�����Ѵٸ� false, ���� ���ϸ� true
int Edgecheck(Vertex *firstvertex, Vertex *secondvertex)
{
	int savesmall;
	Vertex *smallvertex, *bigvertex;
	Link *mv_pointer;
	savesmall = minfind(firstvertex, secondvertex);
	if (savesmall == 1)
	{
		smallvertex = firstvertex;
		bigvertex = secondvertex;
	}
	else
	{
		smallvertex = secondvertex;
		bigvertex = firstvertex;
	}
	mv_pointer = smallvertex->HEAD;
	while (mv_pointer != (Link*)(smallvertex->HEAD->Ptr->TAIL) && bigvertex != opposite(smallvertex,mv_pointer))
	{
		mv_pointer->next;
	}
	if (mv_pointer == (Link*)(smallvertex->HEAD->Ptr->TAIL))
	{
		return 1;
	}//mv_pointer ������ ã������ ���°��
	else
	{
		return 0;
	}//����Ǿ��ִ� ������ �ִ°��
}
int minfind(Vertex *firstvertex,Vertex *secondvertex)
{
	//1. ū���
	return (firstvertex->linksize >= secondvertex->linksize) ? 1 : 2;
	//2. �������
}//���� ����Ʈ�� ��������Ʈ�� ���� ���� ���� ��ȯ.
Vertex *opposite(Vertex *startvertex, Link *startlink)
{
	return ((startlink->EdgeInfo)->connect1 == startvertex) ? (startlink->EdgeInfo)->connect1 : (startlink->EdgeInfo)->connect2;
}//�ݴ��� ����� Ȯ��
void printAll()
{
	int i, j;
	Link *mv_pointer;
	Vertex *k;
	k = drawgraph->VArray;
	system("cls");
	while (k != NULL)
	{
		printf("Key >> %d, Value >> %s \n",
			k->key, k->value);
		mv_pointer = k->HEAD;
		while (mv_pointer != (Link*)(k->HEAD->Ptr->TAIL))
		{
			printf("Connect>> %d", opposite(&k, mv_pointer)->key);
			mv_pointer = mv_pointer->next;
		}
		k = k->next;
		printf("\n");
	} 
	Sleep(10000);
	system("cls");
}

