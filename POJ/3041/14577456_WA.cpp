#include<iostream>  
using namespace std;  
#pragma warning(disable:4996)
int n,k;  //n矩阵规格，k星体数量  
int V1,V2;       //二分图顶点集  
 /*矩阵的行列分别属于二分图的两个顶点集V1、V2，其中行x∈V1，列y∈V2*/  
bool grid[501][501];  //存储数据方式：可达矩阵  
bool vis[501];     //记录V2的点每个点是否已被搜索过  
int link[501];     //记录 V2中的点y 在 V1中 所匹配的点x的编号  
int m;  //最大匹配数  
  
/*Hungary Algorithm*/  
  
bool dfs(int x)  
{  
    for(int y=1;y<=V2;y++)  
        if(grid[x][y] && !vis[y])  //x到y相邻(有边) 且 节点y未被搜索  
        {  
            vis[y]=true;   //标记节点y已被搜索  
            if(link[y]==0 || dfs(link[y])) //link[y]==0 : 如果y不属于前一个匹配M  
            {                               //find(link[y] : 如果被y匹配到的节点可以寻找到增广路  
                link[y]=x; //那么可以更新匹配M'(用M替代M') 
				link[x]=y;
                return true;  //返回匹配成功的标志  
            }  
        }  
    return false;  //继续查找V1下一个x的邻接节点  
}  
  
void search(void)  
{  
    for(int x=1;x<=V1;x++)  
    {  
        memset(vis,false,sizeof(vis)); //清空上次搜索时的标记  
        if(dfs(x))  //从V1中的节点x开始寻找增广路  
            m++;  
    }  
    return;  
}  
  
int main(void)  
{  


    cin>>n>>k;  
    V1=V2=n;  
  
    int x,y;         //坐标(临时变量)  
    for(int i=1;i<=k;i++)  
    {  
        cin>>x>>y;  
        grid[x][y]=true;   //相邻节点标记  
    }  
  
    /*增广轨搜索*/  
  
    search();  
  
    /*Output*/  
  
    cout<<m<<endl;  
  
    return 0;  
} 
