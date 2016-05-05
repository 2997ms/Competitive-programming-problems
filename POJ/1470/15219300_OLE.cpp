#include<cstdio>
#include<cstring>
#define N 1005
using namespace std;
char ch;
struct arr{int next,go;}a[N*2];
int f[N],x,y,num,n,m,i,ans[N],cnt,CNT,end[N],END[N],root,fa[N],ask[N][N];
bool visit[N];
inline void add(int u,int v) {a[++cnt].go=v;a[cnt].next=end[u];end[u]=cnt;}
inline int get(int u){return f[u]==u?u:f[u]=get(f[u]);}
void tarjan(int k)
{
  f[k]=k;
  for (int i=end[k];i;i=a[i].next)
  {
    int go=a[i].go;
    tarjan(go);f[go]=k;
  }
  visit[k]=true;
  for (int i=1;i<=n;i++)
    if (visit[i]&&ask[k][i])
      ans[k]+=ask[k][i];

}
int main()
{
  while (scanf("%d",&n)!=EOF)
  {
    memset(end,0,sizeof(end));
    memset(ask,0,sizeof(ask));
    memset(ans,0,sizeof(ans));
    memset(fa,0,sizeof(fa));
    memset(visit,0,sizeof(visit));
    cnt=0;CNT=0;
    for (i=1;i<=n;i++)
    {
      scanf("%d:(%d)",&x,&num);
      while (num)
      {
        num--;scanf("%d",&y);add(x,y);fa[y]++;
      }
    }
    scanf("%d",&m);
    for (i=1;i<=m;i++)
      scanf(" (%d %d) ",&x,&y),ask[x][y]++,ask[y][x]++;
    for (i=1;i<=n;i++)
      if (fa[i]==0) {root=i;break;}
    tarjan(root);
    for (i=1;i<=n;i++)
      if (ans[i]) printf("%d:%d\n",i,ans[i]);
  }
  return 0;  
}