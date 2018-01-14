#include"FtLNT.h"


void insertVertex(COORD xy)
{
	char insertValue[MAX];
	gotoxy(xy);
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
		xy.Y =xy.Y + 1;
		gotoxy(xy);
		printf("정점이 존재합니다.\n");
		return;
	}
	return;
}//정점 삽입
void insertEdge(COORD xy)
{
	char A[MAX],B[MAX];
	Vertex *connect1;
	Vertex *connect2;

	gotoxy(xy);

	connect1 = drawgraph->VArray;
	connect2 = drawgraph->VArray;

	printf("정점1 입력 :");
	scanf("%s", &A);
	xy.Y = xy.Y + 2;
	gotoxy(xy);
	printf("정점2 입력 :");
	scanf("%s", &B);
	connect1 = findElem(A);
	connect2 = findElem(B);
	if (connect1 == NULL || connect2 == NULL)
	{
		xy.Y++;
		gotoxy(xy);
		printf("정점이 없습니다. 재 입력 부탁드립니다.\n");
		system("pause");
		return;
	}
	if(Edgecheck(connect1, connect2))
	{
		Edgeinput(connect1, connect2);
		insertlink(connect1,connect2);
		insertlink(connect2,connect1);		
	}//연결되어있는 간선이 없는경우에만 시행
	else
	{
		xy.Y++;
		gotoxy(xy);
		printf("간선이 존재합니다.");
		system("pause");
		return;
	}
	return;
}//간선 삽입
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
void FastLocation()
{
	char A[MAX];
	int counting;
	
	Vertex *start,*minvertex, *oppositevertex;
	Vertex **FastLocationArray;
	Link *mv_pointer;
		
	FastLocationArray = (Vertex**)malloc(sizeof(Vertex*)*drawgraph->Vsize);
	counting = 0;
	setFastestinit();
	printf("시작 지점 :");
	scanf("%s", &A);
	start = findElem(A);
	if (start == NULL)
	{
		printf("출발 정점이 없습니다.");
	}
	start->label = 0;
	Qinit();
	printheap();
	while (!Empty())
	{
		minvertex= pop();
		mv_pointer = minvertex->HEAD->next;
		while (mv_pointer != NULL)
		{
			oppositevertex = opposite(minvertex, mv_pointer);
			if (oppositevertex->heapindex != 0)
			{
				if (oppositevertex->label > minvertex->label + mv_pointer->EdgeInfo->value)
				 {
					oppositevertex->label = minvertex->label + mv_pointer->EdgeInfo->value;
					replacevertex(oppositevertex);
					mv_pointer->EdgeInfo->label = VISIT;
				}
			}
			mv_pointer = mv_pointer->next;
		}
		FastLocationArray[counting] = minvertex;
		counting = counting + 1;
	}//Q가 빌때까지
	printFastest(FastLocationArray);
	system("pause");
}
void printFastest(Vertex** find)
{
	int i;
	i = 0;
	for (i = 0; i < drawgraph->Vsize; i++)
	{
		printf("%d %d", find[i]->key,find[i]->label);
		printf("\n");
	}
}
