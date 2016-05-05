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

const ll mod = 100000007;
const int maxn = 255;
const double PI = acos(-1.0);

int n, b, k;
int lo[maxn], val[maxn][maxn];
int dp_min[maxn][maxn][8][8], dp_max[maxn][maxn][8][8];

void init()
{
	int i, j;
	lo[0] = -1;
	for (i = 1; i <= 250; i++)
	{
		lo[i] = (((i&(i - 1)) == 0) ? lo[i - 1] + 1 : lo[i - 1]);
	}
}

void cal()
{
	int i, j, ilen, jlen;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			dp_min[i][j][0][0] = val[i][j];
			dp_max[i][j][0][0] = val[i][j];
		}
	}
	for (ilen = 0; ilen <= lo[n]; ilen++)
	{
		for (jlen = 0; jlen <= lo[n]; jlen++)
		{
			if (ilen + jlen)
			{
				for (i = 1; (i + (1 << ilen)) -1 <= n; i++)
				{
					for (j = 1; (j + (1 << jlen)) - 1 <= n; j++)
					{
						if (ilen)
						{
							dp_min[i][j][ilen][jlen] = min(dp_min[i][j][ilen - 1][jlen], dp_min[i + (1 << (ilen - 1))][j][ilen - 1][jlen]);
							dp_max[i][j][ilen][jlen] = max(dp_max[i][j][ilen - 1][jlen], dp_max[i + (1 << (ilen - 1))][j][ilen - 1][jlen]);
						}
						else
						{
							dp_min[i][j][ilen][jlen] = min(dp_min[i][j][ilen][jlen - 1], dp_min[i][j + (1 << (jlen - 1))][ilen][jlen - 1]);
							dp_max[i][j][ilen][jlen] = max(dp_max[i][j][ilen][jlen - 1], dp_max[i][j + (1 << (jlen - 1))][ilen][jlen - 1]);
						}
					}
				}
			}
		}
	}
}

int rmq_max(int x1, int y1, int x2, int y2)
{
	int xlen = lo[x2 - x1 + 1];
	int ylen = lo[y2 - y1 + 1];

	return max(max(dp_max[x1][y1][xlen][ylen], dp_max[x2 - (1 << xlen) + 1][y1][xlen][ylen]), max(dp_max[x1][y2 - (1 << ylen) + 1][xlen][ylen], dp_max[x2 - (1 << xlen) + 1][y2 - (1 << ylen) + 1][xlen][ylen]));
}

int rmq_min(int x1, int y1, int x2, int y2)
{
	int xlen = lo[x2 - x1 + 1];
	int ylen = lo[y2 - y1 + 1];

	return min(min(dp_min[x1][y1][xlen][ylen], dp_min[x2 - (1 << xlen) + 1][y1][xlen][ylen]), min(dp_min[x1][y2 - (1 << ylen) + 1][xlen][ylen], dp_min[x2 - (1 << xlen) + 1][y2 - (1 << ylen) + 1][xlen][ylen]));
}

void solve()
{
	int i, j;
	int u, v;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			scanf("%d", &val[i][j]);
		}
	}
	cal();
	for (i = 1; i <= k; i++)
	{
		scanf("%d%d", &u, &v);
		int r1 = rmq_max(u, v, u + b - 1, v + b - 1);
		int r2 = rmq_min(u, v, u + b - 1, v + b - 1);
		printf("%d\n", r1 - r2);
	}
}

int main()
{
#ifndef ONLINE_JUDGE  
	freopen("i.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
#endif

	init();
	while (scanf("%d%d%d", &n, &b, &k) != EOF)
	{
		solve();
	}
	return 0;
}
