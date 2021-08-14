
struct node{
    int v, next;
}edge[4005];
int head[1005], num[1005], low[1005], ans[1005];
int n, m, no, all, root;
void add(int u, int v){
    edge[no].v = v;
    edge[no].next = head[u];
    head[u] = no++;
}
void init(){
    no = 1, all = 0, root = 1;
    memset(head, -1, sizeof head);
    memset(ans, 0, sizeof ans);
    memset(num, 0, sizeof num);
}
void dfs(int cur, int father){
    int child = 0;
    ++all;
    num[cur] = all;
    low[cur] = all;
    int k = head[cur];
    while(k != -1){
        if(num[edge[k].v] == 0){
            ++child;
            dfs(edge[k].v, cur);
            low[cur] = min(low[cur], low[edge[k].v]);
            if(cur != root && low[edge[k].v] >= num[cur]) ans[cur] = 1;
            if(child == 2 && cur == root) ans[cur] = 1;
        }
        else if(edge[k].v != father){
            low[cur] = min(low[cur], num[edge[k].v]);
        }
        k = edge[k].next;
    }
}

int main(){
    int i, u, v;
    scanf("%d %d", &n, &m);
    init();
    for(i = 1; i <= m; ++i){
        scanf("%d %d", &u, &v);
        add(u, v);
        add(v, u);
    }
    dfs(root, root);
    for(i = 1; i <= n; ++i)  
        if(ans[i]) printf("%d ", i);  
    printf("\n"); 
    return 0;
}
