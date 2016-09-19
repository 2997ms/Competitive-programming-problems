int cal(vector<vector<int>> &dp, int x, int y)
{
    if (x >= y)
    {
        return 0;
    }
    if (dp[x][y] != 0)
    {
        return dp[x][y];
    }
    int i, j, k;
    int res = INT_MAX;
    for (i = x; i <= y; i++)
    {
        res = min(res, i + max(cal(dp, x, i - 1), cal(dp, i + 1, y)));
    }
    dp[x][y] = res;
    return res;
}

class Solution
{
public:
    int getMoneyAmount(int n) 
    {
        vector<vector<int>>dp(n + 1, (vector<int>(n + 1, 0)));
        return cal(dp, 1, n);
    }
};