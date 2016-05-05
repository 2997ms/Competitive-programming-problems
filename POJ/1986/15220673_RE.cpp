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

#define INF 0x3fffffffffffffff

const ll mod = 1e9 + 7;
const int maxn = 10005;

struct ed
{
	int w;
	int to;
	int next;
}edge[maxn],qedge[maxn];

int n, m, edgen, qedgen;
int head[maxn],fa[maxn], f[maxn], vis[maxn],v[maxn],ans[maxn], qhead[maxn], d[maxn];

void addedge(int from, int to,int w)
{
	edgen++;
	edge[edgen].w = w;
	edge[edgen].to = to;
	edge[edgen].next = head[from];
	head[from] = edgen;
}

void addqedge(int from, int to)
{
	qedgen++;
	qedge[qedgen].to = to;
	qedge[qedgen].next = qhead[from];
	qhead[from] = qedgen;
}

void init()
{
	edgen = 0;
	qedgen = 0;

	memset(d, 0, sizeof(d));
	memset(qhead, -1, sizeof(qhead));
	memset(head, -1, sizeof(head));
	memset(qedge, -1, sizeof(qedge));
	memset(edge, -1, sizeof(edge));
	memset(ans, 0, sizeof(ans));
	memset(fa, 0, sizeof(fa));
	memset(v, 0, sizeof(v));
	memset(vis, 0, sizeof(vis));
	memset(f, 0, sizeof(f));
}

void input()
{
	int u, v, w;
	int i, j, k, num, qnum;
	char x[5];
	for (i = 1; i <= m; i++)
	{
		scanf("%d%d%d%s", &u, &v, &w, x);
		addedge(u, v, w);
		addedge(v, u, w);
		fa[u] = v;
	}
	scanf("%d", &qnum);
	for (i = 1; i <= qnum; i++)
	{
		scanf("%d%d", &u, &v);
		addqedge(u, v);
		addqedge(v, u);
	}
}

inline int getfa(int x)
{
	return f[x] == x ? x : f[x] = getfa(f[x]);
}

void tarjan(int x)
{
	v[x] = 1;
	f[x] = x;
	int i;
	for (i = head[x]; i != -1; i = edge[i].next)
	{
		int k = edge[i].to;
		if (v[k])continue;
		d[k] = d[x] + edge[i].w;
		tarjan(k);
		f[k] = x;
	}
	for (i = qhead[x]; i != -1; i = qedge[i].next)
	{
		int k = qedge[i].to;
		if (vis[k])
		{
			ans[i] = d[x] + d[k] - 2 * d[getfa(k)];
			if (i % 2 != 0)
			{
				ans[i + 1] = ans[i];
			}
		}
	}
	vis[x] = 1;
}

void solve()
{
	int i, root;
	for (i = 1; i <= n; i++)
	{
		if (fa[i] == 0)
		{
			root = i;
			break;
		}
	}
	d[root] = 0;
	tarjan(root);
	for (i = 2; i <= qedgen; i = i + 2)
	{
		printf("%d\n", ans[i]);
	}
}

int main()
{
#ifndef ONLINE_JUDGE  
	freopen("i.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
#endif 

	while (scanf("%d%d", &n, &m) != EOF)
	{
		init();
		input();
		solve();
	}

	//system("pause");
	return 0;
}