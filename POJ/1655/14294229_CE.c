#include<stdio.h> 
#include<string.h> 
#define MAXN 20005 
struct Edge{ 
    int v; 
    int next; 
}edge[MAXN*2]; 
int sum[MAXN*2],son[MAXN]; 
/*
sum[]记载除去"父节点的子树"的节点数量总和
son[]记录除去"父节点的子树"的所有子树中最大节点数
父节点在该题理解为DFS过程中的上一层节点
*/ 
int head[MAXN],visited[MAXN]; 
int tot; 
int Max(int a,int b) 
{ 
    return a>b ? a : b; 
} 
void addedge(int x,int y) 
{ 
   tot++; 
   edge[tot].v = y; 
   edge[tot].next = head[x]; 
   head[x] = tot; 
     
   tot++; 
   edge[tot].v = x; 
   edge[tot].next = head[y]; 
   head[y] = tot; 
   
} 
void dfs(int x) 
{ 
   visited[x] = 1; 
   int t; 
   for(t=head[x];t!=-1;t=edge[t].next) 
   { 
       if(!visited[edge[t].v]) 
       { 
           dfs(edge[t].v); 
           sum[x] += sum[edge[t].v]; 
           if(son[x] < sum[edge[t].v]) 
               son[x] = sum[edge[t].v]; 
       } 
   } 
} 
int main() 
{ 
     
    int ncase; 
    scanf("%d",&ncase); 
    while(ncase--) 
    { 
        int i,N; 
        int x,y; 
        int id,ans; 
        scanf("%d",&N); 
        tot = 0; 
        memset(head,-1,sizeof(head)); 
        memset(edge,0,sizeof(edge)); 
        for(i=1;i<N;i++) 
        { 
            scanf("%d%d",&x,&y); 
            addedge(x,y); 
        } 
        memset(visited,0,sizeof(visited)); 
        memset(son,0,sizeof(son)); 
        for(i=0;i<=N;i++) 
            sum[i] = 1; 
        dfs(1); 
        id = 1; 
        ans = son[1]; 
        for(i=2;i<N;i++) 
            if(ans > Max(son[i],sum[1]-sum[i]))//sum[1]为整棵树的节点数量，sum[1]-sum[i]就是父节点子树的节点数目 
            { 
                ans = Max(son[i],sum[1]-sum[i]); 
                id = i; 
            } 
        printf("%d %d\n",id,ans); 
    } 
    return 0; 
} 