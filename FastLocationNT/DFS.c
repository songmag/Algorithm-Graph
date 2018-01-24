#include"FtLNT.h"

void DFSDraw()
{
	COORD xy;
	int key;
	drawEmptyTable();
	printf("시작점 입력");
	scanf("%d", &key);
	graphvertexX(key);
	graphvertexY(key);
	DFS(key);

}

void DFS(int key)
{
	Vertex *mv_pointer;
	Edge *mv_Epointer;
	mv_pointer = drawgraph->VArray->next;
	mv_Epointer = drawgraph->EArray->next;
	while (mv_pointer != NULL)
	{
		mv_pointer->label = FRESH;
	}
	while (mv_Epointer != NULL)
	{
		mv_Epointer->label = FRESH;
	}
}
void RDFS(Vertex* rvertex)
{

}
