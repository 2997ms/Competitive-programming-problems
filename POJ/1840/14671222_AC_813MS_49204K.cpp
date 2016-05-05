#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

short hash1[25000000];

int main()
{
	int a1, a2, a3, a4, a5;
	int x1, x2, x3, x4, x5;
	int temp;
	long long sum;

	scanf("%d%d%d%d%d",&a1,&a2,&a3,&a4,&a5);

	memset(hash1, 0, sizeof(hash1));
	for (x1 = -50; x1 <= 50; x1++)
	{
		if (x1 == 0)continue;
		for (x2 = -50; x2 <= 50; x2++)
		{
			if (x2 == 0)continue;
			
			temp = -1*(a1*x1*x1*x1 + a2*x2*x2*x2);

			if (temp < 0)
			{
				temp += 25000000;
			}
			hash1[temp]++;
		}
	}
	sum = 0;
	for (x3 = -50; x3 <= 50; x3++)
	{
		if (x3 == 0)continue;
		for (x4 = -50; x4 <= 50; x4++)
		{
			if (x4 == 0)continue;
			for (x5 = -50; x5 <= 50; x5++)
			{
				if (x5 == 0)continue;
				
				temp = a3*x3*x3*x3 + a4*x4*x4*x4 + a5*x5*x5*x5;
				
				if (temp < 0)
				{
					temp += 25000000;
				}
				if (temp >= 0 && temp < 25000000) 
				{
					sum += hash1[temp];
				}
			}
		}
	}
	cout << sum << endl;
	return 0;
}
