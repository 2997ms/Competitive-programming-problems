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

#define INF 0x333f3f3f
#define repp(i, n, m) for (int i = n; i <= m; i++)
#define rep(i, n, m) for (int i = n; i < m; i++)
#define sa(n) scanf("%d", &(n))

const ll mod = 1e9 + 7;
const int maxn = 2e5 + 5;
const double PI = acos(-1.0);

int n, m;
int fa[maxn], used[maxn];
struct ed
{
	int u;
	int v;
	int w;
}edge[maxn];

bool cmp(ed &a,ed &b)
{
	return a.w < b.w;
}

void init()
{
	repp(i, 1, n)
	{
		fa[i] = i;
	}
}

int getfa(int x)
{
	return x == fa[x] ? x : getfa(fa[x]);
}

void solve()
{
	int i, j, k;
	sa(n), sa(m);
	repp(i, 1, m)
	{
		sa(edge[i].u), sa(edge[i].v), sa(edge[i].w);
	}
	sort(edge + 1, edge + m + 1, cmp);

	int num, res = 0, cnt = 0;
	init();
	repp(i, 1, m)
	{
		int x = getfa(edge[i].u);
		int y = getfa(edge[i].v);
		if (x == y)continue;
		res += edge[i].w;
		fa[x] = y;
		cnt++;
		used[cnt] = i;
	}

	for (i = 1; i <= cnt; i++)
	{
		init();
		int r = 0;
		num = 0;
		for (j = 1; j <= m; j++)
		{
			if (j == used[i])continue;
			int x = getfa(edge[j].u);
			int y = getfa(edge[j].v);
			if (x == y)continue;
			num++;
			r += edge[j].w;
			fa[x] = y;
		}
		if (r == res&&num == n - 1)
		{
			puts("Not Unique!");
			return;
		}
	}
	printf("%d\n", res);
}

int main()
{
#ifndef ONLINE_JUDGE  
	freopen("i.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
#endif
	int t;
	scanf("%d", &t);

	while (t--)
	{
		solve();
	}
	return 0;
}