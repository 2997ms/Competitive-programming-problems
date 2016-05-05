#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

long long d;

void ex_gcd(long long a,long long b,long long &xx,long long &yy)
{
	if(b==0)
	{
		xx=1;
		yy=0;
		d=a;
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
	long long x,y,m,n,L,xx,yy;
	cin>>x>>y>>m>>n>>L;

	ex_gcd(n-m,L,xx,yy);

	if((x-y)%d)
	{
		cout<<"Impossible"<<endl;
	}
	else
	{
		xx=xx*((x-y)/d);
        while(xx<0)
			xx+=L/d;
		cout<<xx<<endl;
	}

	return 0;
}
