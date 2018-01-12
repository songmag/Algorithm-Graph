#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include<time.h>
//#include <pthread.h>

//방향 그래프
//방향 그래프 최단경로 지정
//위상정렬 실시

//쓰레드 1에서 할 작업
//그래프의 입력 받기
//시작 지점 확인

//쓰레드 2에서 할 작업
//그래프의 드로잉
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
//값 입력은 문자열로 받는다.
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
int chooseDivice;//Main Page에서 선택된 작업으로 변동
typedef void (*Divice)();
///////////////FastestLocation.c/////////////////
void insertVertex();//정점입력
int vertexcheck(char *value);//정점 존재시 false, 미존재시 true
void insertEdge();//간선입력
int Edgecheck(Vertex *firstvertex, Vertex *secondvertex);//Edge가 존재하는지 확인
int minfind(Vertex *, Vertex *);//연결되어있는 간선이 적은것에서 탐색
Vertex *findElem(char *);//정점 리스트 중 원소에 해당하는 정점 반환
void Graphinit();//그래프 초기화
void vertexinit(char *);//다음 insert정점초기화
void Edgeinput(Vertex *,Vertex *);//다음 insert간선 초기화
Vertex *opposite(Vertex *startvertex, Link *startlink);//반대쪽 정점 반환
void GraphDevice(Divice work);
void insertlink(Vertex *insertvertex);
///////////////MainPage.c////////////////////////
void mainPage();
void gotoxy(COORD xy);
///////////////END///////////////////////////////
//전역처리//
void printAll();
G *drawgraph;