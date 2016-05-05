#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <deque>
#include <ctime>;
#include <set>
#include <map>
using namespace std;

#define INF 0x3fffffff
typedef long long ll;

const ll mod = 1e9 + 7;
const int maxn = 505;

int n;
int val[3][maxn][maxn];

void solve()
{
	int i, j, k;
	ll res;

	for (i = 0; i < 3; i++)
	{
		for (j = 1; j <= n; j++)
		{
			for (k = 1; k <= n; k++)
			{
				scanf("%d", &val[i][j][k]);
			}
		}
	}
	int g = 1, x, y;
	for (i = 1; i <= 40000 && g; i++)
	{
		res = 0;
		x = rand() % n + 1;
		y = rand() % n + 1;

		for (k = 1; k <= n; k++)
			res = res + val[0][x][k] * val[1][k][y];
		if (res != val[2][x][y])
			g = 0;
	}
	if (g)
		puts("YES");
	else
		puts("NO");
}

int main()
{
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);
	
	srand((unsigned)time(0));
	while (scanf("%d", &n) != EOF)
	{
		solve();
	}

	//system("pause");
	return 0;
}