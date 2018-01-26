#include"FtLNT.h"

void makeTable()
{
	drawtable();
	system("pause");
}
void drawtable()
{
	int i,key;
	Vertex *move_vertex;
	COORD xy;
	Link *move_link;
	move_vertex = drawgraph->VArray->next;
	move_link = move_vertex->HEAD->next;
	for (i = 1; i <= drawgraph->Vsize; i++)
	{
		changeColor(5+i);
		xy.X = i*4;
		xy.Y = 0;
		gotoxy(xy);
		printf("%d", move_vertex->key);
		xy.X = 0;
		xy.Y = i;
		gotoxy(xy);
		printf("%d", move_vertex->key);
		changeColor(15);
		move_link = move_vertex->HEAD->next;
		while (move_link != NULL)
		{
			key = opposite(move_vertex, move_link)->key;
			xy.X = i * 4;
			xy.Y = key;
			gotoxy(xy);
			printf("%d", move_link->EdgeInfo->value);
			move_link = move_link->next;
		}
		move_vertex = move_vertex->next;
	}
	down(&xy);
	changeColor(15);
}
void drawEmptyTable()
{
	int i, key;
	Vertex *move_vertex;
	COORD xy;
	Link *move_link;
	move_vertex = drawgraph->VArray->next;
	move_link = move_vertex->HEAD->next;
	for (i = 1; i <= drawgraph->Vsize; i++)
	{
		changeColor(5 + i);
		xy.X = i * 4;
		xy.Y = 0;
		gotoxy(xy);
		printf("%d", move_vertex->key);
		xy.X = 0;
		xy.Y = i;
		gotoxy(xy);
		printf("%d", move_vertex->key);
		move_vertex = move_vertex->next;
	}
	down(&xy);
}
void drawEmptyTableY()
{
	int i, key;
	Vertex *move_vertex;
	COORD xy;
	Link *move_link;
	move_vertex = drawgraph->VArray->next;
	move_link = move_vertex->HEAD->next;
	for (i = 1; i <= drawgraph->Vsize; i++)
	{
		changeColor(5 + i);
		xy.X = 0;
		xy.Y = i;
		gotoxy(xy);
		printf("%d", move_vertex->key);
		move_vertex = move_vertex->next;
	}
	down(&xy);
}