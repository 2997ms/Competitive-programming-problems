class Solution {
public:
    int calculateTime(string keyboard, string word) {
        map<char,int>pos;
        for(int i=0;i<keyboard.size();i++) {
            pos[keyboard[i]] = i;
        }
        int now = 0;
        int ans = 0;
        for(int i=0;i<word.size();i++) {
            ans += abs(pos[word[i]] - now);
            now = pos[word[i]];
        }
        return ans;
    }
};