#include <iostream>
using namespace std;

int main()
{
	int count1,count2,count3,count4,x[1002],y[1002],max=-1,result2=2;
    cin>>count2;
	
		for(count1=1;count1<=count2;count1++)
	{
		cin>>x[count1]>>y[count1];
	}
		max=-1;
	for(count1=1;count1<=count2;count1++)
	{
		for(count3=count1+1;count3<=count2;count3++)
		{
			for(count4=count3+1;count4<=count2;count4++)
			{
	            if((double)(x[count1]-x[count4])*(y[count1]-y[count3])==(double)(x[count1]-x[count3])*(y[count1]-y[count4]))
				{
					result2++;
				}
				if(result2>max)
				{
					max=result2;
				}
			}
				result2=2;
		}
	}
	cout<<max<<endl;
	
	return 0;
}

