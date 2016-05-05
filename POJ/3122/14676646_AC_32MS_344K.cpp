#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

#define PI acos(-1.0)

int n, f;
int ri[10005];
double r[10005];

bool check(double mid)
{
	int sum = 0;
	int i,temp;
	double mid_temp;

	for (i = 0; i < n; i++)
	{
		sum += (int)(r[i] / mid);
	}
	if (sum < f)
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
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);

	int Test,i;
	double left, right, mid;

	cin>>Test;
	
	while(Test--)
	{
		scanf("%d%d",&n,&f);
		
		f++;
		for (i = 0; i < n; i++)
		{
			scanf("%d",&ri[i]);
			
			r[i] = (double)PI*ri[i] * ri[i];
		}
		sort(r, r + n);

		left = 0;
		right = r[n - 1];

		while (right - left > 1.0e-4)
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
		printf("%.4lf\n",left);
	}
	return 0;
}
