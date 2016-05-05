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
const int maxn = 1e5 + 5;
const double PI = acos(-1.0);

struct ed
{
	int to;
	int next;
}edge[3 * maxn], qedge[3 * maxn];

int n, m, edgen, qedgen;
int head[maxn], fa[maxn], f[maxn], vis[maxn], v[maxn], ans[maxn], qhead[maxn], d[maxn];

void addedge(int from, int to)
{
	edgen++;
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

	memset(qhead, -1, sizeof(qhead));
	memset(head, -1, sizeof(head));
	memset(qedge, -1, sizeof(qedge));
	memset(edge, -1, sizeof(edge));
	memset(ans, 0, sizeof(ans));
	memset(fa, 0, sizeof(fa));
	memset(v, 0, sizeof(v));
	memset(vis, 0, sizeof(vis));
	memset(f, 0, sizeof(f));
	memset(d, 0, sizeof(d));
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
		tarjan(k);
		f[k] = x;
	}
	for (i = qhead[x]; i != -1; i = qedge[i].next)
	{
		int k = qedge[i].to;
		if (vis[k])
		{
			d[x]++;
			d[k]++;
			d[getfa(k)] -= 2;
		}
	}
	vis[x] = 1;
}

void input()
{
	int u, v, w;
	int i, j, k;
	for (i = 1; i <= n - 1; i++)
	{
		scanf("%d%d", &u, &v);
		addedge(u, v);
		addedge(v, u);
	}
	for (i = 1; i <= m; i++)
	{
		scanf("%d%d", &u, &v);
		addqedge(u, v);
		addqedge(v, u);
	}
}

void dfs(int x)
{
	int i, j, k;
	v[x] = 1;
	for (i = head[x]; i != -1; i = edge[i].next)
	{
		int k = edge[i].to;
		if (v[k])continue;
		dfs(k);
		d[x] += d[k];
	}
}

void solve()
{
	int i, j, k;
	tarjan(1);

	memset(v, 0, sizeof(v));
	dfs(1);
	int res = 0;
	for (i = 2; i <= n; i++)
	{
		if (d[i] == 0)
		{
			res += m;
		}
		else if(d[i] == 1)
		{
			res++;
		}
	}
	printf("%d\n", res);
}

int main()
{

	while (scanf("%d%d", &n, &m) != EOF)
	{
		init();
		input();
		solve();
	}


	//system("pause");
	return 0;
}