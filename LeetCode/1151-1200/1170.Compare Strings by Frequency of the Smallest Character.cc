class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> t;
        for(int i=0;i<words.size();i++) {
            map<char,int>hax;
            for(auto g:words[i]) {
                hax[g]++;

            }
            int minn = words[i].size();
            for(char z = 'a';z<='z';z++) {
                if(hax.count(z)) {
                    minn = hax[z];
                    break;
                }
            }
            t.push_back(minn);
        }
        sort(t.begin(), t.end());
        vector<int>ans;
        for(int i=0;i<queries.size();i++) {
            map<char,int>hax;
            for(auto g:queries[i]) {
                hax[g]++;

            }
            int minn = queries[i].size();
            for(char z = 'a';z<='z';z++) {
                if(hax.count(z)) {
                    minn = hax[z];
                    break;
                }
            }
           int pos = 0;
           for(int i=0;i<t.size();i++) {
               if(t[i]>minn) {
                   pos++;
               }
           }
            ans.push_back(pos);
        }
        return ans;
    }
};
