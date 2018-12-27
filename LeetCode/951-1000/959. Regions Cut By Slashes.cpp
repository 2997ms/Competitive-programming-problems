/*如果矩形对角线相连，会有上下左右四个三角形。单独的一个线，会连接其中的两个三角形，之后计算并查集。*/
struct DSU
{
  int fa[maxn];
  void init(int n)
  {
    for (int i = 0; i <= n; i++)
    {
      fa[i] = i;
    }
  }
  int find(int x)
  {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
  }
  int uni(int x, int y)
  {
    x = find(x);
    y = find(y);
    if (x == y)
      return 0;
    if (x < y)
      swap(x, y);
    fa[x] = y;
    return 1;
  }
} dsu;
class Solution
{
public:
  int regionsBySlashes(vector<string> &grid)
  {
    int n = grid.size();
    dsu.init(5 * n * n);
    for (int i = 0; i < grid.size(); i++)
    {
      for (int j = 0; j < grid[i].size(); j++)
      {
        char val = grid[i][j];
        int root = 4 * (i * n + j);
        if (val != '\\')
        {
          dsu.uni(root + 0, root + 3);
          dsu.uni(root + 1, root + 2);
        }
        if (val != '/')
        {
          dsu.uni(root + 0, root + 1);
          dsu.uni(root + 2, root + 3);
        }
        if (i >= 1)
        {
          dsu.uni(root + 0, root - 4 * n + 2);
        }
        if (i+1 < n)
        {
          dsu.uni(root + 2, root + 4 * n + 0);
        }
        if (j >= 1)
        {
          dsu.uni(root + 3, root - 4 + 1);
        }
        if (j+1 < n)
        {
          dsu.uni(root + 1, root + 4 + 3);
        }
      }
    }
    int ans = 0;
    for (int i = 0; i < 4 * n * n; i++)
    {
      if (dsu.find(i) == i)
      {
        ans++;
      }
    }
    return ans;
  }
};