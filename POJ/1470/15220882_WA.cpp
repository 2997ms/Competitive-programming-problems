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
const int maxn = 5e5;

struct ed
{
	int to;
	int next;
}edge[maxn];

int n, edgen;
int head[1005], fa[1005], f[1005], vis[1005], ans[1005], q[1005][1005];

void addedge(int from, int to)
{
	edgen++;
	edge[edgen].to = to;
	edge[edgen].next = head[from];
	head[from] = edgen;
}

void init()
{
	edgen = 0;
	memset(head, -1, sizeof(head));
	memset(edge, -1, sizeof(edge));
	memset(ans, 0, sizeof(ans));
	memset(fa, 0, sizeof(fa));
	memset(vis, 0, sizeof(vis));
	memset(f, 0, sizeof(f));
	memset(q, 0, sizeof(q));
}

void input()
{
	int i, j, k, num, m, qnum;
	for (i = 1; i <= n; i++)
	{
		scanf("%d:(%d)", &num, &m);
		for (j = 1; j <= m; j++)
		{
			scanf("%d", &k);
			addedge(num, k);
			fa[k] = num;
		}
	}
	scanf("%d", &qnum);
	for (i = 1; i <= qnum; i++)
	{
		scanf(" (%d %d) ", &j, &k);
		q[j][k]++;
		q[k][j]++;
	}
}

inline int getfa(int x)
{
	return f[x] == x ? x : f[x] = getfa(f[x]);
}

void tarjan(int x)
{
	f[x] = x;
	vis[x] = 1;
	int i;
	for (i = head[x]; i != -1; i = edge[i].next)
	{
		int k = edge[i].to;
		tarjan(k);
		f[k] = x;
	}
	for (i = 1; i <= n; i++)
	{
		if (vis[i] && q[i][x])
		{
			ans[getfa(i)] += q[i][x];
		}
	}

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
	for (i = 1; i <= n; i++)
	{
		if (ans[i] != 0)
		{
			printf("%d:%d\n", i, ans[i]);
		}
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