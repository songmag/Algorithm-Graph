#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
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
//�� �Է��� ���ڿ��� �޴´�.
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