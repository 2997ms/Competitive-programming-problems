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

#define maxn 205

int n, m;
int res[maxn];
int vis[maxn], vnum[maxn];
int con[maxn][maxn];

void input()
{
	int i, j, k, s, e;
	scanf("%d%d", &n, &m);

	memset(res, 0, sizeof(res));
	memset(con, 0, sizeof(con));
	memset(vis, 0, sizeof(vis));
	memset(vnum, 0, sizeof(vnum));
	
	for (i = 1; i <= m; i++)
	{
		scanf("%d%d", &s, &e);
		if (con[e][s])continue;
		con[e][s] = 1;
		vnum[s]++;
	}
}

int work()
{
	int i, j, k;
	int maxx;
	int resn = n;
	for (i = 1; i <= n; i++)
	{
		maxx = -1;
		for (j = 1; j <= n; j++)
		{
			if (vnum[j] == 0&&res[j]==0)
			{
				maxx = max(maxx, j);
			}
		}
		if (maxx == -1)
		{
			return -1;
		}
		res[maxx] = resn;
		resn--;
		for (j = 1; j <= n; j++)
		{
			if (con[maxx][j])
			{
				con[maxx][j] = 0;
				vnum[j]--;
			}
		}
	}
	return 1;
}

int main()
{
	//freopen("i.txt", "r", stdin);
	//freopen("o.txt", "w", stdout);
	
	int i, t;
	scanf("%d", &t);

	while (t--)
	{
		input();
		if (work() == 1)
		{
			for (i = 1; i <= n; i++)
			{
				if (i == 1)
				{
					printf("%d", res[1]);
				}
				else
				{
					printf(" %d", res[i]);
				}
			}
			printf("\n");
		}
		else
		{
			puts("-1");
		}
	}
	//system("pause");
	return 0;
}