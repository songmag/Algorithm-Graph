#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include<time.h>
//#include <pthread.h>

//���� �׷���
//���� �׷��� �ִܰ�� ����
//�������� �ǽ�

//������ 1���� �� �۾�
//�׷����� �Է� �ޱ�
//���� ���� Ȯ��

//������ 2���� �� �۾�
//�׷����� �����
#define FRESH 10000
#define VISIT 200000
#define INFINITE 889888
#define MAX 15
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
int chooseDivice;//Main Page���� ���õ� �۾����� ����
typedef void (*Divice)();
///////////////FastestLocation.c/////////////////
void insertVertex();//�����Է�
int vertexcheck(char *value);//���� ����� false, ������� true
void insertEdge();//�����Է�
int Edgecheck(Vertex *firstvertex, Vertex *secondvertex);//Edge�� �����ϴ��� Ȯ��
int minfind(Vertex *, Vertex *);//����Ǿ��ִ� ������ �����Ϳ��� Ž��
Vertex *findElem(char *);//���� ����Ʈ �� ���ҿ� �ش��ϴ� ���� ��ȯ
void Graphinit();//�׷��� �ʱ�ȭ
void vertexinit(char *);//���� insert�����ʱ�ȭ
void Edgeinput(Vertex *,Vertex *);//���� insert���� �ʱ�ȭ
Vertex *opposite(Vertex *startvertex, Link *startlink);//�ݴ��� ���� ��ȯ
void GraphDevice(Divice work);
void insertlink(Vertex *insertvertex);
///////////////MainPage.c////////////////////////
void mainPage();
void gotoxy(COORD xy);
///////////////END///////////////////////////////
//����ó��//
void printAll();
G *drawgraph;