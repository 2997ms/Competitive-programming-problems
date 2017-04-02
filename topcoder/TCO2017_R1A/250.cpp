/*
ID: wangcho2
PROG: ride
LANG: C++11
*/
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
//#include <unordered_map>
//#include <unordered_set>
using namespace std;

typedef long long ll;
#define eps 1e-10
#define LL_INF 0x3fffffffffffffff
#define INF 2e9
#define mem(a, b) memset(a, b, sizeof(a))
#define pper(i,n,m) for(int i = n;i >= m; i--)
#define repp(i, n, m) for (int i = n; i <= m; i++)
#define rep(i, n, m) for (int i = n; i < m; i++)
#define sa(n) scanf("%d", &(n))
#define mp make_pair
#define ff first
#define ss second
#define pb push_back

const int maxn = 1e3 + 5;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
ll po(ll a, ll b,ll mod) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1)res = res*a%mod; a = a*a%mod; }return res; }
ll gcd(ll a,ll b){ if(a==0){return b;}else{ return gcd(b%a,a);}}
void YES(){puts("YES");exit(0);}
void Yes(){puts("Yes");exit(0);}
void NO(){puts("NO");exit(0);}
void No(){puts("No");exit(0);}
const int dx4[5] = { 0,-1,0,1,0 };
const int dy4[5] = { 0,0,1,0,-1 };
const int dx8[9] = { 0,-1,0,1,0,1,1,-1,-1 };
const int dy8[9] = { 0,0,1,0,-1,1,-1,1,-1 };

class PingPongQueue
{
public:
	vector <int> whoPlaysNext(vector <int> ski, int N, int K)
	{
		queue<int>que;
		vector<int>res;
		for(int i=1;i<ski.size();i++)
		{
			que.push(i+1);
		}
		int now=1;
		int cnt=0;
		repp(i,1,K-1)
		{
			int left = ski[now-1];
			int t=que.front();
			int right=ski[t-1];
			que.pop();
			if(left>right)
			{
				cnt++;
				que.push(t);
				if(cnt==N)
				{
					que.push(now);
					cnt=0;
					now=que.front();
					que.pop();
				}
			}
			else
			{
				cnt=1;
				que.push(now);
				now=t;
				if(cnt==N)
				{
					que.push(now);
					cnt=0;
					now=que.front();
					que.pop();
				}
			}
		}
		int left = ski[now-1];
		int t=que.front();
		int right=ski[t-1];
		que.pop();
		if(left<right)
		{
			res.push_back(left);
			res.push_back(right);
		}
		else
		{
			res.push_back(right);
			res.push_back(left);
		}
		return res;
	}
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("/Users/2997ms/Desktop/eve/algorithm/algorithm/i.txt", "r", stdin);
    //freopen("/Users/2997ms/Desktop/eve/algorithm/algorithm/o.txt", "w", stdout);
#endif
    //solve();
    return 0;
}
