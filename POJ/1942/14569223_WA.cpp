#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

long long weight,height;

int main()
{
	long long temp1,temp2;
	long long small,lo;
	long long i,sum;
	while(cin>>weight>>height)
	{
		if(weight+height==0)
			break;
		if(weight==0||height==0)
		{
			cout<<0<<endl;
			continue;
		}
		small=min(weight,height);
		lo=max(weight,height)+small;
		
		temp1=1;
		temp2=1;
		sum=small;

		for(i=1;i<=sum;i++)
		{
			temp1=temp1*lo;
			lo--;

			temp2=temp2*small;
			small--;
		}

		cout<<temp1/temp2<<endl;
	}
	return 0;
}
