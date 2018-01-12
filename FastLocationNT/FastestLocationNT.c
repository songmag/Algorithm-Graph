#include"FtLNT.h"


void Edgeinit()
{
	drawgraph->Esize += 1;
	drawgraph->insertE->next = (Edge*)malloc(sizeof(Edge));
	drawgraph->insertE->next->front = drawgraph->insertE;
	drawgraph->insertE = drawgraph->insertE->next;
	drawgraph->insertE->next = NULL;
	drawgraph->EArray->Ptr->TAIL = drawgraph->insertE;
}//������ �Ź� ���� �ԷµǹǷ� tail�� ���� �ʿ�
void insertVertex()
{
	char insertValue[MAX];
	printf("���� �Է��Ͻÿ� : ");
	scanf("%s",&insertValue);
	if (vertexcheck(insertValue))
	{
		strcpy(drawgraph->insertV->value,insertValue);
	}
	else
	{
		printf("������ �����մϴ�.\n");
		return;
	}
	if(drawgraph->insertV == drawgraph->VArray->Ptr->TAIL)
	vertexinit();
	else
	{
		//�����ϰ� �ִ°��
		//insertbetween(drawgraph->insertV->next,(drawgraph->insertV->next->key)-1);
	}
	return;
}//���� ����
void vertexinit()
{
	drawgraph->insertV->key = drawgraph->Vsize + 1;
	drawgraph->insertV->HEAD = (Link*)malloc(sizeof(Link));
	drawgraph->insertV->HEAD->Ptr = (PTR*)malloc(sizeof(PTR));
	drawgraph->insertV->HEAD->Ptr->HEAD = drawgraph->insertV->HEAD;
	drawgraph->insertV->HEAD->Ptr->TAIL = drawgraph->insertV->HEAD;
	drawgraph->insertV->HEAD->next = NULL;
	drawgraph->insertV->label = FRESH;
	drawgraph->insertV->next = (Vertex*)malloc(sizeof(Vertex));
	drawgraph->Vsize += 1;
	drawgraph->insertV->next->front = drawgraph->insertV;
	drawgraph->insertV = drawgraph->insertV->next;
	drawgraph->insertV->next = NULL;
	drawgraph->VArray->Ptr->TAIL = drawgraph->insertV;
}//���Խ� �ʱ�ȭ(�Ź� ���� �ԷµǴ°��)
void insertbetween(Vertex *nextvertex,int key)
{
	drawgraph->insertV->key = key;
	drawgraph->Vsize += 1;
	drawgraph->insertV->HEAD = (Link*)malloc(sizeof(Link));
	drawgraph->insertV->HEAD->Ptr->HEAD = drawgraph->insertV->HEAD;
	drawgraph->insertV->HEAD->Ptr->TAIL = drawgraph->insertV->HEAD;
	drawgraph->insertV->HEAD->next = NULL;
	//������ ����
	drawgraph->insertV->label = FRESH;
	drawgraph->insertV->next = nextvertex;
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
	srand(time(NULL));
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
		drawgraph->insertE->connect1 = connect1;
		drawgraph->insertE->connect2 = connect2;
		drawgraph->insertE->value = (rand() % 10) + 1;
		insertlink(connect1);
		Edgeinit();
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
	node = drawgraph->VArray->Ptr->HEAD;
	while (node != drawgraph->VArray->Ptr->TAIL && strcmp(node->value, value))
	{
		node = node->next;
	}//strcmp�� ��� ������ 0, ũ�� ���, ������ ����
	if (node == drawgraph->VArray->Ptr->TAIL)
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
	while (mv_linkptr != insertvertex->HEAD->Ptr->TAIL)
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
	while (mv_pointer != NULL && bigvertex != opposite(smallvertex,mv_pointer))
	{
		mv_pointer->next;
	}
	if (mv_pointer == NULL)
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

	system("cls");
	for (i = 0; i <= drawgraph->Vsize ; i++)
	{
		printf("Key >> %d, Value >> %s \n",
			drawgraph->VArray[i].key, drawgraph->VArray->value);
		mv_pointer = drawgraph->VArray[i].HEAD;
		k = &drawgraph->VArray[i];
		while (mv_pointer != k->HEAD->Ptr->TAIL)
		{
			printf("Connect>> %d", opposite(k, mv_pointer)->key);
			mv_pointer = mv_pointer->next;
		}
		printf("\n");
	}
}

