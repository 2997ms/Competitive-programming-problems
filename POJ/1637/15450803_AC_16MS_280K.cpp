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
const int maxn = 1e3 + 5;
const double PI = acos(-1.0);

struct ed
{
	int to;
	int cap;
	int flow;
	int next;
}edge[4 * maxn];

int edgen;
int out[maxn], in[maxn];
int stac[maxn], head[maxn], dis[maxn], vis[maxn], pre[maxn];

void addedge(int u, int v, int cap)
{
	edge[edgen].to = v;
	edge[edgen].cap = cap;
	edge[edgen].flow = 0;
	edge[edgen].next = head[u];
	head[u] = edgen++;

	edge[edgen].to = u;
	edge[edgen].cap = 0;
	edge[edgen].flow = 0;
	edge[edgen].next = head[v];
	head[v] = edgen++;
}
void init()
{
	edgen = 0;
	memset(head, -1, sizeof(head));
	memset(edge, -1, sizeof(edge));
	memset(out, 0, sizeof(out));
	memset(in, 0, sizeof(in));
}

bool bfs(int S, int T)
{
	int i, j, k, h, t;
	memset(dis, -1, sizeof(dis));
	dis[S] = 0;
	stac[0] = S;

	t = 1;
	for (h = 0; h < t; h++)
	{
		for (k = head[stac[h]]; k != -1; k = edge[k].next)
		{
			j = edge[k].to;
			if (dis[j] == -1 && edge[k].cap>edge[k].flow)
			{
				dis[j] = dis[stac[h]] + 1;
				stac[t++] = j;
			}
		}
	}
	if (dis[T] == -1)
	{
		return false;
	}
	else
	{
		return true;
	}
}

int dfs(int S, int T, int low)
{
	if (S == T)return low;
	int i, j, k;
	int res = 0, tmp;
	for (i = head[S]; i != -1 && res < low; i = edge[i].next)
	{
		k = edge[i].to;
		if (dis[k] == dis[S] + 1 && edge[i].cap>edge[i].flow)
		{
			if (tmp = dfs(k, T, min(low - res, edge[i].cap - edge[i].flow)))
			{
				res += tmp;
				edge[i].flow += tmp;
				edge[i ^ 1].flow -= tmp;
			}
		}
	}
	if (res == 0)
	{
		dis[S] = -1;
	}
	return res;
}

int dinic(int s, int t)
{
	int maxflow = 0, tmp;
	while (bfs(s, t))
	{
		while (tmp = dfs(s, t, INF))
			maxflow += tmp;
	}
	return maxflow;
}

int n, m;

void solve()
{
	int i, j, k;
	sa(n), sa(m);
	repp(i,1,m)
	{
		int u, v, dir;
		sa(u), sa(v), sa(dir);
		out[u]++, in[v]++;
		if (dir == 0)
			addedge(u, v, 1);
	}
	repp(i, 1, n)
	{
		if (abs(out[i] - in[i]) & 1)
		{
			puts("impossible");
			return;
		}
	}
	int maxflow = 0;
	repp(i, 1, n)
	{
		if (out[i] > in[i])
		{
			maxflow += (out[i] - in[i]) / 2;
			addedge(0, i, (out[i] - in[i]) / 2);
		}
		else
		{
			addedge(i, n + 1, abs(out[i] - in[i]) / 2);
		}
	}
	if (maxflow == dinic(0, n + 1))
	{
		puts("possible");
	}
	else
	{
		puts("impossible");
	}
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
		init();
		solve();
	}
	return 0;
}