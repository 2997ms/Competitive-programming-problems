#include <iostream>
#include <cmath>
#include <algorithm>
#pragma warning(disable:4996) 
using namespace std;

int num[100005];
int fre[100005];
int n,q;

int max_v[100005][20];

void RMQ()
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		max_v[i][0]=fre[i];
	}
	for(j=1;j<=n;j++)
	{
		for(i=1;i+(1<<j)-1<=n;i++)
		{
			max_v[i][j]=max(max_v[i][j-1],max_v[i+(1<<(j-1))][j-1]);
		}
	}
}

int cal(int h,int k)
{
	int temp=k-h+1;
	int temp2=log((double)temp)/log(2.0);

	return max(max_v[h][temp2],max_v[k-(1<<temp2)+1][temp2]);
}

int main()
{


	while(cin>>n)
	{
		int i,h,k;
		if(n==0)
			break;
		cin>>q;

		memset(fre,0,sizeof(fre));
		memset(max_v,0,sizeof(max_v));
		for(i=1;i<=n;i++)
		{
			cin>>num[i];
			if(i==1)
			{
				fre[1]=1;
			}
			else
			{
				if(num[i]==num[i-1])
					fre[i]=fre[i-1]+1;
				else
					fre[i]=1;
			}
		}

		RMQ();
		
		for(i=1;i<=q;i++)
		{
			cin>>h>>k;
			int temp=h;
			int t=0;

			while(num[h+t]==num[h])
			{
				t++;
			}
			temp=h+t;
			int temp2=cal(temp,k);
			cout<<max(t,temp2)<<endl;
		}
	}
    return 0;
}