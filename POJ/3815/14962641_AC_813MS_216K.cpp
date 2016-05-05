#pragma warning(disable:4996)  
#include <iostream>  
#include <algorithm>  
#include <cmath>  
#include <vector>  
#include <string>  
#include <cstring>
#include <queue>
#include <map>
using namespace std;
typedef long long ll;

#define INF 0x7fffffff
const int maxn = 1005;

int nq, dq;
struct no
{
	int h;
	int pos;
}node[maxn];

struct EDGE
{
	int v;
	int w;
	int next;
}edge[maxn*2];

int head[maxn], d[maxn], vis[maxn], cnt[maxn], N;

bool cmp(no n1, no n2)
{
	return n1.h < n2.h;
}

void AddEdge(int u, int v, int w)
{
	edge[N].v = v;
	edge[N].w = w;
	edge[N].next = head[u];

	head[u] = N++;
}

bool SPFA(int x1)
{
	int x, i, e;
	for (i = 1; i <= nq; i++)
	{
		d[i] = INF;
		cnt[i] = 0;
		vis[i] = 0;
	}
	d[x1] = 0;
	queue<int>q;
	q.push(x1);

	while (!q.empty())
	{
		x = q.front();
		q.pop();
		vis[x] = 0;
		for (int e = head[x]; e != -1; e = edge[e].next)
		{
			if (d[edge[e].v] > d[x] + edge[e].w)
			{
				d[edge[e].v] = d[x] + edge[e].w;
				if (!vis[edge[e].v])
				{
					q.push(edge[e].v);
					vis[edge[e].v] = 1;

					cnt[edge[e].v]++;
					if (cnt[edge[e].v] > nq)
					{
						return false;
					}
				}
			}
		}
	}
	return true;
}

void input()
{
	int i;

	for (i = 1; i <= nq; i++)
	{
		scanf("%d", &node[i].h);
		node[i].pos = i;
	}
}

void work()
{
	int i, j, k;

	N = 0;
	memset(head, -1, sizeof(head));
	memset(edge, 0, sizeof(edge));

	sort(node + 1, node + nq + 1, cmp);
	for (i = 2; i <= nq; i++)
	{
		int maxpos = max(node[i - 1].pos, node[i].pos);
		int minpos = min(node[i - 1].pos, node[i].pos);
		AddEdge(minpos, maxpos, dq);
		AddEdge(i, i - 1, -1);
	}
	i = node[1].pos > node[nq].pos ? node[nq].pos : node[1].pos;
	if (SPFA(i))
	{
		printf("%d\n", abs(d[node[nq].pos]-d[node[1].pos]));
	}
	else
	{
		printf("-1\n");
	}
}

int main()
{
	//freopen("i.txt", "r", stdin);
	//freopen("o.txt", "w", stdout);

	while (true)
	{
		scanf("%d%d", &nq, &dq);
		if (nq == 0 && dq == 0)
			break;
		input();
		work();
	}

	//system("pause");
	return 0;
}