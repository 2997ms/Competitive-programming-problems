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
#define MAXN 2000

struct EDGE
{
	int v;
	int w;
	int next;
}edge[MAXN];

int N,wtf;
int head[25], d[25], vis[25],cnt[25];
int r[25], t[25], s[25];

void addedge(int u, int v, int w)
{
	edge[wtf].v = v;
	edge[wtf].w = w;
	edge[wtf].next = head[u];
	head[u] = wtf++;
}
bool SPFA(int vv)
{
	int x, i, e;
	for (i = 0; i <= 24; i++)
	{
		d[i] = -INF;
		cnt[i] = 0;
	}
	d[0] = 0;
	queue<int>q;
	q.push(0);

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
					if (cnt[edge[e].v] > 24)
					{
						return false;
					}
				}
			}
		}
	}
	if (d[24] == vv)
		return true;
	else
		return false;
}

void build(int x)
{
	wtf = 0;
	memset(edge, 0, sizeof(edge));
	memset(head, -1, sizeof(head));
	memset(d, 0, sizeof(d));
	memset(vis, 0, sizeof(vis));
	memset(cnt, 0, sizeof(cnt));
	int i, j;
	for (i = 1; i <= 24; i++)
	{
		//addedge(i, i - 1, 0);
		//addedge(i - 1, i, -t[i]);

		addedge(i - 1, i, 0);
		addedge(i, i - 1, -t[i]);
	}
	addedge(0, 24, x);
	for (i = 1; i <= 24; i++)
	{
		if (i >= 1 && i < 8)
		{
			addedge(i+16, i, r[i] - x);
		}
		else
		{
			addedge(i-8, i, r[i]);
		}
	}
}

void read()
{
	int i, temp;
	for (i = 1; i <= 24; i++)
	{
		scanf("%d", &r[i]);
	}
	scanf("%d", &N);
	for (i = 1; i <= N; i++)
	{
		scanf("%d", &temp);
		t[temp + 1]++;
	}
}

void solve()
{
	int i;
	for (i = 0; i <= N; i++)//枚举申请者的个数
	{
		build(i);
		if (SPFA(i))
		{
			printf("%d\n", i);
			return;
		}
	}
	printf("No Solution\n");
	return ;
}

int main()
{ 	
	//freopen("i.txt", "r", stdin); 
	//freopen("o.txt", "w", stdout);
	
	int t;
	scanf("%d", &t);
	while (t--)
	{
		read();
		solve();
	}
	return 0;
}