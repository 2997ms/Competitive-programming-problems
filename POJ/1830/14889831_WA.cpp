#pragma warning(disable:4996)  
#include <iostream>  
#include <algorithm>  
#include <cmath>  
#include <vector>  
#include <string>  
#include <cstring>  
using namespace std;

int n;
int s[350], e[350], x[350], x2[350];
int res[350][350], res2[350][350];

int Gauss()
{
	int row, col, i, j, k, ans;

	ans = 0;
	for (row = 1, col = 1; col <= n&&row <= n; col++, row++)
	{
		k = row;
		while (res[k][col] == 0 && k <= n)
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
				swap(res[k][j], res[row][j]);
			}
		}
		for (i = row + 1; i <= n; i++)
		{
			if (res[i][col])
			{
				for (j = col; j <= n + 1; j++)
				{
					res[i][j] = res[i][j] ^ res[row][j];
				}
			}
		}
	}
	for (i = row; i <= n; i++)
	{
		if (res[i][n + 1])
			return -1;
	}
	if (row <= n)
		return (1 << (n - row+1));
	else
		return 1;
}

int main()
{
	//freopen("i.txt", "r", stdin);
	//freopen("o.txt", "w", stdout);

	int k, i, j, ans;
	scanf("%d", &k);

	while (k--)
	{
		scanf("%d", &n);

		memset(res, 0, sizeof(res));
		memset(res2, 0, sizeof(res2));
		memset(x, 0, sizeof(x));
		memset(x2, 0, sizeof(x2));
		memset(e, 0, sizeof(e));
		memset(s, 0, sizeof(s));
		for (i = 1; i <= n; i++)
		{
			scanf("%d", &s[i]);
			res[i][i] = 1;
		}

		for (i = 1; i <= n; i++)
		{
			scanf("%d", &e[i]);
			res[i][n + 1] = s[i] ^ e[i];
		}
		for (;;)
		{
			scanf("%d%d", &i, &j);
			if (i == 0 && j == 0)
				break;
			res[i][j] = 1;
		}
		memcpy(res2, res, sizeof(res));
		ans = Gauss();
		if (ans == -1)
		{
			printf("Oh,it's impossible~!!\n");
		}
		else
		{
			printf("%d\n", ans);
		}
	}
	//system("pause");
	return 0;
}