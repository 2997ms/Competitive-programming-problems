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
int pre[100005];

int findpre(int x)  
{  
	while(x!=pre[x])  
	{  
		//row[pre[x]] = !row[x];
		num++;
		x=pre[x];  
	}  
	return x;  
}  

void union_set(int x,int y)
{	
	/*int pre_x=findpre(x);
	int pre_y=findpre(y);

	if(pre_x == pre_y)  
		return;  
	else if(pre_x>pre_y)  
	{  
		int temp = pre_x;  
		pre_x = pre_y;  
		pre_y = temp;  
	}  
	pre[pre_y]=pre_x;*/
	pre[x]=y;
}

int main()
{
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);

	int test,i,j,temp1,temp2,num1,num2,pre_x,pre_y;
	scanf("%d",&test);

	while(test--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++)
		{
			pre[i]=i;
		}
		for(i=1;i<=m;i++)
		{
			scanf("%s%d%d",oper,&temp1,&temp2);
			if(oper[0]=='A')
			{
				num=0;
				pre_x=findpre(temp1);
				num1=num;

				num=0;
				pre_y=findpre(temp2);
				num2=num;

				if(pre_x==pre_y)
				{
					if((num1-num2)%2==1)
					{
						printf("In the same gang.\n");
					}
					else
					{
						printf("In different gangs.\n");
					}
				}
				else
				{
					printf("Not sure yet.\n");
				}
			}
			else if(oper[0]=='D')
			{
				union_set(temp1,temp2);
			}
		}
	}
	//system("pause");
	return 0;
}