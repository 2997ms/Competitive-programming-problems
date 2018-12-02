class Solution {
public:
    bool check(string A) {
        int hour = (A[0]-'0')*10 + A[1]-'0';
        int minutes = (A[3]-'0')*10 + A[4]-'0';
        return hour<24&&minutes<60;
    }
    string largestTimeFromDigits(vector<int>& A) {
        string ans = "";
        sort(A.begin(),A.end());
        do {
            string tmp;
            tmp.push_back(char(A[0]+'0'));
            tmp.push_back(char(A[1]+'0'));
            tmp.push_back(':');
            tmp.push_back(char(A[2]+'0'));
            tmp.push_back(char(A[3]+'0'));
            if(check(tmp)) {
                ans = max(ans,tmp);
            }
        }while(next_permutation(A.begin(),A.end()));
        return ans;
    }
};