vector<vector<int>> res;
struct node{
    int v, next;
}edge[2*maxn];
int head[maxn], num[maxn], low[maxn], ans[maxn];
int n, m, no, inde, root;
void add(int u, int v){
    edge[no].v = v;
    edge[no].next = head[u];
    head[u] = no++;
}
void init(){
    no = 1, inde = 0, root = 1;
    memset(head, -1, sizeof head);
    memset(ans, 0, sizeof ans);
    memset(num, 0, sizeof num);
}
void dfs(int cur, int father){
    ++inde;
    num[cur] = inde;
    low[cur] = inde;
    int k = head[cur];
    while(k != -1){
        if(num[edge[k].v] == 0){
            dfs(edge[k].v, cur);
            low[cur] = min(low[cur], low[edge[k].v]);
            if(low[edge[k].v] > num[cur]){
                std::vector<int> t;
                t.push_back(cur);
                t.push_back(edge[k].v);
                res.push_back(t);
            }
        }
        else if(edge[k].v != father){
            low[cur] = min(low[cur], num[edge[k].v]);
        }
        k = edge[k].next;
    }
}


class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        init();
        res.clear();
        rep(i,0,connections.size()) {
            add(connections[i][0], connections[i][1]);
            add(connections[i][1], connections[i][0]);
        }
        dfs(root,root);
        return res;
    }
};