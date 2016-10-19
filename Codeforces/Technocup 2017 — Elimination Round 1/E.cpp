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
typedef unsigned long long ull;
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

const int maxn = 2000005;
const ll mod = 1000;
const double PI = acos(-1.0);
ll po(ll a, ll b, ll mod) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1)res = res*a%mod; a = a*a%mod; }return res; }
ll gcd(ll a, ll b) { if (a == 0) { return b; } else { return gcd(b%a, a); } }

/*--------------------------------------------*/

struct AC_automation
{
#define Ni 2000005
#define Mi 26
    int next[Ni][Mi], fail[Ni];
    ll end[Ni];
    int root, sz;
    int idx(char x)
    {
        return x - 'a';
    }
    int newnode()
    {
        sz++;
        for (int i = 0; i < Mi; i++)
        {
            next[sz][i] = -1;
        }
        end[sz] = 0;
        return sz;
    }
    void init()
    {
        sz = 0;
        root = newnode();
    }
    void insert(char s[], int len, int id)
    {
        int now = root;
        for (int i = 0; i < len; i++)
        {
            int c = idx(s[i]);
            if (next[now][c] == -1)
            {
                next[now][c] = newnode();
            }
            now = next[now][c];
        }
        end[now] = id;
    }
    void build()
    {
        queue<int>que;
        for (int i = 0; i < Mi; i++)
        {
            if (next[root][i] == -1)
            {
                next[root][i] = root;
            }
            else
            {
                fail[next[root][i]] = root;
                que.push(next[root][i]);
            }
        }
        while (!que.empty())
        {
            int now = que.front();
            que.pop();
            if (end[fail[now]])
            {
                end[now] = end[fail[now]];
            }
            for (int i = 0; i < Mi; i++)
            {
                if (next[now][i] == -1)
                {
                    next[now][i] = next[fail[now]][i];
                }
                else
                {
                    fail[next[now][i]] = next[fail[now]][i];
                    que.push(next[now][i]);
                }
            }
        }
    }
}ac;

int n, k;
char x[maxn], val[maxn];
int r[maxn];

void search()
{
    int now = 1, cnt = 0;
    for (int i = 0; x[i]; i++)
    {
        int f = x[i] - 'a';
        while (ac.next[now][f] == -1)
        {
            now = ac.fail[now];
        }
        now = ac.next[now][f];
        if (ac.end[now] != 0)
        {
            r[i] = ac.end[now];
        }
    }
}

void solve()
{
    scanf("%d%d", &n, &k);
    scanf("%s", x);
    int len = strlen(x);
    for (int i = len, cnt = 0; cnt < k; i++, cnt++)
    {
        x[i] = x[cnt];
    }
    len = strlen(x);
    ac.init();
    int g;
    scanf("%d", &g);
    for (int i = 1; i <= g; i++)
    {
        scanf("%s", val);
        int le = strlen(val);
        ac.insert(val, le, i);
    }
    ac.build();
    memset(r, -1, sizeof(r));
    search();
    for (int i = k; i < k+k; i++)
    {
        set<int>num;
        vector<int>ans;
        for (int j = i; j < (n+1)*k; j += k)
        {
            if (r[j] == -1)break;
            num.insert(r[j]);
            ans.push_back(r[j]);
        }
        if (num.size() == n)
        {
            puts("YES");
            for (int i = 0; i < n; i++)
            {
                printf("%d ", ans[i]);
            }
            return;
        }
    }
    puts("NO");
}

int main()
{
    solve();
    return 0;
}
