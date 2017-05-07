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
#define DE(val) cout<<#val<<": "<<val<<endl;

const int dx4[5] = { 0,-1,0,1,0 };
const int dy4[5] = { 0,0,1,0,-1 };
const int dx8[9] = { 0,-1,0,1,0,1,1,-1,-1 };
const int dy8[9] = { 0,0,1,0,-1,1,-1,1,-1 };
const int maxn = 1e2 + 5;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
ll po(ll a, ll b, ll mod) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1)res = res*a%mod; a = a*a%mod; }return res; }
ll gcd(ll a, ll b) { if (a == 0) { return b; } else { return gcd(b%a, a); } }
void YES() { puts("YES"); exit(0); }
void Yes() { puts("Yes"); exit(0); }
void NO() { puts("NO"); exit(0); }
void No() { puts("No"); exit(0); }
void one() { puts("-1"); exit(0); }

int vis[maxn];
class Saleswoman
{
public:
	int minMoves(vector <int> pos, vector <int> delta)
	{
		memset(vis, 0, sizeof(vis));

		int ans = 0;
		int pre = 0;
		int ri = 0;
		int own = 0;
		long long sum = 0;
		for (int i = 0; i<pos.size(); i++)
		{
			ri = max(ri, pos[i]);
			sum += abs(pos[i] - pre);
			pre = pos[i];
			if (own + delta[i]<0)
			{
				int t_ri = 0;
				for (int j = i + 1; j<pos.size(); j++)
				{
					if (delta[j]>0 && vis[j] == 0)
					{
						own += delta[j];
						t_ri = max(t_ri, pos[j]);
						vis[j] = 1;
					}
					if (own + delta[i] >= 0)
					{
						break;
					}
				}
				sum += 2 * (t_ri - ri);
				ri = t_ri;
			}
			if (vis[i] == 0)
				own += delta[i];
		}
		return sum;
	}
}wc;