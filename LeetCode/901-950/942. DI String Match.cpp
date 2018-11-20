/*维护一段用过的区间。当然也可以一开始就从很大的端点开始向里面走*/
class Solution {
public:
    vector<int> diStringMatch(string S) {
        vector<int>ans;
        ans.push_back(0);
        int minn = 0,maxx = 0;
        for (int i=0;i<S.length();i++) {
            int x = ans.back();
            if (S[i]=='I') {
                ans.push_back(maxx+1);
            } else {
                ans.push_back(minn-1);
            }
            minn = min(minn,ans.back());
            maxx = max(maxx,ans.back());
        }
        for (int i=0;i<ans.size();i++) {
            minn = min(ans[i],minn);
        }
        for (int i=0;i<ans.size();i++) {
            ans[i] -= minn;
        }
        return ans;
    }
};