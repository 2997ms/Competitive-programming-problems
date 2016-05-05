#include <iostream>
using namespace std;

int main()
{
	int sons,ex,count1,a[200],result=1,sum=0;
	cin>>sons;
	cin>>ex;
	for(count1=1;count1<=sons;count1++)
	{
		cin>>a[count1];
	}
	if(ex==2)
	{
		for(count1=1;count1<=sons;count1++)
		{
			for(a[0]=1;a[0]<=ex;a[0]++)
			{
				result=result*a[count1];
			}
			sum=sum+result;
			result=1;
		}
	}
	else
	{
		for(count1=1;count1<=sons;count1++)
		{
				for(a[0]=1;a[0]<=ex;a[0]++)
			{
					if(a[count1]>0)
				result=result*a[count1];
					else
						result=0;
			}
				sum=sum+result;
				result=1;
		}
	}
	cout<<sum<<endl;
	return 0;
}


