/*考虑每经历一个位置，维护前面可用的集合*/
class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
    	vector<int>presum(A.size()+1,0);
    	for (int i = 0;i < A.size(); i++) {
    		presum[i+1] = A[i];
    		presum[i+1] += presum[i];
    	}
    	deque<int>que;
    	int ans = A.size() + 1;
    	for(int i=0;i<presum.size();i++) {
    		while(que.size()&&presum[i]-presum[que.back()]<=0) {
    			que.pop_back();
    		}
    		while(que.size()&&presum[i]-presum[que.front()]>=K) {
    			ans = min(i - que.front(), ans);
    			que.pop_front();
    		}
    		que.push_back(i);
    	}
    	return ans == A.size() + 1 ? -1 : ans;
    }
};