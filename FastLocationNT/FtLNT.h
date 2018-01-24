#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include<time.h>
#include<conio.h>
#include<math.h>
//#include <pthread.h>

//무방향 그래프

//쓰레드 1에서 할 작업
//그래프의 입력 받기
//시작 지점 확인

//쓰레드 2에서 할 작업
//그래프의 드로잉


//주의사항
//1. 정점,간선,인접리스트 전부 HEAD를 가지고 있으므로, 모든 작업 수행시 next 처리를 한 것이 시작점
//2. ptr tail은 끝부분의 노드를 가리키고 있으므로 다음 NULL까지 수행 해야 함.

//label과 value 설정
#define FRESH 10000
#define VISIT 200000
#define INFINITYVALUE 88888
#define MAX 15
//Q설정
#define parent(x) x/2
#define leftchild(x) x*2
#define rightchild(x) (x*2)+1
//배경 설정
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
//값 입력은 문자열로 받는다.
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
	int *heap;//키를 저장
	int last;//마지막 index 저장
}Q;
typedef void (*Divice)();

///////////////FastestLocation.c/////////////////
void insertVertex();//정점입력
void insertEdge();//간선입력
void Graphinit();//그래프 초기화
///////////////MainPage.c////////////////////////
void mainPage();
void graphinitprint();
void graphprintchoose();
void handdraw();
void application();
//전역처리//
int chooseDivice[2];//Main Page에서 선택된 작업으로 변동
G *drawgraph;
Q *FastestCheck;
//////////////divice.c///////////////////////////
int vertexcheck(char *);//정점 존재시 false, 미존재시 true
int Edgecheck(Vertex *, Vertex *);//Edge가 존재하는지 확인
int minfind(Vertex *, Vertex *);//연결되어있는 간선이 적은것에서 탐색
Vertex *findElem(char *);//정점 리스트 중 원소에 해당하는 정점 반환
void vertexinit(char *);//다음 insert정점초기화
void Edgeinput(Vertex *, Vertex *);//다음 insert간선 초기화
Vertex *opposite(Vertex *, Link *);//반대쪽 정점 반환
Vertex *EdgetoVertex(Vertex*, Edge *);//간선을 통한 반대쪽
void insertlink(Vertex *,Vertex *);//인접리스트 구현
Vertex *FindAboutKey(int key);

void printAll();
void setFastestinit();
void printFastest(Vertex**);
void randominsertVertex();
void insertEdgeAboutKey();//키값을 통한 간선 생성
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
//////////그래프 그리기//////////////////////
void makeTable();
void drawtable();
void graphdirect(int, int);
void drawEmptyTable();
//////////consolecontrol/////////////////////
void gotoxy(COORD);
void right(COORD *xy, int maxsize);//오른쪽으로 maxsize만큼이동
void down(COORD*);//아래쪽으로 2만큼 이동
void downindex(COORD *xy, int raws);//아래쪽으로 raws만큼 이동
void changeColor(int color);//컬러변경
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