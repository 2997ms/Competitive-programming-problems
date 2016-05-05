#include <iostream>  
#include <algorithm>  
#include <cmath>  
#include <vector>  
#include <string>  
#include <cstring>  
#pragma warning(disable:4996)  
using namespace std;

int n,k;

int main()
{
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);
	
	int i,speed,read,rest,time,reading_time,num;
	cin>>n>>k;
	for(i=1;i<=k;i++)
	{
		cin>>speed>>read>>rest;
		if(n%speed==0)
		{
			reading_time = n/speed;
		}
		else
		{
			reading_time = (n+speed)/speed;
		}
		if(reading_time%read==0)
		{
			num=reading_time/read;
		}
		else
		{
			num=(reading_time+read)/read;
		}
		cout<<reading_time+(num-1)*rest<<endl;
	}

	return 0;
}