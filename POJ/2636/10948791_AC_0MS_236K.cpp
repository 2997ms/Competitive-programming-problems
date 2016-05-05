#include <iostream>
using namespace std;

int main()
{
	int count1,count2,count3,count4,sum,i;
	cin>>count1;
	for(count2=1;count2<=count1;count2++)
	{
		cin>>count3;
		sum=0;
		for(count4=1;count4<=count3;count4++)
		{
			cin>>i;
			sum=sum+i;
		}
		cout<<sum-(count3-1)<<endl;
	}
	return 0;
}

