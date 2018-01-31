#include"ftLNT.h"


void Bfs()
{
	bfs_struct *m_bfs_struct;
	
	informationHT *HT;
	Vertex *startVertex,*m_pointer,*m_opposite_pointer;
	
	Link *m_Vlink;
	int key,count;

	count = 0;
	drawEmptyTable();
	startVertex = Bfsinit();
	m_bfs_struct = (bfs_struct*)malloc(sizeof(bfs_struct)*drawgraph->Vsize);

	HT = (informationHT*)malloc(sizeof(informationHT));
	m_opposite_pointer = NULL;
	listinit(startVertex, HT);
	while (!Ls_empty(HT))
	{ 
		m_pointer = deletfirstlist(HT);
		m_Vlink=m_pointer->HEAD->next;
		while (m_Vlink != NULL)
		{
			if (m_Vlink->EdgeInfo->label != VISIT)
			{
				m_opposite_pointer = opposite(m_pointer, m_Vlink);

				if (m_opposite_pointer->label != VISIT && m_opposite_pointer->label != TREEEDGE)
				{
					m_bfs_struct[count].before = m_pointer;
					inlist(m_opposite_pointer, HT);
					m_bfs_struct[count].after = m_opposite_pointer;
					BfsWork(m_bfs_struct, count);
					count += 1;
					m_Vlink->EdgeInfo->label = VISIT;
					Sleep(500);
				}
			}
			m_Vlink = m_Vlink->next;
		}
	}
	system("pause");
}
void BfsWork(bfs_struct *bfs_after,int count)
{
	bfs_after[count].after->label = VISIT;
	bfs_after[count].before->label = TREEEDGE;
	graphdirect(bfs_after[count].before->key, bfs_after[count].after->key);
	printf("%d", count+1);
}
Vertex *Bfsinit()
{
	int key;
	COORD xy;
	Vertex *startVertex,*m_pointer;
	Edge *m_Epointer;
	xy.X = 0;
	xy.Y = 0;
	gotoxy(xy);
	
	m_pointer = drawgraph->VArray->next;
	m_Epointer = drawgraph->EArray->next;
	while (m_pointer != NULL)
	{
		m_pointer->label = FRESH;
		m_pointer = m_pointer->next;
	}
	while (m_Epointer != NULL)
	{
		m_Epointer->label = FRESH;
		m_Epointer = m_Epointer->next;
	}
	graphdirect(15,0) ;
	printf("insert start VertexKey :");
	scanf(" %d", &key);
	startVertex = FindAboutKey(key);
	return startVertex;
}


void listinit(Vertex *start,informationHT *HT)
{
	listQ *m_list;
	m_list = (listQ*)malloc(sizeof(listQ));
	m_list->elem = NULL;
	m_list->next = (listQ*)malloc(sizeof(listQ));
	m_list->front = NULL;
	HT->head = m_list;
	m_list = m_list->next;
	m_list->elem = start;
	m_list->next = (listQ*)malloc(sizeof(listQ));
	m_list->front = HT->head;
	
	m_list->next->elem = NULL;
	m_list->next->next = NULL;
	m_list->next->front = m_list;
	HT->tail = m_list->next;
	return m_list;
}//queueinit
void inlist(Vertex *insertlist,informationHT *HT)
{
	listQ *new_list;
	
	new_list = (listQ*)malloc(sizeof(listQ));
	new_list->elem = insertlist;
	new_list->next = HT->tail;
	new_list->front = HT->tail->front;
	HT->tail->front->next = new_list;
	HT->tail->front = new_list;
	return;
}//inqueue
Vertex *deletfirstlist(informationHT *HT)
{
	Vertex *firstelem;
	listQ *free_pointer;
	free_pointer = HT->head->next;

	firstelem = free_pointer->elem;
	free_pointer->front->next = free_pointer->next;
	free_pointer->next->front = free_pointer->front;
	free(free_pointer);
	return firstelem;
}//dequeue
int Ls_empty(informationHT *HT)
{
	return (HT->head->next == HT->tail) ? 1 : 0;
}//비었으면 0,아니면 1