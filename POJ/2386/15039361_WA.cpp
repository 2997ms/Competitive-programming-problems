#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <set>
#include <queue>
#include <stack>
using namespace std;

#define INF 0x3fffffff
typedef long long ll;

const int mod = 1e9 + 7;
const int maxn = 105;

int n, m;
int val[maxn][maxn];
int vis[maxn][maxn];

void input()
{
	int i, j;
	scanf("%d%d", &n, &m);

	for (i = 1; i <= n; i++)
	{
		scanf("%s", val[i] + 1);
	}
}

void dfs(int x, int y)
{
	vis[x][y] = 1;
	if (x > 1 && val[x - 1][y] == 'W')
	{
		dfs(x - 1, y);
	}
	if (y > 1 && val[x][y - 1] == 'W')
	{
		dfs(x, y - 1);
	}
	if (x <n  && val[x + 1][y] == 'W')
	{
		dfs(x + 1, y);
	}
	if (y < m && val[x][y + 1] == 'W')
	{
		dfs(x, y + 1);
	}

	if (x > 1 && y > 1 && val[x - 1][y - 1] == 'W')
	{
		dfs(x - 1, y - 1);
	}
	if (y > 1 && x < n&&val[x + 1][y - 1] == 'W')
	{
		dfs(x + 1, y - 1);
	}
	if (x < n  && y < m&&val[x + 1][y+1] == 'W')
	{
		dfs(x + 1, y + 1);
	}
	if (y < m &&x>1 && val[x - 1][y + 1] == 'W')
	{
		dfs(x - 1, y + 1);
	}
}

void solve()
{
	int res = 0;
	int i, j;
	
	memset(vis, 0, sizeof(vis));
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			if (vis[i][j] == 0 && val[i][j] == 'W')
			{
				res++;
				dfs(i, j);
			}
		}
	}
	cout << res << endl;
}

int main()
{
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);
	
	input();
	solve();

	//system("pause");
	return 0;
}
