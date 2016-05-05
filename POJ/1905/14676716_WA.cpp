#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

#define esp 1e-5

double L, N, C, S;

bool check(double mid)
{
	double ans = 2 * asin((L / 2) / ((L*L + 4 * mid*mid) / (8 * mid)))*((L*L + 4 * mid*mid) / (8 * mid));
	return ans >= S;
}

int main()
{
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);
	
	double left, right, mid;

	while (cin>>L>>N>>C)
	{
		if (L + N + C < 0 )
			break;
		S = (1 + N*C)*L;
		left = 0.0;
		right = 2*L;

		while (right - left > esp)
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
		printf("%.3lf\n",mid);
	}
	return 0;
}
