#include <iostream>
using namespace std;

int main()
{
	int count1,count2,a[35],sum=0,temp,sumtemp,sign;
    while(cin>>count1&&count1)
	{
	  for(count2=1;count2<=count1;count2++)
	  {
		cin>>a[count2];
		sum=sum+a[count2];
	  }
	  if(sum%2==0)
	  {
		  temp=sum/2;
		  sumtemp=0;
		  sign=1;
		  for(count2=1;count2<count1;count2++)
		  {
			  sumtemp=sumtemp+a[count2];
              if(sumtemp==temp)
			  {
				  sign=0;
				  cout<<"Sam stops at position "<<count2<<" and Ella stops at position "<<count2+1<<'.'<<endl;
				  break;
			  }
		  }
		  if(sign)
		  {
			  cout<<"No equal partitioning."<<endl;
		  }
	  }
	  else
	  {
		cout<<"No equal partitioning."<<endl;
	  }
	  sum=0;
	}
	return 0;
}

