#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

unsigned long long weight,height;

int main()
{
	unsigned long long small,lo;
	unsigned long long i,j,result;
	while(cin>>weight>>height)
	{
		if(weight==0||height==0)
			break;
		small=min(weight,height);
		lo=weight+height;
		
		result=1;

		for(i=lo,j=1;j<=small;i--,j++)
		{
			result = (result*i)/j;
		}

		cout<<result<<endl;
	}
	return 0;
}
