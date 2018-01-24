#include"FtLNT.h"

void FastLocationValue()
{
	char A[MAX];
	int counting;

	Vertex *start, *minvertex, *oppositevertex;
	Vertex **FastLocationArray;
	Link *mv_pointer;

	FastLocationArray = (Vertex**)malloc(sizeof(Vertex*)*drawgraph->Vsize);
	counting = 0;
	setFastestinit();
	drawEmptyTable();
	printf("���� ���� :");
	scanf("%s", &A);
	start = findElem(A);
	if (start == NULL)
	{
		printf("��� ������ �����ϴ�.");
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
			cantarrived(start, minvertex);
			continue;
		}//�ƹ��͵� ���� ���� �ʾ��� ���
		paintFast(start, minvertex);
		Sleep(500);
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
	}//Q�� ��������
	 //printFastest(FastLocationArray);
	QFree();
	free(FastLocationArray);
	system("pause");
}

void FastLocationKey()
{
	int key;
	int counting;

	Vertex *start, *minvertex, *oppositevertex;
	Vertex **FastLocationArray;
	Link *mv_pointer;

	FastLocationArray = (Vertex**)malloc(sizeof(Vertex*)*drawgraph->Vsize);
	counting = 0;
	setFastestinit();
	drawEmptyTable();
	printf("���� ���� :");
	scanf("%d", &key);
	start = FindAboutKey(key);
	if (start == NULL)
	{
		printf("��� ������ �����ϴ�.");
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
			cantarrived(start, minvertex);
			continue;
		}//�ƹ��͵� ���� ���� �ʾ��� ���
		paintFast(start, minvertex);
		Sleep(500);
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
	}//Q�� ��������
	 //printFastest(FastLocationArray);
	QFree();
	free(FastLocationArray);
	system("pause");
}