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
	Vertex *mv_pointer;
	FastestCheck = (Q*)malloc(sizeof(Q));
	FastestCheck->heap = (int*)malloc(sizeof(int)*(drawgraph->Vsize + 1));
	FastestCheck->last = drawgraph->Vsize;
	mv_pointer = drawgraph->VArray->next;
	for (i = 0; i < drawgraph->Vsize; i++)
	{
		FastestCheck->heap[i+1] = i + 1;
		mv_pointer->heapindex = i+1;
		mv_pointer = mv_pointer->next;
	}//size 의 값을 10개의 정점이 있는경우 10까지 존재(1~10까지)//key값
	HeapMakeToUp();
	return;
}

void HeapMakeToUp()
{
	int pointer;

	pointer = FastestCheck->last;

	while (pointer >= 1)
	{
		if (parent(pointer) == 0)
		{
			rdownheap(1);
			break;
		}
		else {
			rdownheap(parent(pointer));
			pointer = parent(pointer) - 1;
		}//downheap
	}
}//상향식 힙생성
void printheap()
{
	int i;
	for (i = 0; i < FastestCheck->last; i++)
	{
		printf("%d ", FastestCheck->heap[i + 1]);
	}
}
void rdownheap(int index)
{
	Vertex *pr_pointer, *lr_pointer;
	int savelr;
	int left, right;
	left = leftchild(index);
	right = rightchild(index);
	if (left > FastestCheck->last)
		return;
	pr_pointer = drawgraph->VArray->next;
	pr_pointer = FindAboutKey(FastestCheck->heap[index]);
	lr_pointer = FindAboutKey(FastestCheck->heap[left]);
	
	savelr = 1;//left&&right를 확인하기 위한 변수
	if (right <= FastestCheck->last)
	{
		if (lr_pointer->label > FindAboutKey(FastestCheck->heap[right])->label)
		{
			lr_pointer = FindAboutKey(FastestCheck->heap[right]);
			savelr = 2;
		}
	}
	if (pr_pointer->label <= lr_pointer->label)
	{
		return;
	}
	else
	{
		swapKey(lr_pointer->key,index, savelr,pr_pointer,lr_pointer);
		if (savelr == 1)
		{
			rdownheap(left);
		}
		else if (savelr == 2)
		{
			rdownheap(right);
		}
	}
}
void swapKey(int key, int index, int lrcheck, Vertex* parent,Vertex* child)
{  //key == lrchild->key
	//savekey == parentkey
	//index == parent;
	int savekey;
	if (lrcheck == 1)
	{
		savekey=FastestCheck->heap[index];
		FastestCheck->heap[index] = key;
		FastestCheck->heap[leftchild(index)] = savekey;
		parent->heapindex = leftchild(index);
		child->heapindex = index;
	}
	else if (lrcheck == 2)
	{
		savekey = FastestCheck->heap[index];
		FastestCheck->heap[index] = key;
		FastestCheck->heap[rightchild(index)] = savekey;
		parent->heapindex = rightchild(index);
		child->heapindex = index;
	}
}
void QFree()
{
	free(FastestCheck->heap);
	free(FastestCheck);
}
Vertex* pop()
{
	int savekey;
	Vertex *minVertex,*lastVertex;
	savekey = FastestCheck->heap[1];
	minVertex = FindAboutKey(savekey);
	minVertex->heapindex = 0;
	//최소 정점 제외
	FastestCheck->heap[1] = FastestCheck->heap[FastestCheck->last];
	lastVertex = FindAboutKey(FastestCheck->heap[1]);
	lastVertex->heapindex = 1;
	FastestCheck->last = FastestCheck->last - 1;	
	rdownheap(1);
	return minVertex;
}
int Empty()
{
	return (FastestCheck->last == 0) ? 1 : 0;
}//비었으면 1(참),아니면 0;
void upheap(int index)
{
	int parentindex;
	int savekey;
	Vertex *parent, *child;
	
	if (index <= 1)
		return;
	//index == child
	parentindex = parent(index);
	if (FastestCheck->heap[parentindex] > FastestCheck->heap[index])//부모키가 더 큰 경우
	{
		parent = FindAboutKey(FastestCheck->heap[parentindex]);
		child = FindAboutKey(FastestCheck->heap[index]);
		//정점
		savekey = FastestCheck->heap[parentindex];
		FastestCheck->heap[parentindex] = FastestCheck->heap[index];
		FastestCheck->heap[index] = savekey;
		//힙부분 변경
		parent->heapindex = index;
		child->heapindex = parentindex;
		//정점 인덱스 변경
		//재귀호출
		upheap(parentindex);
	}
	else
		return;
	
}

void replacevertex(Vertex *replace)
{
	upheap(replace->heapindex);//힙의 키를 가지고 있는 부분
	rdownheap(1);
	return;
}