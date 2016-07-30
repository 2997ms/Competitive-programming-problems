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
const ll hax = 1e6 + 7;
 
int n, k;
int vis[15], dig[15], res[15];
 
void solve()
{
    int i, j;
    sa(n), sa(k);
 
    repp(i, 1, k)
    {
        int x;
        sa(x);
        vis[x] = 1;
    }
    int cnt = 0;
    while (n)
    {
        ++cnt;
        dig[cnt] = n % 10;
        n /= 10;
    }
    vector<int>num;
    repp(i, 0, 9)
    {
        if (!vis[i])
            num.push_back(i);
    }
    vector<int>re;
    for (i = cnt; i >=1 ;i--)
    {
        int f = 0;
        for (j = dig[i]; j <= 9; j++)
        {
            if (!vis[j])
            {
                if (j != dig[i])
                {
                    printf("%d", j);
                    for (int h = i - 1; h >= 1; h--)
                    {
                        printf("%d", num[0]);
                    }
                    return;
                }
                else
                {
                    f = 1;
                    re.push_back(j);
                    break;
                }
            }
        }
        if (f == 0)
        {
            break;
        }
    }
    if (re.size() == cnt)
    {
        rep(i, 0, re.size())
        {
            printf("%d", re[i]);
        }
    }
    else
    {
        int f = num[0] == 0 ? num[1] : num[0];
        printf("%d", f);
        for (i = cnt; i >= 1; i--)
        {
            printf("%d", num[0]);
        }
    }
}
 
int main()
{
    solve();
    return 0;
}
