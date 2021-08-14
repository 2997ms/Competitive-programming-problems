
ll C(ll n,ll r){
    ll sum=1;
    for(ll i=1;i<=r;i++) {
        sum=sum*(n-r+i)/i;
    }
    return sum;
}
