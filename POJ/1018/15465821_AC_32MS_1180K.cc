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
#define mem(a, b) memset(a, b, sizeof(a))
#define repp(i, n, m) for (int i = n; i <= m; i++)
#define rep(i, n, m) for (int i = n; i < m; i++)
#define sa(n) scanf("%d", &(n))
#define mp make_pair
#define ff first
#define ss second
#define pb push_back

const int maxn = 205;
const ll mod = 1e9 + 7;
const ll mod2 = (mod - 1)*(mod + 1);
const double PI = acos(-1.0);

int n;
int dp[maxn][1200];//dp[i][j]=k表示选取第i个 b的最小值为j时的总价格为p

void solve()
{
	int i, j, k, h;
	int b, p;
	sa(n);

	repp(i, 0, n)
	{
		repp(j, 0, 1199)
		{
			dp[i][j] = INF;
		}
	}
	repp(i, 1, n)
	{
		sa(k);
		repp(j, 1, k)
		{
			sa(b), sa(p);

			if (i == 1)
			{
				dp[1][b] = min(dp[1][b], p);
			}
			else
			{
				repp(h, 1, 1199)
				{
					if (dp[i - 1][h] == INF)continue;
					if (h < b)
					{
						dp[i][h] = min(dp[i][h], dp[i - 1][h] + p);
					}
					else
					{
						dp[i][b] = min(dp[i][b], dp[i - 1][h] + p);
					}
				}
			}
		}
	}
	double res = 0;
	repp(i, 1, 1199)
	{
		if (dp[n][i] == INF)continue;
		res = max(res, 1.0*i / dp[n][i]);
	}
	printf("%.3f\n", res);
}

int main()
{
#ifndef ONLINE_JUDGE  
	freopen("i.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
#endif
	int t;
	sa(t);
	while (t--)
	{
		solve();
	}
	return 0;
}