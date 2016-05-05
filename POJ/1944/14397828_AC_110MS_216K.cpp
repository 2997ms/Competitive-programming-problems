/*#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

struct node
{
	int start;
	int end;

}node_one[10005];

vector<int>start1;
vector<int>end1;

int N,P,i,j,Q1,Q2,Qmin,Qmax,ans,h;

bool cmp(node node1,node node2)
{
	if(node1.start == node2.start)
		return node1.end< node2.end;

	return node1.start<node2.start;
}

void solve()
{
	int pre_s,pre_e;
	if(P==1)
	{
		start1.push_back(node_one[1].start);
		end1.push_back(node_one[1].end);
		return;
	}
	for(i=1;i<=P;i++)
	{
		if(i==1)
		{			
			pre_s=node_one[1].start;
			pre_e=node_one[1].end;
		}
		else
		{
			if(node_one[i].start>pre_e)
			{
				start1.push_back(pre_s);
				end1.push_back(pre_e);

				pre_s=node_one[i].start;
				pre_e=node_one[i].end;
			}
			else 
			{
				pre_e=node_one[i].end;
			}
		}
	}
	start1.push_back(pre_s);
	end1.push_back(pre_e);

	int len=start1.size();
	int result=0;

	for(i=0;i<len;i++)
	{
		result += end1[i]-start1[i];
	}
	if(result<ans)
		ans=result;
}

void solve_2(int duan1,int duan2)
{
	for(i=1;i<=P;i++)
	{
		if(node_one[i].start<=duan1&&node_one[i].end>=duan2)
		{
		}
		else
		{
		}
	}
}

int main()
{
	cin>>N>>P;

	for(i=1;i<=P;i++)
	{
		cin>>Q1>>Q2;
		node_one[i].start = min(Q1,Q2);
		node_one[i].end = max(Q1,Q2);
	}
	sort(node_one+1,node_one+P+1,cmp);

	ans=1000;

	solve();

	for(i=1;i<N;i++)
	{
		solve_2(i,i+1);
	}
	cout<<ans<<endl;
	
	system("pause");
	return 0;
}
*/
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

#define N 1005
#define INF 0x3f3f3f3f
#define MAX(a,b) ((a)>(b)?(a):(b))
 
int n,p,to[N];
struct E
{
    int sta,ed;
}e[10005];
 
void swap(int &a,int &b)
{
    int temp=a;
    a=b;b=temp;
}
 
void re(void)
{
    scanf_s("%d%d",&n,&p);
    for(int i=1;i<=p;i++)
    {
        scanf_s("%d%d",&e[i].sta,&e[i].ed);
        if(e[i].sta>e[i].ed) swap(e[i].sta,e[i].ed);
    }
}
 
void run(void)
{
    int ans=INF;
    for(int i=1;i<=n;i++)
    {
        memset(to,0,sizeof(to));
        int sum=0;
        for(int j=1;j<=p;j++)
        {
            if(i>e[j].sta&&i<=e[j].ed)
            {
                to[1]=MAX(to[1],e[j].sta);
                to[e[j].ed]=n+1;
            }
            else
                to[e[j].sta]=MAX(to[e[j].sta],e[j].ed);
        }
        sum=0;
        int ri=0;
        for(int j=1;j<=n;j++)
        {
            if(!to[j])continue;
            if(j>ri)
            {
                sum+=to[j]-j;
                ri=to[j];
            }
            else if(to[j]>ri)
            {
                sum+=to[j]-ri;
                ri=to[j];
            }
        }
        ans=ans<sum?ans:sum;
    }
    printf("%d\n",ans);
}
 
int main()
{
    re();
    run();
    return 0;
}