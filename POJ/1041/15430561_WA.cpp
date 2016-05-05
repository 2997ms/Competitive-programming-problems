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
#define repp(i, n, m) for (int i = n; i <= m; i++)
#define rep(i, n, m) for (int i = n; i < m; i++)
#define sa(n) scanf("%d", &(n))

const ll mod = 1e9 + 7;
const int maxn = 1e6 + 5;
const double PI = acos(-1.0);

struct ed
{
	int to;
	int next;
	int flag;
	int dir;
	int ind;
}edge[maxn];

int n, edgen;
int head[maxn], out[maxn], fa[maxn];

void init()
{
	edgen = 0;
	memset(head, -1, sizeof(head));
	memset(edge, -1, sizeof(edge));
	memset(out, 0, sizeof(out));
	repp(i, 0, 1e6)
		fa[i] = i;
}

void addedge(int u, int v, int dir,int ind)
{
	edge[edgen].to = v;
	edge[edgen].flag = 0;
	edge[edgen].dir = dir;
	edge[edgen].ind = ind;
	edge[edgen].next = head[u];
	head[u] = edgen;
	edgen++;
}

int getfa(int x)
{
	return fa[x] == x ? x : fa[x] = getfa(fa[x]);
}

vector<int>res;

void uni(int u, int v)
{
	u = getfa(u), v = getfa(v);
	if (u == v)return;
	fa[u] = v;
}

void dfs(int x)
{
	int i, j, k;
	for (i = head[x]; i != -1; i = edge[i].next)
	{
		if (!edge[i].flag)
		{
			edge[i].flag = 1;
			edge[i ^ 1].flag = 1;
			k = edge[i].to;
			//res.push_back(i);
			dfs(k);
			res.push_back(i);
		}
	}
}

int x, y, z;

void solve()
{
	int i, j, k;
	int u, v;
	int st = min(x, y);
	do
	{
		scanf("%d", &z);
		addedge(x, y, 1, z);
		addedge(y, x, -1, z);
		out[x]++;
		out[y]++;
		uni(x, y);
	} while (scanf("%d%d", &x, &y) == 2 && x != 0 && y != 0);

	int cnt = 0;
	int f = -1;
	for (i = 0; i <= 1995; i++)
	{
		if (out[i] & 1)
		{
			cnt++;
			f = i;
		}
		if (out[i] > 0)
		{
			f = i;
		}
	}
	if (f == -1)
	{
		printf("Round trip does not exist.\n");
		return;
	}
	if (cnt != 0 && cnt != 2)
	{
		printf("Round trip does not exist.\n");
		return;
	}
	for (i = 0; i <= 1995; i++)
	{
		if (out[i] > 0 && getfa(i) != getfa(f))
		{
			printf("Round trip does not exist.\n");
			return;
		}
	}
	if (cnt > 0 && (out[st] % 2 == 0))
	{
		printf("Round trip does not exist.\n");
		return;
	}
	res.clear();
	dfs(st);
	for (i = 0; i < res.size(); i++)
	{
		if (i == res.size() - 1)
		{
			printf("%d", edge[res[i]].ind);
		}
		else
		{
			printf("%d ", edge[res[i]].ind);
		}
	}
	printf("\n");
}

int main()
{
	while (scanf("%d%d", &x,&y) != EOF)
	{
		if (x == 0 && y == 0)
			break;
		init();
		solve();
	}
	return 0;
}
