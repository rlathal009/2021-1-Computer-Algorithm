#include <stdio.h>
#include <stdlib.h>

#define M 13

typedef struct
{
	int key;
	int probeCount;
}Bucket;

typedef struct
{
	Bucket A[M];
}HashType;

void initHash(HashType* HT)
{
	for (int i = 0; i < M; i++)
	{
		HT->A[i].key = 0;
		HT->A[i].probeCount = 0;
	}
}

int h(int key) //해시함수
{
	return key % M;
}

int h2(int key) //이중 해시
{
	return 11 - (key % 11);
}

int getNextBucktLinear(int v, int i)  //Linear probing, 선형 조사법
{
	return (v + i) % M;
}

int getNextBucketQuadratic(int v, int i) // Quadratic probing, 이차 조사법
{
	return (v + i * i) % M;
}

int getNextBucketDouble(int v, int i, int key) // Double Hashing, 이중 해시법
{
	return (v + i * h2(key)) % M;
}

int isEmpty(HashType* HT, int b)
{
	return HT->A[b].key == 0;
}

void insertItem(HashType* HT, int key)
{
	int v = h(key);
	int i = 0;
	int count = 0;
	while (i < M)
	{
		count++;
		int b = getNextBucktLinear(v, i);
		//int b = getNextBucketQuadratic(v, i);
		//int b = getNextBucketDouble(v, i, key);
		if (isEmpty(HT, b))
		{
			HT->A[b].key = key;
			HT->A[b].probeCount = count;
			return;
		}
		else
			i++;
	}
}

int findElement(HashType* HT, int key)
{
	int v = h(key);
	int i = 0;
	while (i < M)
	{
		int b = getNextBucktLinear(v, i);
		if (isEmpty(HT, b))
			return 0;
		else if (HT->A[b].key == key)
			return key;
		else
			i++;
	}
	return 0;
}

int removeElement(HashType* HT, int key)
{
	int v = h(key);
	int i = 0;
	while (i < M)
	{
		int b = getNextBucktLinear(v, i);
		if (isEmpty(HT, b))
			return 0;
		else if (HT->A[b].key == key)
		{
			HT->A[b].key = 0;
			HT->A[b].probeCount = 0;
			return key;
		}
		else
			i++;
	}
	return 0;
}

void printHashTable(HashType* HT)
{
	printf("Bucket Key Probe\n");
	printf("=========================\n");

	for (int i = 0; i < M; i++)
		printf("HT[%02d]: %2d  %d\n", i, HT->A[i].key, HT->A[i].probeCount);
}

int main()
{
	HashType HT;
	initHash(&HT);

	insertItem(&HT, 25);
	insertItem(&HT, 13);
	insertItem(&HT, 16);
	insertItem(&HT, 15);
	insertItem(&HT, 7);
	insertItem(&HT, 28);
	insertItem(&HT, 31);
	insertItem(&HT, 20);
	insertItem(&HT, 1);
	insertItem(&HT, 38);
	printHashTable(&HT);

	int key;
	printf("\n탐색할 키 입력 :");
	scanf_s("%d", &key);
	if (findElement(&HT, key))
		printf("\n키 값 %d이(가) 존재합니다. \n", key);
	else
		printf("\n키 값 %d이(가) 없습니다. \n", key);

	printf("삭제할 키 입력 : ");
	scanf_s("%d", &key);
	if (removeElement(&HT, key))
		printf("\n키 값 %d이(가) 삭제되었습니다. \n", key);
	else
		printf("\n키 값 %d이(가) 없습니다. \n", key);
	printf("\n");
	printHashTable(&HT);


	return 0;
}