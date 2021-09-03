#include <stdio.h>
#include <stdlib.h>

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

void init(LinkedListType* L)
{
	L->head = NULL;
}

void addFirst(LinkedListType* L, int item)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = item;
	node->link = L->head;
	L->head = node;
}

void add(LinkedListType* L, int pos, int item)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	ListNode* before = L->head;
	for (int i = 0; i < pos - 1; i++)
		before = before->link;
	node->data = item;
	node->link = before->link;
	before->link = node;
}

int get(LinkedListType* L, int pos)
{
	ListNode* p = L->head;
	for (int i = 1; i < pos; i++)
		p = p->link;
	return p->data;
}

void set(LinkedListType* L, int pos, int item)
{
	ListNode* p = L->head;
	for (int i = 1; i < pos; i++)
		p = p->link;
	p->data = item;
}

//과제
void addLast(LinkedListType* L, int item)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	ListNode* p = L->head;
	node->data = item;
	node->link = NULL;

	if (L->head == NULL) {
		L->head = node;
		return;
	}

	while (p->link != NULL)
		p = p->link;

	p->link = node;
}

int remove(LinkedListType* L, int pos)
{
	ListNode* before = L->head;
	int result;

	if (L->head->link == NULL)
	{
		result = L->head->data;
		free(L->head);
		L->head = NULL;
		return result;
	}
	else
	{
		ListNode* tmp;
		for (int i = 0; i < pos - 1; i++)
			before = before->link;
		tmp = before->link;
		result = tmp->data;
		before->link = before->link->link;
		free(tmp);
		return result;
	}
}

int removeFirst(LinkedListType* L)
{
	int result;
	if (L->head->link == NULL)
	{
		result = L->head->data;
		free(L->head);
		L->head = NULL;
		return result;
	}
	else
	{
		ListNode* tmp;
		tmp = L->head;
		result = tmp->data;
		L->head = L->head->link;
		free(tmp);
		return result;
	}
}

int removeLast(LinkedListType* L)
{
	int result;
	if (L->head->link == NULL)
	{
		result = L->head->data;
		free(L->head);
		L->head = NULL;
		return result;
	}
	else
	{
		ListNode* before = L->head;
		ListNode* del = before->link;
		while (del->link != NULL)
		{
			before = del;
			del = del->link;
		}
		result = del->data;
		free(del);
		before->link = NULL;
		return result;
	}
}


void printList(LinkedListType* L)
{
	for (ListNode* p = L->head; p != NULL; p = p->link)
		printf("[%d] -> ", p->data);
	printf("NULL\n");
}

void main()
{
	LinkedListType list;
	init(&list);

	printf("addLast 함수\n");
	addLast(&list, 10);	printList(&list);
	addLast(&list, 20);	printList(&list);
	addLast(&list, 30);	printList(&list);
	addLast(&list, 40);		printList(&list);
	addLast(&list, 50);		printList(&list);
	addLast(&list, 70);		printList(&list);
	addLast(&list, 80);		printList(&list);
	addLast(&list, 90);		printList(&list);

	printf("\n\n remove 함수\n");
	printf("제거된 값 : %d\n", remove(&list, 1));	printList(&list);
	printf("제거된 값 : %d\n", remove(&list, 3));	printList(&list);

	printf("\n\nremoveFirst 함수\n");
	printf("제거된 값 : %d\n", removeFirst(&list));	printList(&list);
	printf("제거된 값 : %d\n", removeFirst(&list));	printList(&list);

	printf("\n\nremoveLast 함수\n");
	printf("제거된 값 : %d\n", removeLast(&list));	printList(&list);
	printf("제거된 값 : %d\n", removeLast(&list));	printList(&list);

}