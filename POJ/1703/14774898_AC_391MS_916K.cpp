#include <iostream>  
#include <algorithm>  
#include <cmath>  
#include <vector>  
#include <string>  
#include <cstring>  
#pragma warning(disable:4996)  
using namespace std;

char oper[5];
int n,m,num;
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

	int test,i,temp1,temp2;
	scanf("%d",&test);

	while(test--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=2*n;i++)
		{
			pre[i]=i;
		}
		for(i=1;i<=m;i++)
		{
			scanf("%s%d%d",oper,&temp1,&temp2);
			if(oper[0]=='A')
			{
				if(same(temp1,temp2))
				{
					printf("In the same gang.\n");
				}
				else if(same(temp1+n,temp2)||same(temp1,temp2+n))
				{
					printf("In different gangs.\n");
				}
				else
				{
					printf("Not sure yet.\n");
				}
				
			}
			else if(oper[0]=='D')
			{
				union_set(temp1,temp2+n);
				union_set(temp1+n,temp2);
			}
		}
	}
	//system("pause");
	return 0;
}