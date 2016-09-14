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
 
const int maxn = 1e5 + 5;
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);
ll po(ll a, ll b, ll mod) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1)res = res*a%mod; a = a*a%mod; }return res; }
ll gcd(ll a, ll b) { if (a == 0) { return b; } else { return gcd(b%a, a); } }
 
int h, w;
int ex, ey;
char val[101][101];
int col[101][101], row[101][101];
int dp[101][101][101][101];
 
int co(int x, int y, int c)
{
	return col[y][c] - col[x - 1][c];
}
 
int ro(int x, int y, int r)
{
	return row[r][y] - row[r][x - 1];
}
 
void solve()
{
	scanf("%d%d", &h, &w);
	for (int i = 1; i <= h; i++)
	{
		scanf("%s", val[i] + 1);
		for (int j = 1; j <= w; j++)
		{
			if (val[i][j] == 'E')
			{
				ex = i;
				ey = j;
			}
		}
	}
 
	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= w; j++)
		{
			row[i][j] = row[i][j - 1] + (val[i][j] == 'o');
		}
	}
	for (int j = 1; j <= w; j++)
	{
		for (int i = 1; i <= h; i++)
		{
			col[i][j] = col[i - 1][j] + (val[i][j] == 'o');
		}
	}
	int leb = ey, rib = w - ey + 1;
	int upb = ex, dob = h - ex + 1;
	int res = 0;
	for (int le = 0; le < leb; le++)
	{
		for (int ri = 0; ri < rib; ri++)
		{
			for (int u = 0; u < upb; u++)
			{
				for (int d = 0; d < dob; d++)
				{
					res = max(res, dp[le][ri][u][d]);
					if (ri < ey - le - 1)
					{//left
						int x = max(d + 1, ex - u);
						int y = min(ex + d, h - u);
						dp[le + 1][ri][u][d] = max(dp[le + 1][ri][u][d], dp[le][ri][u][d] + co(x, y, ey - le - 1));
					}
					if (w - le>ey + ri)
					{//right
						int x = max(d + 1, ex - u);
						int y = min(ex + d, h - u);
						dp[le][ri + 1][u][d] = max(dp[le][ri + 1][u][d], dp[le][ri][u][d] + co(x, y, ey + ri + 1));
					}
					if (d < ex - u - 1)
					{//up
						int x = max(ri + 1, ey - le);
						int y = min(ey + ri, w - le);
						dp[le][ri][u + 1][d] = max(dp[le][ri][u + 1][d], dp[le][ri][u][d] + ro(x, y, ex - u - 1));
 
					}
					if (h - u>ex + d)
					{//down
						int x = max(ri + 1, ey - le);
						int y = min(ey + ri, w - le);
						dp[le][ri][u][d + 1] = max(dp[le][ri][u][d + 1], dp[le][ri][u][d] + ro(x, y, ex + d + 1));
					}
				}
			}
		}
	}
	printf("%d\n", res);
	//printf("%d\n", dp[leb - 1][rib - 1][upb - 1][dob - 1]);
}
 
int main()
{
	solve();
	return 0;
}