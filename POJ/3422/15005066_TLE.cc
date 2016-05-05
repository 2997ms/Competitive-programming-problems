#pragma warning(disable:4996)  
#include <iostream>  
#include <algorithm>  
#include <cmath>  
#include <vector>  
#include <string>  
#include <cstring>
#include <queue>
#include <cstdio>
using namespace std;
typedef long long ll;

#define INF 0x3f3f3f3f
#define MAXN 5005

ll res;
int n;
int N, K;

struct EDGE
{
	int v;
	int reverse;
	int cap;
	int cost;
	int next;
}edge[50005];

int val[MAXN][MAXN];
int stac[MAXN], head[MAXN], d[MAXN], vis[MAXN], pre[MAXN];

void addedge(int u, int v, int cost, int cap)
{
	edge[n].v = v;
	edge[n].cost = cost;
	edge[n].cap = cap;
	edge[n].next = head[u];
	edge[n].reverse = n + 1;
	head[u] = n++;

	edge[n].v = u;
	edge[n].cost = -cost;
	edge[n].cap = 0;
	edge[n].next = head[v];
	edge[n].reverse = n - 1;
	head[v] = n++;
}

void input()
{
	int i, j;
	int s, e, ww;

	scanf("%d%d", &N, &K);

	memset(edge, 0, sizeof(edge));
	memset(head, -1, sizeof(head));

	n = 0;
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			scanf("%d", &val[i][j]);

			s = ((i - 1)*N + j) * 2 - 1;
			e = ((i - 1)*N + j) * 2;

			addedge(s, e, val[i][j], 1);
			addedge(s, e, 0, K - 1);
			if (i + 1 <= N)
			{
				s = ((i - 1)*N + j) * 2;
				e = (i*N + j) * 2 - 1;

				addedge(s, e, 0, K);

			}
			if (j + 1 <= N)
			{
				s = ((i - 1)*N + j) * 2;
				e = ((i - 1)*N + j + 1) * 2 - 1;

				addedge(s, e, 0, K);
			}
		}
	}
	N = N*N * 2;
	addedge(0, 1, 0, K);
	addedge(N, N + 1, 0, K);
}

bool spfa()
{
	int i, top;
	for (i = 0; i <= N + 1; i++)
	{
		d[i] = -INF;
		vis[i] = 0;
		pre[i] = i;
	}
	top = 0;
	d[0] = 0;
	stac[++top] = 0;
	vis[0] = 0;

	while (top)
	{
		int u = stac[top];
		top = (top - 1) % MAXN;
		for (i = head[u]; i != -1; i = edge[i].next)
		{
			int v = edge[i].v;
			if (edge[i].cap&&d[v] < d[u] + edge[i].cost)
			{
				d[v] = d[u] + edge[i].cost;
				pre[v] = i;//与之前邻接矩阵记录点不同的是，这里记录的是边

				if (!vis[v])
				{
					vis[v] = 1;
					top = (top + 1) % MAXN;
					stac[top] = v;
				}
			}
		}
		vis[u] = 0;
	}
	if (d[N + 1] <= 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void compute()
{
	int sum = INF;
	int u, p;

	for (u = N + 1; u != 0; u = edge[edge[p].reverse].v)
	{
		p = pre[u];
		edge[p].cap -= 1;
		edge[edge[p].reverse].cap += 1;
		res += edge[p].cost;
	}
}

void solve()
{
	res = 0;
	while (spfa())
		compute();
	printf("%lld\n", res);
}

int main()
{
	//freopen("i.txt", "r", stdin);
	//freopen("o.txt", "w", stdout);

	input();
	solve();

	//system("pause");
	return 0;
}