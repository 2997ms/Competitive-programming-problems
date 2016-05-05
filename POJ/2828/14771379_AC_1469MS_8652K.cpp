#include <iostream>    
#include <algorithm>    
#include <cmath>    
#include <vector>    
#include <string>    
#include <cstring>    
#pragma warning(disable:4996)    
using namespace std;  
  
struct no  
{  
    int L,R;  
    int len;  
}tree[800005];  

int n;  
int val[200005];
int pos[200005]; 
int cnt[200005];

void buildtree(int root,int L,int R)  
{  
    tree[root].L=L;  
    tree[root].R=R;  
  
    tree[root].len = R-L+1;  
  
    if(L!=R)  
    {  
        int mid = (L+R)>>1;  
        buildtree((root<<1)+1,L,mid);  
        buildtree((root<<1)+2,mid+1,R);  
    }  
}  
  
void query(int root,int num,int val)  
{  
    tree[root].len--;  
    if(tree[root].L==tree[root].R)  
    {  
        cnt[tree[root].L]=val;
		return;
    }  
    if(tree[(root<<1)+1].len >= num)  
    {  
        query((root<<1)+1,num,val);  
    }  
    else  
    {  
        query((root<<1)+2,num-tree[(root<<1)+1].len,val);  
    }  
}  
  
int main()  
{  	
    int i;  
    while(scanf("%d",&n)!=EOF)  
    {  
        buildtree(0,1,n);  
  
        for(i=1;i<=n;i++)  
        {  
            scanf("%d%d",pos+i,val+i);  
        }  
        for(i=n;i>=1;i--)  
        {  
            query(0,pos[i]+1,val[i]);  
        }  
        for(i=1;i<=n;i++)  
        {  
			if(i==1)
                 printf("%d",cnt[i]);
			else
				 printf(" %d",cnt[i]);
        }
		printf("\n");
    }  
    return 0;  
} 