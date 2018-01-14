#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include<time.h>
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

#define FRESH 10000
#define VISIT 200000
#define INFINITE 88888
#define MAX 15
#define parent(x) x/2
#define leftchild(x) x*2
#define rightchild(x) (x*2)+1

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
	
}Vertex;
//�� �Է��� ���ڿ��� �޴´�.
typedef struct edge {
	struct vertex *connect1;
	struct vertex *connect2;
	int value;
	struct edge* next;
	struct edge* front;
	
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
int chooseDivice;//Main Page���� ���õ� �۾����� ����
typedef void (*Divice)();
///////////////FastestLocation.c/////////////////
void insertVertex(COORD);//�����Է�
void insertEdge(COORD);//�����Է�
void Graphinit();//�׷��� �ʱ�ȭ
///////////////MainPage.c////////////////////////
void mainPage();
void gotoxy(COORD);
///////////////END///////////////////////////////
//����ó��//
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
void FastLocation();
void printAll();
//////////////Q.c/////////////////////////////////
void Qinit();
void HeapMakeToUp();
void swapKey(int,int,int);
void QFree();
void rdownheap(int index);
int pop();
int Empty();