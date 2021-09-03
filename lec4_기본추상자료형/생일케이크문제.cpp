#include <stdio.h>
#include <stdlib.h>

//배열 문제

void buildList(int* A, int n)
{
	for (int i = 0; i < n; i++)
	{
		A[i] = i + 1;
	}
}

void removes(int* A, int n, int pos)
{
	for (int i = pos; i < n; i++)
		A[i] = A[i + 1];
}

//배열_ver1
int runSimulation(int* A, int n, int k)
{
	int r = 0;
	int num = n, N = n;
	while (num > 1)
	{
		int i = 0;
		while (i < k)
		{
			r = (r + 1) % N;
			if (A[r] != 0)
				i++;
		}
		A[r] = 0;
		num--;
		while (A[r] == 0)
			r = (r + 1) % N;
	}
	return A[r];
}

//배열_ver2
int runSimulation2(int* A, int n, int k)
{
	int r = 0, num = n;
	while (num > 1)
	{
		r = (r + k) % num;
		removes(A, num, r);
		num--;
	}
	return A[0];
}

int candle(int* A, int n, int k)
{
	buildList(A, n);

	return runSimulation2(A, n, k);
}

int main()
{
	int size;
	scanf_s("%d", &size);
	int* arr = (int*)malloc(sizeof(int)*size);
	int k;
	scanf_s("%d", &k);

	printf("%d", candle(arr, size, k));
	return 0;
}
