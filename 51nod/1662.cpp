#include <iostream>  
#include <algorithm>  
#include <cmath>  
#include <vector>  
#include <string>  
#include <cstring>
#include <queue>
#include <map>
using namespace std;
typedef long long ll;

const int mod = 1e9 + 7;

ll p, k;
ll po(ll x, ll k)
{
    ll n = 1;

    while (k > 0)
    {
        if (k & 1)
            n = (n*x) % mod;
        x = (x*x) % mod;
        k = k >> 1;
    }
    return n;
}

int main()
{
    cin >> p >> k;
    if (k == 0)
    {
        cout << po(p, p - 1) << endl;
    }
    else if (k == 1)
    {
        cout << po(p, p) << endl;
    }
    else
    {
        int i;
        ll res = 1;
        for (i = 1;; i++)
        {
            res = res*k;
            if (res%p == 1)
                break;
            res = res%p;
        }
        cout << po(p, (p - 1) / i) << endl;
    }

    return 0;
}