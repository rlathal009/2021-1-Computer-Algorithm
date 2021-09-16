#include <stdio.h>
#include <stdlib.h>

#define M 100
#define N 100

#define max(x, y) ((x) > (y) ? (x) : (y))

int map[M][N];
int path[M][N];
int joy[M][N];

int num_path(int m, int n)
{
	if (map[m][n] == 0)
		return 0;
	if (m == 0 && n == 0)
		return 1;
	return((m > 0) ? num_path(m - 1, n) : 0) + ((n > 0) ? num_path(m, n - 1) : 0);
}

int cal_path(int m, int n)
{
	int i, j;
	path[0][0] = map[0][0];

	for (i = 1; i < m; i++)
		if (map[i][0] == 0)
			path[i][0] = 0;
		else
			path[i][0] = path[i - 1][0];

	for (j = 1; j < n; j++)
		if (map[0][j] == 0)
			path[0][j] = 0;
		else
			path[0][j] = path[0][j - 1];

	for (i = 1; i < m; i++)
		for (j = 1; j < n; j++)
			if (map[i][j] == 0)
				path[i][j] = 0;
			else
				path[i][j] = path[i - 1][j] + path[i][j - 1];
	return path[m - 1][n - 1];
}

void cal_joy(int m, int n)
{
	int i, j;
	joy[0][0] = map[0][0];

	for (i = 1; i < m; i++)
			joy[i][0] = joy[i - 1][0] + map[i][0];

	for (j = 1; j < n; j++)
		joy[0][j] = joy[0][j - 1] + map[0][j];

	for (i = 1; i < m; i++)
		for (j = 1; j < n; j++)
			joy[i][j] = max(joy[i - 1][j], joy[i][j - 1]) + map[i][j];
}

void print(int m, int n)
{
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			printf("%d ", path[i][j]);
		printf("\n");
	}	
}

void print2(int m, int n)
{
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			printf("%02d ", joy[i][j]);
		printf("\n");
	}
}

int main()
{
	int m, n;
	scanf_s("%d %d", &m, &n);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			scanf_s("%d", &map[i][j]);

	/*printf("%d\n", cal_path(m,n));*/

	cal_joy(m, n);
	printf("\n");
	print2(m, n);
	return 0;
}