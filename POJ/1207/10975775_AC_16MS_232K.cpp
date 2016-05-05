#include <iostream>
using namespace std;

int main()
{
	int i,j,count,count1,result,max;
	while(scanf("%d%d",&i,&j)==2)
	{
	     	result=1;max=-1;
		if(i<j)
		{
			for(count=i;count<=j;count++)
			{
				count1=count;
				while(count1!=1)
				{
				if(count1%2==0)
				{
					count1/=2;
				}
				else
				{
					count1=3*count1+1;
				}
				result++;
				}
				if(result>max)
				{
					max=result;
				}
				result=1;
			}
		}
		else
		{	for(count=j;count<=i;count++)
			{
			count1=count;
				while(count1!=1)
				{
				if(count1%2==0)
				{
					count1/=2;
				}
				else
				{
					count1=3*count1+1;
				}
				result++;
				}
				if(result>max)
				{
					max=result;
				}
					result=1;
			}
		}
		cout<<i<<' '<<j<<' '<<max<<endl;
	}
	return 0;
}

