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
	int u;
	int v;
}edge[maxn];

int out[maxn], vis[maxn];

void init()
{
	memset(vis, 0, sizeof(vis));
	memset(out, 0, sizeof(out));
	memset(edge, 0, sizeof(edge));
}

vector<int>res;

int n, m;
int x, y, z;

void dfs(int x)
{
	int i, j, k;
	for (i = 1; i <= m; i++)
	{
		if (vis[i] == 0 && (edge[i].u == x || edge[i].v == x))
		{
			vis[i] = 1;
			if (edge[i].u == x)
			{
				dfs(edge[i].v);
			}
			else
			{
				dfs(edge[i].u);
			}
			res.push_back(i);
		}
	}
}

void solve()
{
	int i, j, k;
	int u, v;
	int st = min(x, y);
	n = 0, m = 0;

	do
	{
		scanf("%d", &z);
		n = max(n, max(x, y));
		m++;
		edge[z].u = x;
		edge[z].v = y;
		out[x]++;
		out[y]++;
	} while (scanf("%d%d", &x, &y) == 2 && x != 0 && y != 0);

	for (i = 1; i <= n; i++)
	{
		if (out[i] & 1)
		{
			printf("Round trip does not exist.\n");
			return;
		}
	}
	res.clear();
	dfs(st);
	for (i = res.size() - 1; i >= 0; i--)
	{
		if (i == 0)
		{
			printf("%d", res[i]);
		}
		else
		{
			printf("%d ", res[i]);
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
