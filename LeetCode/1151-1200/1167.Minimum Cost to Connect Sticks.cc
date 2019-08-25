class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        multiset<int>val;
        int ans = 0;
        for(int i=0;i<sticks.size();i++) {
            val.insert(sticks[i]);
        }
        while(val.size() != 1) {
            auto k = val.begin();
            auto g = val.begin();
            g++;
            int t = (*k) + (*g);
            val.erase(k);
            val.erase(g);
            val.insert(t);
            ans+=t;
        }
        return ans;
    }
};