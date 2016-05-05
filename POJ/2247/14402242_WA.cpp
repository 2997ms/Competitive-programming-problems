#include <iostream>
#pragma warning(disable:4996)
using namespace std;
#define MAXN 10006

long long a[MAXN];

int main()
{
	a[1] = 1;
	int i=1,i2,j1=1,j2=1,j3=1,j4=1;
	long long m;

	while(i<=5842)
	{
		m=4000000000;
		if(m>2*a[j1]) m=2*a[j1];
		if(m>3*a[j2]) m=3*a[j2];
		if(m>5*a[j3]) m=5*a[j3];
		if(m>7*a[j4]) m=7*a[j4];

		if(m==2*a[j1])j1++;
		if(m==3*a[j2])j2++;
		if(m==5*a[j3])j3++;
		if(m==7*a[j4])j4++;
		a[++i]=m;
	}
	while(cin>>i2)
	{
		if(!i2)
			break;
		if(i2%10==1)
		{
			cout<<"The "<<i2<<"st humble number is "<<a[i2]<<"."<<endl;
		}
		else if(i2%10==2)
		{
			cout<<"The "<<i2<<"nd humble number is "<<a[i2]<<"."<<endl;
		}
		else if(i2==3)
		{
			cout<<"The 3rd humble number is 3."<<endl;
		}
		else 
		{
			cout<<"The "<<i2<<"th humble number is "<<a[i2]<<"."<<endl;
		}
	}

	return 0;
}
