#include<iostream>
#include<iomanip>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<stack>
#define y0 abc111qqz
#define y1 hust111qqz
#define yn hez111qqz
#define j1 cute111qqz
#define tm crazy111qqz
#define lr dying111qqz
using namespace std;
#define REP(i, n) for (int i=0;i<int(n);++i)  
typedef long long LL;
typedef unsigned long long ULL;
const int N =1E4+5;
int pri[N],which[N];
int a,b,k;
bool flag;
int d[N];
bool prime(int x)
{
    for ( int i = 2 ; i*i<=x;i++ )
    {
	  if (x %i==0) return false;
    }
    return true;
}

bool ok (int x,int y)
{
    if (d[y]!=-1) return false;
    int res = 0; //记录两个数不对应不相等的数字的个数
    int xx=x,yy=y;
    while (x&&y)
    {
	  if (x%10!=y%10) res++;
	  x = x/10;
	  y = y/10;
    }
 //   if (res==1) cout<<"x:"<<xx<<" y:"<<yy<<endl;
    if (res==1) return true;
    return false;
}
void bfs()
{
    queue<int>x;
    memset(d,-1,sizeof(d));
    x.push(a);
    d[a]=0;
    while (!x.empty())
    {
	  int px = x.front();
//	  cout<<"px:"<<px<<endl;
	  x.pop();
	  if (px==b) return;
	  for ( int i = 0 ;  i< k ; i++ )
	  {
		if (ok(px,pri[i]))
		{
		    d[pri[i]]=d[px]+1;
		    x.push(pri[i]);
		}
	  }
    }


}
int main()
{
     k =0;
    for ( int i = 1000; i <=9999; i++ )
    {
	  if (prime(i))
	  {
		pri[k++]=i;
	  
	  }
    }
    int T;
    cin>>T;
    while (T--)
    {
	  cin>>a>>b;
	  bfs();
	  if (d[b]==-1)
	  {
		cout<<"Impossible"<<endl;
	  }
	  else
	  {
		cout<<d[b]<<endl;
	  }

    }

  
	return 0;
}