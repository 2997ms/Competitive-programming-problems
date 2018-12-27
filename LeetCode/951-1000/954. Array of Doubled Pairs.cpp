/*贪心*/
class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
        sort(A.begin(),A.end());
        map<int,int>hax;
        for(int i=0;i<A.size();i++) {
            hax[A[i]]++;
        }
        int need = A.size()/2;
        if(need==0)return true;
        for(int i=0;i<A.size();i++) {
            if(need==0) {
                return true;
            }
            if(hax[A[i]]==0) {
                continue;
            }
            if(hax[2*A[i]]>0) {
                hax[A[i]]--;
                hax[2*A[i]]--;
                need--;
            }
            if(need==0) {
                return true;
            }
        }
        return false;
    }
};