#include <iostream>
using namespace std;

int main()
{
	int sons,ex,count1,count2,a[50],result=1,sum=0;
	cin>>sons;
	cin>>ex;
	for(count1=1;count1<=sons;count1++)
	{
		cin>>a[count1];
	}
	for(count1=1;count1<=sons;count1++)
	{
		int temp=a[count1];
		for(count2=1;count2<ex;count2++)
		{
			temp=temp*a[count1];
		}
		a[count1]=temp;
	}
	for(count1=1;count1<=sons;count1++)
	{
		if(a[count1]>0)
			sum=sum+a[count1];
	}
	cout<<sum<<endl;
	return 0;
}



