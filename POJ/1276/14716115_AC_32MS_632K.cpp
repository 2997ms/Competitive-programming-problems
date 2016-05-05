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
int c[100002];
int dp[100002];

void ZeroOne_Pack(int cost, int weight, int n)
{
	for (int i = n; i >= cost; i--)
		dp[i] = max(dp[i], dp[i - cost] + weight);
}

void Complete_Pack(int cost, int weight, int n)
{
	for (int i = cost; i <= n; i++)
		dp[i] = max(dp[i], dp[i - cost] + weight);
}

int Multi_Pack(int c[], int w[], int num[], int n, int m)
{
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= n; i++)
	{
		if (num[i] * c[i] > m)
			Complete_Pack(c[i], w[i], m);
		else
		{
			int k = 1;
			while (k < num[i])
			{
				ZeroOne_Pack(k*c[i], k*w[i], m);
				num[i] -= k;
				k <<= 1;
			}
			ZeroOne_Pack(num[i] * c[i], num[i] * w[i], m);
		}
	}
	return dp[m];
}

int main()
{
	int i, j, v, max_v,re;
	while (scanf("%d", &cash) != EOF)
	{
		memset(dp, 0, sizeof(dp));
		scanf("%d", &n);
		for (i = 1; i <= n; i++)
		{
			scanf("%d%d", num + i, val + i);
			c[i] = val[i];
		}
		re = Multi_Pack(val, val, num, n, cash);
		cout << re << endl;
	}
	return 0;
}
