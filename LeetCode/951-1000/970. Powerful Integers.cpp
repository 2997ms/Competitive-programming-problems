class Solution
{
public:
  vector<int> powerfulIntegers(int x, int y, int bound)
  {
    int px = x, py = y;
    x = 1;
    y = 1;
    vector<int> ans1, ans2;
    while (x <= bound)
    {
      ans1.push_back(x);
      x = x * px;
      if (px == 1)
        break;
    }
    while (y <= bound)
    {
      ans2.push_back(y);
      y = y * py;
      if (py == 1)
        break;
    }
    set<int> ans;
    for (int i = 0; i < ans1.size(); i++)
    {
      for (int j = 0; j < ans2.size(); j++)
      {
        if (ans1[i] + ans2[j] <= bound)
        {
          ans.insert(ans1[i] + ans2[j]);
        }
      }
    }
      vector<int>res(ans.begin(),ans.end());
    return res;
  }
};