#include"FtLNT.h"

void DfsDraw()
{
	COORD xy;
	int key;
	drawEmptyTable();
	printf("시작점 입력");
	scanf("%d", &key);
	if (FindAboutKey(key) == NULL)
	{
		printf("존재하지 않는 키입니다.");
		system("pause");
		return;
	}
	graphvertexX(key);
	graphvertexY(key);
	Dfs(key);

}

void Dfs(int key)
{
	Vertex *mv_pointer;
	//Link *mv_link;
	int count;
	count = 0;
	system("cls");
	Dfsinit();
	
	mv_pointer = FindAboutKey(key);
	RDfs(mv_pointer, &count);
	/*mv_pointer->label = VISIT;
	mv_link = mv_pointer->HEAD->next;
	while (mv_link != NULL)
	{
		if (mv_link->EdgeInfo->label != VISIT)
		{
			printf("key >> %d count>> %d\n", mv_pointer->key, count);
			mv_link->EdgeInfo->label = VISIT;
			RDfs(opposite(mv_pointer, mv_link), &count);
			mv_link = mv_link->next;
		}
		else
		{
			mv_link = mv_link->next;
		}
	}*/
	system("pause");
	return;
}
void RDfs(Vertex* oppositevertex,int *count)
{
	Link *mv_link;
	(*count) += 1;
	
	if (oppositevertex->label == VISIT)
	{
		return;
	}
	
	oppositevertex->label = VISIT;
	
	mv_link=oppositevertex->HEAD->next;
	
	while (mv_link != NULL)
	{
		if (mv_link->EdgeInfo->label != VISIT)
		{
			mv_link->EdgeInfo->label = VISIT;
			printf("key >> %d count>> %d\n", oppositevertex->key, (*count));
	        RDfs(opposite(oppositevertex,mv_link),&(*count));
			mv_link = mv_link->next;
		}
			else
			mv_link = mv_link->next;
	}
}
void Dfsinit()
{
	Vertex *mv_pointer;
	Edge *mv_Epointer;
	mv_pointer = drawgraph->VArray->next;
	mv_Epointer = drawgraph->EArray->next;
	while (mv_pointer != NULL)
	{
		mv_pointer->label = FRESH;
		mv_pointer = mv_pointer->next;
	}
	while (mv_Epointer != NULL)
	{
		mv_Epointer->label = FRESH;

		mv_Epointer = mv_Epointer->next;
	}
}