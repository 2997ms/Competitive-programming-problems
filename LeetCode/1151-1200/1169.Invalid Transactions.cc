
struct no{
    string name;
    int time;
    int amount;
    string city;
}g[1005];

class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        vector<string> ans;

        for(int i=0;i<transactions.size();i++) {
            string k = transactions[i];
            string name;
            int st = 0;
            for(st=0;st<k.length();st++) {
                if(k[st]==',')break;
                name.push_back(k[st]);
            }
            int t = 0;
            for(st=st+1;st<k.length();st++) {
                 if(k[st]==',')break;
                 t = t*10 + k[st]-'0';
            }
            int amount = 0;
            for(st=st+1;st<k.length();st++) {
                 if(k[st]==',')break;
                 amount = amount*10 + k[st]-'0';
            }
            string city;
            for(st=st+1;st<k.length();st++) {
                 if(k[st]==',')break;
                 city.push_back(k[st]);
            }
            g[i].name = name;
            g[i].time = t;
            g[i].amount = amount;
            g[i].city = city;
        }        
        for(int i=0;i<transactions.size();i++) {
            if(g[i].amount>1000) {
                ans.push_back(transactions[i]);
            } else {
                for(int j=0;j<transactions.size();j++) {
                    if(i==j)continue;
                    if(abs(g[j].time - g[i].time)<=60 && g[j].name == g[i].name && g[j].city != g[i].city) {
                        ans.push_back(transactions[i]);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};