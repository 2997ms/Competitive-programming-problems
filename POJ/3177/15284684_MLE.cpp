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

#define INF 0x333f3f3f

const ll mod = 1000000007;
const int maxn = 5005;
const double PI = acos(-1.0);

struct ed
{
	int to;
	int next;
}edge[2 * maxn];

int n, m, edgen, index, Bcnt, Stop;
int head[maxn], dfn[maxn], low[maxn], instack[maxn], Stack[maxn], Belong[maxn], an[maxn], con[maxn][maxn];

void addedge(int u, int to)
{
	edgen++;
	edge[edgen].to = to;
	edge[edgen].next = head[u];
	head[u] = edgen;
}

void init()
{
	edgen = 0, index = 0, Bcnt = 0, Stop = 0;

	memset(con, 0, sizeof(con));
	
	memset(dfn, 0, sizeof(dfn));
	memset(low, 0, sizeof(low));
	memset(an, 0, sizeof(an));
	memset(Belong, 0, sizeof(Belong));
	memset(instack, 0, sizeof(instack));

	memset(head, -1, sizeof(head));
	memset(edge, -1, sizeof(edge));
}

void tarjan(int i,int fa)
{
	int j;
	dfn[i] = low[i] = ++index;
	instack[i] = 1;
	Stack[++Stop] = i;

	for (j = head[i]; j != -1; j = edge[j].next)
	{
		int v = edge[j].to;
		if (dfn[v] == 0)
		{
			tarjan(v, i);
			low[i] = min(low[i], low[v]);
		}
		else if (v != fa&&instack[v] == 1)
		{
			low[i] = min(low[i], dfn[v]);
		}
	}

	if (dfn[i] == low[i])
	{
		Bcnt++;
		do
		{
			j = Stack[Stop--];
			instack[j] = 0;
			Belong[j] = Bcnt;
		} while (j != i);
	}
}

void solve()
{
	int i, j, k;
	int u, v, res;

	scanf("%d%d", &n, &m);
	for (i = 1; i <= m; i++)
	{
		scanf("%d%d", &u, &v);
		if (con[u][v] == 0)
		{
			con[u][v] = con[v][u] = 1;
			addedge(u, v);
			addedge(v, u);
		}
	}
	tarjan(1, -1);
	for (i = 1; i <= n; i++)
	{
		for (j = head[i]; j != -1; j = edge[j].next)
		{
			k = edge[i].to;
			if (Belong[i] != Belong[k])
			{
				an[Belong[i]]++;
			}
		}
	}
	res = 0;
	for (i = 1; i <= Bcnt; i++)
	{
		if (an[i] == 1)
		{
			res++;
		}
	}
	printf("%d", (res + 1) / 2);
}

int main()
{
#ifndef ONLINE_JUDGE  
	freopen("i.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
#endif
	init();
	solve();
	//system("pause");
	return 0;
}