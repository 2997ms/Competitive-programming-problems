class Solution {
public:
    int n;
    int dis[105][105];
    int maxDistance(vector<vector<int>>& grid) {
        n = grid.size();
        for(int i=0;i<grid.size();i++) {
          int now = -1;
          for(int j=0;j<grid.size();j++) {
            if(grid[i][j]) {
              now = j;
            }
            if(now == -1) {
              dis[i][j] = -1;
            } else {
              dis[i][j] = j - now;
            }
          }
        }

        for(int i=0;i<grid.size();i++) {
          int now = -1;
          for(int j= grid[i].size()-1;j>=0;j--) {
            if(grid[i][j]) {
              now = j;
            }
            if(now != -1) {
              if(dis[i][j]==-1) {
                dis[i][j] = now - j;
              } else {
                dis[i][j] = min(dis[i][j],now - j);
              }
            }
          }
        }

        int ans = -1;
        for(int i=0;i<n;i++) {
          for(int j=0;j<n;j++) {
            if(grid[i][j] == 0) {
              int tmp = -1;

              for(int k=0;k<n;k++) {
                if(dis[k][j]!=-1) {
                  if(tmp == -1) {
                    tmp = dis[k][j] + abs(k-i);
                  } else {
                    tmp = min(tmp,dis[k][j] + abs(k-i));
                  }

                }
              }
              if(ans == -1) {
                ans = tmp;
              } else {
                ans = max(ans,tmp);
              }
            }
          }
        }
        return ans;
    }
};