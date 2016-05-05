#include <iostream>  
#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <string>  
#include <cmath>  
#include <cstdlib>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
  
using namespace std;  
  
typedef long long int LL;  
  
const int MOD=76543;  
  
int hs[MOD],head[MOD],next[MOD],id[MOD],top;  
  
void insert(int x,int y)  
{  
    int k=x%MOD;  
    hs[top]=x; id[top]=y;  
    next[top]=head[k]; head[k]=top++;  
}  
  
int find(int x)  
{  
    int k=x%MOD;  
    for(int i=head[k];~i;i=next[i])  
        if(hs[i]==x) return id[i];  
    return -1;  
}  
  
int BSGS(int a,int b,int n)  
{  
    memset(head,-1,sizeof(head));  
    top=1;  
    if(b==1) return 0;  
    int m=sqrt(n*1.0),j;  
    LL x=1,p=1;  
    for(int i=0;i<m;i++,p=p*a%n) insert(p*b%n,i);  
    for(LL i=m;;i+=m)  
    {  
        if((j=find(x=x*p%n))!=-1) return i-j;  
        if(i>n) break;  
    }  
    return -1;  
}  
  
int main()  
{  
    //freopen("in.txt","r",stdin);  
    //freopen("out.txt","w",stdout);  
  
    int a,b,n;  
    while(scanf("%d%d%d",&a,&n,&b)!=EOF)  
    {  
        if(a==0&&b==0&&n==0) break;  
        int ans=BSGS(a,b,n);  
        if(ans==-1) puts("No Solution");  
        else printf("%d\n",ans);  
    }  
      
    return 0;  
}  