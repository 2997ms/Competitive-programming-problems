class Solution
{
public:
  int leastOpsExpressTarget(int x, int target)
  {
    if (x > target)
    {
      return min((x - target) * 2, target * 2 - 1);
    }
    if (x == target)
    {
      return 0;
    }
    long long cur = x;
    int ans = 0;
    while (cur < target)
    {
      ans++;
      cur *= x;
    }
    if (cur == target)
    {
      return ans;
    }
    int le = 1e9;
    if(cur-target<target)le = leastOpsExpressTarget(x, cur - target) + ans;
    int ri = leastOpsExpressTarget(x, target - cur / x) + ans - 1;
    return min(le, ri) + 1;
  }
};