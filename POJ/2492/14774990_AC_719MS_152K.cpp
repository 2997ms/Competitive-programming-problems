#include <iostream>  
#include <algorithm>  
#include <cmath>  
#include <vector>  
#include <string>  
#include <cstring>  
#pragma warning(disable:4996)  
using namespace std;

int n,m;
int pre[200015];

int findpre(int x)  
{  
	while(x!=pre[x])  
	{  
		x=pre[x];  
	}  
	return x;  
}  

void union_set(int x,int y)
{	
	int pre_x=findpre(x);
	int pre_y=findpre(y);

	if(pre_x == pre_y)  
		return;  
	else if(pre_x>pre_y)  
	{  
		int temp = pre_x;  
		pre_x = pre_y;  
		pre_y = temp;  
	}  
	pre[pre_y]=pre_x;
}

bool same(int x,int y)
{
	return findpre(x) == findpre(y);  
}

int main()
{
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);

	int test,i,j,temp1,temp2;
	scanf("%d",&test);

	for(i=1;i<=test;i++)
	{
		printf("Scenario #%d:\n",i);
		scanf("%d%d",&n,&m);

		for(j=1;j<=2*n;j++)
		{
			pre[j]=j;
		}

		bool flag=false;
		for(j=1;j<=m;j++)
		{
			scanf("%d%d",&temp1,&temp2);
			
			if(flag)continue;
			
			if(same(temp1,temp2))
			{
				flag=true;
				continue;
			}
			union_set(temp1,temp2+n);
			union_set(temp1+n,temp2);
		}
		if(flag)
		{
			printf("Suspicious bugs found!\n\n");
		}
		else
		{
			printf("No suspicious bugs found!\n\n");
		}
	}

	//system("pause");
	return 0;
}