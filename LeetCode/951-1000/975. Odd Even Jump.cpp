/*从右往左，map的lower和upper*/
class Solution {
public:
    int oddEvenJumps(vector<int>& A) {
        int sz = A.size();
        vector<bool>high(sz,false);
        vector<bool>low(sz,false);
        map<int,int>m;
        high[sz-1] = low[sz-1] = true;
        
        int res = 1;
        m[A[sz-1]] = sz-1;
        for(int i = sz-2; i >= 0;i--) {
            auto hi = m.lower_bound(A[i]);
            auto lo = m.upper_bound(A[i]);
            if(hi!=m.end()) {
                high[i] = low[hi->second];
            }
            if(lo!=m.begin()) {
                low[i]=high[(--lo)->second];
            }
            if(high[i]) {
                res++;
            }
            m[A[i]] = i;
        }
        return res;
    }
};