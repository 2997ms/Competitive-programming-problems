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
#define LL_INF 0x33ffffffffffffff
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

const int maxn = 200005;
const ll mod = 998244353;
const double PI = acos(-1.0);

int dp[maxn][3];

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums)
    {
        if (nums.size() == 0)
            return 0;
        int sz = nums.size();
        mem(dp, 0);
        dp[1][1] = 1;//>
        dp[1][2] = 1;//<
        rep(i, 1, sz)
        {
            if (nums[i] < nums[i - 1])
            {
                dp[i + 1][2] = dp[i][1] + 1;
                dp[i + 1][1] = dp[i][1];
            }
            else if (nums[i] > nums[i - 1])
            {
                dp[i + 1][1] = dp[i][2] + 1;
                dp[i + 1][2] = dp[i][2];
            }
            else
            {
                dp[i + 1][1] = dp[i][1];
                dp[i + 1][2] = dp[i][2];
            }
        }
        return max(dp[sz][1], dp[sz][2]);
    }
}t;


