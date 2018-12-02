class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        vector<int>v = deck;
        sort(v.begin(),v.end());

        int sz = v.size();
        vector<int>ans(sz,-1);
        queue<int>que;

        for(int i=0;i<sz;i++) {
            que.push(i);
        }        
        for(int i=0;i<sz;i++) {
            int s = que.front();
            que.pop();
            ans[s] = v[i];

            int s2 = que.front();
            que.pop();

            que.push(s2);
        }
        return ans;
    }
};