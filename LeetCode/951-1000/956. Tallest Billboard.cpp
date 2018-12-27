/*题意是凑出两个集合，使得两个集合的数总和相等，求这个最大和。
dp，就是三种操作，+ - 什么都不做*/
class Solution {
public:
    int dp[25][10005];
    int tallestBillboard(vector<int>& rods) {
        memset(dp,-1,sizeof(dp));
        return cal(rods,0,5000);
    }
    int cal(vector<int>&rods,int st,int sum) {
        if(st==rods.size()) {
            if(sum==5000) {
                return 0;
            } else {
                return -1e9;
            }
        }
        if(dp[st][sum]!=-1) {
            return dp[st][sum];
        }
      
        dp[st][sum] = cal(rods,st+1,sum);
        dp[st][sum] = max(dp[st][sum],rods[st]+cal(rods,st+1,sum+rods[st]));
        dp[st][sum] = max(dp[st][sum],cal(rods,st+1,sum - rods[st]));
        return dp[st][sum];
    }
};