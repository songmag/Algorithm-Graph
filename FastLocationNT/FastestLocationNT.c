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
}//간선은 매번 끝에 입력되므로 tail의 변경 필요
void insertVertex()
{
	char insertValue[MAX];
	printf("값을 입력하시오 : ");
	scanf("%s",&insertValue);
	if (vertexcheck(insertValue))
	{
		if (drawgraph->insertV == (Vertex*)drawgraph->Vptr->TAIL)
			vertexinit(insertValue);
		else
		{
			//삭제하고 넣는경우
			//insertbetween(drawgraph->insertV->next,(drawgraph->insertV->next->key)-1);
		}
	}
	else
	{
		printf("정점이 존재합니다.\n");
		return;
	}
	return;
}//정점 삽입
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
}//삽입시 초기화(매번 끝에 입력되는경우)
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

	//정점의 변경
	drawgraph->insertV->next = make;
	make->next = nextvertex;
	nextvertex->front = drawgraph->insertV;
}//KEY값의 2차이 이상이 나서 사이에 INSERT을 하는경우
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

	printf("정점1 입력 :");
	scanf("%s", &A);
	printf("\n정점2 입력 :");
	scanf("%s", &B);
	connect1 = findElem(A);
	connect2 = findElem(B);
	if (connect1 == NULL || connect2 == NULL)
	{
		printf("정점이 없습니다. 재 입력 부탁드립니다.\n");
		insertEdge();
		return;
	}
	if(Edgecheck(connect1, connect2))
	{
		insertlink(connect1);
		insertlink(connect2);
		Edgeinput(connect1,connect2);
	}//연결되어있는 간선이 없는경우에만 시행
	else
	{
		printf("간선이 존재합니다.");
		return;
	}
	return;
}//간선 삽입
Vertex* findElem(char *value) {
	Vertex *node;
	node = (Vertex*)drawgraph->VArray;
	while (node != NULL && strcmp(node->value, value))
	{
		node = node->next;
	}//strcmp의 경우 같으면 0, 크면 양수, 작으면 음수
	if (node == NULL)
	{
		return NULL;
	}//node 가 npt이면 null 리턴
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
}//존재한다면 false, 존재 않하면 true
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
	}//mv_pointer 끝까지 찾았으나 없는경우
	else
	{
		return 0;
	}//연결되어있는 정점이 있는경우
}
int minfind(Vertex *firstvertex,Vertex *secondvertex)
{
	//1. 큰경우
	return (firstvertex->linksize >= secondvertex->linksize) ? 1 : 2;
	//2. 작은경우
}//정점 리스트의 부착리스트가 적은 것을 수로 반환.
Vertex *opposite(Vertex *startvertex, Link *startlink)
{
	return ((startlink->EdgeInfo)->connect1 == startvertex) ? (startlink->EdgeInfo)->connect1 : (startlink->EdgeInfo)->connect2;
}//반대편 노드의 확인
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

