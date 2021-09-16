//#include<stdio.h>
//#include <stdlib.h>
//
//typedef struct Edge
//{
//	int vNum1;
//	int vNum2;
//	struct Edge* next;
//}Edge;
//
//typedef struct IncidentEdge
//{
//	int adjVertex;
//	Edge* e;
//	struct IncidentEdge* next;
//}IncidentEdge;
//
//typedef struct Vertex
//{
//	int num;
//	int isFresh;
//	struct Vertex* next;
//	IncidentEdge* top;
//}Vertex;
//
//Vertex* vHead = NULL;
//Edge* eHead = NULL;
//int vCount;
//int eCount;
//
//void makeVertices() {
//	Vertex* p = (Vertex*)malloc(sizeof(Vertex));
//	p->num = ++vCount;
//	p->top = NULL;
//	p->next = NULL;
//	p->isFresh = 0;
//	Vertex* q = vHead;
//	if (q == NULL)
//		vHead = p;
//	else
//	{
//		while (q->next != NULL)
//			q = q->next;
//		q->next = p;
//	}
//}
//
//void insertIncidentEdge(Vertex* v, int av, Edge* e)
//{
//	IncidentEdge* p = (IncidentEdge*)malloc(sizeof(IncidentEdge));
//	p->adjVertex = av;
//	p->e = e;
//	p->next = NULL;
//	IncidentEdge* q = v->top;
//	if (q == NULL)
//		v->top = p;
//	else
//	{
//		while (q->next != NULL)
//			q = q->next;
//		q->next = p;
//	}
//}
//
//Vertex* findVertex(int v)
//{
//	Vertex* p = vHead;
//	while (p->num != v)
//		p = p->next;
//	return p;
//}
//
//void insertEdges(int v1, int v2)
//{
//	Edge* p = (Edge*)malloc(sizeof(Edge));
//	p->vNum1 = v1;
//	p->vNum2 = v2;
//	p->next = NULL;
//	Edge* q = eHead;
//	if (q == NULL)
//		eHead = p;
//	else
//	{
//		while (q->next != NULL)
//			q = q->next;
//		q->next = p;
//	}
//	Vertex* v = findVertex(v1);
//	insertIncidentEdge(v, v2, p);
//}
//
//void print()
//{
//	Vertex* p = vHead;
//	IncidentEdge* q;
//	for (; p != NULL; p = p->next)
//	{
//		printf("Á¤Á¡ %d : ", p->num);
//		for (q = p->top; q != NULL; q = q->next)
//			printf("[%d] ", q->adjVertex);
//		printf("\n");
//	}
//}
//
//int main()
//{
//	for (int i = 0; i < 6; i++)
//		makeVertices();
//
//	insertEdges(1, 2);
//	insertEdges(1, 5);
//	insertEdges(2, 3);
//	insertEdges(4, 5);
//	insertEdges(5, 2);
//	insertEdges(5, 3);
//	insertEdges(5, 6);
//	insertEdges(6, 3);
//
//	print();
//
//	return 0;
//}