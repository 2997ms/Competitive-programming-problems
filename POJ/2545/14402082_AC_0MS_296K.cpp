#include <iostream>
#pragma warning(disable:4996)
using namespace std;
#define MAXN 10006

long long a[MAXN];

int main()
{
	a[0] = 1;
	int i=1,i2,j1=0,j2=0,j3=0,p1,p2,p3;
	long long m;
	cin>>p1>>p2>>p3>>i2;
	while(i<=10005)
	{
		m=9223372036854775807;
		if(m>p1*a[j1]) m=p1*a[j1];
		if(m>p2*a[j2]) m=p2*a[j2];
		if(m>p3*a[j3]) m=p3*a[j3];

		if(m==p1*a[j1])j1++;
		if(m==p2*a[j2])j2++;
		if(m==p3*a[j3])j3++;
		a[i]=m;
		i++;
	}

	cout<<a[i2]<<endl;

	return 0;
}
