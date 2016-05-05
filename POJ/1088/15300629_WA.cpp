#pragma warning(disable:4996)
#include <iostream>
#include <functional>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <deque>
#include <ctime>
#include <set>
#include <map>
using namespace std;
typedef long long ll;

#define INF 0x33ffffff

#define eps 1e-6
const ll mod = 1000000007;
const int maxn = 200;
const double PI = acos(-1.0);

int r, c;
int val[maxn][maxn], used[maxn][maxn],dp[maxn][maxn];

void init()
{
	memset(used, 0, sizeof(used));
	memset(dp, 0, sizeof(dp));
	memset(val, 0, sizeof(val));
}

void dfs(int i, int j)
{
	int max_num = 0;

	used[i][j] = 1;

	if (i>1 && val[i][j]> val[i - 1][j])
	{
		if (!used[i - 1][j])
			dfs(i - 1, j);
		max_num = max(dp[i - 1][j], max_num);
	}

	if (i<r && val[i][j]> val[i + 1][j])
	{
		if (!used[i + 1][j])
			dfs(i + 1, j);
		max_num = max(dp[i + 1][j], max_num);
	}

	if (j>1 && val[i][j]> val[i][j - 1])
	{
		if (!used[i][j - 1])
			dfs(i, j - 1);
		max_num = max(dp[i][j - 1], max_num);
	}

	if (j<c && val[i][j]> val[i][j + 1])
	{
		if (!used[i][j + 1])
			dfs(i, j + 1);
		max_num = max(dp[i][j + 1], max_num);
	}

	dp[i][j] = max_num + 1;

}
void solve()
{
	int i, j;
	scanf("%d%d", &r, &c);

	for (i = 1; i <= r; i++)
	{
		for (j = 1; j <= c; j++)
		{
			scanf("%d", &val[i][j]);
		}
	}
	for (i = 1; i <= r; i++)
	{
		for (j = 1; j <= c; j++)
		{
			if (!used[i][j])
				dfs(i, j);
		}
	}
	int max_num = 0;
	for (i = 1; i <= r; i++)
	{
		for (j = 1; j <= c; j++)
		{
			if (dp[i][j]>max_num)
				max_num = dp[i][j];
		}
	}
	printf("%d\n", max_num);
}

int main()
{

	
	int t;
	scanf("%d", &t);
	while (t--)
	{
		init();
		solve();
	}

//system("pause");
	return 0;
}
