/*深搜一次，记录父亲节点*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    map<TreeNode*, TreeNode*>hax;
    void dfs(TreeNode* now) {
        if(now == NULL) return;
        if(now->left) {
            hax[now->left] = now;
            dfs(now->left);
        }
        if(now->right) {
            hax[now->right] = now;
            dfs(now->right);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
       hax.clear();
       dfs(root);

       map<TreeNode*, int>dis;
       queue<TreeNode*>que;
       que.push(target);
       dis[target] = 0;

       vector<int>ans;
       while(!que.empty()) {
        TreeNode* now = que.front();
        que.pop();
        if(now==NULL)continue;
        if(dis[now]==K) {
            if(now)ans.push_back(now->val);
        } else if(dis[now]>K) {
            continue;
        }
        if(!dis.count(hax[now])) {
            dis[hax[now]] = dis[now] + 1;
            que.push(hax[now]);
        }
        if(now->left && !dis.count(now->left)) {
            dis[now->left] = dis[now] + 1;
            que.push(now->left);
        }
        if(now->right && !dis.count(now->right)) {
            dis[now->right] = dis[now] + 1;
            que.push(now->right);
        }
       }
       return ans;
    }
};