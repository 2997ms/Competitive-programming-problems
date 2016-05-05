#pragma warning(disable:4996)  
#include <iostream>  
#include <algorithm>  
#include <cmath>  
#include <vector>  
#include <string>  
#include <cstring>
#include <queue>
using namespace std;

#define INF 1000000007
#define MAXN 1005

int n, m;

struct EDGE
{
	int v;
	int w;
	int next;
}edge[2 * 100000 + 1000];

int head[MAXN], d[MAXN], vis[MAXN], cnt[MAXN], N, Max, Min;

void AddEdge(int u, int v, int w)
{
	edge[N].v = v;
	edge[N].w = w;
	edge[N].next = head[u];
	head[u] = N++;
}

bool SPFA()
{
	int x, i, e;
	for (i = Min; i <= Max; i++)
	{
		d[i] = -INF;
		cnt[i] = 0;
	}
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

					cnt[edge[e].v]++;
					if (cnt[edge[e].v] > n)
					{
						return false;
					}
				}
			}
		}
	}

	return true;
}

int main()
{
	//freopen("i.txt", "r", stdin);
	//freopen("o.txt", "w", stdout);

	int i, j, u, v, w;
	string s;
	
	while (scanf("%d%d", &n, &m) != EOF)
	{
		N = 0;
		memset(head, -1, sizeof(head));
		memset(vis, 0, sizeof(vis));
		memset(edge, 0, sizeof(edge));
		
		Min = INF;
		Max = -INF;
		for (i = 0; i < m; i++)
		{
			cin >> s;
			if (s[0] == 'P')
			{
				scanf("%d%d%d", &u, &v, &w);
				AddEdge(u, v, w);
				AddEdge(v, u, -w);
				Min = min(Min, u);
				Max = max(Max, v);
			}
			else
			{
				scanf("%d%d", &u, &v);
				AddEdge(u, v, 1);
				Min = min(Min, u);
				Max = max(Max, v);
			}
		}
		if (!SPFA())
			printf("Unreliable\n");
		else
			printf("Reliable\n");
	}
	//system("pause");
	return 0;
}