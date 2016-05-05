#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	int i,n,sum,a[12];
	cin>>n>>sum;

	for(i=1;i<=10;i++)
		a[i]=i;
	if(n==1)
	{
		cout<<1<<endl;
	}
	else if(n==2)
	{
		cout<<1<<" "<<2<<endl;
	}
	else if(n==3)
	{
		while(1*a[1]+2*a[2]+1*a[3]!=sum)
		{
			next_permutation(a+1,a+3+1);
		}
		cout<<a[1]<<" "<<a[2]<<" "<<a[3]<<endl;
	}
	else if(n==4)
	{
		while(1*a[1]+3*a[2]+3*a[3]+1*a[4]!=sum)
		{
			next_permutation(a+1,a+4+1);
		}
		cout<<a[1]<<" "<<a[2]<<" "<<a[3]<<" "<<a[4]<<endl;
	}
	else if(n==5)
	{
		while(1*a[1]+4*a[2]+6*a[3]+4*a[4]+1*a[5]!=sum)
		{
			next_permutation(a+1,a+5+1);
		}
		cout<<a[1]<<" "<<a[2]<<" "<<a[3]<<" "<<a[4]<<" "<<a[5]<<endl;
	}
	else if(n==6)
	{
		while(1*a[1]+5*a[2]+10*a[3]+10*a[4]+5*a[5]+1*a[6]!=sum)
		{
			next_permutation(a+1,a+n+1);
		}
		cout<<a[1]<<" "<<a[2]<<" "<<a[3]<<" "<<a[4]<<" "<<a[5]<<" "<<a[6]<<endl;
	}
	else if(n==7)
	{
		while(1*a[1]+6*a[2]+15*a[3]+20*a[4]+15*a[5]+6*a[6]+1*a[7]!=sum)
		{
			next_permutation(a+1,a+n+1);
		}
		cout<<a[1]<<" "<<a[2]<<" "<<a[3]<<" "<<a[4]<<" "<<a[5]<<" "<<a[6]<<" "<<a[7]<<endl;
	}
	else if(n==8)
	{
		while(1*a[1]+7*a[2]+21*a[3]+35*a[4]+35*a[5]+21*a[6]+7*a[7]+1*a[8]!=sum)
		{
			next_permutation(a+1,a+n+1);
		}
		cout<<a[1]<<" "<<a[2]<<" "<<a[3]<<" "<<a[4]<<" "<<a[5]<<" "<<a[6]<<" "<<a[7]<<" "<<a[8]<<endl;
	}
	else if(n==9)
	{
		while(1*a[1]+8*a[2]+28*a[3]+56*a[4]+70*a[5]+56*a[6]+28*a[7]+8*a[8]+1*a[9]!=sum)
		{
			next_permutation(a+1,a+n+1);
		}
		cout<<a[1]<<" "<<a[2]<<" "<<a[3]<<" "<<a[4]<<" "<<a[5]<<" "<<a[6]<<" "<<a[7]<<" "<<a[8]<<" "<<a[9]<<endl;
	}
	else if(n==10)
	{
		while(1*a[1]+9*a[2]+36*a[3]+84*a[4]+126*a[5]+126*a[6]+84*a[7]+36*a[8]+9*a[9]+1*a[10]!=sum)
		{
			next_permutation(a+1,a+n+1);
		}
		cout<<a[1]<<" "<<a[2]<<" "<<a[3]<<" "<<a[4]<<" "<<a[5]<<" "<<a[6]<<" "<<a[7]<<" "<<a[8]<<" "<<a[9]<<" "<<a[10]<<endl;
	}

	return 0;
}