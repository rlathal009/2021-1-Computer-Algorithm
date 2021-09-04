#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_ELEMENT 100

typedef struct
{
	int heap[MAX_ELEMENT];
	int heap_size;
}HeapType;

typedef struct
{
	int stack[MAX_ELEMENT];
	int top;
}StackType;

void init_Heap(HeapType *h)
{
	h->heap_size = 0;
}

void upheap(HeapType *h)
{
	int i = h->heap_size;
	int key = h->heap[i];

	while ((i != 1) && (key < h->heap[i / 2]))
	{
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = key;
}

void insertItem(HeapType *h, int key)
{
	h->heap_size += 1;
	h->heap[h->heap_size] = key;
	upheap(h);
}

void printHeap(HeapType *h)
{
	for (int i = 1; i <= h->heap_size; i++)
		printf("[%d] ", h->heap[i]);
	printf("\n");
}

void init_Stack(StackType *s)
{
	s->top = -1;
}

int is_Empty(StackType *s)
{
	if (s->top == -1) return 1;
	else
		return 0;
}

void push(StackType *s, int data)
{
	if (s->top != MAX_ELEMENT - 1)
		s->stack[++s->top] = data;
}

int pop(StackType *s)
{
	if (!is_Empty(s))
		return s->stack[s->top--];
}

void binaryExpansion(int i, StackType *s)
{
	int num = i;
	while (num >= 2)
	{
		push(s, num % 2);
		num = num / 2;
	}
	push(s, num);
	return;
}

int findLastNode(HeapType *h, int n)
{
	int bit;
	int v = 1;
	StackType s;
	init_Stack(&s);
	binaryExpansion(n, &s);
	bit = pop(&s);
	while (!is_Empty(&s))
	{
		bit = pop(&s);
		if (bit == 0)
			v = 2 * v;
		else
			v = 2 * v + 1;
	}
	return h->heap[v];
}

void main()
{
	HeapType h;
	int n = 15;
	srand(time(NULL));
	init_Heap(&h);
	for (int i = 0; i < n; i++)
		insertItem(&h, rand() % 30);
	printHeap(&h);

	int node = findLastNode(&h, n);
	printf("Last node : %d", node);
}