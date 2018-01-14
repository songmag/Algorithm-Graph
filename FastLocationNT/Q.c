#include"FtLNT.h"


//1. insertheap//다시 넣는 작업을 시행하지 않음.(무조껀 상향식 힙생성)
//2. deletheap(pop) //최소값을 추출해내는 메소드
//3. upheap 
//4. downheap
//최소힙으로 구현
//pop시에 실행해야 하는 작업
// 1. downheap
//insert시에 해야 하는 작업
//1. 삽입 시 마지막 원소에서 upheap 시행 // 상향식 생성으로 존재 X
//2. 맨 위로 올라온 경우 이제 downheap 실행(왼,오의 차이를 줄이기 위해)
// 시간복잡도  = upheap -> O(logN) + downheap -> O(logN) = O(logN)
// 비었는지 확인하는 작업
// 

void Qinit()
{
	int i;
	FastestCheck = (Q*)malloc(sizeof(Q));
	FastestCheck->heap = (int*)malloc(sizeof(int)*(drawgraph->Vsize + 1));
	FastestCheck->last = drawgraph->Vsize;
	
	for (i = 0; i < drawgraph->Vsize; i++)
	{
		FastestCheck->heap[i+1] = i + 1;
	}//size 의 값을 10개의 정점이 있는경우 10까지 존재(1~10까지)//key값
	HeapMakeToUp();
	return;
}

void HeapMakeToUp()
{
	int pointer;

	pointer = FastestCheck->last;

	while (parent(pointer) >= 1)
	{
		rdownheap(parent(pointer));
		pointer=pointer-2;
		//downheap
	}
}//상향식 힙생성
void rdownheap(int index)
{
	Vertex *pr_pointer, *lr_pointer;
	int savelr;

	if (index >= FastestCheck->last)
		return;
	pr_pointer = drawgraph->VArray->next;
	pr_pointer = FindAboutKey(index);
	lr_pointer = FindAboutKey(leftchild(index));
	
	savelr = 1;//left&&right를 확인하기 위한 변수
	if (rightchild(index) <= FastestCheck->last)
	{
		if (lr_pointer->label > FindAboutKey(rightchild(index))->label)
		{
			lr_pointer = FindAboutKey(rightchild(index));
			savelr = 2;
		}
	}
	if (pr_pointer->label <= lr_pointer->label)
	{
		return;
	}
	else
	{
		swapKey(lr_pointer->key,index, savelr);
		if (savelr == 1)
		{
			rdownheap(leftchild(index));
		}
		else if (savelr == 2)
		{
			rdownheap(rightchild(index));
		}
	}
}
void swapKey(int key, int index, int lrcheck)
{
	int savekey;
	if (lrcheck == 1)
	{
		savekey=FastestCheck->heap[leftchild(index)];
		FastestCheck->heap[index] = savekey;
		FastestCheck->heap[leftchild(index)] = key;
	}
	else if (lrcheck == 2)
	{
		savekey = FastestCheck->heap[rightchild(index)];
		FastestCheck->heap[index] = savekey;
		FastestCheck->heap[rightchild(index)] = key;
	}
}
void QFree()
{
	free(FastestCheck->heap);
	free(FastestCheck);
}
int pop()
{
	int savekey;
	int for_i;
	savekey = FastestCheck->heap[1];
	FastestCheck->heap[1] = FastestCheck->heap[FastestCheck->last];
	FastestCheck->last = FastestCheck->last - 1;
	for (for_i = 0; for_i < FastestCheck->last; for_i++)
	{
		rdownheap(1);
	}
	return savekey;
}
int Empty()
{
	return (FastestCheck->last == 0) ? 1 : 0;
}//비었으면 1(참),아니면 0;