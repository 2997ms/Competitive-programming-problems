#include <iostream>
using namespace std;
int main()
{
	int count1,count2,num,sum=0,count3;
	cin>>count1;
	for(count2=1;count2<=count1;count2++)
	{
		cin>>num;
		for(count3=1;count3<=num;count3++)
		{
			if(count3*count3<=num)
			{
				sum++;
			}
			else
				break;
		}
		cout<<sum<<endl;
		sum=0;
	}
	return 0;
}


