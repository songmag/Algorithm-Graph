#include"FtLNT.h"

void FastLocationValue()
{
	char A[MAX];
	int counting;
	int backcounting;
	Vertex *start, *minvertex, *oppositevertex;
	Vertex **FastLocationArray;
	Link *mv_pointer;

	FastLocationArray = (Vertex**)malloc(sizeof(Vertex*)*drawgraph->Vsize);
	counting = 1;
	backcounting = drawgraph->Vsize;
	setFastestinit();
	drawEmptyTableY();
	printf("시작 지점 :");
	scanf("%s", &A);
	start = findElem(A);
	if (start == NULL)
	{
		printf("출발 정점이 없습니다.");
		return;
	}
	start->label = 0;
	paintVertex(start);
	Qinit();
	while (!Empty())
	{
		minvertex = pop();
		if (minvertex->label == INFINITYVALUE)
		{
			cantarrived(start, minvertex,backcounting--);
			Sleep(50);
			continue;
		}//아무것도 변경 되지 않았을 경우
		paintFast(start, minvertex,counting);
		Sleep(50);
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
	 //printFastest(FastLocationArray);
	QFree();
	free(FastLocationArray);
	system("pause");
}

void FastLocationKey()
{
	int key;
	int counting;
	int backcounting;
	COORD xy;
	Vertex *start, *minvertex, *oppositevertex;
	Vertex **FastLocationArray;
	Link *mv_pointer;
	xy.X = 0;
	xy.Y = drawgraph->Vsize;
	//FastLocationArray = (Vertex**)malloc(sizeof(Vertex*)*drawgraph->Vsize);
	counting = 1;
	backcounting = drawgraph->Vsize;
	setFastestinit();
	drawEmptyTableY();
	printf("시작 지점 :");
	scanf("%d", &key);
	start = FindAboutKey(key);
	if (start == NULL)
	{
		printf("출발 정점이 없습니다.");
		return;
	}
	start->label = 0;
	paintVertex(start);
	Qinit();
	while (!Empty())
	{
		minvertex = pop();
		if (minvertex->label == INFINITYVALUE)
		{
			cantarrived(start, minvertex,backcounting--);
			Sleep(50);
			continue;
		}//아무것도 변경 되지 않았을 경우
		paintFast(start, minvertex,counting);
		Sleep(50);
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
	//	FastLocationArray[counting] = minvertex;
		counting = counting + 1;
	}//Q가 빌때까지
	 //printFastest(FastLocationArray);
	QFree();
	//free(FastLocationArray);
	gotoxy(xy);
	system("pause");
}

void paintFast(Vertex* startVertex, Vertex* minVertex,int counting)
{
	changeColor(7);
	graphvertexX(counting);
	printf("%d", minVertex->key);
	graphdirect(startVertex->key, counting);
	printf("%d", minVertex->label);
	return;
}
void cantarrived(Vertex* startVertex, Vertex* minVertex,int backcounting)
{
	changeColor(7);
	graphvertexX(backcounting);
	printf("%d", minVertex->key);
	graphdirect(startVertex->key, backcounting);
	printf("X");
	return;
}