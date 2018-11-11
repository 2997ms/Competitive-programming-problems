/*贪心，对两个数组都只遍历一遍*/
class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        vector< pair<int,int> > Apair;
        vector< pair<int,int> > Bpair;

        for (int i=0;i<A.size();i++) {
            Apair.push_back(make_pair(A[i],i));
        }
        for (int i=0;i<B.size();i++) {
            Bpair.push_back(make_pair(B[i],i));
        }
        sort(Apair.begin(),Apair.end());
        sort(Bpair.begin(),Bpair.end());

        int j = 0;
        vector<int>ans(A.size(),-1);
        vector<int>tmp;
        for (int i=0;i < Bpair.size();i++) {
            while (j < Apair.size()) {
                if (Apair[j].first > Bpair[i].first) {
                    ans[Bpair[i].second] = Apair[j].first;
                    j++;
                    break;
                } else {
                    tmp.push_back(Apair[j].second);
                    j++;
                }
            }
        }
        for (int i = 0;i < A.size(); i++) {
            if (ans[i]!=-1) {
                continue;
            } else {
                ans[i] = A[tmp.back()];
                tmp.pop_back();
            }
        }
        return ans;
    }
};