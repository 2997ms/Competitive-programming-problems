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
#define MAXN 505

int n, m;

struct EDGE
{
	int st;
	int en;
	int w;
}edge[5005];

int d[MAXN], vis[MAXN], N, Max, Min;

void AddEdge(int u, int v, int w)
{
	edge[N].st = u;
	edge[N].en = v;
	edge[N].w = w;
	N++;
}

void read()
{
	int i, st, nt, val;
	string s;
	
	N = 0;
	for (i = 1; i <= m; i++)
	{
		cin >> st >> nt >> s >> val;
		if (s == "gt")
		{
			AddEdge(st - 1, st + nt, (val +	1));//减一
			//AddEdge(st + nt, st - 1, -val - 1);
		}
		else
		{
			AddEdge(st + nt, st - 1, -(val - 1));
			//AddEdge(st - 1, st + nt, (val - 1));
		}
	}
}

bool Bellman_ford()
{
	int i, j;
	for (i = 1; i <= n; i++)
		d[i] = 0;

	for (i = 1; i <= n; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (d[edge[j].st] + edge[j].w < d[edge[j].en])
			{
				d[edge[j].en] = d[edge[j].st] + edge[j].w;
			}
		}
	}
	for (j = 0; j < N; j++)
		if (d[edge[j].st] + edge[j].w < d[edge[j].en])
			return 0;
	return 1;
}

int main()
{
	//freopen("i.txt", "r", stdin);
	//freopen("o.txt", "w", stdout);

	while (scanf("%d",&n)!=EOF)
	{
		if (n == 0)
			break;
		scanf("%d", &m);
		read();
		if (Bellman_ford())
		{
			puts("lamentable kingdom");
		}
		else
		{
			puts("successful conspiracy");
		}
	}

	//system("pause");
	return 0;
}