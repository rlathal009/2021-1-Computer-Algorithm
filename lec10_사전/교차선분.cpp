//#include <stdio.h>
//#include <stdlib.h>
//
//#define SIZE 6
//
//typedef struct
//{
//	int num;
//	float s, e;
//}Segment;
//
//typedef struct
//{
//	float coor;
//	char code;
//	int id;
//}Event;
//
//typedef struct
//{
//	int id1, id2;
//}interSegment;
//
//void insertion_sort(Event ev[], int n)
//{
//	int i, j;
//	Event item;
//	for (i = 1; i < n; i++)
//	{
//		item = ev[i];
//		for (j = i - 1; j >= 0 && ev[j].coor > item.coor; j--)
//			ev[j + 1] = ev[j];
//		ev[j + 1] = item;
//	}
//}
//
//void findIntersectingSegment(Event ev[])
//{
//	int openSegments[SIZE];
//	interSegment is[SIZE * 2];
//	int oCnt = 0;  //openSegment count ����
//	int iCnt = 0;
//
//	for (int i = 0; i < SIZE * 2; i++)
//	{
//		if (ev[i].code == 'S')
//		{
//			for(int j = 0; j<oCnt; j++)
//				if (openSegments[j] != 0)
//				{
//					is[iCnt].id1 = openSegments[j];
//					is[iCnt].id2 = ev[i].id;
//					iCnt++;
//				}
//			openSegments[oCnt++] = ev[i].id;
//		}
//		else
//		{
//			for (int j = 0; j < oCnt; j++)
//				if (openSegments[j] == ev[i].id)
//					openSegments[j] = 0;
//		}
//	}
//
//	for (int i = 0; i < iCnt; i++)
//		printf("(%d, %d)", is[i].id1, is[i].id2);
//	printf("\n");
//}
//
//int main()
//{
//	Segment lines[] = { {1,1.0,3.2}, {2, 0.8, 3.0}, {3, 0.6,2.8}, {4,1.1,2.0} , {5,5.4,7.0}, {6, 2.9, 5.0} };
//	Event ev[SIZE * 2];
//	for (int i = 0; i < SIZE; i++)
//		printf("%d. (%.1f ~ %.1f)\n", lines[i].num, lines[i].s, lines[i].e);
//	printf("\n");
//	getchar();
//
//	for (int i = 0, j = 0; i< SIZE * 2; i++, j++)
//	{
//		ev[i].coor = lines[j].s;
//		ev[i].code = 'S';
//		ev[i].id = lines[j].num;
//		ev[i + 1].coor = lines[j].e;
//		ev[i + 1].code = 'E';
//		ev[++i].id = lines[j].num;
//	}
//	for (int i = 0; i < SIZE * 2; i++)
//		printf("((%.1f, %c), %d)\n", ev[i].coor, ev[i].code, ev[i].id);
//	printf("\n");
//	getchar();
//
//	//����
//	insertion_sort(ev, SIZE * 2);
//	for (int i = 0; i < SIZE * 2; i++)
//		printf("((%.1f, %c), %d)\n", ev[i].coor, ev[i].code, ev[i].id);
//	printf("\n");
//
//	findIntersectingSegment(ev);
//}