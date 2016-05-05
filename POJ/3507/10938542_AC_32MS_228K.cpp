#include <iostream>
using namespace std;

int main()
{
	int count,k,flag[7]={0};
	double sum,max,min,a[7];
	for(;;)
	{
		flag[1]=0;
		flag[2]=0;flag[3]=0;flag[4]=0;flag[5]=0;flag[6]=0;
		sum=0;
	   for(count=1;count<=6;count++)
	   {
		cin>>a[count];
	   }
	   if(a[1]==0&&a[2]==0&&a[3]==0&&a[4]==0&&a[5]==0&&a[6]==0)
	   {
		   break;
	   }
	   max=min=a[1];
	   for(count=1;count<=6;count++)
	   {
		   if(a[count]>=max)
		   {
			   max=a[count];
			   k=count;
		   }
	   }
	    flag[k]=1;
	   for(count=1;count<=6;count++)
	   {
		   if(a[count]<=min)
		   {
			   min=a[count];
			   k=count;
		   }
	   }
		flag[k]=1;
		for(count=1;count<=6;count++)
		{		
				sum=sum+a[count];
		}
		printf("%g\n",(sum-max-min)/4);
	}
	return 0;
}


