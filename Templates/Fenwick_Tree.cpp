ll num[maxn];
int lowbit(int x)
{
    return x&(-x);
}
ll getsum(ll x)
{
    ll ans = 0;
    while(x>0)
    {
        ans+=num[x];
        x-=lowbit(x);
    }
    return ans;
}
ll add(int x,int v)
{
    int up=maxn-1;
    while(x<=up)
    {
        num[x]+=v;
        x+=lowbit(x);
    }
    return x;
} 
