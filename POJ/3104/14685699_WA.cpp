#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

int n,k;
int val[100005];
int temp[100005];

bool check(int mid)
{
	int i,sum = 0;
	for (i = 1; i <= n; i++)
	{
		temp[i] = max(0, val[i] - mid);
		sum += ceil((double)temp[i]/(double)k);
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
	int i,max_v=-1,left,right,mid;
	scanf("%d",&n);

	for (i = 1; i <= n; i++)
	{
		scanf("%d", &val[i]);
		max_v = max(max_v, val[i]);
	}
	scanf("%d", &k);
	left = -1; right = max_v + 1;
	
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
