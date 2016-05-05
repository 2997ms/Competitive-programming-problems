#pragma warning(disable:4996)  
#include <iostream>  
#include <algorithm>
#include <cstring>
#include <cstring>
#include <vector>  
#include <string>  
#include <cmath>
#include <queue>
#include <map>
using namespace std;
typedef long long ll;

#define INF 0x3fffffff
const int maxn = 150;

int stac[1005];
ll r0, res;
int N, M, K;
int d[maxn], vis[maxn], pre[maxn];
int cost[maxn][maxn], con[maxn][maxn];

int need[maxn], pro[maxn];
int need_matrix[maxn][maxn], pro_matrix[maxn][maxn];

bool spfa()
{
	int top;
	int i, j, k;
	for (i = 0; i <= N + M + 1; i++)
	{
		d[i] = INF;
		vis[i] = 0;
		pre[i] = i;
	}
	top = 0;
	d[0] = 0;
	stac[++top] = 0;

	while (top)
	{
		int x = stac[top--];
		vis[x] = 0;

		for (int e = 0; e <= N + M + 1; e++)
		{
			if (con[x][e] && d[e] > d[x] + cost[x][e])
			{
				pre[e] = x;
				d[e] = d[x] + cost[x][e];
				if (!vis[e])
				{
					stac[++top] = e;
					vis[e] = 1;
				}
			}
		}
	}
	if (d[N + M + 1] < INF)
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
	for (i = N + M + 1; i != 0; i = pre[i])
	{
		r = min(r, con[pre[i]][i]);
	}
	for (i = N + M + 1; i != 0; i = pre[i])
	{
		con[pre[i]][i] -= r;
		con[i][pre[i]] += r;

		res += cost[pre[i]][i] * r;
	}
}

void input()
{
	int flag = 0;
	int i, j, k;

	memset(need, 0, sizeof(need));
	for (i = 1; i <= N; i++)
	{
		for (k = 1; k <= K; k++)
		{
			scanf("%d", &need_matrix[i][k]);
			need[k] += need_matrix[i][k];
		}
	}

	memset(pro, 0, sizeof(pro));
	for (i = 1; i <= M; i++)
	{
		for (k = 1; k <= K; k++)
		{
			scanf("%d", &pro_matrix[i][k]);
			pro[k] += pro_matrix[i][k];
		}
	}

	for (k = 1; k <= K; k++)
	{
		if (need[k] > pro[k])
		{
			flag = 1;
			break;
		}
	}

	r0 = 0;
	for (k = 1; k <= K; k++)
	{
		for (i = 0; i <= N + M + 1; i++)
		{
			for (j = 0; j <= N + M + 1; j++)
			{
				con[i][j] = cost[i][j] = 0;
			}
		}

		for (i = 1; i <= N; i++)
		{
			for (j = 1; j <= M; j++)
			{
				scanf("%d", &cost[j][i + M]);
				cost[i + M][j] = -cost[j][i + M];

				con[j][i + M] = pro_matrix[j][k];
			}
		}
		if (flag)continue;


		for (i = 1; i <= M; i++)
		{
			con[0][i] = pro_matrix[i][k];
		}
		for (i = 1; i <= N; i++)
		{
			con[i + M][N + M + 1] = need_matrix[i][k];
		}
		res = 0;
		while (spfa())
		{
			compute();
		}
		r0 += res;
	}
	if (flag)
	{
		puts("-1");
	}
	else
	{
		printf("%lld\n", r0);
	}
}

int main()
{
	//freopen("i.txt", "r", stdin);
	//freopen("o.txt", "w", stdout);

	while (scanf("%d%d%d", &N, &M, &K) != EOF)
	{
		if (N == 0 && M == 0 && K == 0)
			break;

		input();
	}
	
	//system("pause");
	return 0;
}