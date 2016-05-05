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
int val[100002];
int dp[100002];

int main()
{
	int i, j, v, max_v;
	while (scanf("%d", &cash) != EOF)
	{
		memset(dp, 0, sizeof(dp));
		scanf("%d", &n);
		for (i = 1; i <= n; i++)
		{
			scanf("%d%d", num + i, val + i);
		}
		int temp = n;
		for (i = 1; i <= temp; i++)
		{
			if (num[i] == 0)
			{
				val[i] = 0;
				continue;
			}
			for (j = 1; j < num[i]; j++)
			{
				val[n + j] = val[i];
			}
			n += (num[i] - 1);
		}
		for (i = 1; i <= n; i++)
		{
			for (v = cash; v >= val[i]; v--)
			{
				dp[v] = max(dp[v], dp[v - val[i]] + val[i]);
			}
		}
		cout << dp[cash] << endl;
	}
	return 0;
}
