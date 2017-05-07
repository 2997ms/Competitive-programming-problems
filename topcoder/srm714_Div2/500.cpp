#pragma comment(linker, "/STACK:102400000,102400000")
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
const int maxn = 2e5 + 5;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
ll po(ll a, ll b, ll mod) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1)res = res*a%mod; a = a*a%mod; }return res; }
ll gcd(ll a, ll b) { if (a == 0) { return b; } else { return gcd(b%a, a); } }
void YES() { puts("YES"); exit(0); }
void Yes() { puts("Yes"); exit(0); }
void NO() { puts("NO"); exit(0); }
void No() { puts("No"); exit(0); }
void one() { puts("-1"); exit(0); }

bool check(string s)
{
	int pre = 0, suf = 0;
	for (int i = 0; i<s.length(); i++)
	{
		if (s[i] == '(')
		{
			pre++;
		}
		else
		{
			suf++;
		}
		if (suf>pre)return false;
	}
	return suf == pre;
}

class RemovingParenthesis
{
public:
	map<string, int>hax;
	int countWays(string s)
	{
		if (s == "")return 1;
		if (hax.count(s))return hax[s];
		int res = 0;
		string x = s;

		int cnt = 0;
		string now;
		for (int i = 0; i<x.length(); i++)
		{
			if (x[i] == '(')
			{
				now = x.substr(0, i) + x.substr(i + 1);
				break;
			}
		}
		map<string, int>thi;
		for (int i = 0; i<now.length(); i++)
		{
			if (now[i] == ')')
			{
				string t = now.substr(0, i) + now.substr(i + 1);

				if (check(t))
				{
					cnt++;
					//if (thi.count(t))continue;
					//thi[t]++;
					res += countWays(t);
				}
			}
		}

		hax[s] = res;
		return res;
	}
}wc;

void solve()
{

}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("i.txt", "r", stdin);
	//freopen("o.txt", "w", stdout);
#endif
	solve();
	//system("pause");
	return 0;
}