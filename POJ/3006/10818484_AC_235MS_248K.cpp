#include <iostream>
using namespace std;
int is_prime(int prime)
{
	if(prime==1)
		return 0;
	for(int i=2;i*i<=prime;i++)
	{
		if(prime%i==0)
			return 0;
	}
	return 1;
}
int main()
{
	long long a,b,n,count,count1=0;
	cin>>a>>b>>n;
	while(a!=0&&b!=0&&n!=0)
	{
		for(count=a;;)
            {
             if(is_prime(count))
               count1++;
			 if(count1==n)
				 break;
			 else
				 count=count+b;
              }
		count1=0;
		cout<<count<<endl;

		cin>>a>>b>>n;
	}
	return 0;
}

