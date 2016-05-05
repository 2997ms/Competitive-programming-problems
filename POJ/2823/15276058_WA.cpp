#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX=0X3f3f3f3f;
const int MIN=-MAX;
const int maxn=4e6+5;
int n,k;
int dat_min[maxn*2-1];
int dat_max[maxn*2-1];
int res_min[maxn];
int res_max[maxn];

void init(int n_){
    n=1;
    while(n < n_) n*=2;
    for(int i=0;i<2*n-1;i++) dat_min[i]=MAX;
    for(int i=0;i<2*n-1;i++) dat_max[i]=MIN;
    memset(res_min,0,sizeof(res_min));
    memset(res_max,0,sizeof(res_max));
}

//k从0开始
void update(int k,int a){
    k+=n-1;
    dat_min[k]=a;
    dat_max[k]=a;
    //向上更新
    while(k > 0){
        k=(k-1)/2;
        dat_max[k]=max(dat_max[k*2+1],dat_max[k*2+2]);
        dat_min[k]=min(dat_min[k*2+1],dat_min[k*2+2]);
    }
}

int query_min(int a,int b,int k,int l,int r){
    if(r<=a || b<=l){
        return MAX;
    }
    if(a<=l && r<=b){
        return dat_min[k];
    }
    else {
        int vl=query_min(a,b,k*2+1,l,(l+r)/2);
        int vr=query_min(a,b,k*2+2,(l+r)/2,r);
        return min(vl,vr);
    }
}

int query_max(int a,int b,int k,int l,int r){
    if(r<=a || b<=l){
        return MIN;
    }
    if(a<=l && r<=b){
        return dat_max[k];
    }
    else {
        int vl=query_max(a,b,k*2+1,l,(l+r)/2);
        int vr=query_max(a,b,k*2+2,(l+r)/2,r);
        return max(vl,vr);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n>>k){
        init(n);
        for(int i=0;i<n;i++){
            int temp;
            cin>>temp;
            update(i,temp);
        }
        for(int i=0;i+k<=n;i++){
            res_min[i]=query_min(i,i+k,0,0,n);
            res_max[i]=query_max(i,i+k,0,0,n);
        }
        for(int i=0;i+k<=n;i++){
            cout<<res_min[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i+k<=n;i++){
            cout<<res_max[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}