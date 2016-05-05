#pragma warning(disable:4996)  
#include <iostream>  
#include <algorithm>  
#include <cmath>  
#include <vector>  
#include <string>  
#include <cstring>  
using namespace std;

int dir[5][2] = {
	{0,0},
	{-1,0},
	{1,0},
	{0,-1},
	{0,1}
};

int n;
int x[300];
char val_c[300][300];
int val[300][300];

int Gauss()
{
	int row, col, i, j, k, ans;

	ans = 0;
	for (row = 1, col = 1; col <= n&&row <= n; col++, row++)
	{
		k = row;
		while (val[k][col] == 0 && k <= n)
			k++;
		if (k>n)
		{
			row--;
			ans++;
			continue;
		}
		if (k != row)
		{
			for (j = 1; j <= n + 1; j++)
			{
				swap(val[k][j], val[row][j]);
			}
		}
		for (i = row + 1; i <= n; i++)
		{
			if (val[i][col])
			{
				for (j = col; j <= n + 1; j++)
				{
					val[i][j] = val[i][j] ^ val[row][j];
				}
			}
		}
	}
	for (i = row; i <= n; i++)
	{
		if (val[i][n + 1])
			return -1;
	}
	for (i = n - ans; i >= 1; i--)
	{
		x[i] = val[i][n + 1];
		for (j = n; j > i; j--)
		{
			x[i] ^= (val[i][j] && x[j]);
		}
	}
	ans = 0;
	for (i = 1; i <= n; i++)
	{
		if (x[i])
			ans++;
	}
	return ans;
}

int main()
{
	//freopen("i.txt", "r", stdin);
	//freopen("o.txt", "w", stdout);

	int a, b, ans;
	int t, i, j, k;

	scanf("%d", &t);

	while (t--)
	{
		scanf("%d", &n);
		
		memset(val, 0, sizeof(val));
		memset(val_c, 0, sizeof(val_c));
		memset(x, 0, sizeof(x));

		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				for (k = 0; k <= 4; k++)
				{
					a = i + dir[k][0];
					b = j + dir[k][1];
					if (a >= 1 && a <= n&&b >= 1 && b <= n)
					{
						val[(i - 1)*n + j][(a - 1)*n + b] = 1;
					}
				}
			}
		}
		for (i = 1; i <= n; i++)
		{
			cin >> val_c[i] + 1;
			for (j = 1; j <= n; j++)
			{
				if (val_c[i][j] == 'w')
				{
					val[(i - 1)*n + j][n*n + 1] = 1;
				}
			}
		}
		n = n*n;
		ans = Gauss();
		if (ans == -1)
		{
			printf("inf\n");
		}
		else
		{
			printf("%d\n",ans);
		}
	}
	//system("pause");
	return 0;
}