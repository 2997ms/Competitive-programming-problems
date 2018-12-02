/*判断每个点*/
class Solution {
public:
    bool equal(TreeNode* root1, TreeNode* root2) {
        if(root1==NULL && root2==NULL) {
            return true;
        }
        if(!root1 || !root2) {
            return false;
        }
        return root1->val == root2->val;
    }

    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if (!equal(root1,root2)) {
            return false;
        }
        if(root1==NULL && root2==NULL) {
            return true;
        }

        if(equal(root1->left,root2->left) && equal(root1->right,root2->right)) {
            return flipEquiv(root1->left,root2->left) && flipEquiv(root1->right,root2->right);
        } else if (equal(root1->left,root2->right) && equal(root1->right,root2->left)) {
            return flipEquiv(root1->left,root2->right) && flipEquiv(root1->right,root2->left);
        } else {
            return false;
        }
    }
};