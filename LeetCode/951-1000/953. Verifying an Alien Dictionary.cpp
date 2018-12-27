/*按题意执行一遍就行了*/
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int sz = words.size();
        vector<int>flag(sz, 0);
        map<char,int>ind;
        for(int i=0;i<order.size();i++) {
            ind[order[i]] = i;
        }

        int cnt = 0;
        while(true) {
            int f = 1;
            for(int i=1;i<words.size();i++) {
                if(flag[i]==0) {
                    f=0;
                } if(flag[i]==-1) {
                    return false;
                }
            }
            if(f) {
                return true;
            }

            for(int i=1;i<words.size();i++) {
                if(flag[i]) {
                    continue;
                }
                if(words[i].length()<cnt &&words[i-1].length()<cnt) {
                    flag[i]=1;
                }
                if(words[i].length()<cnt) {
                    flag[i]=-1;
                    break;
                }
                if(words[i-1].length()<cnt) {
                    flag[i]=1;
                    continue;
                }
                char s = words[i-1][cnt];
                char g = words[i][cnt];
                if(ind[s]<ind[g]) {
                    flag[i]=1;
                } else if(ind[s]==ind[g]) {
                    continue;
                } else {
                    flag[i]=-1;
                    break;
                }
            }
            cnt++;
        }
        return true;
    }
}s;