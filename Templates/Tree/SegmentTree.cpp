// CF 1263E
struct node {
    int le, ri;
    ll lazy;
    ll minn;
    ll maxx;
    ll sum;
} seg_tree[maxn * 4 + 5];
struct segmentTree{
    ll val[maxn];
    
    void pushup(int root) {
        seg_tree[root].minn = min(seg_tree[root<<1].minn, seg_tree[root<<1|1].minn);
        seg_tree[root].maxx = max(seg_tree[root<<1].maxx, seg_tree[root<<1|1].maxx);
        seg_tree[root].sum = (seg_tree[root<<1].sum + seg_tree[root<<1|1].sum);
    }

    void pushdown(int root) {
        if(seg_tree[root].lazy) {
            seg_tree[root<<1].sum += (seg_tree[root<<1].ri-seg_tree[root<<1].le+1)*seg_tree[root].lazy;
            seg_tree[root<<1|1].sum += (seg_tree[root<<1|1].ri-seg_tree[root<<1|1].le+1)*seg_tree[root].lazy;
            
            seg_tree[root<<1].lazy += seg_tree[root].lazy;
            seg_tree[root<<1].minn += seg_tree[root].lazy;
            seg_tree[root<<1].maxx += seg_tree[root].lazy;
            seg_tree[root<<1|1].lazy += seg_tree[root].lazy;
            seg_tree[root<<1|1].minn += seg_tree[root].lazy;
            seg_tree[root<<1|1].maxx += seg_tree[root].lazy;

            seg_tree[root].sum = seg_tree[root<<1].sum + seg_tree[root<<1|1].sum; 
            seg_tree[root].lazy = 0;
        }
    }

    void build(int root, int le, int ri) {
        // cout<<root<<" "<<le<<" "<<ri<<endl;
        seg_tree[root].le = le;
        seg_tree[root].ri = ri;
        if(le == ri) {
            seg_tree[root].minn = 0;
            seg_tree[root].maxx = 0;
            seg_tree[root].lazy = 0;
            seg_tree[root].sum = 0;
        } else {
            int mid = (le + ri) >> 1;
            build(root << 1, le, mid);
            build(root << 1 | 1, mid + 1, ri);
            pushup(root);
        }
    }
    
    void update(int root, int update_le, int update_ri, int val) {
        if(update_le <= seg_tree[root].le && update_ri >= seg_tree[root].ri) {
            seg_tree[root].lazy += val;
            seg_tree[root].minn += val;
            seg_tree[root].maxx += val;
            seg_tree[root].sum += (seg_tree[root].ri-seg_tree[root].le+1)*val;
            return;
        }
        pushdown(root);
        int mid = (seg_tree[root].le + seg_tree[root].ri)/2;
        if(update_le <= mid) {
            update(root<<1, update_le, update_ri, val);
        }
        if(update_ri > mid) {
            update(root<<1|1, update_le, update_ri, val);
        }
        pushup(root);
    }

    node query(int root, int ask_le, int ask_ri) {
        if (seg_tree[root].le >= ask_le && seg_tree[root].ri <= ask_ri) {
            return seg_tree[root];
        }
        pushdown(root);
        int mid = (seg_tree[root].le + seg_tree[root].ri) >> 1;
        if (ask_ri <= mid) {
            return query(root << 1, ask_le, ask_ri);
        } else if (ask_le > mid) {
            return query(root << 1 | 1, ask_le, ask_ri);
        } else {
            node res1 = query(root << 1, ask_le, ask_ri);
            node res2 = query(root << 1 | 1, ask_le, ask_ri);
            node res = res1;
            res.sum = res1.sum+res2.sum;
            res.minn = min(res1.minn, res2.minn);
            res.maxx = max(res1.maxx, res2.maxx);
            return res;
        }
    }
}t;

string s;
int ss[maxn];

void solve() {
    int n;
    scanf("%d",&n);
    n=n+5;

    t.build(1,1,n);
    
    cin>>s;
    int pos = 1;
    vector<int>ans;
    for(int i=0;i<s.size();i++){
        if(s[i]=='('){
            t.update(1,pos,n,1-ss[pos]);
            ss[pos]=1;
        }else if(s[i]==')'){
            t.update(1,pos,n,-1-ss[pos]);
            ss[pos]=-1;
        }else if(s[i]=='L'){
            if(pos>1)pos--;
        }else if(s[i]=='R'){
            pos++;
        }else{
            if(ss[pos]==1){
                t.update(1,pos,n,-1);
            }else if(ss[pos]==-1){
                t.update(1,pos,n,1);
            }
            ss[pos]=0;
        }
        node ansnode = t.query(1,1,n);
        node sumnode = t.query(1,n,n);
        // cout<<ansnode.minn<<" "<<ansnode.sum<<" "<<ansnode.maxx<<endl;
        if(ansnode.minn==0&&sumnode.sum==0){
            ans.push_back(ansnode.maxx);
        }else{
            ans.push_back(-1);
        }
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

int main()
{   
    solve();

    return 0;
 
}
 