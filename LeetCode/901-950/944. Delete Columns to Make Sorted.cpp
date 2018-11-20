/*并不知道这个题想表达什么。莫名其妙的hard题*/
class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int n = A[0].size();
        int ans = 0;
        for(int i=0;i<n;i++) {
            int flag = 1;
            for(int j=1;j<A.size();j++) {
                if(A[j-1][i]>A[j][i]) {
                   flag = 0; 
                }
            }
            if(flag==0) {
                ans++;
            }
        }
        return ans;
    }
};