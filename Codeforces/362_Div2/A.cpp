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

const int maxn = 100005;
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);

int main()
{
     ll t, s, x;
     cin >> t >> s >> x;
     if (x == t)
     {
         puts("YES");
         return 0;
     }
     x = x - t;
     if (x%s == 0 && x / s >= 1)
     {
         puts("YES");
         return 0;
     }
     x--;
     if (x%s == 0 && x / s >= 1)
     {
         puts("YES");
         return 0 ;
     }
     puts("NO");
     return 0;
}