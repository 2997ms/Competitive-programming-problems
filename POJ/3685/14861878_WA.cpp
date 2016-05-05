#include <iostream>  
#include <algorithm>  
#include <cmath>  
#include <vector>  
#include <string>  
#include <cstring>  
#pragma warning(disable:4996)  
using namespace std;

#define maxn 1e12
typedef long long ll;

ll m, n;
ll le, ri, mid;

ll cal(ll i, ll j)
{
	return i*i + 100000 * i + j*j - 100000 * j + i*j;
}

ll check(ll x)
{
	ll i, le, ri, mid, cnt;
	
	ll temp;
	cnt = 0;
	for (i = 1; i <= n; i++)
	{
		le = 0;//mid不能取到0，所以这里的le取1
		ri = n + 1;//因为mid可能要取到n，所以这里的ri要取到比n大的数
		
		mid = le + (ri - le) / 2;
		while (le < ri)
		{
                       mid = le + (ri - le) / 2;
			temp = cal(mid, i);
			if (cal(mid, i) < x)
			{
				le = mid + 1;
			}
			else
			{
				ri = mid ;
			}
		}
		cnt += (mid);//经过计算，这里始终是多计算了一个1，所以要在这里把它扣掉
	}
	return cnt;
}

int main()
{
	//freopen("i.txt", "r", stdin);
	//freopen("o.txt", "w", stdout);

	int test;
	scanf("%d", &test);

	while (test--)
	{
		scanf("%lld%lld", &n, &m);
		le = -maxn;
		ri = maxn;

		mid = le + (ri - le) / 2;
		while (le < ri)
		{
			if (check(mid) < m)//检查小于 mid 的个数
			{
				le = mid + 1;
			}
			else
			{
				ri = mid;
			}
			mid = le + (ri - le) / 2;
		}
		printf("%lld\n", mid-1);//有m个小于mid的数，所以第m大的数就是mid-1
	}

	//system("pause");
	return 0;
}