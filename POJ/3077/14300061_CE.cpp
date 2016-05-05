#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int wei[15];

int main()
{
	int count;
	cin>>count;

	while(count--)
	{
		int wang,i,j;
		int str=0;

		memset(wei,0,sizeof(wei));

		cin>>wang;

		i=wang;

		while(i)
		{
			wei[++str]=i%10;
			i /=10;
		}
		for(j=str-1;j>=0;j--)
		{
			if(wei[j]==4)
				continue;
			else if(wei[j]>4)
			{
				wei[str]++;
				break;
			}
			else
				break;
		}
		int result=wei[str]*pow(10,str-1);
		cout<<result<<endl;
	}

	
	return 0;
}