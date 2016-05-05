#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

queue <int> q;
int ans[10005];

bool pend(int a)
{
	int i;
	for(i=2;i<a;i++)
	{
		if(a%i==0)
			return false;
	}
	return true;
}

int main()
{
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);

	int Test,temp,dis,wei1,wei2,wei3,wei4,i,k;
	cin>>Test;

	while(Test--)
	{
		while(q.size())q.pop();
		
		cin>>temp>>dis;
		
		q.push(temp);
		memset(ans,0,sizeof(ans));

		while(1)
		{
			temp=q.front();
			q.pop();
			if(temp==dis)
			{
				cout<<ans[temp]<<endl;
				break;
			}
			
			wei1=temp%10;
			wei2=(temp%100-wei1)/10;
			wei4=temp/1000;
			wei3=temp/100-wei4*10;

			for(i=1;i<=9;i=i+2)
			{
				k=wei4*1000+wei3*100+wei2*10+i;
				if(wei1!=i && pend(k) &&!ans[k])
				{
					ans[k]=ans[temp]+1;
					q.push(k);
				}
			}
			for(i=0;i<=9;i++)
			{
				k=wei4*1000+wei3*100+i*10+wei1;
				if(wei2!=i && pend(k)&&!ans[k])
				{
					ans[k]=ans[temp]+1;
					q.push(k);
				}
			}
			for(i=0;i<=9;i++)
			{
				k=wei4*1000+i*100+wei2*10+wei1;
				if(wei3!=i && pend(k)&&!ans[k])
				{
					ans[k]=ans[temp]+1;
					q.push(k);
				}
			}
			for(i=1;i<=9;i++)
			{
				k=i*1000+wei3*100+wei2*10+wei1;
				if(wei4!=i && pend(k)&&!ans[k])
				{
					ans[k]=ans[temp]+1;
					q.push(k);
				}
			}
		}
	}

	return 0;
}
