/*一开始考虑有问题，行和列一直考虑不清晰。后来发现先贪心找行的最大值，然后一列一列扫过去，发现是一致的*/
class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int n = A.size();
        int m = A[0].size();
        vector<int>flip(n,0);
        for (int i=0;i<n;i++) {
            if(A[i][0]==0) {
                flip[i]=1;
            }
        }
        int ans = 0;
        for(int i=0;i<m;i++) {
            int sum = (1<<(m-i-1));
            int cnt = 0;
            for(int j=0;j<n;j++) {
                cnt += (A[j][i] ^ flip[j]);
            }
            ans += max(cnt,n-cnt)*sum;
        }
        return ans;
    }
};