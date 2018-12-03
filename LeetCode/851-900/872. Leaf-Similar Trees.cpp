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
    void getleaf(TreeNode* root, vector<int>&v) {
        if (root == NULL) {
            return;
        } 
        if (root->left == NULL && root->right == NULL) {
            v.push_back(root->val);
        }
        if (root->left) {
            getleaf(root->left, v);
        }
        if (root->right) {
            getleaf(root->right, v);
        }
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>s1,s2;
        getleaf(root1,s1);
        getleaf(root2,s2);
        return s1 == s2;
    }
};