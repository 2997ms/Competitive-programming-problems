#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

int num,m;
int val[100005];

bool check(int mid)
{
	int i,sum=0;

	for (i = 0; i < num; i++)
	{
		sum += (lower_bound(val + i, val + num, val[i] + mid + 1) - (val + i) - 1);
	}
	if (sum >= m)
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
	int i,left,right,mid;
	while (scanf("%d", &num) != EOF)
	{
		for (i = 0; i < num; i++)
		{
			scanf("%d", &val[i]);
		}
		m = (num*(num - 1) / 2 + 1) / 2;
		sort(val,val+num);
		
		left = 0;
		right = val[num - 1] - val[0];
		
		while (right-left > 1)
		{
			mid = (left + right) / 2;
			
			if (check(mid))
			{
				right = mid ;
			}
			else
			{
				left = mid ;
			}
		}
		cout << right << endl;
	}
	return 0;
}
