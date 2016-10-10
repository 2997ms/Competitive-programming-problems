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
#include <ctime>
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
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)

const int maxn = 2e3 + 5;
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);
ll po(ll a, ll b, ll mod) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1)res = res*a%mod; a = a*a%mod; }return res; }
ll gcd(ll a, ll b) { if (a == 0) { return b; } else { return gcd(b%a, a); } }

int n, m;
int state[maxn], num[maxn];
int chan[maxn][maxn][2];

void solve()
{
	memset(state, 0, sizeof(state));
	memset(num, 0, sizeof(num));
	memset(chan, 0, sizeof(chan));

	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d", &num[i]);
		for (int j = 1; j <= num[i]; j++)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			chan[i][j][0] = u;
			chan[i][j][1] = v;
		}
	}
	int fini = 0;
	int imp = 0;
	while (!fini)
	{
		fini = 1;
		for (int i = 1; i <= m; i++)
		{
			int k = -1;
			int j = 1;
			for (j = 1; j <= num[i]; j++)
			{
				if (state[chan[i][j][0]] == chan[i][j][1])
				{
					break;
				}
				if (chan[i][j][1] == 1)
				{
					k = j;
				}
			}
			if (j > num[i])
			{
				if (k == -1)
				{
					fini = 1;
					imp = 1;
					break;
				}
				fini = 0;
				state[chan[i][k][0]] = 1;
			}
		}
	}
	if (imp)
	{
		puts("IMPOSSIBLE");
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (i > 1)
		{
			printf(" ");
		}
		printf("%d", state[i]);
	}
	printf("\n");
}

int main()
{
#ifndef ONLINE_JUDGE  
	freopen("i.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
#endif
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++)
	{
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}