struct Graph {
    std::vector< pair<int,int> > edge[maxn];
    int dis[maxn], vis[maxn];
    void spfa(int st) {
        REPP(i,0,maxn -1) {
            dis[i] = (1<<30);
            vis[i] = 0;
        }
        queue<int>que;
        que.push(st);
        vis[st] = 1;
        dis[st] = 0;
        while(!que.empty()) {
            int now = que.front();
            que.pop();
            vis[now] = 0;
            REP(i,0,edge[now].size()) {
                int nxt = edge[now][i].first;
                if(dis[nxt] > dis[now] + edge[now][i].second) {
                    dis[nxt] = dis[now] + edge[now][i].second;
                    if(vis[nxt] == 0) {
                        vis[nxt] = 1;
                        que.push(nxt);
                    }
                }
            }
        }
    }
}gh;