#include"FtLNT.h"


void Graphinit()
{
	int i;
	drawgraph = (G*)malloc(sizeof(G));
	drawgraph->VArray = (Vertex*)malloc(sizeof(Vertex));
	drawgraph->EArray = (Edge*)malloc(sizeof(Edge));
	drawgraph->Vsize = 0;
	drawgraph->Esize = 0;
	drawgraph->Vptr = (PTR*)malloc(sizeof(PTR));
	drawgraph->Eptr = (PTR*)malloc(sizeof(PTR));

	drawgraph->Vptr->HEAD = drawgraph->VArray;
	drawgraph->Vptr->TAIL = drawgraph->VArray;
	drawgraph->Eptr->HEAD = drawgraph->EArray;
	drawgraph->Eptr->TAIL = drawgraph->EArray;
	drawgraph->EArray->label = FRESH;
	drawgraph->insertV = drawgraph->VArray;
	drawgraph->insertE = drawgraph->EArray;
	//�׷��� �ʱ�ȭ

	drawgraph->VArray->HEAD = (Link*)malloc(sizeof(Link*));
	drawgraph->VArray->HEAD->Ptr = (PTR*)malloc(sizeof(PTR));
	drawgraph->VArray->HEAD->Ptr->HEAD = drawgraph->VArray->HEAD;
	drawgraph->VArray->HEAD->Ptr->TAIL = drawgraph->VArray->HEAD;
	drawgraph->VArray->key = 0;
	for (i = 0; i < MAX; i++)
	{
		drawgraph->VArray->value[i] = 0;
	}
	drawgraph->VArray->label = INFINITYVALUE;
	drawgraph->VArray->linksize = 0;
	drawgraph->VArray->next = NULL;
	drawgraph->VArray->heapindex = 0;
	//����
	drawgraph->EArray->connect1 = NULL;
	drawgraph->EArray->connect2 = NULL;
	drawgraph->EArray->value = 0;
	drawgraph->EArray->next = NULL;
	//����
}
void Edgeinputofweight(Vertex *first, Vertex *second, int weight)
{
	Edge* make;

	make = (Edge*)malloc(sizeof(Edge));
	drawgraph->Esize += 1;
	make->connect1 = first;
	make->connect2 = second;
	make->value = weight;
	make->next = NULL;
	make->front = drawgraph->insertE;
	make->label = FRESH;
	drawgraph->insertE->next = make;
	drawgraph->insertE = make;
	drawgraph->Eptr->TAIL = make;
}
void Edgeinput(Vertex *first, Vertex *second)
{
	Edge* make;

	srand(time(NULL));
	Sleep(300);
	make = (Edge*)malloc(sizeof(Edge));

	drawgraph->Esize += 1;
	make->connect1 = first;
	make->connect2 = second;
	make->value = (rand() % 20);
	make->next = NULL;
	make->front = drawgraph->insertE;
	make->label = FRESH;
	drawgraph->insertE->next = make;
	drawgraph->insertE = make;
	drawgraph->Eptr->TAIL = make;
}//������ �Ź� ���� �ԷµǹǷ� tail�� ���� �ʿ�
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
}//������ ���� ã�� ��
void insertlink(Vertex *insertvertex,Vertex *addvertex)
{
	Link *make, *mv_linkptr, *front;
	int key, key2;
	make = (Link*)malloc(sizeof(Link));
	make->EdgeInfo = drawgraph->insertE;
	make->next = NULL;
	// ���� �� mv_linkptr �� make�� insert E�� insertvertex�� ���� ��
	mv_linkptr = insertvertex->HEAD->next;
	front = insertvertex->HEAD;
	key2 = addvertex->key;
	while (mv_linkptr != NULL)
	{
		key = opposite(insertvertex, mv_linkptr)->key;//����Ʈ�� �ִ� ������ Ű
		if (key2 < key)
		{
			front->next = make;
			make->next = mv_linkptr;
			return;
		}
		mv_linkptr = mv_linkptr->next;
		front = front->next;
	}
	front->next = make;
	make->next = NULL;
	insertvertex->HEAD->Ptr->TAIL = make;
}
int vertexcheck(char *value)
{
	Vertex* checkPointer;
	checkPointer = findElem(value);
	return (checkPointer == NULL) ? 1 : 0;
}//�����Ѵٸ� false, ���� ���ϸ� true
Vertex *EdgetoVertex(Vertex* find, Edge *connect)
{
	return (connect->connect1 == find) ? connect->connect2 : connect->connect1;
}
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
	mv_pointer = smallvertex->HEAD->next;
	while (mv_pointer != NULL && bigvertex != opposite(smallvertex, mv_pointer))
	{
		mv_pointer = mv_pointer->next;
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
int minfind(Vertex *firstvertex, Vertex *secondvertex)
{
	//1. ū���
	return (firstvertex->linksize >= secondvertex->linksize) ? 1 : 2;
	//2. �������
}//���� ����Ʈ�� ��������Ʈ�� ���� ���� ���� ��ȯ.
Vertex *opposite(Vertex *startvertex, Link *startlink)
{
	return (startlink->EdgeInfo->connect1 == startvertex) ? startlink->EdgeInfo->connect2 : startlink->EdgeInfo->connect1;
}//�ݴ��� ����� Ȯ��
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
	make->key = drawgraph->Vsize;
	make->heapindex = 0;
	make->label = INFINITYVALUE+drawgraph->Vsize;
	make->linksize = 0;
	strcpy(make->value, value);
	drawgraph->insertV->next = make;
	drawgraph->insertV = make;
	make->next = NULL;
	drawgraph->Vptr->TAIL = make;
}//���Խ� �ʱ�ȭ(�Ź� ���� �ԷµǴ°��)
void insertbetween(Vertex *nextvertex, int key)
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

Vertex *FindAboutKey(int key)
{
	Vertex *mv_pointer;
	mv_pointer = drawgraph->VArray->next;

	while (mv_pointer != NULL && mv_pointer->key != key)
	{
		mv_pointer = mv_pointer->next;
	}
	if (mv_pointer == NULL)
	{
		return NULL;
	}
	return mv_pointer;
}

void setFastestinit()
{
	Vertex *mv_pointer;
	mv_pointer = drawgraph->VArray->next;
	while (mv_pointer != NULL)
	{
		mv_pointer->label = INFINITYVALUE;
		mv_pointer = mv_pointer->next;
	}
	return;
}
void randominsertVertex()
{
	int seed_vertex;
	char random_char[MAX];
	int i, vertex_size,edge_size;
	Vertex *one, *two;
	COORD xy;
	xy.X = 0;
	xy.Y = 0;
	gotoxy(xy);
	srand(time(NULL));
	seed_vertex = 10;
	printf("please type vertex_size :");
	scanf(" %d", &vertex_size);
	down(&xy);
	printf("please type edge_size :");
	scanf(" %d", &edge_size);

	while (drawgraph->Vsize < vertex_size)
	{
		for (i = 0; i < MAX; i++)
		{
			random_char[i] = 0;
		}
		random_char[0] = (rand() % 26) + 'a';

		if (vertexcheck(&random_char))
		{
			vertexinit(&random_char);
		}
	}
	while (drawgraph->Esize < edge_size)
	{
		seed_vertex = rand() % 10+1;
		one = FindAboutKey(seed_vertex);
		seed_vertex = rand() % 10+1;
		two = FindAboutKey(seed_vertex);

		if ( one != NULL && two !=NULL && Edgecheck(one, two))
		{
			Edgeinput(one,two);
			insertlink(one,two);
			insertlink(two,one);
		}
	}
}
