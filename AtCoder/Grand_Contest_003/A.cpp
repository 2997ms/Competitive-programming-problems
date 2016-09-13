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
#define LL_INF 0x33ffffffffffffff
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
 
const int maxn = 15;
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);
ll po(ll a, ll b) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1)res = res*a%mod; a = a*a%mod; }return res; }
ll gcd(ll a, ll b) { if (a == 0) { return b; } else { return gcd(b%a, a); } }
 
int f[maxn];
int idx(char x)
{
	if (x == 'N')
	{
		return 0;
	}
	else if (x == 'S')
	{
		return 1;
	}
	else if (x == 'W')
	{
		return 2;
	}
	else
	{
		return 3;
	}
}
 
int main()
{
	string res;
	cin >> res;
	memset(f, 0, sizeof(f));
	rep(i, 0, res.length())
	{
		f[idx(res[i])] = 1;
	}
	if (f[0] == f[1] && f[2] == f[3])
	{
		puts("Yes");
	}
	else
	{
		puts("No");
	}
	return 0;
}