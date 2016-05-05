#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

int cash, n;
int num[15];
int val[15];
int dp[15][100002];

int main()
{
int i, j, v;
	while (scanf("%d",&cash)!=EOF)
	{
		memset(dp, 0, sizeof(dp));
		scanf("%d", &n);
		for (i = 1; i <= n; i++)
		{
			scanf("%d%d", num + i, val + i);
		}
		for (i = 1; i <= n; i++)
		{
			for (j = 0; j <= num[i]; j++)
			{
				for (v = cash; v >= j*val[i]; v--)
				{
						dp[i][v] = max(dp[i][v], dp[i - 1][v - j*val[i]] + j*val[i]);
				}
			}
		}
		cout << dp[n][cash] << endl;
	}
	return 0;
}
