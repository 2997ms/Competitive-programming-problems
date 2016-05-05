/*#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

int num,flag;
int stick[25];

void dfs(int num,int )
{
}

bool cmp()
{
}
int main()
{
	freopen("i.txt","r",stdin);
	freopen("o.txt","w",stdout);

	int Test,sum,i;
	cin>>Test;
	
	while(Test--)
	{
		cin>>num;
		sum=0;
		flag=0;
		for(i=1;i<=num;i++)
		{
			cin>>stick[i];
			sum += stick[i];
		}
		if(num<4||sum%4)//!!!!num小于4的情况
		{
			cout<<"NO"<<endl;
		}
		else
		{
			sort(stick+1,stick+1+num,cmp);
			dfs(1,sum/4,0);//第一个数代表当前完成第几根木棒了
			               //第二个数代表当前要完成的长度
			               //第三个数代表木棒从第几个开始找起的
			if(flag==1)
			{
			}
			else
			{
			}
		}
	}
	return 0;
}*/

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

int dis[50002];

int main()
{
	int n,i,min,min_x,pre,sum;
	cin>>n;

	dis[0]=0;
	min=1000000000;
	cin>>dis[1];
	for(i=2;i<n-1;i++)
	{
		cin>>dis[i];
		if(dis[i]-dis[i-1]<min)
		{
			min=dis[i]-dis[i-1];
			min_x=i;
		}
	}
	cin>>dis[n-1];
	if(n>=4)
	{
		cout<<sum+dis[n-1]<<endl;
		cout<<min_x+1<<" "<<1<<" "<<n<<" "<<min_x<<endl;
	}
	else
	{
		cout<<0<<endl;
	}
	return 0;
}
