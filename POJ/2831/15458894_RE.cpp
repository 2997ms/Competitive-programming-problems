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

const int maxn = 1e3 + 5;
const ll mod = 1000000;
const double PI = acos(-1.0);

int n, m, q;
int mini[maxn], vis[maxn], pre[maxn];
int dis[maxn][maxn], res[maxn][maxn];

struct ed
{
	int u;
	int v;
	int w;
}edge[maxn];

void init()
{
	int i, j, k;
	repp(i, 1, n)
	{
		repp(j, i, n)
		{
			if (i == j)
			{
				dis[i][j] = 0;
			}
			else
			{
				dis[i][j] = dis[j][i] = INF;
			}
			res[i][j] = res[j][i] = 0;
		}
	}
}

void prim()
{
	int i, j, k, st;
	int top = 0;
	for (i = 1; i <= n; i++)
	{
		mini[i] = INF;
		vis[i] = 0;
		mini[i] = dis[1][i];
	}
	st = 1;
	vis[1] = 1;
	mini[1] = 0;

	for (i = 1; i <= n - 1; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (vis[j] == 0 && dis[st][j] < mini[j])
			{
				mini[j] = dis[j][st];
				pre[j] = st;
			}
		}
		int min_all = INF;
		for (j = 1; j <= n; j++)
		{
			if (vis[j] == 0 && mini[j] < min_all)
			{
				min_all = mini[j];
				st = j;
			}
		}
		for (j = 1; j <= n; j++)
		{
			if (vis[j])
			{
				res[j][st] = res[st][j] = max(res[j][pre[st]], mini[st]);
			}
		}
		vis[st] = 1;
	}
}

void solve()
{
	int i, j, k;
	int u, v, w;
	repp(i, 1, m)
	{
		sa(edge[i].u), sa(edge[i].v), sa(edge[i].w);
		dis[edge[i].u][edge[i].v] = dis[edge[i].v][edge[i].u] = min(dis[edge[i].v][edge[i].u], edge[i].w);
	}
	prim();
	repp(i, 1, q)
	{
		sa(u), sa(w);
		if (res[edge[u].u][edge[u].v] >= w)
		{
			puts("Yes");
		}
		else
		{
			puts("No");
		}
	}
}


int main()
{
	while (scanf("%d%d%d", &n, &m, &q) != EOF)
	{
		init();
		solve();
	}
	return 0;
}