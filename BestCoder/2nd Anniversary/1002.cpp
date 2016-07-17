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

const int maxn = 1e5 + 5;
const ll mod = 998244353;
const double PI = acos(-1.0);

int n;
int b[maxn],c[maxn];

void solve()
{
	int i,j,k;

	sa(n);

	repp(i,1,n)
	{
		sa(b[i]);
	}
	repp(i,1,n)
	{
		sa(c[i]);
	}
	if(b[1]!=c[1])
	{
		puts("0");
		return;
	}
	int le = b[1];
	int ri = c[1];
	int num = 0;
	ll res = 1;
	
	repp(i,2,n)
	{
		if(b[i]!=b[i-1]&&c[i]!=c[i-1])
		{
			puts("0");
			return;
		}
		if(b[i]==ri&&c[i]==le)
		{
			res = res*num%mod;
			num--;
		}
		else if(b[i]!=b[i-1])
		{
			if(b[i]<=b[i-1])
			{
				num += ri-b[i]-1;
				ri = b[i];
			}
			else
			{
				puts("0");
				return;
			}
		}
		else 
		{
			if(c[i]>=c[i-1])
			{
				num += c[i]-le-1;
				le=c[i];
			}
			else
			{
				puts("0");
				return;
			}
		}
		//cout<<"le : "<<le<<endl;
		//cout<<"ri : "<<ri<<endl;
		//cout<<num<<endl;
	}
	printf("%lld\n",res);
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
