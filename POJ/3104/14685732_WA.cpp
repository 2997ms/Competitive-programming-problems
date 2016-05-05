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
		temp[i] = max(0ll, val[i] - mid);
		if (k != 0)
		{
			if (temp[i] % k==0)
			{
				sum += temp[i] / k;
			}
			else
				sum += temp[i] / k + 1;
		}
		else
			sum += temp[i];
	}

	if (sum <= mid)
	{
		return true;
	}
	else
	{
		return false;
	}
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
