/*
 * =====================================================================================
 *
 *       Filename:  1061.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2011年12月08日 11时27分16秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  MaZheng (blog.csdn.net/mazheng1989), mazheng19891019@gmail.com
 *        Company:  Dalian University Of Technology
 *
 * =====================================================================================
 */


#include<stdio.h>

//please declare parameters here.
long long k,t,d;

//please declare functions here.
void extend_gcd(long long a,long long b)
{
	if(b==0)
	{
		k=1;
		t=0;
		d=a;
	}
	else
	{
		extend_gcd(b,a%b);
		long long temp;
		temp=k;
		k=t;
		t=temp-(a/b)*t;
	}
}
int main()
{
	freopen("input.txt","r",stdin);
    long long a,b;
    long long int x,y,m,n,l;
	//input your ...
	while(scanf("%lld %lld %lld %lld %lld",&x,&y,&m,&n,&l)!=EOF)
	{
		a=m-n;
		b=y-x;
		if(a<0)
		{
			a=-a;
			b=-b;
		}
		extend_gcd(a,l);
		if(b%d!=0)
		{
			printf("Impossible\n");
		}
		else
		{
			k=k*b/d;
			t=t*b/d;
			l=l/d;
			if(k>=0)
				k=k%l;
			else
				k=k%l+l;
			if(k==0)
				k=l;
			printf("%lld\n",k);
		}
//		printf("%lld %lld %lld %lld %lld",x,y,m,n,l);
	}

	return 0;
}
