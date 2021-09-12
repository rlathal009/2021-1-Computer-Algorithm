#include <stdio.h>
#include <stdlib.h>


//뭐가 틀렸는지 모르겠지만 15강에 연습이라고 쓴 코드 보기.

typedef struct Edge
{
	int vNum1;
	int vNum2;
	int isTree;  //TreeBack 마킹하기 위한 변수. 사용하는 방법으로 프로그램 수정
	struct Edge* next;
}Edge;

typedef struct IncidentEdge
{
	int adjVertex; //인접 정점 이름
	Edge* e;
	struct IncidentEdge* next;
}IncidentEdge;

typedef struct Vertex
{
	int num;
	int isFresh;
	struct Vertex* next;
	IncidentEdge* top;
}Vertex;

Vertex* vHead = NULL;
Edge* eHead = NULL;
int vCount; //정점의 개수
int eCount; //간선의 개수

void makeVertices()
{
	Vertex* p = (Vertex*)malloc(sizeof(Vertex));
	p->num = ++vCount;
	p->top = NULL;
	p->next = NULL;
	p->isFresh = 0;
	Vertex* q = vHead;
	if (q == NULL)
		vHead = p;
	else
	{
		while (q->next != NULL)
			q = q->next;
		q->next = p;
	}
}

void insertIncidentEdge(Vertex* v, int av, Edge* e)
{
	IncidentEdge* p = (IncidentEdge*)malloc(sizeof(IncidentEdge));
	p->adjVertex = av;
	p->e = e;  // 실제 어떤 edge랑 연결되어있는지 찾아야함
	p->next = NULL;
	IncidentEdge* q = v->top;
	if (q == NULL)
		v->top = p;
	else
	{
		while (q->next != NULL)
			q = q->next;
		q->next = p;
	}
}

Vertex* findVertex(int v)  //찾는 정점의 위치를 반환
{
	Vertex* p = vHead;
	while (p->num != v)
		p = p->next;
	return p;
}

void insertEdges(int v1, int v2)
{
	Edge* p = (Edge*)malloc(sizeof(Edge));
	p->vNum1 = v1;
	p->vNum2 = v2;
	p->isTree = 0;  //fresh
	p->next = NULL;
	Edge* q = eHead;
	if (q == NULL)
		eHead = p;
	else
	{
		while (q->next != NULL)
			q = q->next;
		q->next = p;
	}
	Vertex* v = findVertex(v1);
	insertIncidentEdge(v, v2, p);
	v = findVertex(v2);
	insertIncidentEdge(v, v1, p);
}

void dfs(Vertex* v)  //DFS
{
	IncidentEdge* q;
	if (v->isFresh == 0)
	{
		printf("[%d] ", v->num);
		v->isFresh = 1;
	}
	for (q = v->top; q != NULL; q = q->next)
	{
		v = findVertex(q->adjVertex);
		if (v->isFresh == 0)
			dfs(v);
	}
}

void print()
{
	Vertex* p = vHead;
	IncidentEdge* q;
	for (; p != NULL; p = p->next)
	{
		printf("정점 %d : ", p->num);
		for (q = p->top; q != NULL; q = q->next)  //각 정점별로 인접 간선을 통해 인접 정점 출력
			printf("[%d] ", q->adjVertex);
		printf("\n");
	}
}


int main()
{
	for (int i = 0; i < 6; i++)
		makeVertices();

	insertEdges(1, 2);
	insertEdges(1, 3);
	insertEdges(2, 4);
	insertEdges(2, 5);
	insertEdges(3, 5);
	insertEdges(3, 6);
	insertEdges(4, 7);
	insertEdges(5, 7);
	insertEdges(5, 8);
	insertEdges(6, 8);
	insertEdges(7, 9);
	insertEdges(8, 9);

	print();
	/*dfs(vHead);*/
}