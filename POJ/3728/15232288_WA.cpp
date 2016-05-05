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
const int maxn = 4e5 + 5;

struct ed
{
	int id;
	int to;
	int next;
}edge[maxn], qedge[maxn], q2edge[maxn];

int n, edgen, qedgen, q2edgen, qnum;
int pri[maxn], v[maxn], uu[maxn], vv[maxn];
int head[maxn], qhead[maxn], q2head[maxn], f[maxn], vis[maxn], ans[maxn];
int up[maxn], down[maxn], up_w[maxn], down_w[maxn];

void addedge(int from, int to)
{
	edgen++;
	edge[edgen].to = to;
	edge[edgen].next = head[from];
	head[from] = edgen;
}

void addqedge(int from, int to, int id)
{
	qedgen++;
	qedge[qedgen].to = to;
	qedge[qedgen].id = id;
	qedge[qedgen].next = qhead[from];
	qhead[from] = qedgen;
}

void addq2edge(int from, int to, int id)
{
	q2edgen++;
	q2edge[q2edgen].to = to;
	q2edge[q2edgen].id = id;
	q2edge[q2edgen].next = q2head[from];
	q2head[from] = q2edgen;
}

void init()
{
	edgen = 0;
	qedgen = 0;
	q2edgen = 0;

	memset(q2head, -1, sizeof(q2head));
	memset(qhead, -1, sizeof(qhead));
	memset(head, -1, sizeof(head));

	memset(q2edge, -1, sizeof(q2edge));
	memset(qedge, -1, sizeof(qedge));
	memset(edge, -1, sizeof(edge));

	memset(ans, 0, sizeof(ans));
	memset(v, 0, sizeof(v));
	memset(vis, 0, sizeof(vis));
	memset(f, 0, sizeof(f));

	memset(up, 0, sizeof(up));
	memset(down, 0, sizeof(down));
	memset(up_w, 0, sizeof(up_w));
	memset(down_w, 0, sizeof(down_w));
}

void input()
{
	int i, j, k;
	int u, v;
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &pri[i]);
		down_w[i] = up_w[i] = pri[i];
	}
	for (i = 1; i <= n - 1; i++)
	{
		scanf("%d%d", &u, &v);
		addedge(u, v);
		addedge(v, u);
	}
	scanf("%d", &qnum);
	for (i = 1; i <= qnum; i++)
	{
		scanf("%d%d", &uu[i], &vv[i]);
		addqedge(uu[i], vv[i], i);
		addqedge(vv[i], uu[i], i);
	}
}

int getfa(int x)
{
	if (f[x] == x)
	{
		return x;
	}
	else
	{
		int father = f[x];
		f[x] = getfa(f[x]);
		up_w[x] = max(up_w[x], up_w[father]);
		down_w[x] = min(down_w[x], down_w[father]);

		up[x] = max(max(up[x], up[father]), up_w[father] - down_w[x]);
		down[x] = max(max(down[x], down[father]), up_w[x] - down_w[father]);

		return f[x];
	}
}

//up[i]表示i节点到祖先节点的差值最大值
//down[i]表示祖先节点到i的差值最大值
//up_w[i]表示i到祖先节点的值的最大值
//down_w[i]表示祖先节点到i的值的最小值

void tarjan(int x)
{
	v[x] = 1;
	f[x] = x;
	int i, k, id, fa;

	for (i = qhead[x]; i != -1; i = qedge[i].next)
	{
		k = qedge[i].to;
		id = qedge[i].id;
		if (v[k] == 0)continue;
		fa = getfa(k);
		addq2edge(fa, k, id);
	}
	for (i = head[x]; i != -1; i = edge[i].next)
	{
		k = edge[i].to;
		if (v[k])continue;
		tarjan(k);
		f[k] = x;
	}

	for (i = q2head[x]; i != -1; i = q2edge[i].next)
	{
		k = q2edge[i].to;
		id = q2edge[i].id;
		getfa(uu[id]);
		getfa(vv[id]);
		//x到k
		ans[id] = max(max(up[uu[id]], down[vv[id]]), up_w[vv[id]] - down_w[uu[id]]);
	}
}

void solve()
{
	int i;
	tarjan(1);
	for (i = 1; i <= qnum; i++)
	{
		//printf("%d %d\n", i, ans[i]);
		printf("%d\n", ans[i]);
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
		init();
		input();
		solve();
	}

	//system("pause");
	return 0;
}