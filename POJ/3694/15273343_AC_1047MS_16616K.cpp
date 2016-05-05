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

const ll mod = 1e9 + 7;
const int maxn = 500005;

struct ed
{
	int to;
	int next;
}edge[maxn];

int n, m, t;
int edgen, res_cnt, index;
int head[maxn], dfn[maxn], Dfn[maxn], low[maxn], fa[maxn], bridge[maxn];

void addedge(int u, int to)
{
	edgen++;
	edge[edgen].to = to;
	edge[edgen].next = head[u];
	head[u] = edgen;
}

void init()
{
	index = 0, edgen = 0, res_cnt = 0;
	
	memset(dfn, 0, sizeof(dfn));
	memset(Dfn, 0, sizeof(Dfn));
	memset(low, 0, sizeof(low));
	memset(bridge, 0, sizeof(bridge));
	memset(head, -1, sizeof(head));
	memset(edge, -1, sizeof(edge));

	for (int i = 1; i <= n; i++)
		fa[i] = i;
}

void tarjan(int x)
{
	index++;
	low[x] = dfn[x] = index;
	Dfn[x] = Dfn[fa[x]] + 1;
	int i, j, k;
	for (i = head[x]; i != -1; i = edge[i].next)
	{
		k = edge[i].to;
		if (dfn[k] == 0)
		{
			fa[k] = x;
			tarjan(k);
			low[x] = min(low[x], low[k]);

			if (low[k] > dfn[x])
			{
				res_cnt++;
				bridge[k] = 1;
			}
		}
		else if (k != fa[x])
		{
			low[x] = min(low[x], dfn[k]);
		}
	}
}

void LCA(int u, int v)
{
	while (Dfn[u] > Dfn[v])
	{
		if (bridge[u])
		{
			res_cnt--; 
			bridge[u] = 0;
		}
		u = fa[u];
	}
	while (Dfn[v] > Dfn[u])
	{
		if (bridge[v])
		{
			res_cnt--;
			bridge[v] = 0;
		}
		v = fa[v];
	}
	while (u != v)
	{
		if (bridge[v])
		{
			res_cnt--;
			bridge[v] = 0;
		}
		v = fa[v];
		if (bridge[u])
		{
			res_cnt--;
			bridge[u] = 0;
		}
		u = fa[u];
	}
}

void solve()
{
	int i, j, k;
	int u, v;

	for (i = 1; i <= m; i++)
	{
		scanf("%d%d", &u, &v);
		addedge(u, v);
		addedge(v, u);
	}
	tarjan(1);
	scanf("%d", &k);
	printf("Case %d:\n", t);
	for (i = 1; i <= k; i++)
	{
		scanf("%d%d", &u, &v);
		LCA(u, v);
		printf("%d\n", res_cnt);
	}
	printf("\n");
}

int main()
{
#ifndef ONLINE_JUDGE  
	freopen("i.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
#endif
	t = 0;
	while (scanf("%d%d", &n, &m) != EOF)
	{
		if (n == 0 && m == 0)
			break;
		t++;
		init();
		solve();
	}
	return 0;
}