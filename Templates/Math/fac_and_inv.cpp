struct CC {
    ll fac[maxn], inv[maxn];

    CC() {
        fac[0] = 1;
        REPP(i,1,maxn-1) {
            fac[i] = fac[i-1] * i % mod;
        }
        inv[maxn-1] = po(fac[maxn-1], mod-2, mod);
        for(int i=maxn-2;i>=0;i--) {
            inv[i] = inv[i+1] * (i+1) % mod; 
        }
    }
    ll operator() (ll n, ll k) {
        if(n < k) {
            return 0;
        }
        return fac[n] * inv[n-k] % mod * inv[k] % mod;
    } 
}C;