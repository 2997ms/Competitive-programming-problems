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

const int maxn = 5005;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
ll po(ll a, ll b,ll mod) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1)res = res*a%mod; a = a*a%mod; }return res; }
ll gcd(ll a,ll b){ if(a==0){return b;}else{ return gcd(b%a,a);}}

int n;
int val[maxn],v[maxn];

int check(int x)
{
    v[1]=x;
    for(int i=1;i<n;i++)
    {
        v[i+1]=val[i]-v[i];
        if(v[i+1]>=100000)
        {
            if(((i+1)&1)==0)
            {
                return -1;
            }
            else
            {
                return 1;
            }
        }
        else if(v[i+1]<=0)
        {
            if(((i+1)&1)==0)
            {
                return 1;
            }
            else
            {
                return -1;
            }
        }
    }
    if(v[n]+v[1]>val[n])
    {
        return 1;
    }
    else if(v[n]+v[1]<val[n])
    {
        return -1;
    }
    return 0;
}
int max(int x,int y)
{
    if(x>y)
    {
        return x;
    }
    else
    {
        return y;
    }
}
void solve()
{
    cin>>n;

    for(int i=1;i<=3;i++)
    {
        if(i==3)
        {
            cout<<"? 1 3"<<endl;
        }
        else
        {
            cout<<"?"<<" "<<i<<" "<<i+1<<endl;
        }
        cin>>val[i];
        fflush(stdout);
    }
    int sum=val[1]+val[2]+val[3];
    sum=sum/2;
    v[3]=sum-val[1];// 1 2
    v[2]=sum-val[3];// 1 3
    v[1]=sum-val[2];
    //cout<<sum<<endl;//
    for(int i=4;i<=n;i++)
    {
        cout<<"?"<<" "<<i-1<<" "<<i<<endl;
        cin>>val[i];
        fflush(stdout);
        v[i]=val[i]-v[i-1];
    }
    printf("! ");
    for(int i=1;i<=n;i++)
    {
        if(i>1)
        {
            printf(" ");
        }
        printf("%d",v[i]);
    }
}

int main()
{
    solve();
    return 0;
}