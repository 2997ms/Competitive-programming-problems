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

const int maxn = 1e6 + 5;
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);
ll po(ll a, ll b) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1)res = res*a%mod; a = a*a%mod; }return res; }

int res;
int vis[15][15], v[15];

void dfs(int st, int m, int n, int step)
{
    if (step >= m&&step <= n)
    {
        res++;
    }
    if (step == n)
    {
        return;
    }
    v[st] = 1;
    for (int i = 1; i <= 9; i++)
    {
        if (v[i])continue;
        if (vis[st][i] && !v[vis[st][i]])
        {
            continue;
        }
        dfs(i, m, n, step + 1);
    }
    v[st] = 0;
}

class Solution 
{
public:
    int numberOfPatterns(int m, int n) 
    {
        mem(vis, 0);
        vis[1][3] = vis[3][1] = 2;
        vis[4][6] = vis[6][4] = 5;
        vis[7][9] = vis[9][7] = 8;

        vis[1][7] = vis[7][1] = 4;
        vis[2][8] = vis[8][2] = 5;
        vis[3][9] = vis[9][3] = 6;

        vis[1][9] = vis[9][1] = 5;
        vis[3][7] = vis[7][3] = 5;

        res = 0;
        mem(v, 0);
        for (int i = 1; i <= 9; i++)
        {
            dfs(i, m, n, 1);
        }
        return res;
    }
}t;
