#include <iostream>  
#include <cstring>  
#include <cstdio>  
#include <algorithm>  
#pragma warning(disable:4996)
using namespace std;  
  
const int N = 32005;  
  
int c[N],a[N],n;  
  
  
int lowbit(int x)  
{  
    return x & (-x);  
}  
   
int main()  
{   
	int i,query;
	long long ask;
	scanf("%d",&query);

	for(i=1;i<=query;i++)
	{
		cin>>ask;
		cout<<ask-(lowbit(ask)-1)<<" "<<ask+(lowbit(ask)-1)<<endl;
	}
    return 0;  
} 
