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

#define INF 0x3fffffffffffffff
#define repp(i, n, m) for (int i = n; i <= m; i++)
#define rep(i, n, m) for (int i = n; i < m; i++)
#define sa(n) scanf("%d", &(n))

const ll mod = 100000007;
const int maxn = 1e5 + 5;
const double PI = acos(-1.0);

int nx;
ll ans;
char val[15];

void dfs(int x, int y1, int y2)
{
	if (x == nx + 1)
	{
		if (y1 == 0 || y2 == 0)
		{
			return;
		}
		else
		{
			ans = min(ans, (ll)abs(y1 - y2));
		}
	}
	else
	{
		dfs(x + 1, y1 * 10 + val[x], y2);
		dfs(x + 1, y1, y2 * 10 + val[x]);
	}
}

int main()
{
	
	int t;
	char ch;
	scanf("%d", &t);
	scanf("%c", &ch);
	
	while (t--)
	{
		nx = 0;
		while (scanf("%c", &ch) != EOF)
		{
			if (ch == '\n')
				break;
			if (ch >= '0'&&ch <= '9')
			{
				++nx;
				val[nx] = ch - '0';
			}
		}
		sort(val + 1, val + 1 + nx);
		ans = INF;
		while (val[1] != 0)
		{
			next_permutation(val + 1, val + 1 + nx);
		}
		do
		{
			dfs(1, 0, 0);
		} while (next_permutation(val + 1, val + 1 + nx));

		printf("%lld\n", ans);
	}

	return 0;
}