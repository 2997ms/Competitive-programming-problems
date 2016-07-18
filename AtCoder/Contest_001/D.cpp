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
 
const int maxn = 1e5 + 5;
const ll mod = 998244353;
const double PI = acos(-1.0);
 
int n, m;
int val[maxn];
 
void solve()
{
    int i, j, k;
    sa(n), sa(m);
 
    vector<int>odd;
    vector<int>even;
    repp(i, 1, m)
    {
        sa(val[i]);
        if (val[i] & 1)
        {
            odd.push_back(val[i]);
        }
        else
        {
            even.push_back(val[i]);
        }
    }
    if (n == 1)
    {
        printf("1\n");
        printf("1\n");
        printf("1\n");
    }
    else
    {
        int od_sz = odd.size();
        int ev_sz = even.size();
 
        if (od_sz > 2)
        {
            puts("Impossible");
        }
        else
        {
            if (od_sz == 0)
            {
                rep(i, 0, ev_sz - 1)
                {
                    printf("%d ", even[i]);
                }
                printf("%d\n", even[ev_sz - 1]);
 
                printf("%d\n", ev_sz + 1);
                printf("1 ");
                rep(i, 0, ev_sz - 1)
                {
                    printf("%d ", even[i]);
                }
                printf("%d\n", even[ev_sz - 1] - 1);
            }
            else if (od_sz == 1)
            {
                if (ev_sz == 0)
                {
                    printf("%d\n", odd[0]);
                    printf("2\n");
 
                    printf("%d %d\n", odd[0] - 1, 1);
                }
                else
                {
                    printf("%d ", odd[0]);
                    rep(i, 0, ev_sz - 1)
                    {
                        printf("%d ", even[i]);
                    }
                    printf("%d\n", even[ev_sz - 1]);
                    printf("%d\n", m);
 
                    printf("%d ", odd[0] + 1);
                    rep(i, 0, ev_sz - 1)
                    {
                        printf("%d ", even[i]);
                    }
                    printf("%d\n", even[ev_sz - 1] - 1);
                }
            }
            else if (od_sz == 2)
            {
                if (ev_sz == 0)
                {
                    if (odd[0] == 1 && odd[1] == 1)
                    {
                        printf("1 1\n");
                        printf("1\n");
                        printf("2\n");
                    }
                    else
                    {
                        sort(odd.begin(), odd.end());
                        printf("%d %d\n", odd[0], odd[1]);
                        printf("2\n");
                        printf("%d %d\n", odd[0] + 1, odd[1] - 1);
                    }
                }
                else
                {
                    printf("%d ", odd[0]);
                    rep(i, 0, ev_sz)
                    {
                        printf("%d ", even[i]);
                    }
                    printf("%d\n", odd[1]);
 
                    vector<int>r;
                    r.push_back(odd[0] + 1);
                    rep(i, 0, ev_sz)
                    {
                        r.push_back(even[i]);
                    }
                    if (odd[1] - 1)
                    {
                        r.push_back(odd[1] - 1);
                    }
                    printf("%d\n", r.size());
                    int sz = r.size();
                    rep(i, 0, sz)
                    {
                        if (i == sz-1)
                        {
                            printf("%d\n", r[i]);
                        }
                        else
                        {
                            printf("%d ", r[i]);
                        }
                    }
                }
            }
        }
    }
}
 
int main()
{
     solve();
     return 0;
}