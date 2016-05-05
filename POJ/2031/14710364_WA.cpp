#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

struct no{
	double x;
	double y;
	double z;
	double r;
}node[105];

int num,n;  
double map[102][102];  
int stack[102];  
double minidis[102];  
  
double prim()  
{  
    int i,j,s;
	double result;  
  
    memset(stack,0,sizeof(stack));  
    for(i=1;i<=num;i++)  
    {  
        minidis[i]=100000005;  
    }  
  
    stack[1]=1;  
    minidis[1]=0;  
    s=1;  
    result=0;  
  
    for(i=1;i<=num-1;i++)  
    {  
        double min_all=100000005;  
        int min_temp=0;  
        for(j=2;j<=num;j++)  
        {  
            if(stack[j]==0&&minidis[j]>map[s][j])  
            {  
                minidis[j]=map[s][j];  
            }  
            if(stack[j]==0&&minidis[j]<min_all)  
            {  
                min_temp=j;  
                min_all=minidis[j];  
            }  
        }  
        s=min_temp;  
        stack[s]=1;  
        result += min_all;  
    }  
    return result;  
} 

int main()
{
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);

	int i,j;
	while(cin>>n)
	{
		if(n==0)
			break;
		memset(map,0,sizeof(map));
		for(i=1;i<=n;i++)
		{
			cin>>node[i].x>>node[i].y>>node[i].z>>node[i].r;
		}
		for(i=1;i<=n;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				map[i][j]=max(0.0,sqrt((node[i].x-node[j].x)*(node[i].x-node[j].x) +(node[i].y-node[j].y)*(node[i].y-node[j].y) +(node[i].z-node[j].z)*(node[i].z-node[j].z))-node[i].r-node[j].r);
			}
		}
		num=n;
	    printf("%.3lf\n",prim());
	}
	return 0;
}