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

const ll mod = 1e9 + 7;
const int maxn = 1005;

int n;
int val[maxn],spa[maxn];

void solve()
{
	int i, j, k;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &val[i]);
	}
	sort(val + 1, val + n + 1);
	val[0] = 0;
	for (i = 1; i <= n; i++)
	{
		spa[i] = val[i] - val[i - 1] + 1;
	}
	int s = 0;
	for (i = n; i >= 1; i -= 2)
	{
		s ^= spa[i];
	}
	if (s)
	{
		puts("Georgia will win");
	}
	else
	{
		puts("Bob will win");
	}
}

int main()
{

	int t;
	scanf("%d", &t);
	
	while(t--)
		solve();

	return 0;
}