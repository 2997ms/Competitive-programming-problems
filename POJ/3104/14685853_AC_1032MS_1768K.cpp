#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

long long n,k;
long long val[100005];
long long temp[100005];

bool check(long long mid)
{
	long long i,sum = 0;
	for (i = 1; i <= n; i++)
	{
		if (val[i] - mid <= 0)
			continue;
		else
		{
			temp[i] = val[i] - mid;
		}
		if (k != 0&&k != 1)
		{
			//一共mid时间  x1*k +(mid-x1)=val[i]
			if ((val[i] - mid) % (k - 1) == 0)
			{
				sum += (val[i] - mid) / (k - 1);
			}
			else
				sum += (val[i] - mid) / (k - 1)+1;
		}
		else
			return false;
	}
	return sum <= mid;
}

int main()
{

	long long i,max_v=-1,left,right,mid;
	scanf("%lld",&n);

	for (i = 1; i <= n; i++)
	{
		scanf("%lld", &val[i]);
		max_v = max(max_v, val[i]);
	}
	scanf("%lld", &k);
	left = 0; right = max_v + 1;
	
	while (right - left > 1)
	{
		mid = (right + left) / 2;
		if (check(mid))
		{
			 right = mid;
		}
		else
		{
			left = mid;
		}
	}
	cout << right << endl;
	return 0;
}
