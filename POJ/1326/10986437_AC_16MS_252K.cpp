#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main()
{
	string start1,end;
	int distance,sum=0;
	char panduan;
	cin>>start1;
	while(1)
	{
	 while(start1!="0")
	 {
	   if(start1=="#")
		 return 0;
	   cin>>end>>distance>>panduan;
       if(panduan=='F')
	   {
		 sum=sum+2*distance;
	   }
	   else if(panduan=='Y')
	   {
		   if(distance<=500)
		   {
			   sum=sum+500;
		   }
		   else
		   {
			   sum=sum+distance;
		   }
	   }
	   else if(panduan=='B')
	   {
		   sum=sum+distance+ceil((float)distance/2);
	   }
	   cin>>start1;
	 }
	 cout<<sum<<endl;
	 sum=0;
	 cin>>start1;
	}
	return 0;
}