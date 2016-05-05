#include <iostream>  
#include <algorithm>  
#include <cmath>  
#include <vector>  
#include <string>  
#include <cstring>  
#pragma warning(disable:4996)  
using namespace std;

int a[20005];
bool cmp(int a,int b)
{
	return a>b;
}

int main()
{
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);
	
	int test,num,i;
	long long ans;
	scanf("%d",&test);
	
	while(test--)
	{
		scanf("%d",&num);
		for(i=0;i<num;i++)
		{
			scanf("%d",a+i);
		}
		sort(a,a+num,cmp);
		ans=0;
		for(i=2;i<num;i=i+3)
		{
			ans += a[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}