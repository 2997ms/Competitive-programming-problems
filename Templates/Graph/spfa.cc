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

using P = pair<int, int>;
using T = tuple<int, int, int>;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

struct edge {
  int to, cost;
};

vector<int> dijkstra(const vector<vector<edge>> &g, int s) {
  vector<int> d(g.size(), INF);
  priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> que;
  d[s] = 0;
  que.emplace(0, s);
  while (!que.empty()) {
    auto p = que.top();
    que.pop();
    int u = p.second;
    if (d[u] < p.first) continue;
    for (auto &e : g[u]) {
      int v = e.to;
      if (d[v] > d[u] + e.cost) {
        d[v] = d[u] + e.cost;
        que.emplace(d[v], v);
      }
    }
  }
  return d;
}