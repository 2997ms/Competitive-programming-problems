/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool equal(TreeNode* le, TreeNode* ri)
{
    if (le == NULL&&ri == NULL)
    {
        return true;
    }
    else
    {
        if (!le || !ri)
        {
            return false;
        }
        else
        {
            return (le->val == ri->val) && equal(le->left, ri->right) && equal(le->right, ri->left);
        }
    }
}

class Solution {
public:
    bool isSymmetric(TreeNode* root) 
    {
        if (root == NULL)
        {
            return true;
        }
        else
        {
            return equal(root->left, root->right);
        }
    }
};