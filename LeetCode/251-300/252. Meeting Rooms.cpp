//#pragma comment(linker, "/STACK:102400000,102400000") 
#pragma warning(disable:4996)
#include <fstream>
#include <iostream>
#include <functional>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <deque>
#include <ctime>
#include <list>
#include <set>
#include <map>
using namespace std;
typedef long long ll;

#define eps 1e-10
#define LL_INF 0x3fffffffffffffff
#define INF 0x3f3f3f3f
#define mem(a, b) memset(a, b, sizeof(a))
#define pper(i,n,m) for(int i = n;i >= m; i--)
#define repp(i, n, m) for (int i = n; i <= m; i++)
#define rep(i, n, m) for (int i = n; i < m; i++)
#define sa(n) scanf("%d", &(n))
#define mp make_pair
#define ff first
#define ss second
#define pb push_back

const int maxn = 1e5 + 5;
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);

 struct no
 {
     int tim;
     int val;
 };

 bool cmp(no a, no b)
 {
     if (a.tim == b.tim)
     {
         return a.val < b.val;
     }
     else
     {
         return a.tim < b.tim;
     }
 }

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& in)
    {
        int i, j, k;
        int sz = in.size();
        if (sz == 0)
            return true;
        vector<no>r;
        rep(i, 0, sz)
        {
            no tmp;
            tmp.tim = in[i].start;
            tmp.val = 1;
            r.push_back(tmp);

            tmp.tim = in[i].end;
            tmp.val = -1;
            r.push_back(tmp);
        }
        sort(r.begin(), r.end(), cmp);
        int res = 1;
        int cur = 0;
        sz = r.size();
        rep(i, 0, sz)
        {
            cur += r[i].val;
            res = max(res, cur);
        }
        return res == 1;
    }
};
