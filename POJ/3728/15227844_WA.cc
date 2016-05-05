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
const int maxn = 5e5 + 5;

struct ed
{
	int to;
	int next;
}edge[maxn], qedge[maxn];

int n, edgen, qedgen;
int pri[maxn], v[maxn];
int head[maxn], qhead[maxn], fa[maxn], f[maxn], vis[maxn], ans[maxn];
int up[maxn], down[maxn], up_w[maxn], down_w[maxn];

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

	memset(up, 0, sizeof(up));
	memset(down, 0, sizeof(down));
	memset(up_w, 0, sizeof(up_w));
	memset(down_w, 0, sizeof(down_w));
}

void input()
{
	int i, j, k, qnum;
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
		fa[v] = u;
	}
	scanf("%d", &qnum);
	for (i = 1; i <= qnum; i++)
	{
		scanf("%d%d", &u, &v);
		addqedge(u, v);
		addqedge(v, u);
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
		f[x] = getfa(f[x]);
		
		up_w[x] = max(up_w[x], up_w[f[x]]);
		down_w[x] = min(down_w[x], down_w[f[x]]);
		up[x] = max(max(up[x], up[f[x]]), up_w[f[x]] - pri[x]);
		down[x] = max(max(down[x], down[f[x]]), pri[x] - down_w[f[x]]);

		return f[x];
	}
}

//up[i]表示i节点到祖先节点的差值最大值
//down[i]表示祖先节点到i的差值最大值
//up_w[i]表示i到祖先节点的值的最大值
//down_w[i]表示祖先节点到i的值的最小值

void tarjan(int x)
{
	f[x] = x;
	int i;
	for (i = head[x]; i != -1; i = edge[i].next)
	{
		int k = edge[i].to;
		tarjan(k);
		f[k] = x;
	}

	for (i = qhead[x]; i != -1; i = qedge[i].next)
	{
		int k = qedge[i].to;

		if (vis[k])
		{
			getfa(k);
			getfa(x);
			if (i % 2 == 1)
			{
				//x到k
				ans[i] = max(max(up[x], down[k]), up_w[k] - down_w[x]);
			}
			else
			{
				//k到x
				ans[i - 1] = max(max(up[k], down[x]), up_w[x] - down_w[k]);
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
	tarjan(root);
	for (i = 1; i <= qedgen; i += 2)
	{
		printf("%d\n", ans[i]);
	}
}

int main()
{

	while (scanf("%d", &n) != EOF)
	{
		init();
		input();
		solve();
	}
	
	//system("pause");
	return 0;
}