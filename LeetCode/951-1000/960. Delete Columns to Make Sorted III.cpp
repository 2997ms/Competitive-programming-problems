/*最长增长子序列的变种*/
class Solution
{
public:
  int minDeletionSize(vector<string> &A)
  {
    if (A.size() == 0)
    {
      return 0;
    }
    int n = A[0].length();
    vector<int> dp(n, 1);
    for (int i = 1; i < n; i++)
    {
      for (int j = 0; j < i; j++)
      {
        int flag = 1;
        for (int k = 0; k < A.size(); k++)
        {
          if (A[k][j] > A[k][i])
          {
            flag = 0;
          }
        }
        if (flag)
        {
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }
    }
    int maxx = 0;
    for(auto x: dp) 
    {
        maxx = max(maxx, x);
    }
    return n - maxx;
  }
};