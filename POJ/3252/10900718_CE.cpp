#include <iostream>
#include <cmath>
using namespace std;

int is_round(int p)
{
	int count,count1,result=1;
	for(count=0;;)
	{
		if(pow(2,count)<=p&&pow(2,count+1)>p)
			break;
		else 
			count++;
	}
		p=p-pow(2,count);
	while(p>0)
	{
		for(count1=0;;)
		{
			if(pow(2,count1)<=p&&pow(2,count1+1)>p)
			break;
		else 
			count1++;
		}
		result++;
		p=p-pow(2,count1);
	}	
	return ++count-result>=result; 
}
int main()
{
	int start,finnish,count,result=0;
	cin>>start>>finnish;

	for(count=start;count<=finnish;count++)
	{
		if(is_round(count))
			result++;
	}
	cout<<result<<endl;
	return 0;
}


