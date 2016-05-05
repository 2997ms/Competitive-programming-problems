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
    while( scanf( "%lld %lld %lld %lld %lld", &x, &y, &m, &n, &l )!= EOF )
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