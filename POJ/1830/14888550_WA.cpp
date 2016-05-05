#pragma warning(disable:4996)  
#include <iostream>  
#include <algorithm>  
#include <cmath>  
#include <vector>  
#include <string>  
#include <cstring>  
using namespace std;

int n;
int s[35], e[35], x[35], x2[35];
int res[35][35], res2[35][35];

int Gauss()
{
	int row, col, i, j, k, ans;
	
	ans = 0;
	for (row = 1, col = 1; col <= n&&row <= n; col++, row++)
	{
		k = row;
		for (i = k + 1; i <= n; i++)
		{
			if (abs(res[i][col]) > abs(res[k][col]))
			{
				k = i;
			}
		}
		if (res[k][col] == 0)
		{
			k--;
			ans++;
			continue;
		}
		if (k != row)
		{
			for (j = col; j <= n; j++)
			{
				swap(res[k][j],res[row][j]);
			}
		}
		for (i = row + 1; i <= n; i++)
		{
			if (res[i][col])
			{
				for (j = col; j <= n; j++)
				{
					res[i][j] ^= res[row][j];
				}
			}
		}
	}
	for (i = n; i >= 1; i--)
	{
		x[i] = res[i][n+1];
		for (j = n; j > i; j--)
		{
			x[i] ^= (res[i][j] && x[j]);
		}
	}
	for (i = 1; i <= n ; i++)
	{
		x2[i] = 0;
		for (j = 1; j <= n ; j++)
		{
			x2[i] ^= (res2[i][j] && x[j]);
		}
		if (x2[i] != x[i])
		{
			return -1;
		}
	}
	return (1 << ans);
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