#include <stdio.h>
#include <stdlib.h>

//원형 연결리스트

typedef struct ListNode
{
	int data;
	struct ListNode* link;
}ListNode;

//헤더
typedef struct
{
	ListNode* head;
}LinkedListType;

LinkedListType buildList(int n)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	LinkedListType* L = (LinkedListType*)malloc(sizeof(LinkedListType));
	L->head = p;
	p->data = 1;
	for (int i = 2; i <= n; i++)
	{
		p->link = (ListNode*)malloc(sizeof(ListNode));
		p = p->link;
		p->data = i;
	}
	p->link = L->head;

	return *L;
}

int runSimulation(LinkedListType* L,int n,int k)
{
	ListNode* p = L->head;
	while (p != p->link)
	{
		for (int i = 1; i < k; i++)
			p = p->link;
		ListNode* pnext = p->link;
		p->link = p->link->link;
		free(pnext);
		p = p->link;
	}
	return p->data;
}

int candle(int n, int k)
{
	LinkedListType L = buildList(n);
	return runSimulation(&L, n, k);
}

void main()
{
	int size;
	scanf_s("%d", &size);
	int k;
	scanf_s("%d", &k);

	printf("%d", candle( size, k));

}