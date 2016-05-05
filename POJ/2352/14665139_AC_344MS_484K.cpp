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
  
void update(int x)  
{  
    while (x <= N)  
    {  
        c[x] += 1;  
        x += lowbit(x);  
    }  
}  
  
int getsum(int x)  
{  
    int sum = 0;  
    while (x > 0)  
    {  
        sum += c[x];  
        x -= lowbit(x);  
    }  
    return sum;  
}  
  
int main()  
{  
	int i;
	int x,y;
	
	memset(a,0,sizeof(a));
	scanf("%d",&n);
	
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&x,&y);
		update(++x);
		a[getsum(x)]++;
	}
	
	for(i=1;i<=n;i++)
	{
		cout<<a[i]<<endl;
	}
    return 0;  
} 
