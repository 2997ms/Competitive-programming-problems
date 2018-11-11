/*给出一堆的点，问其中四个点构成的平行于x y轴的最小矩形面积。
枚举对角线上的两个点，看另外两个点是否存在。
*/
class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        set < pair<int,int> > t;
        for (int i=0;i<points.size();i++) {
            t.insert( make_pair(points[i][0],points[i][1]));
        }    
        long long ans = 1e16;
        for(int i=0;i<points.size();i++) {
            for (int j=i+1;j<points.size();j++) {
                int mx = points[i][0];
                int my = points[i][1];

                int nx = points[j][0];
                int ny = points[j][1];

                if(t.find(make_pair(mx,ny))!=t.end() &&
                    t.find(make_pair(nx,my))!=t.end()) {
                    int k1 = max(mx,nx) - min(mx,nx);
                    int k2 = max(my,ny) - min(my,ny);
                    if(k1==0||k2==0) {
                        continue;
                    } else {
                        ans = min(ans,1LL*k1*k2);
                    }
                }
            }
        }
        if(ans==1e16) {
            return 0;
        } else {
            return ans;
        }
    }
};