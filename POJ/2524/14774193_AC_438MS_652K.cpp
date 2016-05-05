#include <iostream>  
#include <algorithm>  
#include <cmath>  
#include <vector>  
#include <string>  
#include <cstring>  
#include <set>
#pragma warning(disable:4996)  
using namespace std;

int n,m;
int pre[50005];
set <int> res;

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
    int pre_x = findpre(x);  
    int pre_y = findpre(y);  
  
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

int main()
{
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);

	int i,j,temp1,temp2,test_num;

	test_num=1;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(n==0 && m==0)
		{
			break;
		}

		printf("Case %d: ",test_num++);
		
		for(i=1;i<=n;i++)
		{
			pre[i]=i;
		}
		for(i=1;i<=m;i++)
		{
			scanf("%d%d",&temp1,&temp2);
			union_set(temp1,temp2);
		}
		res.clear();
		for(i=1;i<=n;i++)
		{
			res.insert(findpre(i));
		}
		printf("%d\n",res.size());
	}

	//system("pause");
	return 0;
}