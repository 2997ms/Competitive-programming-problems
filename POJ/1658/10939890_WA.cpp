#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int count1,count2,count3;
	float a[6];
	cin>>count1;
	for(count2=1;count2<=count1;count2++)
	{
		for(count3=1;count3<=4;count3++)
		{
			cin>>a[count3];
		}
		if(floor(a[4]-a[3])==floor(a[3]-a[2])==floor(a[2]-a[1])&&ceil(a[4]-a[3])==ceil(a[3]-a[2])==ceil(a[2]-a[1]))
		{
			a[5]=a[4]+a[4]-a[3];
		}
		else
			a[5]=a[4]*(a[4]/a[3]);
		for(count3=1;count3<=5;count3++)
		{
			cout<<a[count3]<<' ';
		}
		cout<<endl;
	}
	return 0;
}
