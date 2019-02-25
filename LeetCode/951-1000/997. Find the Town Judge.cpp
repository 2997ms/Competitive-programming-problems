class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int>ans;
        for(int i=1;i<=N;i++) {
            int flag = 1;
            for(int j=0;j<trust.size();j++) {
                if(trust[j][0]==i){
                    flag=0;
                }
            }
            int cnt=0;
            for(int j=0;j<trust.size();j++) {
                if(trust[j][1]==i){
                    cnt++;
                }
            }
            if(flag&&cnt==N-1) {
                ans.push_back(i);
            }
        }
        if(ans.size()==1) {
            return ans[0];
        }
        else {
            return -1;
        }
    }
};