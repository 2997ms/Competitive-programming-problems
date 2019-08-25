ll po(ll a, ll b, ll mod)
{
    ll res = 1;
    a %= mod;
    for (; b; b >>= 1)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
    }
    return res;
}
ll Test[10] = {2, 3, 5, 7, 11, 13, 17};
bool Query(ll P) {
    if(P == 1) return 0;
    ll t = P - 1, k = 0;
    while(!(t & 1)) k++, t >>= 1;
    for(int i = 0; i < 7; i++) {
        if(P == Test[i]) return 1;
        ll a = po(Test[i], t, P), nxt = a;
        for(ll j = 1; j <= k; j++) {
            nxt = (a * a) % P;
            if(nxt == 1 && a != 1 && a != P - 1) return 0;
            a = nxt;
        }
        if(a != 1) return 0;
    }
    return 1;
}