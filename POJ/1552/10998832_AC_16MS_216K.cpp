#include <iostream>
using namespace std;

int main()
{
	int inter[105]={0},count1,count2,result=0;

	while(cin>>count1&&count1!=-1)
	{
		inter[count1]++;
		while(cin>>count2&&count2)
		{
			inter[count2]++;
		}

	for(count1=1;count1<=52;count1++)
	{
		if(inter[count1]==1&&inter[2*count1]==1)
		{
			result++;
		}
	}
	cout<<result<<endl;
	result=0;
	memset(inter,0,sizeof(inter));
	}
	return 0;
}
			
			



