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
	make->label = FRESH;
	drawgraph->insertE->next = make;
	drawgraph->insertE = make;
	drawgraph->Eptr->TAIL = make;
}//간선은 매번 끝에 입력되므로 tail의 변경 필요
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
void insertlink(Vertex *insertvertex,Vertex *addvertex)
{
	Link *make, *mv_linkptr, *front;
	int key, key2;
	make = (Link*)malloc(sizeof(Link));
	make->EdgeInfo = drawgraph->insertE;
	make->next = NULL;
	// 시작 점 mv_linkptr 비교 make의 insert E의 insertvertex의 값과 비교
	mv_linkptr = insertvertex->HEAD->next;
	front = insertvertex->HEAD;
	key2 = addvertex->key;
	while (mv_linkptr != NULL)
	{
		key = opposite(insertvertex, mv_linkptr)->key;//리스트에 있는 숫자의 키
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
}//존재한다면 false, 존재 않하면 true
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
		printf("%d %d", opposite(smallvertex, mv_pointer)->key, bigvertex->key);
		mv_pointer = mv_pointer->next;
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
int minfind(Vertex *firstvertex, Vertex *secondvertex)
{
	//1. 큰경우
	return (firstvertex->linksize >= secondvertex->linksize) ? 1 : 2;
	//2. 작은경우
}//정점 리스트의 부착리스트가 적은 것을 수로 반환.
Vertex *opposite(Vertex *startvertex, Link *startlink)
{
	return (startlink->EdgeInfo->connect1 == startvertex) ? startlink->EdgeInfo->connect2 : startlink->EdgeInfo->connect1;
}//반대편 노드의 확인
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
	make->label = INFINITY+drawgraph->Vsize;
	make->linksize = 0;
	strcpy(make->value, value);
	drawgraph->insertV->next = make;
	drawgraph->insertV = make;
	make->next = NULL;
	drawgraph->Vptr->TAIL = make;
}//삽입시 초기화(매번 끝에 입력되는경우)
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

	//정점의 변경
	drawgraph->insertV->next = make;
	make->next = nextvertex;
	nextvertex->front = drawgraph->insertV;
}//KEY값의 2차이 이상이 나서 사이에 INSERT을 하는경우

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
		mv_pointer->label = INFINITY;
		mv_pointer = mv_pointer->next;
	}
	return;
}
void randominsertVertex()
{

}