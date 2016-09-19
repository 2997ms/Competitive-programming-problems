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

const int maxn = 2e6 + 5;
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);
ll po(ll a, ll b) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1)res = res*a%mod; a = a*a%mod; }return res; }

int xcode(char x)
{
    if (x == 'I')
    {
        return 1;
    }
    else if (x == 'V')
    {
        return 5;
    }
    else if (x == 'X')
    {
        return 10;
    }
    else if (x == 'L')
    {
        return 50;
    }
    else if (x == 'C')
    {
        return 100;
    }
    else if (x == 'D')
    {
        return 500;
    }
    else if (x == 'M')
    {
        return 1000;
    }
    else
    {
        return 0;
    }
}

class Solution
{
public:
    int romanToInt(string s) 
    {
        int len = s.length();
        vector<int>val(len, 0);
        rep(i, 0, len)
        {
            val[i] = xcode(s[i]);
        }
        int res = val[0];
        rep(i, 1, len)
        {
            if (val[i] > val[i - 1])
            {
                res = res - 2 * val[i - 1];
                res = res + val[i];
            }
            else
            {
                res = res + val[i];
            }
        }
        return res;
    }
};

