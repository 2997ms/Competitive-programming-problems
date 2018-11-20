/*找极值，确定极点。当然也可以遍历一次，碰到不符合要求的break掉。*/
class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        if(A.size()<3)return false;
        int cnt = 0;
        int p = -1;
        for (int i=1;i<A.size()-1;i++) {
            if (A[i-1] < A[i] && A[i] > A[i+1]) {
                cnt++;
                p = i;
            }
        }
        if(cnt != 1) {
            return false;
        }
        for(int i=1;i<A.size();i++) {
            if (i>p) {
               if(A[i-1]<=A[i]) {
                   return false;
               } 
            } else {
                if(A[i-1]>=A[i]) {
                    return false;
                }
            }
        }
        return true;
    }
};