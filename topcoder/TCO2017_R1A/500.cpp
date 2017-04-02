//#pragma comment(linker, "/STACK:102400000,102400000")
#include <fstream>
#include <iostream>
#include <functional>
#include <algorithm>
#include <sstream>
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
#include <bitset>
#include <cassert>
//#include <unordered_map>
//#include <unordered_set>
using namespace std;

typedef long long ll;
#define eps 1e-8
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

const int dx4[5] = { 0,-1,0,1,0 };
const int dy4[5] = { 0,0,1,0,-1 };
const int dx8[9] = { 0,-1,0,1,0,1,1,-1,-1 };
const int dy8[9] = { 0,0,1,0,-1,1,-1,1,-1 };
const int maxn = 204801;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
ll po(ll a, ll b, ll mod) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1)res = res*a%mod; a = a*a%mod; }return res; }
ll gcd(ll a, ll b) { if (a == 0) { return b; } else { return gcd(b%a, a); } }
void YES() { puts("YES"); exit(0); }
void Yes() { puts("Yes"); exit(0); }
void NO() { puts("NO"); exit(0); }
void No() { puts("No"); exit(0); }
void one() { puts("-1"); exit(0); }


struct no
{
	int a, b, c;
	int num;
};
class CheeseSlicing
{
public:
	int totalArea(int A, int B, int C, int S)
	{
		queue<no>que;
		no tmp;
		tmp.a = A, tmp.b = B, tmp.c = C;
		tmp.num = 1;
		que.push(tmp);

		ll ans = 0;
		while (!que.empty())
		{
			no now = que.front();
			que.pop();
			int a = now.a;
			int b = now.b;
			int c = now.c;
			int num = now.num;
			int minn = min(min(a, b), c);
			int maxx = max(max(a, b), c);

			if (minn<S)continue;
			if (maxx<2 * S)
			{
				ans += (maxx*(a + b + c - maxx - minn))*num;
				continue;
			}
			if (maxx%S == 0)
			{
				no nxt;
				nxt.a = minn;
				nxt.b = a + b + c - minn - maxx;
				nxt.c = S;
				nxt.num = num*maxx / S;
				que.push(nxt);
			}
			else
			{
				no nxt1, nxt2;
				nxt1.a = minn;
				nxt1.b = a + b + c - minn - maxx;
				nxt1.c = S;
				nxt1.num = num*(maxx / S - 1);
				que.push(nxt1);

				nxt2.a = minn;
				nxt2.b = a + b + c - minn - maxx;
				nxt2.c = S + maxx%S;
				nxt2.num = num;
				que.push(nxt2);
			}
		}
		return ans;
	}
}wc;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("i.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
#endif
	wc.totalArea(5, 3, 5, 3);
	//system("pause");
	return 0;
}