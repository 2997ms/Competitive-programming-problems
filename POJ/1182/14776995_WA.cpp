#include <iostream>  
#include <algorithm>  
#include <cmath>  
#include <vector>  
#include <string>  
#include <cstring>  
#pragma warning(disable:4996)  
using namespace std;

int n,m,num;  
int pre[150015];  
  
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

	int oper,i,x,y,ans;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		ans=0;
		for(i=1;i<=3*n;i++)
		{
			pre[i]=i;
		}
		for(i=1;i<=m;i++)
		{
			scanf("%d%d%d",&oper,&x,&y);
			if(x<=0||x>n||y<=0||y>n)
			{
				ans++;
				continue;
			}
			if(oper==1)
			{
				if(same(x,y+n)||same(x,y+2*n)||same(x+2*n,y))
				{
					ans++;
					continue;
				}
				union_set(x,y);
				union_set(x+n,y+n);
				union_set(x+2*n,y+2*n);
			}
			else if(oper==2)
			{
				if(x==y||same(x,y)||same(x+n,y)||same(x,y+2*n))
				{
					ans++;
					continue;
				}
				union_set(x,y+n);
				union_set(x+n,y+2*n);
				union_set(x+2*n,y);
			}
		}
		printf("%d\n",ans);
	}

	//system("pause");
	return 0;
}