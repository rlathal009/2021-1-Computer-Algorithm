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

int h(int key) //�ؽ��Լ�
{
	return key % M;
}

int h2(int key) //���� �ؽ�
{
	return 11 - (key % 11);
}

int getNextBucktLinear(int v, int i)  //Linear probing, ���� �����
{
	return (v + i) % M;
}

int getNextBucketQuadratic(int v, int i) // Quadratic probing, ���� �����
{
	return (v + i * i) % M;
}

int getNextBucketDouble(int v, int i, int key) // Double Hashing, ���� �ؽù�
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
	printf("\nŽ���� Ű �Է� :");
	scanf_s("%d", &key);
	if (findElement(&HT, key))
		printf("\nŰ �� %d��(��) �����մϴ�. \n", key);
	else
		printf("\nŰ �� %d��(��) �����ϴ�. \n", key);

	printf("������ Ű �Է� : ");
	scanf_s("%d", &key);
	if (removeElement(&HT, key))
		printf("\nŰ �� %d��(��) �����Ǿ����ϴ�. \n", key);
	else
		printf("\nŰ �� %d��(��) �����ϴ�. \n", key);
	printf("\n");
	printHashTable(&HT);


	return 0;
}