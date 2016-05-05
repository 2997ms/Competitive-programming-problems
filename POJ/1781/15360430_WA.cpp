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

ll n, e;

void solve()
{
	ll i;
	ll k = 1;
	for (i = 1; i <= e; i++)
	{
		k = k * 10;
	}
	k = k*n;
	if (k == 1 || k == 2)
	{
		printf("1\n");
		return;
	}
	i = 1;
	while (i < k)
	{
		i <<= 1;
	}
	i >>= 1;
	k = k - i;
	printf("%lld\n", 2 * k + 1);
}

int main()
{

	while (scanf("%llde%lld", &n, &e) != EOF)
	{
		if (n == 0 && e == 0)
		{
			break;
		}
		solve();
	}
	return 0;
}