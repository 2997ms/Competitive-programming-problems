class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int>pre(S.length(),-1);
        vector<int>suf(S.length(),-1);

        for (int i=0;i<S.length();i++) {
            if (S[i]==C) {
                pre[i]=i;
            } else {
                if (i)
                    pre[i]=pre[i-1];
            }
        }
        for (int i=S.length()-1;i>=0;i--) {
            if(S[i]==C) {
                suf[i]=i;
            } else {
                if (i + 1 < S.length()) {
                    suf[i] = suf[i + 1];
                }
            }
        }

        vector<int>res;
        for (int i=0;i<S.length();i++) {
            int ans = 1e9;
            if (pre[i]!=-1) {
                ans = min(ans,i-pre[i]);
            }
            if (suf[i]!=-1) {
                ans = min(ans,suf[i]-i);
            }
            res.push_back(ans);
        }
        return res;
    }
};