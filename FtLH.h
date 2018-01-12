#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
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
typedef struct Graph {
	struct vertex *VArray;
	struct edge *EArray;
	int Vsize;
	int Esize;
}G;
typedef struct vertex {
	struct vertex *next;
	struct Link *HEAD;
	int key;
	char value;
	int label;
}Vertex;
//값 입력은 문자열로 받는다.
typedef struct edge {
	int connect1;
	int connect2;
	int value;
	struct edge* next;
}Edge;
typedef struct Link {
	struct Link *next;
	int edgenumber;
}Link;

typedef void (*Divice)();