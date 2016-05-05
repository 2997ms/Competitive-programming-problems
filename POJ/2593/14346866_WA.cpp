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
		right_v[Test+2]=0;

		int i,max_v=0;
		for(i=1;i<=Test;i++)
		{
			cin>>value[i];
		}
		for(i=1;i<=Test;i++)
		{
			left_v[i]=max(left_v[i-1]+value[i],value[i]);//max(value[i],left_v[i-1]));
		}
		for(i=Test;i>=1;i--)
		{
			right_v[i]=max(right_v[i+1]+value[i],value[i]);//max(value[i],left_v[i-1]));
		}
		for(i=1;i<=Test;i++)
		{
			left_v[i]=max(left_v[i-1],left_v[i]);
		}
		for(i=1;i<=Test;i++)
		{
			right_v[i]=max(right_v[i+1],right_v[i]);
		}
		for(i=1;i<=Test;i++)
		{
			if(left_v[i]+right_v[i+1]>max_v)
				max_v=left_v[i]+right_v[i+1];
		}
		cout<<max_v<<endl;
	}
	return 0;
}