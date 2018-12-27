class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        int init = 0;
        rep(i,0,cells.size()) {
            init = init*2 + cells[i];
        }
        map<int,int>hax;
        map<int,int>ind;
        hax[init] = 0;
        ind[0]=init;
        int cnt = 0;
        int c = 1;
        while(true) {
            if(N==cnt) {
                return cells;
            }
            vector<int>s(cells.size(),0);
            rep(i,0,cells.size()) {
                if(i==0 || i==cells.size()-1) {
                    s[i] = 0;
                } else {
                    if(cells[i-1] == cells[i+1]) {
                        s[i] = 1;
                    }
                }
            }
            cells = s;
            int nxt = 0;
            rep(i,0,cells.size()) {
                nxt = nxt*2 + cells[i];
            }
            if(hax.count(nxt)) {
                c = cnt - hax[nxt] + 1;
                N -= hax[nxt];
                N %= c;
                N+=hax[nxt];
                break;
            }
            cnt++;
            hax[nxt] = cnt;
            ind[cnt] = nxt;
        }
        vector<int>ans;
        int res = ind[N];
        rep(i,0,cells.size()) {
            ans.push_back( ((res>>(cells.size() - i -1)) &1) );
        }
        return ans;
    }
};
