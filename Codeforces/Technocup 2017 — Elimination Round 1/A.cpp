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

const int maxn = 2e4+5;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
ll po(ll a, ll b,ll mod) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1)res = res*a%mod; a = a*a%mod; }return res; }
ll gcd(ll a,ll b){ if(a==0){return b;}else{ return gcd(b%a,a);}}

ll a,b;
map<ll,ll>hax;

void solve()
{
    cin>>a>>b;
    queue<ll>que;
    que.push(a);

    while(!que.empty())
    {
        ll k=que.front();
        que.pop();

        if(k>b)continue;
        if(k==b)
        {
            vector<ll>res;
            while(k)
            {
                res.push_back(k);
                k=hax[k];
            }
            puts("YES");
            reverse(res.begin(),res.end());
            int sz=res.size();
            printf("%d\n",sz);
            rep(i,0,res.size())
            {
                if(i)
                {
                    printf(" ");
                }
                printf("%lld",res[i]);
            }
            return;
        }
        else
        {
            hax[2*k]=k;
            hax[10*k+1]=k;
            que.push(2*k);
            que.push(10*k+1);
        }
    }
    puts("NO");
}

int main()
{
    solve();
    return 0;
}