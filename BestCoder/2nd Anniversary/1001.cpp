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
typedef pair<int, ll> pill;

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

const int maxn = 1e7 + 5;
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);

char x[maxn], res[maxn];

bool cmp(char a, char b)
{
    return a > b;
}

void solve()
{
    int i, j, k;
    int len;

    scanf("%s", x + 1);
    len = strlen(x + 1);
    
    mem(res,0);//初始化啊。。。。。。。。。。。。。
    
    if (len == 1)
    {
        puts("Uncertain");
    }
    else
    {
        sort(x + 1, x + len + 1, cmp);
        if (x[2] == '0')
        {
            puts("Uncertain");
            return;
        }
        else
        {
            for (i = len; i >= 1; i--)
            {
                if (x[i] != '0')
                {
                    k = i;
                    break;
                }
            }
            int f = 1;
            int cnt = 0;
            for (i = 1; i <= len; i++)
            {
                if (i == k)continue;
                cnt++;
                res[cnt] = x[i];
            }
            int tmp = 0;
            int t = (res[cnt] - '0') + (x[k] - '0') + tmp;
            if (t < 10)
            {
                res[cnt] = t + '0';
                printf("%s\n", res + 1);
                return;
            }
            else
            {
                res[cnt] = t % 10 + '0';
                tmp = 1;
            }
            for (i = cnt - 1; i >= 1; i--)
            {
                int t = (res[i] - '0') + tmp;
                if (t >= 10)
                {
                    tmp = 1;
                    t %= 10;
                }
                else
                {
                    tmp = 0;
                }
                res[i] = t + '0';
            }
            if (tmp)
            {
                res[0] = '1';
                printf("%s\n", res);
            }
            else
            {
                printf("%s\n", res + 1);
            }

        }
    }
}


int main()
{
     int t;
     sa(t);
     while (t--)
     {
         solve();
     }
    return 0;
}
