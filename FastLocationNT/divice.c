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
	//그래프 초기화

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
	//정점
	drawgraph->EArray->connect1 = NULL;
	drawgraph->EArray->connect2 = NULL;
	drawgraph->EArray->value = 0;
	drawgraph->EArray->next = NULL;
	//간선
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
}//값으로 값을 찾는 것
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
	make->label = INFINITYVALUE+drawgraph->Vsize;
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
		mv_pointer->label = INFINITYVALUE;
		mv_pointer = mv_pointer->next;
	}
	return;
}
void randominsertVertex()
{
	int seed_vertex;
	char random_char[MAX];
	int i;
	Vertex *one, *two;
	srand(time(NULL));
	seed_vertex = 10;
	while (drawgraph->Vsize < 10)
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
	while (drawgraph->Esize < 20)
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
void insertEdgeAboutKey()
{
	int key1, key2;
	Vertex *ver1, *ver2;
	printf("1번 Key 값 입력 :");
	scanf(" %d", &key1);
	printf("2번 key 값 입력 :");
	scanf(" %d", &key2);
	ver1 = FindAboutKey(key1);
	ver2 = FindAboutKey(key2);
	if (ver1 != NULL && ver2 != NULL &&Edgecheck(ver1, ver2))
	{
		Edgeinput(ver1, ver2);
		insertlink(ver1, ver2);
		insertlink(ver2, ver1);
	}
	else if(ver1 == NULL)
	{
		printf("key>> %d는 존재하지 않습니다.\n",key1);
		system("pause");
		return;
	}
	else if (ver2 == NULL)
	{
		printf("key>> %d는 존재하지 않습니다.\n", key2);
		system("pause");
		return;
	}
	else
	{
		printf("존재하는 간선입니다.");
		system("pause");
		return;
	}
}
void paintVertex(Vertex* startVertex)
{
	changeColor(7);
	graphvertexX(startVertex->key);
	printf("%d", startVertex->key);
	graphvertexY(startVertex->key);
	printf("%d", startVertex->key);
	return;
}//최소값 혹은 시작 값
void paintFast(Vertex* startVertex, Vertex* minVertex)
{
	changeColor(7);
	graphdirect(startVertex->key, minVertex->key);
	printf("%d", minVertex->label);
	return;
}
void cantarrived(Vertex* startVertex, Vertex* minVertex)
{
	changeColor(7);
	graphdirect(startVertex->key, minVertex->key);
	printf("X");
	return;
}