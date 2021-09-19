#include <stdio.h>
#include <stdlib.h>

int c[15][150];

void calculate_subset_sum(int s[], int n, int m)
{
	int i, j;
	
	for (i = 0; i <= n; i++)
		c[i][0] = 1;

	for (i = 1; i <= m; i++)
		c[0][i] = 0;

	for(i=1;i<=n;i++)
		for (j = 1; j <= m; j++)
		{
			c[i][j] = 0;

			if (j >= s[i - 1])
				if (c[i - 1][j - s[i - 1]] == 1)
					c[i][j] = 1;

			if (c[i - 1][j] == 1)
				c[i][j] = 1;
		}
}

void main()
{
	int m, n;
	printf("input m,n : ");
	scanf_s("%d %d", &m, &n);
	int* s = (int*)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++)
		scanf_s("%d", &s[i]); 

}