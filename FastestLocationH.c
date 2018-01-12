#include"FtLH.h"

G *drawgraph;

void main()
{
	Graphinit();
}
void Graphinit()
{
	drawgraph = (G*)malloc(sizeof(G));
	drawgraph->VArray = (Vertex*)malloc(sizeof(Vertex));
	drawgraph->EArray = (Edge*)malloc(sizeof(Edge));
	drawgraph->Vsize = 0;
	drawgraph->EArray = 0;
	//그래프 초기화
	drawgraph->VArray->HEAD = (Link*)malloc(sizeof(Link));
	drawgraph->VArray->key = 0;
	drawgraph->VArray->value = 0;
	drawgraph->VArray->label = INFINITE;
	drawgraph->VArray->next = NULL;
	//정점
	drawgraph->EArray->connect1 = 0;
	drawgraph->EArray->connect2 = 0;
	drawgraph->EArray->value = 0;
	drawgraph->EArray->next = NULL;
	//간선
}
void insertVertex()
{
	Vertex **V_pointer;
	*V_pointer = vertexEnd();
	printf("값 입력 :");
	scanf("%d", &(*V_pointer)->value);
	(*V_pointer)->key = drawgraph->Vsize+1;
	drawgraph->Vsize = drawgraph->Vsize + 1;
	NewVertex(&V_pointer);
	return;
}//정점 삽입
void insertEdge()
{

}


int findkey(char value)
{
	
}//리턴값 -> Value에 맞는 key값(key는 for loop을 돌기위한 자리) return;


void NewVertex(Vertex ***V_pointer)
{
	(**V_pointer)->next = NULL;
	(**V_pointer)->HEAD = (Link*)malloc(sizeof(Link));
	(**V_pointer)->label = INFINITE;
	return;
}
Vertex* VertexEnd()
{
	Vertex *V_pointer;

	V_pointer = drawgraph->VArray;
	while(V_pointer->next != NULL)
	{
		V_pointer = drawgraph->VArray->next;
		if (drawgraph->VArray->next != NULL)
		{
			if (V_pointer->key - V_pointer->next->key >= 2)
			{
				break;
			}
		}
	}
	return V_pointer;
}