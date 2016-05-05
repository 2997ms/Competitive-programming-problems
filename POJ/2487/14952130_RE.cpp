#pragma warning(disable:4996)  
#include <iostream>  
#include <algorithm>  
#include <cmath>  
#include <vector>  
#include <string>  
#include <cstring> 
#include <set>
#include <map>
using namespace std;

int val[1005];

bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	freopen("i.txt", "r", stdin);
	freopen("o.txt", "w", stdout);

	int casen, t, sum, n, k;
	scanf("%d", &t);

	for (casen = 1; casen <= t; casen++)
	{
		scanf("%d%d", &sum, &n);
		for (k = 0; k < n; k++)
		{
			scanf("%d", val + k);
		}
		sort(val, val + n, cmp);

		int s = 0;
		for (k = 0; k < n; k++)
		{
			s = s + val[k];
			if (s >= sum)
				break;
		}
		cout << "Scenario #" << casen << ":" << endl;
		if (s >= sum)
		{
			cout << k+1 << endl << endl;
		}
		else
		{
			cout << "impossible" << endl << endl;
		}
	}

	return 0;
}