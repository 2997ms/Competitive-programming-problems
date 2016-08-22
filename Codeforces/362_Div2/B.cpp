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

bool standardizeNumNoDot(string &s)
{
    while (!s.empty() && '0' == s[0]) s.erase(s.begin());
    if (s.empty()) s = "0";//防止n==1的时候，要输出0  
    if (s[0] == '.')s = '0' + s;
    bool notDot = true;
    for (unsigned i = 0; i < s.size() && notDot; i++)
    {
        if ('.' == s[i]) notDot = false;
    }
    if (notDot) return true;

    while (!s.empty() && '0' == s[s.size() - 1]) s.erase(s.end() - 1);
    if (!s.empty() && '.' == s[s.size() - 1]) s.erase(s.end() - 1);
    if (s.empty()) s = "0";
    return false;
}

int main()
{
     string t;
     string a, d;
     cin >> t;
     a = "";
     d = "";
     int len = t.length();

     int i, j, k;
     for (i = 0; i < len; i++)
     {
         if (t[i] != '.')
         {
             a = a + t[i];
         }
         else
         {
             break;
         }
     }
     for (i = i + 1; i < len; i++)
     {
         if (t[i] != 'e')
         {
             d = d + t[i];
         }
         else
         {
             break;
         }
     }
     int b = 0;
     for (i = i + 1; i < len; i++)
     {
         if (t[i] != 'e')
         {
             b = b * 10 + (t[i] - '0');
         }
         else
         {
             break;
         }
     }
     string res = a;
     int f = 0;
     for (i = 0; i < b; i++)
     {
         res = res + d[i];
         if (i == d.length() - 1)
         {
             f = 1;
             break;
         }
     }
     if (f)
     {
         for (i = i + 1; i < b; i++)
         {
             res = res + '0';
         }
     }
     else
     {
         res = res + '.';
         for (; i < d.length(); i++)
         {
             res = res + d[i];
         }
     }
     standardizeNumNoDot(res);
     cout << res << endl;
     return 0;
}