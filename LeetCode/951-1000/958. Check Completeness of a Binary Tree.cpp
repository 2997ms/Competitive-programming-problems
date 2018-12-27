class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if(root==NULL)return true;
        queue<TreeNode*>que;
        que.push(root);

        while(!que.empty()) {
            TreeNode* now = que.front();
            if(now->left && now->right) {
                que.pop();
                que.push(now->left);
                que.push(now->right);
            }
            if(now->left==NULL && now->right) {
                return false;
            }
            if((now->left && now->right==NULL) || (now->left==NULL && now->right==NULL)) {
                que.pop();
                if(now->left) {
                    que.push(now->left);
                }
                while(!que.empty()) {
                    now = que.front();
                    if(now->left==NULL && now->right==NULL){
                        que.pop();
                    } else {
                        return false;
                    }
                 }
            }
        }
        return true;
    }
};