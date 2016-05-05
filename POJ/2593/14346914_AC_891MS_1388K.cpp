#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int left_v[100005];
int right_v[100005];
int value[100005];

int main()
{
	int Test;
	while(cin>>Test)
	{
		if(!Test)
			break;
		
		left_v[0]=0;
		right_v[0]=0;
		left_v[Test+1]=0;
		right_v[Test+1]=0;

		int i,max_v=-100000000;
		for(i=1;i<=Test;i++)
		{
			cin>>value[i];
		}
		left_v[1]=value[1];
		right_v[Test]=value[Test];

		for(i=2;i<=Test;i++)
		{
			left_v[i]=max(left_v[i-1]+value[i],value[i]);//max(value[i],left_v[i-1]));
		}
		for(i=Test-1;i>=1;i--)
		{
			right_v[i]=max(right_v[i+1]+value[i],value[i]);//max(value[i],left_v[i-1]));
		}
		for(i=2;i<=Test;i++)
		{
			left_v[i]=max(left_v[i-1],left_v[i]);
		}
		for(i=Test-1;i>=1;i--)
		{
			right_v[i]=max(right_v[i+1],right_v[i]);
		}
		for(i=1;i<Test;i++)
		{
			if(left_v[i]+right_v[i+1]>max_v)
				max_v=left_v[i]+right_v[i+1];
		}
		cout<<max_v<<endl;
	}
	return 0;
}