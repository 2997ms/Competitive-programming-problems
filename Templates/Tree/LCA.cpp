struct LcaStruct {
	int root;
	int n;
	int fa[maxn][30];
	int depth[maxn];
	vector<int>vec[maxn];

	void dfs(int u,int pre,int d)  //预处理出每个节点的深度及父亲节点
	{
	    fa[u][0]=pre;
	    depth[u]=d;
	    for(int i=0;i<vec[u].size();i++)
	    {
	        int v=vec[u][i];
	        if(v!=pre)
	        {
	            dfs(v, u, d + 1);
	        }
	    }
	}

	void init()                    //预处理出每个节点往上走2^k所到的节点，超过根节点记为-1
	{
	    dfs(root,-1,0);              //root为根节点
	    for(int j=0;(1<<(j+1))<=n;j++)  
	    {
	        for(int i=0;i<=n;i++)
	        {
	            if(fa[i][j]<0) 
	                fa[i][j+1]=-1;
	            else 
	                fa[i][j+1]=fa[fa[i][j]][j];
	        }
	     }
	}
	 
	int LCA(int u,int v)
	{
	    if(depth[u]>depth[v]) swap(u,v);
	    int temp=depth[v]-depth[u];
	    for(int i=0;(1<<i)<=temp;i++)      //使u,v在同一深度
	    {
	        if((1<<i)&temp)
	            v=fa[v][i];
	    }
	    if(v==u) return u;
	    for(int i=20;i>=0;i--)  //两个节点一起往上走
	    {
	        if(fa[u][i]!=fa[v][i])
	        {
	            u=fa[u][i];
	            v=fa[v][i];
	        }
	    }
	    return fa[u][0];
	}
}lca;