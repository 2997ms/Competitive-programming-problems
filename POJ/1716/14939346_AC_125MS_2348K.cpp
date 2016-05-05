#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#pragma warning(disable:4996)
using namespace std;

#define INF 1000000007
#define MAXN 50005

struct EDGE
{
	int v;
	int w;
	int next;
}edge[3 * MAXN];

int head[MAXN], d[MAXN], vis[MAXN], N, n, Max, Min;

void AddEdge(int u, int v, int w)
{
	edge[N].v = v;
	edge[N].w = w;
	edge[N].next = head[u];
	head[u] = N++;
}

void SPFA()
{
	int x, i, e;
	for (i = Min; i <= Max; i++)
		d[i] = -INF;
	d[Min] = 0;

	queue<int>q;
	q.push(Min);

	while (!q.empty())
	{
		x = q.front();
		q.pop();
		vis[x] = 0;

		for (int e = head[x]; e != -1; e = edge[e].next)
		{
			if (d[edge[e].v] < d[x] + edge[e].w)
			{
				d[edge[e].v] = d[x] + edge[e].w;
				if (!vis[edge[e].v])
				{
					q.push(edge[e].v);
					vis[edge[e].v] = 1;
				}
			}
		}
	}
}

int main()
{
	//freopen("i.txt", "r", stdin);
	//freopen("o.txt", "w", stdout);

	int i;
	int u, v, w;

	while (scanf("%d", &n) != EOF)
	{
		N = 0;
		memset(head, -1, sizeof(head));
		memset(vis, 0, sizeof(vis));
		memset(edge, 0, sizeof(edge));

		Min = INF;
		Max = -INF;

		for (i = 0; i < n; i++)
		{
			scanf("%d%d", &u, &v);
			AddEdge(u, v + 1, 2);
			Min = min(Min, u);
			Max = max(Max, v + 1);
		}
		for (i = Min; i < Max; i++)
		{
			AddEdge(i, i + 1, 0);
			AddEdge(i + 1, i, -1);
		}
		SPFA();
		printf("%d\n", d[Max]);
	}
	//system("pause");
	return 0;
}
