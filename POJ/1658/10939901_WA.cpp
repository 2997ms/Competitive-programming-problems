#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int count1,count2,count3,a[6];
	float result;
	cin>>count1;
	for(count2=1;count2<=count1;count2++)
	{
		for(count3=1;count3<=4;count3++)
		{
			cin>>a[count3];
		}
		if(a[4]-a[3]==a[3]-a[2]==a[2]-a[1])
		{
			a[5]=a[4]+a[4]-a[3];
			cout<<a[1]<<' '<<a[2]<<' '<<a[3]<<' '<<a[4]<<' '<<a[5]<<endl;
		}
		else
		{
			result=a[4]*(float)(a[4]/a[3]);
cout<<a[1]<<' '<<a[2]<<' '<<a[3]<<' '<<a[4]<<' '<<result<<endl;
		}
	}
	return 0;
}
