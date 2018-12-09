ll phi[maxn],mu[maxn],pri[maxn],vis[maxn];
void get_phi() {
    phi[1]=mu[1]=1;
    int tot=0;
    for(int i=2;i<=maxn-5;i++)
    {
        if(!vis[i]) pri[++tot]=i,mu[i]=-1,phi[i]=i-1;
        for(int j=1;j<=tot&&pri[j]*i<=maxn-5;j++)
        {
            vis[pri[j]*i]=1;
            if(i%pri[j]==0) {mu[i*pri[j]]=0;phi[i*pri[j]]=phi[i]*pri[j];break;}
            else mu[i*pri[j]]=-mu[i],phi[i*pri[j]]=phi[i]*(pri[j]-1);
        }
    }
}