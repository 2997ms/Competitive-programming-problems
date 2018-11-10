/*简单题*/
class Solution {
public:
    int binaryGap(int N) {
        vector<int>v;
        int ans = 0;
        while (N > 0) {
            v.push_back(N&1);
            N>>=1;
        }
        int pre=-1;
        for (int i=0;i<v.size();i++) {
            if (v[i]==1) {
                if (pre!=-1)
                    ans = max(ans,i-pre);
                pre=i;
            } 
        }
        return ans;
    }
};