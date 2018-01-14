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
	FastestCheck = (Q*)malloc(sizeof(Q));
	FastestCheck->heap = (int*)malloc(sizeof(int)*(drawgraph->Vsize + 1));
	FastestCheck->last = drawgraph->Vsize;
	
	for (i = 0; i < drawgraph->Vsize; i++)
	{
		FastestCheck->heap[i+1] = i + 1;
	}//size �� ���� 10���� ������ �ִ°�� 10���� ����(1~10����)//key��
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
}//����� ������
void rdownheap(int index)
{
	Vertex *pr_pointer, *lr_pointer;
	int savelr;

	if (index >= FastestCheck->last)
		return;
	pr_pointer = drawgraph->VArray->next;
	pr_pointer = FindAboutKey(index);
	lr_pointer = FindAboutKey(leftchild(index));
	
	savelr = 1;//left&&right�� Ȯ���ϱ� ���� ����
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
}//������� 1(��),�ƴϸ� 0;