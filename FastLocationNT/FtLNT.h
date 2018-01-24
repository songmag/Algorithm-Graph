#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include<time.h>
#include<conio.h>
#include<math.h>
//#include <pthread.h>

//������ �׷���

//������ 1���� �� �۾�
//�׷����� �Է� �ޱ�
//���� ���� Ȯ��

//������ 2���� �� �۾�
//�׷����� �����


//���ǻ���
//1. ����,����,��������Ʈ ���� HEAD�� ������ �����Ƿ�, ��� �۾� ����� next ó���� �� ���� ������
//2. ptr tail�� ���κ��� ��带 ����Ű�� �����Ƿ� ���� NULL���� ���� �ؾ� ��.

//label�� value ����
#define FRESH 10000
#define VISIT 200000
#define INFINITYVALUE 88888
#define MAX 15
//Q����
#define parent(x) x/2
#define leftchild(x) x*2
#define rightchild(x) (x*2)+1
//��� ����
#define defaultx 10
#define defaulty 3

typedef struct Graph {
	struct vertex *VArray;
	struct edge *EArray;
	struct vertex *insertV;
	struct edge *insertE;
	int Vsize;
	int Esize;
	struct PTR *Vptr;
	struct PTR *Eptr;
}G;
typedef struct vertex {
	struct vertex *next;
	struct vertex *front;
	struct Link *HEAD;
	int linksize;
	int key;
	char value[MAX];
	int label;
	int heapindex;
}Vertex;
//�� �Է��� ���ڿ��� �޴´�.
typedef struct edge {
	struct vertex *connect1;
	struct vertex *connect2;
	int value;
	struct edge* next;
	struct edge* front;
	int label;
}Edge;
typedef struct Link {
	struct Link *next;
	struct edge *EdgeInfo;
	struct PTR *Ptr;
}Link;
typedef struct PTR {
	void *HEAD;
	void *TAIL;
}PTR;
typedef struct Q {
	int *heap;//Ű�� ����
	int last;//������ index ����
}Q;
typedef void (*Divice)();

///////////////FastestLocation.c/////////////////
void insertVertex();//�����Է�
void insertEdge();//�����Է�
void Graphinit();//�׷��� �ʱ�ȭ
///////////////MainPage.c////////////////////////
void mainPage();
void graphinitprint();
void graphprintchoose();
void handdraw();
void application();
//����ó��//
int chooseDivice[2];//Main Page���� ���õ� �۾����� ����
G *drawgraph;
Q *FastestCheck;
//////////////divice.c///////////////////////////
int vertexcheck(char *);//���� ����� false, ������� true
int Edgecheck(Vertex *, Vertex *);//Edge�� �����ϴ��� Ȯ��
int minfind(Vertex *, Vertex *);//����Ǿ��ִ� ������ �����Ϳ��� Ž��
Vertex *findElem(char *);//���� ����Ʈ �� ���ҿ� �ش��ϴ� ���� ��ȯ
void vertexinit(char *);//���� insert�����ʱ�ȭ
void Edgeinput(Vertex *, Vertex *);//���� insert���� �ʱ�ȭ
Vertex *opposite(Vertex *, Link *);//�ݴ��� ���� ��ȯ
Vertex *EdgetoVertex(Vertex*, Edge *);//������ ���� �ݴ���
void insertlink(Vertex *,Vertex *);//��������Ʈ ����
Vertex *FindAboutKey(int key);

void printAll();
void setFastestinit();
void printFastest(Vertex**);
void randominsertVertex();
void insertEdgeAboutKey();//Ű���� ���� ���� ����
void paintVertex(Vertex*);
//////////////Q.c/////////////////////////////////
void Qinit();
void HeapMakeToUp();
void swapKey(int,int,int,Vertex*,Vertex*);
void QFree();
void rdownheap(int index);
Vertex* pop();
int Empty();
void printheap();
void replacevertex(Vertex *);
void upheap(int);
//////////DrawTable.c//////////////////////////
//////////�׷��� �׸���//////////////////////
void makeTable();
void drawtable();
void graphdirect(int, int);
void drawEmptyTable();
//////////consolecontrol/////////////////////
void gotoxy(COORD);
void right(COORD *xy, int maxsize);//���������� maxsize��ŭ�̵�
void down(COORD*);//�Ʒ������� 2��ŭ �̵�
void downindex(COORD *xy, int raws);//�Ʒ������� raws��ŭ �̵�
void changeColor(int color);//�÷�����
void graphvertexY(int key);
void graphvertexX(int key);
void paintFast(Vertex* startVertex, Vertex* minVertex);
void cantarrived(Vertex* startVertex, Vertex* minVertex);
//////////////FastLocation.c///////////////////////
void FastLocationValue();
void FastLocationKey();
/////////////DFS.c/////////////////////////////////
void DFS(Vertex*);
void RDFS(Vertex*);