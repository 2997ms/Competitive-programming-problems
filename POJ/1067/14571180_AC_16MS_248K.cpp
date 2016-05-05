#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

int a,b;
int temp_max,temp_min;
int diff;

int main()
{
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);

	while(cin>>a>>b)
	{
		temp_max=max(a,b);
		temp_min=min(a,b);

		diff=temp_max-temp_min;

		if(temp_min==floor(diff*(sqrt(5.0)+1)/2))
		{
			cout<<0<<endl;
		}
		else
		{
			cout<<1<<endl;
		}
	}
	return 0;
}
