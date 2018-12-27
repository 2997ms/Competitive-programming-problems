class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int sz=A.size();
        if(sz==0)return 0;
        int len = A[0].length();
        vector<int>flag(sz,0);
        int cnt = 0;
        for(int i=0;i<len;i++) {
            int del = 0;
            for(int k=1;k<A.size();k++) {
                if(flag[k]==1) {
                    continue;
                }
                if(A[k-1][i]>A[k][i]) {
                    del=1;
                    break;
                }
            }
            if(del==0) {
            for(int k=1;k<A.size();k++) {
                if(flag[k]==1) {
                    continue;
                }
                if(A[k-1][i]<A[k][i]) {
                    flag[k]=1;
                }
            }
            } else {
                cnt+=1;
            }
        }
        return cnt;
    }
};
