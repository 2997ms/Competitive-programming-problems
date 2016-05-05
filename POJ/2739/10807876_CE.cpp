#include <iostream>
using namespace std;
int is_prime(int prime)
{    int i;
	for(i=2;i<prime;i++)
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
	int count=0,sum=0,prime=2,currentprime,test;
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
	   cout<<count<<endl;
	   cin>>test;
	   prime=2;
	   sum=0;
	   count=0;
     }
     return 0;
}

