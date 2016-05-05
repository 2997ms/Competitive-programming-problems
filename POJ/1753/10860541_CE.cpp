#include<iostream>
using namespace std;
int re(int (*a)[6],int (*b)[6],int tag)
{
 int i,j,p,q,k,m,sum,temp_sum;
 bool flag=false;
 sum=1000;
 for(i=0;i<=1;i++)
 {
  for(j=0;j<=1;j++)
  {
   for(p=0;p<=1;p++)
   {
    for(q=0;q<=1;q++)
    {
     a[0][1]=i;
     a[0][2]=j;
     a[0][3]=p;
     a[0][4]=q;
     temp_sum=0;
     for(k=1;k<=4;k++)
     {
      for(m=1;m<=4;m++)
      {
       if(a[k-1][m]%2!=tag)
       {
        temp_sum++;
        a[k-1][m]++;
        a[k][m]++;
        a[k+1][m]++;
        a[k][m-1]++;
        a[k][m+1]++;
       }
      }
     }
     for(k=1;k<=4;k++)
     {
      if(a[4][k]%2!=tag)
       break;
     }
     //cout<<temp_sum<<endl;
     if(k>4)
     {
      if(temp_sum<sum)
       sum=temp_sum;
     }
     for(k=0;k<6;k++)
      for(m=0;m<6;m++)
       a[k][m]=b[k][m];
    }
   }
  }
 }
 if(sum==1000) return -1;
 else
  return sum;
}
int main()
{
 int a[6][6],b[6][6],c[6][6],i,j,x,y,total=0;;
 char temp;
 for(i=0;i<6;i++)
  for(j=0;j<6;j++)
   a[i][j]=0;
 for(i=1;i<=4;i++)
 {
  for(j=1;j<=4;j++)
  {
   cin>>temp;
   if(temp=='w')
   {
    a[i][j]=1;
    total++;
   }
  }
 }
 if(total==16||total==0)
 {
  cout<<"0"<<endl;
  return 0;
 }
 for(i=0;i<6;i++)
 {
  for(j=0;j<6;j++)
  {
   b[i][j]=a[i][j];
   c[i][j]=a[i][j];
  }
 }
 x=re(a,c,0);
 //cout<<endl;
 y=re(b,c,1);
 //cout<<x<<" "<<y<<endl;
 if(x==-1&&y==-1) cout<<"Impossible"<<endl;
 if(x==-1&&y!=-1) cout<<y<<endl;
 if(x!=-1&&y==-1) cout<<x<<endl;
 if(x!=-1&&y!=-1)
 {
  total=(x<y)?x:y;
  cout<<total<<endl;
 }
 return 0;
}