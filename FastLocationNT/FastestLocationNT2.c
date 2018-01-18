#include "FtLNT.h"

void main()
{
	COORD xy;
	Divice command;
	Graphinit();
	xy.X = 0;
	xy.Y = 0;
	while (1)
	{
		mainPage();
		command = NULL;
		switch (chooseDivice[0])
		{
		case 1:
			graphinitprint();
			break;
		case 2:
			graphprintchoose();
			//graphprintchoose();그래프 출력선택
			break;
		case 3:
			application();
			break;
		case 4:
			return;
		default:
			printf("정확한 값을 입력해주세요 \n");
			break;
		}
		if (command == NULL)
		{
			continue;
		}
		system("cls");
		command();
		system("cls");
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
	drawgraph->VArray->label = INFINITY;
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