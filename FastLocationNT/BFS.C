#include"ftLNT.h"

typedef struct listQ {
	Vertex *elem;
	struct listQ *next;
	struct listQ *front;
}listQ;
typedef struct informationHT {
	struct listQ *head;
	struct listQ *tail;
}informationHT;

void Bfs()
{
	bfs_struct *m_bfs_struct;
	
	informationHT *HT;
	Vertex *startVertex,*m_pointer,*m_opposite_pointer;
	
	Link *m_Vlink;
	int key;
	drawEmptyTable();
	startVertex = Bfsinit();
	HT = (informationHT*)malloc(sizeof(informationHT));
	listinit(startVertex, HT);
	while (!Ls_empty(HT))
	{
		m_pointer = deletfirstlist(HT);
		m_Vlink=m_pointer->HEAD->next;
		while (m_Vlink != NULL)
		{
			m_opposite_pointer = opposite(m_pointer, m_Vlink);
			inlist(m_opposite_pointer, HT);

			m_Vlink = m_Vlink;
		}
	}

}
void BfsWork(bfs_struct *bfs_after,int count)
{
	bfs_after->after->label = VISIT;
	bfs_after->before->label = TREEEDGE;
	graphdirect(bfs_after->before->key, bfs_after->after->key);
	printf("%d", count);
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

	printf("insert start VertexKey :");
	scnaf(" %d", &key);
	startVertex = findAboutKey(key);
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
	HT->tail->front = new_list;
	return;
}//inqueue
Vertex *deletfirstlist(informationHT *HT)
{
	Vertex *firstelem;
	listQ *free_pointer;
	firstelem = HT->head->next->elem;
	free_pointer = HT->head->next;
	free_pointer->front->next = free_pointer->next;
	free_pointer->next->front = free_pointer->front;
	free(free_pointer);
	return firstelem;
}//dequeue
int Ls_empty(informationHT *HT)
{
	(HT->head->next == HT->tail) ? 1 : 0;
}//비었으면 1,아니면 0