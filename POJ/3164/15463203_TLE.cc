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

#define INF 1<<25 
#define repp(i, n, m) for (int i = n; i <= m; i++)
#define rep(i, n, m) for (int i = n; i < m; i++)
#define sa(n) scanf("%d", &(n))
#define mp make_pair
#define ff first
#define ss second
#define pb push_back

const int maxn = 2e4 + 5;
const ll mod = 1000000007;
const double PI = acos(-1.0);

int n, m;
struct po
{
	double x;
	double y;
}point[105];

struct ed
{
	int u;
	int v;
	double w;
}edge[maxn];

double dis(po a, po b)
{
	return sqrt(1.0*(a.x - b.x)*(a.x - b.x) + 1.0*(a.y - b.y)*(a.y - b.y));
}

double in[105];
int pre[105], vis[105], id[105];

double directed_mst(int root, int nv, int ne)
{
	int i, j, k;
	double res = 0;
	while (true)
	{
		repp(i, 1, nv)
		{
			in[i] = INF;
		}
		repp(i, 1, ne)
		{
			int u = edge[i].u;
			int v = edge[i].v;

			if (u != v&&edge[i].w < in[v])
			{
				pre[v] = u;
				in[v] = edge[i].w;
			}
		}
		repp(i, 1, nv)
		{
			if (i == root)continue;
			if (in[i] == INF)return -1;
		}
		int cntnode = 0;
		memset(id, -1, sizeof(id));
		memset(vis, -1, sizeof(vis));

		in[root] = 0;
		repp(i, 1, nv)
		{
			res += in[i];
			int v = i;
			while (vis[v] != i&&id[v] == -1 && v != root)
			{
				vis[v] = 1;
				v = pre[v];
			}
			if (v != root&&id[v] == -1)
			{
				cntnode++;
				for (int u = pre[v]; u != v; u = pre[u])
				{
					id[u] = cntnode;
				}
				id[v] = cntnode;
			}
		}
		if (cntnode == 0)
			break;
		repp(i, 1, nv)
		{
			if (id[i] == -1)
			{
				++cntnode;
				id[i] = cntnode;
			}
		}
		repp(i, 1, ne)
		{
			int v = edge[i].v;
			edge[i].u = id[edge[i].u];
			edge[i].v = id[edge[i].v];
			if (edge[i].u != edge[i].v)
				edge[i].w -= in[v];
		}
		nv = cntnode;
		root = id[root];
	}
	return res;
}

void solve()
{
	int i, j, k;
	repp(i, 1, n)
	{
		scanf("%lf%lf", &point[i].x, &point[i].y);
	}
	repp(i, 1, m)
	{
		sa(edge[i].u), sa(edge[i].v);
		if (edge[i].u != edge[i].v)
			edge[i].w = dis(point[edge[i].u], point[edge[i].v]);
		else
			edge[i].w = INF;
	}
	double res = directed_mst(1, n, m);
	if (res == -1)
	{
		puts("poor snoopy");
	}
	else
	{
		printf("%.2lf\n", res);
	}
}

int main()
{
	while (scanf("%d%d", &n, &m) != EOF)
	{
		solve();
	}
	return 0;
}