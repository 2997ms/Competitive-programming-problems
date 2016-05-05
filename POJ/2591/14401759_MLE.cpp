#include <iostream>
#pragma warning(disable:4996)
using namespace std;

long long a[10000005];

int main()
{
	a[0] = 1;
	int i=1,j2=0,j3=0;
	long long m;
	while(i<=10000000)
	{
		m=9223372036854775807;
		if(m>2*a[j2])m=2*a[j2]+1;
		if(m>3*a[j3])m=3*a[j3]+1;
		
		if(m==2*a[j2]+1)j2++;
        if(m==3*a[j3]+1)j3++;
		a[i]=m;
		i++;
	}
	while(scanf("%d",&i)==1)
	{
		cout<<a[--i]<<endl;
	}
	return 0;
}
