#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

int main()
{
	double ka;
	double ori_con;
	int m;
	int n;
	
	while(1)
	{
		cin>>ka;
		cin>>ori_con;
		cin>>m;
		cin>>n;
		
		if(ka+ori_con+m+n==0)
			break;
		double x=(sqrt(ka*ka+4*ka*ori_con*m*n)-ka)/(2*n);

		printf("%.3f\n",-log10(x));
	}
	return 0;
}
