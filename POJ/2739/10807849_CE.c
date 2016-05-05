#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;
int is_prime(int prime)
{
	for(int i=2;i<=sqrt(prime);i++)
	{
		if(prime%i==0)
		{
			return 0;
		}
	}
	return 1;
}
main()
{
	int count=0,sum=0,prime=2,currentprime;
	int test;
    cin>>test;
	while(test!=0)
	{
		if(is_prime(test))
	   
			count++;
		
		currentprime=prime;
    
		while(currentprime<test) 
		{   
			prime=currentprime;              
			
			while(prime<test)
			{
              if(is_prime(prime))
			  {
               sum=prime+sum;
			  }
	          if(sum==test)
			  {
               count++;
               break;
			  }
		      prime++;
			}
			  currentprime++;
		   
		while(!is_prime(currentprime))
		   
				   currentprime++;
			sum=0;
		}
	   printf("%d\n",count);
	   cin>>test;
	   prime=2;
	   sum=0;
	   count=0;
     }
     return 0;
}
