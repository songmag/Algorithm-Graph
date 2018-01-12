#include"FtLNT.h"


void Edgeinit()
{
	drawgraph->Esize += 1;
	drawgraph->insertE->next = (Edge*)malloc(sizeof(Edge));
	drawgraph->insertE->next->front = drawgraph->insertE;
	drawgraph->insertE = drawgraph->insertE->next;
	drawgraph->insertE->next = NULL;
	drawgraph->EArray->Ptr->TAIL = drawgraph->insertE;
}//간선은 매번 끝에 입력되므로 tail의 변경 필요
void insertVertex()
{
	char insertValue[MAX];
	printf("값을 입력하시오 : ");
	scanf("%s",&insertValue);
	if (vertexcheck(insertValue))
	{
		strcpy(drawgraph->insertV->value,insertValue);
	}
	else
	{
		printf("정점이 존재합니다.\n");
		return;
	}
	if(drawgraph->insertV == drawgraph->VArray->Ptr->TAIL)
	vertexinit();
	else
	{
		//삭제하고 넣는경우
		//insertbetween(drawgraph->insertV->next,(drawgraph->insertV->next->key)-1);
	}
	return;
}//정점 삽입
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
}//삽입시 초기화(매번 끝에 입력되는경우)
void insertbetween(Vertex *nextvertex,int key)
{
	drawgraph->insertV->key = key;
	drawgraph->Vsize += 1;
	drawgraph->insertV->HEAD = (Link*)malloc(sizeof(Link));
	drawgraph->insertV->HEAD->Ptr->HEAD = drawgraph->insertV->HEAD;
	drawgraph->insertV->HEAD->Ptr->TAIL = drawgraph->insertV->HEAD;
	drawgraph->insertV->HEAD->next = NULL;
	//정점의 변경
	drawgraph->insertV->label = FRESH;
	drawgraph->insertV->next = nextvertex;
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
	srand(time(NULL));
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
		drawgraph->insertE->connect1 = connect1;
		drawgraph->insertE->connect2 = connect2;
		drawgraph->insertE->value = (rand() % 10) + 1;
		insertlink(connect1);
		Edgeinit();
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
	node = drawgraph->VArray->Ptr->HEAD;
	while (node != drawgraph->VArray->Ptr->TAIL && strcmp(node->value, value))
	{
		node = node->next;
	}//strcmp의 경우 같으면 0, 크면 양수, 작으면 음수
	if (node == drawgraph->VArray->Ptr->TAIL)
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
	while (mv_pointer != NULL && bigvertex != opposite(smallvertex,mv_pointer))
	{
		mv_pointer->next;
	}
	if (mv_pointer == NULL)
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

