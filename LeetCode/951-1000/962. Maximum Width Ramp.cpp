/*排序 贪心*/
class Solution
{
public:
  int maxWidthRamp(vector<int> &A)
  {
    vector<pair<int, int>> v;
    for (int i = 0; i < A.size(); i++)
    {
      v.push_back(make_pair(A[i], i));
    }
    sort(v.begin(), v.end());
    if (v.size() == 0)
      return 0;
    int minn = v[0].second;
    int ans = 0;
    for (int i = 1; i < v.size(); i++)
    {
      ans = max(v[i].second - minn, ans);
      minn = min(minn, v[i].second);
    }
    return ans;
  }
};