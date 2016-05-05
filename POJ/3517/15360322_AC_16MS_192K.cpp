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

#define INF 0x33ffffff
#define eps 1e-8

const ll mod = 1000000007;
const int maxn = 1e6 + 5;
const double PI = acos(-1.0);

int n, k, m;

void solve()
{
	int i, j;
	int ans = 0;
	for (i = 2; i <= n - 1; i++)
	{
		ans = (ans + k) % i;
	}
	ans = (ans + m) % n + 1;
	printf("%d\n", ans);
}

int main()
{
	while (scanf("%d%d%d", &n, &k, &m) != EOF)
	{
		if (n == 0 && k == 0 && m == 0)
		{
			break;
		}
		solve();
	}

	return 0;
}