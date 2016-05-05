#pragma warning(disable:4996)
#include <iostream>  
#include <algorithm>
#include <cstring>
#include <vector>  
#include <string>  
#include <cmath>
#include <queue>
#include <map>
using namespace std;

typedef unsigned long long ll;
const int maxn = 5005;

int n;
int dp[maxn], val[maxn];

void input()
{
	int i;
	scanf("%d", &n);

	for (i = 1; i <= n; i++)
	{
		scanf("%d", val + i);
	}
}

int dfs()
{
	int i;
	dp[1] = val[1];
	dp[2] = val[2];
	dp[3] = val[1] + val[2] + val[3];
	for (i = 4; i <= n; i++)
	{
		dp[i] = val[i] + val[1] + min(dp[i - 1], 2 * val[2] + dp[i - 2]);
	}
	return dp[n];
}

void solve()
{
	sort(val + 1, val + n + 1);
	printf("%d\n", dfs());
}

int main()
{
	//freopen("i.txt", "r", stdin);
	//freopen("o.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	while (t--)
	{
		input();
		solve();
	}

	return 0;
}