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

const ll mod = 1e9 + 7;
const int maxn = 1e6 + 5;
const double PI = acos(-1.0);

int n;

bool check(int x)
{
	int ans = 0;
	int i, j, k;
	for (i = 2; i <= n - 1; i++)
	{
		ans = (ans + x) % i;
	}
	ans = (ans + 1) % n + 1;

	return ans == 2;
}

void solve()
{
	int i;
	for (i = 1;; i++)
	{
		if (check(i))
		{
			printf("%d\n", i);
			return;
		}
	}
}

int main()
{
	while (scanf("%d", &n) != EOF)
	{
		if (n == 0)
			break;
		solve();
	}

	return 0;
}