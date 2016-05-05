#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

int main()
{
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);

	long long n,c;
	while(scanf("%lld%lld",&n,&c)!=EOF)
	{
		if(n==0)
		{
			cout<<0<<endl;
			continue;
		}
		else
		{
			long long x=c/(2*n);
			long long y=x+1;
			cout<<(x*(c-n*x)<y*(c-n*y)?y:x)<<endl;
		}
	}
	return 0;
}
