#include <iostream>
using namespace std;

int main()
{
	int days,gold,count,surplus;
	for(;cin>>days&&days!=0;)
	{
		gold=0;
		for(count=1;;count++)
		{
			if((count-1)*count/2<=days&&count*(count+1)/2>days)
			{
				break;
			}
		}
		surplus=days-(count-1)*count/2;
		for(int count1=1;count1<count;count1++)
		{
			gold=gold+count1*count1;
		}
		gold=gold+count1*surplus;
		cout<<days<<' '<<gold<<endl;
	}
	return 0;
}
		
        