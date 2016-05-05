#include <iostream>  
#include <algorithm>  
using namespace std;  
#define MAXV 410  
#define MAXM 40010  
  
typedef struct {  
    int h,a,c;  
}Blocks;  
  
Blocks v[MAXV];  
  
int cmp(Blocks x,Blocks y){  
    return x.a<y.a;  
}  
int f[MAXM],user[MAXM];  
  
int main(){  
    int i,t,j,max;  
    while(~scanf_s("%d",&t)){  
        for(i=1;i<=t;i++){  
            scanf_s("%d%d%d",&v[i].h,&v[i].a,&v[i].c);  
        }  
        sort(v+1,v+t+1,cmp);  
        memset(f,0,sizeof(f));  
        f[0]=1;  
        max=0;  //赋值为0，不能为-1  
        for(i=1;i<=t;i++){  
            memset(user,0,sizeof(user));  
            for (j=v[i].h;j<=v[i].a;j++){  
                if(!f[j] && f[j-v[i].h] && user[j-v[i].h]+1<=v[i].c){  
                    f[j]=1;  
                    user[j]=user[j-v[i].h]+1;  
                    if(j>max) max=j;  
                }  
            }  
        }  
        printf("%d\n",max);  
    }  
    return 0;  
} 
/*int count;
	int i;
	int sum[40002][7];
	cin>>count;
	for(i=1;i<=count;i++)
	{
		cin>>node[i].h>>node[i].cant>>node[i].num;
	}
	sort(node+1,node+1+count,cmp);

	memset(sum,0,sizeof(sum));
	memset(dp,0,sizeof(dp));
	dp[0]=1;
	int j,ans=-1;
	for(i=1;i<=count;i++)
	{
		for(j=0;j<=node[i].cant;j++)
		{
			if(!dp[j]&&dp[j-node[i].h]&&sum[j-node[i].h][i]<node[i].num)
			{
				sum[j][i] = sum[j-node[j].h][i]+1;
				dp[j]=1;
				if(j>ans)
					ans=j;
			}
		}
	}
	cout<<ans<<endl;*/