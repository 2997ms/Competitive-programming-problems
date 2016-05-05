#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

long long yue;

void ex_gcd(long long a,long long b, long long &xx,long long &yy)
{
	if(b==0)
	{
		xx=1;
		yy=0;
		yue=a;
	}
	else
	{
		ex_gcd(b,a%b,xx,yy);

		long long t=xx;
		xx=yy;
		yy=t-(a/b)*yy;

	}
}


int main()
{
	long long A,B,C,k,k2,xx,yy;

	while(scanf_s("%lld%lld%lld%lld",&A,&B,&C,&k))
	{
		if(!A&&!B&&!C&&!k)
			break;

		k2=(1LL<<k);
		ex_gcd(-C,k2,xx,yy);
		
		if((A-B)%yue)
		{
			cout<<"FOREVER"<<endl;
		}
		else
		{
			xx=xx*((A-B)/yue);
			long long r=k2/abs(yue);
			xx=(xx%r+r)%r;
			printf("%lld\n",xx);
		}
	}
	return 0;
}
