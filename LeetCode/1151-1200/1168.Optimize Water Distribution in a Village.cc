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



class Solution {
public:
    vector< pair<int, pair<int,int> > >v;
    int minCostToSupplyWater(int n, vector<int>& wells, vector< vector<int> >& pipes) {
        v.clear();
        for(int i=0;i<wells.size();i++) {
            v.push_back(make_pair(wells[i], make_pair(0, i+1)));
        }
        for(int i=0;i<pipes.size();i++) {
            v.push_back(make_pair(pipes[i][2], make_pair(pipes[i][0],pipes[i][1])));
        }
        dsu.init(n);
        sort(v.begin(),v.end());
        int ans = 0;
        rep(i,0,v.size()) {
            int x = v[i].second.first;
            int y = v[i].second.second;
            if(dsu.find(x) == dsu.find(y)) continue;
            dsu.uni(x,y);
            ans += v[i].first;
            cout<<x<<" "<<y<<endl;
        }
        return ans;
    }
};