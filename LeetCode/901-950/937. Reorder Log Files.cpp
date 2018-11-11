/*简单题，模拟排序*/
class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector< pair<string,int> >vstr;
        vector<int>vnum;
        for (int i=0;i<logs.size();i++) {
            for (int j=0;j<logs[i].size();j++) {
                if (logs[i][j]==' ') {
                    if(logs[i][j+1]>='a' && logs[i][j+1]<='z') {
                        string k = logs[i].substr(j+1);
                        vstr.push_back(make_pair(k,i));
                        break;
                    } else {
                        vnum.push_back(i);
                        break;
                    }
                } 
            } 
        }
        sort(vstr.begin(),vstr.end());

        vector<string>ans;
        for(int i=0;i<vstr.size();i++) {
            ans.push_back(logs[vstr[i].second]);
        }
        for(int i=0;i<vnum.size();i++) {
            ans.push_back(logs[vnum[i]]);
        }
        return ans;     
    }
};