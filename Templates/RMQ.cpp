const int maxn = 1e5 + 5;
int num[maxn];

struct RMQ {
    int f_min[maxn][20],f_max[maxn][20];
     
    void init(int num[],int n)
    {
        for(int i = 1; i <= n; i++)
        {
            f_min[i][0] = f_max[i][0] = num[i];
        }
     
        for(int i = 1; (1<<i) <= n; i++)  //按区间长度递增顺序递推
        {
            for(int j = 1; j+(1<<i)-1 <= n; j++)  //区间起点
            {
                f_max[j][i] = max(f_max[j][i-1],f_max[j+(1<<(i-1))][i-1]);
                f_min[j][i] = min(f_min[j][i-1],f_min[j+(1<<(i-1))][i-1]);
            }
        }
    }
     
    int query_max(int l,int r)
    {
        int k = (int)(log(double(r-l+1))/log((double)2));
        return max(f_max[l][k], f_max[r-(1<<k)+1][k]);
    }
     
    int query_min(int l,int r)
    {
        int k = (int)(log(double(r-l+1))/log((double)2));
        return min(f_min[l][k], f_min[r-(1<<k)+1][k]);
    }
}rmq;