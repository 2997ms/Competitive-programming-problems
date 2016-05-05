#include <iostream>
using namespace std;

int is_round(int p)
{
	int count0=0,count1=0,yu;
	while(p!=0)
	{
		yu=p%2;
		if(yu)
			count1++;
		else
			count0++;
		p=p/2;
	}
	return count0>=count1;
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

