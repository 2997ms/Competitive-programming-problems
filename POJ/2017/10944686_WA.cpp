#include <iostream>
using namespace std;

int main()
{
	int count1,count2,sum=0,speed,hour[100];
	for(;cin>>count1&&count1!=-1;)
	{
		hour[0]=0;
		for(count2=1;count2<=count1;count2++)
		{
			cin>>speed>>hour[count2];

			sum=sum+speed*(hour[count2]-hour[count2-1]);
		
		}
		cout<<sum<<endl;
		sum=0;
	}
	return 0;
}
