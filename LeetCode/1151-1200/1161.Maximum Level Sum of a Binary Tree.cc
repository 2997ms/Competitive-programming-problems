class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if(root==NULL) return 0;
        vector<TreeNode*> que;
        que.push_back(root);

        int ans = 0;
        int res = 0;
        int cnt = 0;
        while(que.size()>0) {
            cnt++;
            int sum = 0;
            for(int i=0;i<que.size();i++) {
                sum += que[i]->val;
            }
            if(sum>ans) {
                ans = sum;
                res = cnt;
            }
            vector<TreeNode*> nxt;
            for(int i=0;i<que.size();i++) {
                if(que[i]) {
                    if(que[i]->left) {
                        nxt.push_back(que[i]->left);
                    }
                    if(que[i]->right) {
                        nxt.push_back(que[i]->right);
                    }
                }
            }
            que = nxt;
        }
        return res;
    }
};

