class Solution
{
public:
  set<int> v;
  void dfs(TreeNode *root)
  {
    if (root == NULL)
    {
      return;
    }
    v.insert(root->val);
    dfs(root->left);
    dfs(root->right);
  }
  bool isUnivalTree(TreeNode *root)
  {
    v.clear();
    dfs(root);
    return v.size() <= 1;
  }
};
