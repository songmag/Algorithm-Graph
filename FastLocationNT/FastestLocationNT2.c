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
			Sleep(1000);
			insertVertex();
			system("cls");
			break;
		case 2:
			system("cls");
			insertEdge();
			Sleep(1000);
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
	//그래프 초기화
	drawgraph->VArray->Ptr = (PTR*)malloc(sizeof(PTR));
	drawgraph->VArray->Ptr->HEAD = drawgraph->VArray;
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
	drawgraph->VArray->next = (Vertex*)malloc(sizeof(Vertex));
	drawgraph->VArray->Ptr->TAIL = drawgraph->VArray->next;
	drawgraph->VArray->linksize = 0;
	//정점
	drawgraph->EArray->connect1 = NULL;
	drawgraph->EArray->connect2 = NULL;
	drawgraph->EArray->value = 0;
	drawgraph->EArray->next = (Edge*)malloc(sizeof(Edge));
	drawgraph->EArray->Ptr = (PTR*)malloc(sizeof(PTR));
	drawgraph->EArray->Ptr->HEAD = drawgraph->EArray;
	drawgraph->EArray->Ptr->TAIL = drawgraph->EArray->next;
	//간선
	drawgraph->insertV = drawgraph->VArray->Ptr->TAIL;
	drawgraph->insertV->front = drawgraph->VArray->HEAD;
	for (i = 0; i < MAX; i++)
	{
		drawgraph->insertV->value[i] = 0;
	}
	drawgraph->insertV->next = NULL;
	drawgraph->insertV->linksize = 0;

	drawgraph->insertE = drawgraph->EArray->Ptr->TAIL;
	drawgraph->insertE->front = drawgraph->EArray->Ptr->HEAD;
	drawgraph->insertE->next = NULL;
}