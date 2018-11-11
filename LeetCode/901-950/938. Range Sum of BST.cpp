/*简单题，遍历一遍树*/
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
    int ans;

    void dfs(TreeNode* root, int L, int R) {
        if (root==NULL)return;
        if (root->val>=L&&root->val<=R) {
            ans += root->val;
        }
        dfs(root->left,L,R);
        dfs(root->right,L,R);
    }

    int rangeSumBST(TreeNode* root, int L, int R) {
        ans = 0;
        dfs(root,L,R);
        return ans;
    }
};