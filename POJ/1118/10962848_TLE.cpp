#include <iostream>
using namespace std;

int main()
{
	int count1,count2,count3,count4,x[1002],y[1002],max=-1,result1=1,result2=2;
	while(cin>>count2&&count2)
	{
	for(count1=1;count1<=count2;count1++)
	{
		cin>>x[count1]>>y[count1];
	}
	for(count1=1;count1<=count2;count1++)
	{
		for(count3=count1+1;count3<=count2;count3++)
		{
			for(count4=count3+1;count4<=count2;count4++)
			{
				if(y[count3]==y[count4])
				{
					result1++;
				}
				else if((double)(x[count1]-x[count4])/(y[count1]-y[count4])==(double)(x[count1]-x[count3])/(y[count1]-y[count3]))
				{
					result2++;
				}
				if(result1>max||result2>max)
				{
					max=result1>result2?result1:result2;
				}
			}
				result1=1;result2=2;
		}
	}
	}
	cout<<max<<endl;
	return 0;
}

