#include"FtLNT.h"

void example1()
{
	insert_fix_value("1");
	insert_fix_value("2");
	insert_fix_value("3");
	insert_fix_value("4");
	insert_fix_value("5");
	insert_fix_value("6");

	insert_fix_Edge("1", "2", 0);
	insert_fix_Edge("1", "3", 0);
	insert_fix_Edge("2", "4", 0);
	insert_fix_Edge("2", "5", 0);
	insert_fix_Edge("3", "4", 0);
	insert_fix_Edge("3", "6", 0);
	insert_fix_Edge("5", "2", 0);
	insert_fix_Edge("5", "6", 0);
}
void example2() {
	insert_fix_value("1");
	insert_fix_value("2");
	insert_fix_value("3");
	insert_fix_value("4");
	insert_fix_value("5");
	insert_fix_value("6");
	insert_fix_value("7");
	insert_fix_value("8");

	insert_fix_Edge("1", "2", 0);
	insert_fix_Edge("1", "3", 0);
	insert_fix_Edge("2", "4", 0);
	insert_fix_Edge("2", "5", 0);
	insert_fix_Edge("3", "6", 0);
	insert_fix_Edge("3", "7", 0);
	insert_fix_Edge("4", "8", 0);
	insert_fix_Edge("5", "8", 0);
	insert_fix_Edge("6", "8", 0);
	insert_fix_Edge("7", "8", 0);
}
void example3() {
	insert_fix_value("a");
	insert_fix_value("b");
	insert_fix_value("c");
	insert_fix_value("d");
	insert_fix_value("e");
	insert_fix_value("f");
	insert_fix_value("g");

	insert_fix_Edge("a", "b", 7);
	insert_fix_Edge("a", "d", 5);
	insert_fix_Edge("b", "c", 8);
	insert_fix_Edge("b", "e", 5);
	insert_fix_Edge("b", "d", 9);
	insert_fix_Edge("d", "e", 15);
	insert_fix_Edge("d", "f", 6);
	insert_fix_Edge("e", "f", 8);
	insert_fix_Edge("f", "g", 11);
	insert_fix_Edge("e", "g", 9);
}
void example4() {
	insert_fix_value("a");
	insert_fix_value("b");
	insert_fix_value("c");
	insert_fix_value("d");
	insert_fix_value("e");

	insert_fix_Edge("a", "b", 3);
	insert_fix_Edge("a", "d", 3);
	insert_fix_Edge("a", "c", 6);
	insert_fix_Edge("c", "d", 2);
	insert_fix_Edge("b", "d", 1);
	insert_fix_Edge("b", "e", 4);
	insert_fix_Edge("d", "e", 2);
}
void insert_fix_value(char *value)
{
	char insertValue[MAX];

	strcpy(insertValue, value);
	if (vertexcheck(insertValue))
	{
		if (drawgraph->insertV == (Vertex*)drawgraph->Vptr->TAIL)
			vertexinit(insertValue);
	}
	return;
}//정점 삽입

void insert_fix_Edge(char *key1, char *key2, int insert_weight)
{
	char A[MAX], B[MAX];
	int weight;
	Vertex *connect1;
	Vertex *connect2;
	
	connect1 = drawgraph->VArray;
	connect2 = drawgraph->VArray;

	strcpy(A, key1);
	strcpy(B, key2);
	connect1 = findElem(A);
	connect2 = findElem(B);
	weight = insert_weight;
	if (Edgecheck(connect1, connect2))
	{
		if (weight != 0)
		{
			Edgeinputofweight(connect1, connect2, weight);
		}
		else
		{
			Edgeinput(connect1, connect2);
		}
		insertlink(connect1, connect2);
		insertlink(connect2, connect1);
	}//연결되어있는 간선이 없는경우에만 시행
	else
	{
		return;
	}
	return;
}//간선 삽입