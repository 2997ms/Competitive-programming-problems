#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int max(int a,int b)
{
	return a>b?a:b;
}

int main()
{
	int a[50005],count1,count2,count3,left[50005],right[50005],max1;
	cin>>count1;
	while(count1--)
	{
		cin>>count2;
		for(count3=1;count3<=count2;count3++)
		{
			cin>>a[count3];
		}
		left[1]=a[1];
		for(count3=2;count3<=count2;count3++)
		{
			if(left[count3-1]<0)
			{
				left[count3]=a[count3];
			}
			else
				left[count3]=a[count3]+left[count3-1];
		}
	   for(count3=2;count3<=count2;count3++)
		   left[count3]=max(left[count3],left[count3-1]);

		right[count2]=a[count2];
		for(count3=count2-1;count3>=1;count3--)
		{
			if(right[count3+1]<0)
			{
				right[count3]=a[count3];
			}
			else
			{
				right[count3]=a[count3]+right[count3+1];
			}
		}
		for(count3=count2-1;count3>=1;count3--)
			right[count3]=max(right[count3+1],right[count3]);
		max1=left[1]+right[2];
        for(count3=2;count3+1<=count2;count3++)
		{
			max1=max(max1,left[count3]+right[count3+1]);
		}
		cout<<max1<<endl;
	}
return 0;
}
