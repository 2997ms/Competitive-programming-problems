#include<iostream>
#include<iomanip>
#pragma warning(disable:4996) 
using namespace std;

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	long long i,x0=3,y0=1,last_x=3,last_y=1,x,y;
	for(i=1;i<=10;i++)
	{
		x=last_x*x0+8*last_y*y0;
		y=last_x*y0+last_y*x0;

		cout<<setw(10)<<y<<setw(10)<<(x-1)/2<<endl; 

		last_x=x;
		last_y=y;
	}      
	return 0;
}