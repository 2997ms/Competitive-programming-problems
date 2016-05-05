#pragma warning(disable:4996)  
#include <iostream>  
#include <algorithm>  
#include <cmath>  
#include <vector>  
#include <string>  
#include <cstring>
#include <queue>
using namespace std;

#define INF 0x7fffffff
#define MAXN 1005

int n, ml, md;
struct EDGE
{
	int v;
	int w;
	int next;
}edge[21005];
int d[MAXN], vis[MAXN], cnt[MAXN], head[MAXN], N;

void AddEdge(int u, int v, int w)
{
	edge[N].v = v;
	edge[N].w = w;
	edge[N].next = head[u];
	head[u] = N++;
}

int SPFA()
{
	int x, i, e;
	for (i = 1; i <= n; i++)
	{
		d[i] = -INF;
		cnt[i] = 0;
	}
	d[n] = 0;
	queue<int>q;
	q.push(n);

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

					cnt[edge[e].v]++;
					if (cnt[edge[e].v] > n)
					{
						return -1;
					}
				}
			}
		}
	}
	if (d[n] == -INF)
		return -2;
	else
	{
		return -d[1];
	}
}

void input()
{
	int i;
	int temp1, temp2, temp3;

	memset(head, -1, sizeof(head));
	memset(vis, 0, sizeof(vis));
	memset(edge, -1, sizeof(edge));

	scanf("%d%d%d", &n, &ml, &md);

	N = 0;
	for (i = 1; i <= ml; i++)
	{
		scanf("%d%d%d", &temp1, &temp2, &temp3);
		AddEdge(temp2, temp1, -temp3);
	}
	for (i = 1; i <= md; i++)
	{
		scanf("%d%d%d", &temp1, &temp2, &temp3);
		AddEdge(temp1, temp2, temp3);
	}
	for (i = 1; i < n; i++)
	{
		AddEdge(i, i + 1, 0);
	}
}

int main()
{
	//freopen("i.txt", "r", stdin);
	//freopen("o.txt", "w", stdout);

	input();
	printf("%d\n", SPFA());

	//system("pause");
	return 0;
}