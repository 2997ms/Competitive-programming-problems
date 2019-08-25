/*此处是统计所有回文子串*/
long long h[600],b[600];
int dp1[1005];
int dp2[1005];
inline long long solve(int i1,int i2) {
    sz=0;
    for (int i=i1;i<=i2;++i)
        b[++sz]=h[i];
    long long res=0;
    int l=0,r=0,x;
    for (int i=1;i<=sz;++i) {
        if (i>r) x=1;
        else x=min(dp1[l+r-i],r-i);
        while (i-x>=1 && i+x<=sz && b[i-x]==b[i+x]) ++x;
        dp1[i]=x;
        if (i+x-1>r) l=i-x+1,r=i+x-1;
        res+=x;
    }
    l=0,r=0;
    for (int i=1;i<=sz;++i) {
        if (i>r) x=0;
        else x=min(dp2[l+r-i+1],r-i+1);
        while (i-x-1>=1 && i+x<=sz && b[i-x-1]==b[i+x]) ++x;
        dp2[i]=x;
        res+=x;
        if (i+x>=r) l=i-x,r=i+x-1;
    }
    return res;
}