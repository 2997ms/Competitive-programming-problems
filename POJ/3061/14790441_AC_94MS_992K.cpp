#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

long long n,s,a[1000005];

int main()
{	
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);

	int test,i,ans,start;
	long long sum;
	scanf("%d",&test);

	while(test--)
	{
		scanf("%lld%lld",&n,&s);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		ans=n+1;
		a[0]=0;
		sum=0;
		start=1;
		for(i=1;i<=n;i++)
		{
			sum += a[i];
			while(sum>s)
			{
				sum = sum - a[start];
				start++;
			}
		   if(sum+a[start-1]>s && i-(start-1)+1<ans)
		   {
			   ans=i-(start-1)+1;
		   }
		}
		if(ans == n+1)
		{
			cout<<0<<endl;
		}
		else
		{
			cout<<ans<<endl;
		}
	}
	//system("pause");
	return 0;
}
