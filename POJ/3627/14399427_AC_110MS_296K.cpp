#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

bool cmp(int a,int b)
{
	return a>b;
}

int main()
{
	int N,B,i;
	int height[20005];
	cin>>N>>B;

	for(i=0;i<N;i++)
	{
		cin>>height[i];
	}
	sort(height,height+N,cmp);

	int ans=0;
	for(i=0;i<N;i++)
	{
		ans += height[i];
		if(ans>=B)
		{
			cout<<i+1<<endl;
			return 0;
		}
	}


	return 0;
}
