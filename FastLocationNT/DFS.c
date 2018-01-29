#include"FtLNT.h"

void DfsDraw()
{
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
	dfs_struct *key_Array;
	int count;
	key_Array = (dfs_struct*)malloc(sizeof(dfs_struct)*((drawgraph->Vsize)*(drawgraph->Vsize-1)/2));

	Dfsinit(key_Array);
	count = 0;
	
	mv_pointer = FindAboutKey(key);
	key_Array[0].before = mv_pointer->key;
	RDfs(mv_pointer,key_Array,&count);
	
	Dfsprint(key_Array,count);
	free(key_Array);
	system("pause");
	return;
}
void RDfs(Vertex* oppositevertex,dfs_struct *keyArray,int *count)
{
	Link *mv_link;
	
	if (oppositevertex->label == VISIT)
	{
		return;
	}
	keyArray[(*count)++].after = oppositevertex->key;
	oppositevertex->label = VISIT;
	mv_link=oppositevertex->HEAD->next;
	
	while (mv_link != NULL)
	{
		if (mv_link->EdgeInfo->label != VISIT)
		{
			mv_link->EdgeInfo->label = VISIT;
			keyArray[(*count)].before = oppositevertex->key;
			RDfs(opposite(oppositevertex,mv_link),keyArray,&(*count));
			mv_link = mv_link->next;
		}
		else
		{
			mv_link = mv_link->next;
		}
	}
}
void Dfsinit(dfs_struct *keyArray)
{
	Vertex *mv_pointer;
	Edge *mv_Epointer;
	int i;
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
	for (i = 0; i < ((drawgraph->Vsize)*(drawgraph->Vsize - 1) / 2); i++)
	{
		keyArray[i].after = FRESH;
		keyArray[i].before = FRESH;
	}
}
void Dfsprint(dfs_struct *keyArray,int dfs_count)
{
	int i;
	int count;
	count = 0;
	i = 0;
	graphdirect(keyArray[i].after, keyArray[i].before);
	printf("%d", count);
	for (; i< dfs_count; i++)
	{
		if (keyArray[i].after == FRESH)
		{
			break;
		}
		graphdirect(keyArray[i].before, keyArray[i].after);
		printf("%d", ++count);
		Sleep(300);
	}
	graphvertexY(20);
}