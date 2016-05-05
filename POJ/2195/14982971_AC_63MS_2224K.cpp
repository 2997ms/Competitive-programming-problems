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

#define INF 200000

struct no
{
	int x;
	int y;
}man[505], house[505];

inline int step(int i, int j)
{
	return abs(man[i].x - house[j].x) + abs(man[i].y - house[j].y);
}

int res;
int n, m;
int cnt_m, cnt_h;
int d[505];
int vis[505];
int pre[505];
char val[105][105];
int cost[505][505];
int con[505][505];

void input()
{
	int i, j, k;

	memset(val, 0, sizeof(val));
	cnt_m = 0;
	cnt_h = 0;
	for (i = 1; i <= n; i++)
	{
		cin >> val[i] + 1;
		for (j = 1; j <= m; j++)
		{
			if (val[i][j] == 'm')
			{
				cnt_m++;
				man[cnt_m].x = i;
				man[cnt_m].y = j;
			}
			if (val[i][j] == 'H')
			{
				cnt_h++;
				house[cnt_h].x = i;
				house[cnt_h].y = j;
			}
		}
	}

}

bool spfa()
{
	int i, j, k;
	for (i = 1; i <= cnt_h + cnt_m + 1; i++)
	{
		d[i] = INF;
		vis[i] = 0;
		pre[i] = i;
	}
	d[0] = 0;
	
	queue<int>qu;
	qu.push(0);

	while (!qu.empty())
	{
		int x = qu.front();
		qu.pop();
		vis[x] = 0;

		for (int e = 1; e <= cnt_h + cnt_m + 1; e++)
		{
			if (con[x][e]&& d[e] > d[x] + cost[x][e])
			{
				pre[e] = x;
				d[e] = d[x] + cost[x][e];
				if (!vis[e])
				{
					qu.push(e);
					vis[e] = 1;
				}
			}
		}
	}
	if (d[cnt_h + cnt_m + 1] < INF)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void compute()
{
	int i;
	int r = INF;
	for (i = cnt_h + cnt_m + 1; i != 0; i = pre[i])
	{
		r = min(r, con[pre[i]][i]);
	}
	for (i = cnt_h + cnt_m + 1; i != 0; i = pre[i])
	{
		con[pre[i]][i] -= r;
		con[i][pre[i]] += r;

		res += cost[pre[i]][i] * r;
	}
}

void solve()
{
	int i, j;

	memset(con, 0, sizeof(con));
	memset(cost, 0, sizeof(cost));
	
	for (i = 1; i <= cnt_m; i++)
	{
		for (j = 1; j <= cnt_h; j++)
		{
			con[i][cnt_m + j] = 1;
			cost[i][cnt_m + j] = step(i, j);
			cost[cnt_m + j][i] = -cost[i][cnt_m + j];
		}
	}
	for (i = 1; i <= cnt_m; i++)
	{
		con[0][i] = 1;
	}
	for (j = 1; j <= cnt_h; j++)
	{
		con[cnt_m + j][cnt_m + cnt_h + 1] = 1;
	}
	res = 0;
	while (spfa())
	{
		compute();
	}
	printf("%d\n", res);
}

int main()
{
	//freopen("i.txt", "r", stdin);
	//freopen("o.txt", "w", stdout);

	while (scanf("%d%d", &n, &m) != EOF)
	{
		if (n == 0 && m == 0)
			break;
		input();
		solve();
	}

	return 0;
}
