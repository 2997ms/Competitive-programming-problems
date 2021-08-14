int n;
ll SEED1 = 31;
ll SEED2 = 97;
ll k1[maxn], k2[maxn];
ll Hash1[maxn], Hash2[maxn];
char s[maxn];
struct string_hash
{
    void init() {
        k1[0]=1;
        k2[0]=1;
        Hash1[0] = 0;
        Hash2[0] = 0;
        for(int i=1; i<=n; i++) {
            k1[i] = k1[i-1]*SEED1;
            k2[i] = k2[i-1]*SEED2;
        }
        for(int i=1; i<=n; i++) {
            Hash1[i]=Hash1[i-1]*SEED1 + (s[i]-'a' + 1);
            Hash2[i]=Hash2[i-1]*SEED2 + (s[i]-'a' + 1);
        }
    }
    ll get_val1(int i,int j) {
        return Hash1[j] - Hash1[i-1]*k1[j-i+1];
    }
    ll get_val2(int i,int j) {
        return Hash2[j] - Hash2[i-1]*k2[j-i+1];
    }
};