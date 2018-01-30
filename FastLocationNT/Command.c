#include"FtLNT.h"
void insertVertex()
{
	COORD xy;
	char insertValue[MAX];
	
	xy.X = 0;
	xy.Y = 0;

	gotoxy(xy);
	printf("값을 입력하시오 : ");
	scanf("%s",&insertValue);
	if (vertexcheck(insertValue))
	{
		if (drawgraph->insertV == (Vertex*)drawgraph->Vptr->TAIL)
			vertexinit(insertValue);
		else
		{
			//삭제하고 넣는경우
			//insertbetween(drawgraph->insertV->next,(drawgraph->insertV->next->key)-1);
		}
	}
	else
	{
		xy.Y += 1;
		gotoxy(xy);
		printf("정점이 존재합니다.\n");
		return;
	}
	return;
}//정점 삽입
void insertEdge()
{
	char A[MAX],B[MAX];
	int weight;
	Vertex *connect1;
	Vertex *connect2;
	COORD xy;
	xy.X = 0;
	xy.Y = 0;
	
	gotoxy(xy);

	connect1 = drawgraph->VArray;
	connect2 = drawgraph->VArray;

	printf("정점1 입력 :");
	scanf("%s", &A);
	down(&xy);
	printf("정점2 입력 :");
	scanf("%s", &B);
	connect1 = findElem(A);
	connect2 = findElem(B);
	down(&xy);
	printf("간선 weight 입력 : ");
	scanf("%d", &weight);
	if (connect1 == NULL || connect2 == NULL)
	{
		xy.Y+=1;
		gotoxy(xy);
		printf("정점이 없습니다. 재 입력 부탁드립니다.\n");
		system("pause");
		return;
	}
	if(Edgecheck(connect1, connect2))
	{
		if (weight != 0)
		{
			Edgeinputofweight(connect1, connect2, weight);
		}
		else
		{
			Edgeinput(connect1, connect2);
		}
		insertlink(connect1,connect2);
		insertlink(connect2,connect1);		
	}//연결되어있는 간선이 없는경우에만 시행
	else
	{
		xy.Y +=1;
		gotoxy(xy);
		printf("간선이 존재합니다.");
		system("pause");
		return;
	}
	return;
}//간선 삽입
void insertEdgeAboutKey()
{
	int key1, key2,weight;
	Vertex *ver1, *ver2;
	COORD xy;
	xy.X = 0;
	xy.Y = 0;
	gotoxy(xy);
	printf("1번 Key 값 입력 :");
	scanf(" %d", &key1);
	down(&xy);
	printf("2번 key 값 입력 :");
	scanf(" %d", &key2);
	down(&xy);
	printf("weight 입력 : ");
	scanf(" %d", &weight);
	ver1 = FindAboutKey(key1);
	ver2 = FindAboutKey(key2);
	if (ver1 != NULL && ver2 != NULL &&Edgecheck(ver1, ver2))
	{
		if (weight != 0)
		{
			Edgeinputofweight(ver1, ver2, weight);
		}
		else
			Edgeinput(ver1, ver2);
		insertlink(ver1, ver2);
		insertlink(ver2, ver1);
	}
	else if (ver1 == NULL)
	{
		printf("key>> %d는 존재하지 않습니다.\n", key1);
		system("pause");
		return;
	}
	else if (ver2 == NULL)
	{
		printf("key>> %d는 존재하지 않습니다.\n", key2);
		system("pause");
		return;
	}
	else
	{
		printf("존재하는 간선입니다.");
		system("pause");
		return;
	}
}//키를 이용한 간선삽입
void printAll()
{
	Link *mv_pointer;
	Vertex *k;
	k = drawgraph->VArray->next;
	while (k != NULL)
	{
		printf("Key >> %d, Value >> %s \n",
			k->key, k->value);
		mv_pointer = k->HEAD->next;
		while (mv_pointer != NULL)
		{
			printf("Connect>> %s weight >> %d", opposite(k, mv_pointer)->value,mv_pointer->EdgeInfo->value);
			mv_pointer = mv_pointer->next;
			printf("\n");
		}
		k = k->next;
		printf("\n");
	} 
	system("pause");
}

int CycleCheck(){
}
int PrimAlgo() {

}
