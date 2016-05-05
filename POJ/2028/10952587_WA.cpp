#include <iostream>
using namespace std;

int main()
{
	int N,Q,count1,count2,dail,temp,max,min,day[1000];
	cin>>N>>Q;
	while(N!=0||Q!=0)
	{
		memset(day,0,sizeof(day));
		max=0;min=10000;
		for(count1=1;count1<=N;count1++)
		{
			cin>>dail;
			for(count2=1;count2<=dail;count2++)
			{
				cin>>temp;
				day[temp]++;
				if(temp<=min)
					min=temp;
				if(temp>=max)
					max=temp;
			}
		}
		for(count1=min;count1<=max;count1++)
		{
			if(day[count1]>=Q)
			{
				cout<<count1<<endl;
				break;
			}
			
		}
		if(count1==max+1)
		{
			cout<<'0'<<endl;
		}
		cin>>N>>Q;
	}
	return 0;
}
			





