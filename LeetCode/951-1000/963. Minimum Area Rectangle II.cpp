/*tip：枚举矩形的时候，就记得枚举对角线就够了*/
class Solution
{
public:
  double minAreaFreeRect(vector<vector<int>> &points)
  {
    map<pair<pair<double, double>, double>, vector<pair<int, int>>> hax;
    for (int i = 0; i < points.size(); i++)
    {
      for (int j = i + 1; j < points.size(); j++)
      {
        pair<double, double> center;
        center.first = points[i][0] + points[j][0];
        center.second = points[i][1] + points[j][1];
        double dis = (points[i][0] - points[j][0]) * (points[i][0] - points[j][0]) + (points[i][1] - points[j][1]) * (points[i][1] - points[j][1]);
        hax[make_pair(center, dis)].push_back(make_pair(i, j));
      }
    }
    double ans = 1e9;
    for (auto it : hax)
    {
      for (int i = 0; i < it.second.size(); i++)
      {
        double x = points[it.second[i].first][0];
        double y = points[it.second[i].first][1];
        for (int j = i + 1; j < it.second.size(); j++)
        {
          double x1 = points[it.second[j].first][0];
          double y1 = points[it.second[j].first][1];
          double dis1 = sqrt(1.0*(x - x1) * (x - x1) + (y - y1) * (y - y1));
          double x2 = points[it.second[j].second][0];
          double y2 = points[it.second[j].second][1];
          double dis2 = sqrt(1.0*(x - x2) * (x - x2) + (y - y2) * (y - y2));
            
          ans = min(dis1 * dis2, ans);
        }
      }
    }
    if (ans == 1e9)
    {
      return 0;
    }
    return ans;
  }
};