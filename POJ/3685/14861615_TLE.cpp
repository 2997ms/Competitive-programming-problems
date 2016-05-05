#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
#include<queue>
#include<iostream>
#include<map>
using namespace std;
typedef long long LL;
const int maxn = 1000 + 5;
const LL INF = 1LL<<40;
LL n,m;

LL cal(LL i,LL j){
    return  i*i + 100000 * i + j*j - 100000 * j + i * j;
}

int can(LL x){
    LL cntx = 0,cnty = 0;
    for(LL i = 1;i <= n;i++){
        LL l = 1,r = n;
        LL tem = -1;
        while(l <= r){
            LL mid = l+(r-l)/2;
            if(cal(mid,i) < x){
                l = mid+1;
                tem = mid;
            }
            else {
                r = mid-1;
            }
        }
        if(tem != -1){
            cntx += tem;
        }
    }
    for(LL i = 1;i <= n;i++){
        LL l = 1,r = n;
        LL tem = -1;
        while(l <= r){
            LL mid = l+(r-l)/2;
            if(cal(mid,i) <= x){
                l = mid+1;
                tem = mid;
            }
            else {
                r = mid-1;
            }
        }
        if(tem != -1){
            cnty += tem;
        }
    }
    if(cntx < m){
        return 1;
    }
    else if(cntx > m-1){
        return -1;
    }
    else{
        return 0;
    }
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%I64d%I64d",&n,&m);
        LL l = -INF,r = INF;
        LL ans;
        while(l <= r){
            LL mid = l+(r-l)/2;
            int tag = can(mid);
            if(tag == 1){
                l = mid+1;
            }
            else if(tag == -1){
                r = mid-1;
            }
            else{
                ans = mid;
                break;
            }
        }
        printf("%I64d\n",ans);
    }
    return 0;
}