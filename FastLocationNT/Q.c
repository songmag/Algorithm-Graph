#include"FtLNT.h"


//1. insertheap//�ٽ� �ִ� �۾��� �������� ����.(������ ����� ������)
//2. deletheap(pop) //�ּҰ��� �����س��� �޼ҵ�
//3. upheap 
//4. downheap
//�ּ������� ����
//pop�ÿ� �����ؾ� �ϴ� �۾�
// 1. downheap
//insert�ÿ� �ؾ� �ϴ� �۾�
//1. ���� �� ������ ���ҿ��� upheap ���� // ����� �������� ���� X
//2. �� ���� �ö�� ��� ���� downheap ����(��,���� ���̸� ���̱� ����)
// �ð����⵵  = upheap -> O(logN) + downheap -> O(logN) = O(logN)
// ������� Ȯ���ϴ� �۾�
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
	}//size �� ���� 10���� ������ �ִ°�� 10���� ����(1~10����)//key��
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
}//����� ������
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
	
	savelr = 1;//left&&right�� Ȯ���ϱ� ���� ����
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
	//�ּ� ���� ����
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
}//������� 1(��),�ƴϸ� 0;
void upheap(int index)
{
	int parentindex;
	int savekey;
	Vertex *parent, *child;
	
	if (index <= 1)
		return;
	//index == child
	parentindex = parent(index);
	if (FastestCheck->heap[parentindex] > FastestCheck->heap[index])//�θ�Ű�� �� ū ���
	{
		parent = FindAboutKey(FastestCheck->heap[parentindex]);
		child = FindAboutKey(FastestCheck->heap[index]);
		//����
		savekey = FastestCheck->heap[parentindex];
		FastestCheck->heap[parentindex] = FastestCheck->heap[index];
		FastestCheck->heap[index] = savekey;
		//���κ� ����
		parent->heapindex = index;
		child->heapindex = parentindex;
		//���� �ε��� ����
		//���ȣ��
		upheap(parentindex);
	}
	else
		return;
	
}

void replacevertex(Vertex *replace)
{
	upheap(replace->heapindex);//���� Ű�� ������ �ִ� �κ�
	rdownheap(1);
	return;
}