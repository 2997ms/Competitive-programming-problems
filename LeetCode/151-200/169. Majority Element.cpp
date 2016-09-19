#define rep(i, n, m) for (int i = n; i < m; i++)
class Solution
{
public:
    int majorityElement(vector<int>& nums)
    {
        int i, j, k;
        int sz = nums.size();
        int tot = 0;
        int now = 0;
        rep(i, 0, sz)
        {
            if (nums[i] == now)
            {
                tot++;
            }
            else
            {
                tot--;
                if (tot < 0)
                {
                    now = nums[i];
                    tot = 0;
                }
            }
        }
        return now;
    }
};