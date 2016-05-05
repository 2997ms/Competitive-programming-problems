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

#define INF 0x3fffffff
#define repp(i, n, m) for (int i = n; i <= m; i++)
#define rep(i, n, m) for (int i = n; i < m; i++)
#define sa(n) scanf("%d", &(n))

const ll mod = 100000007;
const int maxn = 1e5 + 5;
const double PI = acos(-1.0);

int nx;
int ans;
int val[15];

int cal(int st, int en)
{
	int i, j, k;
	int ans = 0;
	for (i = st; i <= en; i++)
	{
		if (val[st] == 0)
			return INF;
		ans = ans * 10 + val[i];
	}
	if (ans == 0)
		return INF;
	else
		return ans;
}

int main()
{
#ifndef ONLINE_JUDGE  
	freopen("i.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
#endif
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
		if (nx == 2)
		{
			printf("%d\n", val[2] - val[1]);
			continue;
		}
		ans = INF;
		do
		{
			int x, y;
			x = cal(1, nx >> 1);
			y = cal((nx >> 1) + 1, nx);
			if (x != INF&&y != INF)
			{
				ans = min(ans, abs(x - y));
			}
			
			x = cal(1, (nx >> 1) - 1);
			y = cal(nx >> 1 , nx);
			if (x != INF&&y != INF)
			{
				ans = min(ans, abs(x - y));
			}
			
		} while (next_permutation(val + 1, val + 1 + nx));

		printf("%d\n", ans);
	}

	return 0;
}