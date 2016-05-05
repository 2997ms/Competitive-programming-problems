#include <stdio.h>
 
long long int gcd( long long int x, long long int y )
{
    if( y== 0 )
    {
        return x;
    }
    return gcd( y, x% y );
}
 
void exgcd( long long int a, long long int b, long long int &x, long long int &y )
{
    if( b== 0 )
    {
        x= 1;
        y= 0;
        return;
    }
    exgcd( b, a% b, x, y );
    long long int t= x;
    x= y;
    y= t- a/ b* y;
    return;
}
 
int main(  )
{
    long long int x, y, m, n, l;
    while( scanf_s( "%lld %lld %lld %lld %lld", &x, &y, &m, &n, &l )!= EOF )
    {
        long long int a= n- m, b= l, c= x- y, p, q;
        long long int d= gcd( a, b );
        if( c% d )
        {
            puts( "Impossible" );
            continue;
        }
        a/= d, b/= d, c/= d;
        exgcd( a, b, p, q );
        p*= c;
        long long int t= p% b;
        while( t< 0 )
        {   
            t+= b; 
        }
        printf( "%lld\n", t );
    }
}
/*#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

long long xx,yy,d;

void ex_gcd(long long a,long long b)
{
	if(b==0)
	{
		xx=1;
		yy=1;
		d=a;
	}
	else
	{
		ex_gcd(b,a%b);
		
		long long t=xx;
		xx=yy;
		yy=t-(a/b)*yy;
	}
}

int main()
{
	long long x,y,m,n,L;
	cin>>x>>y>>m>>n>>L;

	ex_gcd(m-n,L);

	if((y-x)%d)
	{
		cout<<"Impossible"<<endl;
	}
	else
	{

	}
	system("pause");
	return 0;
}
*/