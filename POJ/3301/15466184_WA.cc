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

#define eps 1e-6 
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

int n;
double xx[maxn], yy[maxn];

const int xx0 = 0;
const int yy0 = 0;

double cal(double pi)
{
	double maxx = -INF, maxy = -INF, minx = INF, miny = INF;
	repp(i, 1, n)
	{
		double resx = cos(pi)*(xx[i] - xx0) - sin(pi)*(yy[i] - yy0) + 1.0*xx0;
		double resy = sin(pi)*(xx[i] - xx0) - cos(pi)*(yy[i] - yy0) + 1.0*yy0;

		maxx = max(maxx, resx);
		minx = min(minx, resx);
		maxy = max(maxy, resy);
		miny = min(miny, resy);
	}
	double res = max(maxx - minx, maxy - miny);
	return res*res;
}

void solve()
{
	sa(n);
	repp(i, 1, n)
	{
		cin >> xx[i] >> yy[i];
	}
	double le = 0, ri = PI;
	double mid, res = 0;
	while (ri - le > eps)
	{
		mid = (le + ri) / 2.0;
		double midri = (mid + ri) / 2.0;
		if (cal(mid) < cal(midri))
		{
			ri = midri;
			res = cal(mid);
		}
		else
		{
			le = mid;
			res = cal(midri);
		}
	}
	printf("%.2lf\n", res);
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