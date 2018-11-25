const int maxn = 1e5 + 5;
struct DSU
{
    int fa[maxn];
    void init(int n)
    {
        for (int i=0;i<=n;i++)
        {
            fa[i] = i;
        }
    }
    int find(int x)
    {
        return fa[x]==x?x:fa[x]=find(fa[x]);
    }
    int uni(int x,int y)
    {
        x = find(x);
        y = find(y);
        if(x==y)return 0;
        if(x<y)swap(x,y);
        fa[x]=y;
        return 1;
    }
}dsu;

