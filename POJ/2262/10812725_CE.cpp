#include <iostream>
#include <cmath>
using namespace std;
int is_prime(int prime)
{
	for(int i=2;i<=sqrt(prime);i++)
	{
		if(prime%i==0)
			return 0;
	}
	return 1;
}
int main()
{
	int oper,prime3=3,prime2=0;
	cin>>oper;
	while(oper!=0)
	{
		while(prime3<=(oper/2))
		{
			if(is_prime(oper-prime3))
			{
				cout<<oper<<" = "<<prime3<<" + "<<oper-prime3<<endl;
				prime2=1;
				break;
			}
			prime3++;
		}
		if(!prime2)
		{
			cout<<"Goldbach's conjecture is wrong."<<endl; 
		}
		cin>>oper;
		prime3=3;
	}
	
	return 0;
}
