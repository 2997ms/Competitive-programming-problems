#include <iostream>
using namespace std;

int main()
{
	int sons,ex,count1,count2,a[50],result=1,sum=0;
	scanf("%d",&sons);
	scanf("%d",&ex);
	for(count1=1;count1<=sons;count1++)
	{
		scanf("%d",&a[count1]);
	}
if(ex==1)
{
	for(count1=1;count1<=sons;count1++)
	{
		if(a[count1]>0)
		sum=sum+a[count1];
	}
}
else if(ex==2)
{
	for(count1=1;count1<=sons;count1++)
	{
		sum=sum+a[count1]*a[count1];
	}
}
else 
{
	for(count1=1;count1<=sons;count1++)
	{
		if(a[count1]>0)
		sum=sum+a[count1]*a[count1]*a[count1];
	}
}
	cout<<sum<<endl;
	return 0;
}



