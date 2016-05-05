//#pragma comment(linker, "/STACK:655360000")  
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
#include <set>
#include <map>
using namespace std;
typedef long long ll;

#define INF 0x3fffffff
#define repp(i, n, m) for (int i = n; i <= m; i++)
#define rep(i, n, m) for (int i = n; i < m; i++)
#define sa(n) scanf("%d", &(n))
#define mp make_pair
#define ff first
#define ss second
#define pb push_back

const int maxn = 1e6 + 5;
const ll mod = 1000000;
const double PI = acos(-1.0);

int n;
int val[22], dp[22][9000];

int dfs(int id, int res)
{
	if (res == 0)
	{
		return dp[id][res] = 1;
	}
	if (dp[id][res] != -1)
	{
		return dp[id][res];
	}
	int i, j, k;

	for (i = 1; i <= val[id] && i <= res; i++)
	{
		if (dfs((id + 1) % (2 * n), res - i) == 0)
		{
			return dp[id][res] = 1;
		}
	}
	return dp[id][res] = 0;
}

void solve()
{
	int i, j, k;
	memset(dp, -1, sizeof(dp));
	sa(k);
	rep(i, 0, 2 * n)
	{
		sa(val[i]);
	}
	if (dfs(0, k) == 0)
	{
		puts("0");
	}
	else
	{
		puts("1");
	}
}

int main()
{
#ifndef ONLINE_JUDGE  
	freopen("i.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
#endif
	while (scanf("%d", &n) != EOF)
	{
		if (n == 0)
			break;
		solve();
	}
	return 0;
}