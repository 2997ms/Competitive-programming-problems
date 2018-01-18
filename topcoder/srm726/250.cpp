int dp[55][maxn];

int solve(vector<int>x, vector<int>cost, int k)
{
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 0; i < x.size(); i++)
    {
        for (int h = 0; h <= 1e5; h++)
        {
            dp[i + 1][h] = dp[i][h];
        }
        for (int h = 0; h <= 1e5; h++)
        {
            if(dp[i][h] >= 1e9)continue;
            dp[i + 1][h + x[i]] = min(dp[i + 1][h + x[i]], dp[i][h] + cost[i]);
        }
    }
    int ans = 1e9;
    for (int i = k; i <= 1e5; i++)
    {
        ans = min(ans, dp[x.size()][i]);
    }
    return ans;
}


class Unpacking
{
public:
    int getcost(vector<int>a, vector<int>b, vector<int>cost, int k) {
        int ans = 1e9;
        for (int i = 0; i < a.size(); i++)
        {
            a[i]--;
        }
        ans = min(ans, solve(a, cost, k - 1));
        for (int i = 0; i < a.size(); i++)
        {
            a[i]++;
            b[i]--;
        }
        ans = min(ans, solve(b, cost, k - 1));
        for (int i = 0; i < a.size(); i++)
        {
            b[i]++;
        }
        for (int i = 0; i < a.size(); i++)
        {
            a[i] += b[i];
        }
        ans = min(ans, solve(a, cost, 2 * k - 1));
        if (ans == 1e9)ans = -1;
        return ans;
    }
};