#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

int yue,cur,num,i,flag;
int test[200];

long long MaxY(long long x,long long y)
{

	if (!x || !y)
		return x > y ? x : y;
	for (long long t; t = x % y; x = y, y = t)
		;
	return y;
} 

long long cal(long long a,long long b)
{
	return (a*b)/yue;
}


int main()
{
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);
	while(1)
	{
		cin>>num;
		if(num==0)
			break;
		flag=1;
		cur=1;
		for(i=1;i<=num;i++)
		{
			cin>>test[i];
			if(flag)
			{
				yue=MaxY(cur,test[i]);
				cur=cal(cur,test[i]);
			}
			if(cur>=1000000)
			{
				flag=0;
			}
		}
		if(flag)
			cout<<"The CEO must bring "<<cur<<" pounds."<<endl;
		else
			cout<<"Too much money to pay!"<<endl;
	}
	return 0;
}
