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
	unsigned long long temp1,temp2;
	unsigned long long small,lo;
	unsigned long long i,sum;
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

			if(temp1%small==0)
			{
				temp1=temp1/small;
				small--;
				continue;
			}
			temp2=temp2*small;
			small--;
		}

		cout<<temp1/temp2<<endl;
	}
	return 0;
}
