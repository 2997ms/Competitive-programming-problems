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
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);

	unsigned long long temp1;
	unsigned long long small,lo;
	unsigned long long i,j,result;
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
		
		temp1=lo-small;
		result=1;

		for(i=lo,j=1;j<=small;i--,j++)
		{
			result= result*i/(double)j;
		}

		cout<<result<<endl;
	}
	return 0;
}
