#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

int wei[10000];

void change_to(char R[10000])
{
	int i,j;
	for(i=7;i>=0;i--)
	{
		int temp=R[i];
		for(j=0;j<=3;j++)
		{
			wei[(7-i)*4+j]=temp&1;
			temp=temp>>1;
		}
	}
}

void change(int x,int y)
{
	if(x>=0&&x<=31)
		wei[x]=0;
	if(y>=2)
	{
		wei[y]=1;
		wei[y-1]=1;
		wei[y-2]=0;
	}
	else if(y==1)
	{
		wei[y]=1;
		wei[y-1]=1;
	}
	else 
		wei[y]=1;

}

void solve()
{
	char temp;
	int i;
	for(i=31;i>=3;i=i-4)
	{
		int sum=wei[i]*8+wei[i-1]*4+wei[i-2]*2+wei[i-3];
		if(sum<9)
		{
			temp=sum+'0';
		}
		else
		{
			temp=sum+87;
		}
		cout<<temp;
	}
}

int main()
{
	char R[10000];
	char temp;
	int x,y;

	for(x=0;x<=7;x++)
	{
		cin>>R[x];
		R[x]=R[x]-'0';
	}
	cin>>temp;
	cin>>x;
	cin>>temp;
	cin>>y;

	change_to(R);
	change(x,y);
	solve();

	return 0;
}