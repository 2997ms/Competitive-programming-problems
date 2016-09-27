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

const int maxn = 2e5+5;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
ll po(ll a, ll b,ll mod) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1)res = res*a%mod; a = a*a%mod; }return res; }
ll gcd(ll a,ll b){ if(a==0){return b;}else{ return gcd(b%a,a);}}

int n,t;
char val[maxn];
int v[maxn];

void solve()
{
    scanf("%d%d",&n,&t);
    scanf("%s",val+1);
    int pos=0;
    int f=0;
    for(int i=n;i>=1;i--)
    {
        if(val[i]=='.')
        {
            pos=i;
            break;
        }
    }
    int p=0;
    for(int i=pos+1;i<=n;i++)
    {
        if(val[i]>='5')
        {
            p=i;
            break;
        }
    }
    if(p==0)
    {
        cout<<val+1<<endl;
    }
    else
    {
        int cur=p;
        while(t>=1&&cur>pos)
        {
            if(val[cur]<'4')
            {
                break;
            }
            cur--;
            t--;
        }
        if(cur==pos)
        {
            int k=1;
            for(int i=pos-1;i>=1;i--)
            {
                int t=val[i]-'0'+k;
                if(t>=10)
                {
                    val[i]=t%10+'0';
                    k=1;
                }
                else
                {
                    val[i] = t+'0';
                    k=0;
                }
            }
            if(k==1)
            {
                cout<<"1";
                for(int i=1;i<=pos-1;i++)
                {
                    printf("%c",val[i]);
                }
            }
            else
            {
                for(int i=1;i<=pos-1;i++)
                {
                    printf("%c",val[i]);
                }
            }
        }
        else
        {
            for(int i=1;i<cur;i++)
            {
                cout<<val[i];
            }
            //cout<<char(val[cur]+1)<<endl;
            printf("%c",char(val[cur]+1));
        }
    }
}

int main()
{
    solve();
    return 0;
}