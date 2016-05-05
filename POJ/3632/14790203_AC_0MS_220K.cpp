#include <iostream>  
#include <algorithm>  
#include <cmath>  
#include <vector>  
#include <string>  
#include <cstring>  
#pragma warning(disable:4996)  
using namespace std;

int a[500];

int main()
{
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);

	int test,num,maxn,mixn,i;
	cin>>test;
	
	while(test--)
	{
		cin>>num;
		
		maxn=-1;
		mixn=500;

		for(i=1;i<=num;i++)
		{
			cin>>a[i];
			if(a[i]>maxn)
			{
				maxn=a[i];
			}
			if(a[i]<mixn)
			{
				mixn=a[i];
			}
		}
		cout<<(maxn-mixn)*2<<endl;
	}
	return 0;
}