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

#define INF 1<<25 
#define repp(i, n, m) for (int i = n; i <= m; i++)
#define rep(i, n, m) for (int i = n; i < m; i++)
#define sa(n) scanf("%d", &(n))
#define mp make_pair
#define ff first
#define ss second
#define pb push_back

const int maxn = 1e4 + 5;
const ll mod = 1000000007;
const double PI = acos(-1.0);

void solve()
{
	int n, k,res = 0, f = 0;
	sa(n);
	repp(i, 1, n)
	{
		sa(k);
		if (k > 1)
			f = 1;
		res = res^k;
	}
	if (f)
	{
		if (res)
		{
			puts("John");
		}
		else
		{
			puts("Brother");
		}
	}
	else
	{
		if (n & 1)
		{
			puts("Brother");
		}
		else
		{
			puts("John");
		}
	}
}

int main()
{
	int t;
	sa(t);
	while (t--)
	{
		solve();
	}
	return 0;
}