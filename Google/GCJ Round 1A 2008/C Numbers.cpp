//#pragma comment(linker, "/STACK:102400000,102400000") 
#pragma warning(disable:4996)
#include <fstream>
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
#include <ctime>
#include <list>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
#define eps 1e-10
#define LL_INF 0x3fffffffffffffff
#define INF 0x3f3f3f3f
#define mem(a, b) memset(a, b, sizeof(a))
#define pper(i,n,m) for(int i = n;i >= m; i--)
#define repp(i, n, m) for (int i = n; i <= m; i++)
#define rep(i, n, m) for (int i = n; i < m; i++)
#define sa(n) scanf("%d", &(n))
#define mp make_pair
#define ff first
#define ss second
#define pb push_back

const int maxn = 2e5 + 5;
const ll mod = 1000;
const double PI = acos(-1.0);
ll po(ll a, ll b, ll mod) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1)res = res*a%mod; a = a*a%mod; }return res; }
ll gcd(ll a, ll b) { if (a == 0) { return b; } else { return gcd(b%a, a); } }

struct Matrix
{
	int a[2][2];
	Matrix()
	{
		memset(a, 0, sizeof(a));
	}
	void init()
	{
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				a[i][j] = (i == j);
			}
		}
	}
	Matrix operator +(const Matrix &b)const
	{
		Matrix res;
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				res.a[i][j] = (a[i][j] + b.a[i][j]) % mod;
			}
		}
		return res;
	}
	Matrix operator *(const Matrix &b)const
	{
		Matrix res;
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				for (int k = 0; k < 2; k++)
				{
					res.a[i][j] = res.a[i][j] + (1LL*a[i][k] * b.a[k][j]) % mod;
					res.a[i][j] %= mod;
				}
			}
		}
		return res;
	}
	Matrix operator^(const int &t)const
	{
		Matrix A = (*this), res;
		res.init();
		int p = t;
		while (p)
		{
			if (p & 1)
			{
				res = res*A;
			}
			A = A*A;
			p >>= 1;
		}
		return res;
	}
};

ll n;
void solve()
{
	cin >> n;
	Matrix x;
	x.a[0][0] = 3, x.a[0][1] = 5;
	x.a[1][0] = 1, x.a[1][1] = 3;

	x = x ^ (n);
	ll res = (2 * x.a[0][0] + 999) % 1000;
	printf("%03lld\n", res);
}
int main()
{
	freopen("i.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++)
	{
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}


