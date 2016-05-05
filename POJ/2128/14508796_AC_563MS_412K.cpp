#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

int dis[50002];

int main()
{
	int n,i,min,min_x,pre;
	cin>>n;

	dis[0]=0;
	min=1000000000;
	cin>>dis[1];
	for(i=2;i<n-1;i++)
	{
		cin>>dis[i];
		if(dis[i]-dis[i-1]<min)
		{
			min=dis[i]-dis[i-1];
			min_x=i;
		}
	}
	cin>>dis[n-1];
	if(n>=4)
	{
		cout<<min+dis[n-1]<<endl;
		cout<<min_x+1<<" "<<1<<" "<<n<<" "<<min_x<<endl;
	}
	else
	{
		cout<<0<<endl;
	}
	return 0;
}
