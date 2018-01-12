#include "FtLNT.h"

void main()
{
	Graphinit();
	while (1)
	{
		mainPage();
		switch (chooseDivice)
		{
		case 1:
			system("cls");
			insertVertex();
			system("cls");
			break;
		case 2:
			system("cls");
			insertEdge();
			system("cls");
			//insertEdge();
			break;
		case 3:
			printAll();
			break;
		case 4:
			break;
		case 5:
			break;
		}
	}
}
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
	drawgraph->VArray->label = INFINITE;
	drawgraph->VArray->linksize = 0;
	drawgraph->VArray->next = NULL;
	//정점
	drawgraph->EArray->connect1 = NULL;
	drawgraph->EArray->connect2 = NULL;
	drawgraph->EArray->value = 0;
	drawgraph->EArray->next = NULL;
	//간선
}