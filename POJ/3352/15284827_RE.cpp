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
const int maxn = 20005;
const double PI = acos(-1.0);

struct ed
{
	int to;
	int next;
}edge[2 * maxn];
char x[maxn];
map< pair<int, int>, int >ha;
int n, m, edgen, index, Bcnt, Stop;
int head[maxn], dfn[maxn], low[maxn], instack[maxn], Stack[maxn], Belong[maxn], an[maxn];

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

	ha.clear();
	memset(dfn, 0, sizeof(dfn));
	memset(low, 0, sizeof(low));
	memset(an, 0, sizeof(an));
	memset(Belong, 0, sizeof(Belong));
	memset(instack, 0, sizeof(instack));
	memset(Stack, 0, sizeof(Stack));

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
		if (v == fa)continue;
		if (dfn[v] == 0)
		{
			tarjan(v, i);
			low[i] = min(low[i], low[v]);
		}
		else if (instack[v] == 1)
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
		if (ha[make_pair(u, v)] == 0 && ha[make_pair(u, v)] == 0)
		{
			ha[make_pair(u, v)] = ha[make_pair(v, u)] = 1;
			addedge(u, v);
			addedge(v, u);
		}
	}
	for (i = 1; i <= n; i++)
	{
		if (dfn[i] == 0)
		{
			tarjan(i, -1);
		}
	}
	for (i = 1; i <= n; i++)
	{
		for (j = head[i]; j != -1; j = edge[j].next)
		{
			k = edge[j].to;
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
	int t = 0;
	char e;
	while (cin.getline(x, 50))
	{
		t++;
		printf("Output for Sample Input %d\n", t);
		init();
		solve();
		printf("\n\n");
		scanf("%c%c", &e, &e);
	}
	//system("pause");
	return 0;
}