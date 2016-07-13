/*
 首先二分答案x，之后如果大于x的那么必然有|li-x| +| y-ri | <= x
 这个是曼哈顿距离，将其转换成切比雪夫距离之后，维护一个矩形就好了。
*/
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

const int maxn = 500005;
const ll mod = 1000000007;
const double PI = acos(-1.0);

int n, m;
int li[maxn], ri[maxn];

bool check(int x)
{
    int i, j, k;
    int up = INF, right = INF;
    int down = -INF, left = -INF;
    repp(i, 1, m)
    {
        if (ri[i] - li[i] <= x)continue;
        int ut = ri[i] + li[i] + x;
        int dt = ri[i] + li[i] - x;
        int lt = ri[i] - li[i] - x;
        int rt = ri[i] - li[i] + x;
        
        if (dt > up)
        {
            return 0;
        }
        if (rt < left)
        {
            return 0;
        }
        if (ut < down)
        {
            return 0;
        }
        if (lt > right)
        {
            return 0;
        }
        left = max(left, lt);
        down = max(down, dt);
        up = min(up, ut);
        right = min(right, rt);
    }
    return 1;
}

void solve()
{
    int i, j, k;
    repp(i, 1, m)
    {
        sa(li[i]), sa(ri[i]);
        if (li[i] > ri[i])
        {
            swap(li[i], ri[i]);
        }
    }
    int le = 0, rii = INF;
    int mid;
    while (le < rii)
    {
        mid = (le + rii) >> 1;
        if (check(mid))
        {
            rii = mid;
        }
        else
        {
            le = mid + 1;
        }
    }
    printf("%d\n", rii);
}

int main()
{
    while (scanf("%d%d", &n, &m) != EOF)
    {
        solve();
    }
    return 0;
}
