#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

int a[8];

int main()
{
	int sum;
	while(cin>>a[1]>>a[2]>>a[3]>>a[4]>>a[5]>>a[6])
	{
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]==0)
			break;
		sum=0;
		
		sum+=a[6];
		
		sum+=a[5];
		a[1]=max(0,a[1]-11*a[5]);

		sum+=a[4];
		if(a[2]>=a[4]*5)
			a[2]=a[2]-a[4]*5;
		else
		{
			a[2]=0;
			a[1]=max(0,a[1]-(a[4]*5-a[2])*4);
		}

		sum+=(a[3]+3)/4;
		int yu3=a[3]%4;
		if(yu3==1)
		{
			a[2]=max(0,a[2]-5);
			a[1]=max(0,a[1]-7);
		}
		else if(yu3==2)
		{
			a[2]=max(0,a[2]-3);
			a[1]=max(0,a[1]-6);
		}
		else if(yu3==3)
		{
			a[2]=max(0,a[2]-1);
			a[1]=max(0,a[1]-5);
		}

		sum += (a[2]+8)/9;
		int yu2 = a[2]/9;
		a[1]=max(0,a[1]-(36-yu2*4));

		sum += (a[1]+35)/36;
		cout<<sum<<endl;
	}
	return 0;
}
